#ifndef SCANNER_H_
#define SCANNER_H_

#include <string>
#include <iosfwd>
#include <vector>

namespace jast {

class CharacterStream {
public:
    virtual ~CharacterStream() = default;

    virtual void putback(char ch) = 0;

    virtual int read(std::string &str, int num) = 0;

    virtual char readchar() = 0;
};

// simple scanner class
template <class StreamType, class BufferType>
class BufferedCharacterStream : public CharacterStream {
public:
    BufferedCharacterStream(StreamType &is) : is_(is), buffer_(0) { }
    ~BufferedCharacterStream() = default;

    // read a character from stream
    int read(std::string &str, int num) override  {
        str.resize(num, '\0');

        if (is_.eof())
            return -1;
        // FIXME: make it working
        // auto size = is_.readsome(str.data(), num);
        return -1;
    }

    void putback(char ch) override {
        buffer_.push_back(ch);
    }

    char readchar() override {
        if (!buffer_.empty()) {
            char ch = buffer_.back();
            buffer_.pop_back();
            return ch;
        }
        if (is_.fail() || is_.eof()) {
            return EOF;
        }
        return is_.get();
    }

private:
    StreamType &is_;
    BufferType buffer_;
};

using Scanner = BufferedCharacterStream<std::istream, std::vector<char>>;
using StandardCharacterStream = Scanner;

} // jast

#endif
