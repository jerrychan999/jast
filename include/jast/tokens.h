#ifndef TOKENS_H_
#define TOKENS_H_


enum TokenType {
#define O(t, k, p) t,
#define K(t, k, p) t,
#define T(t, k, p) t,
#include "jast/tokens.inc"
    NUM_TOKENS
};

bool IsKeyword(TokenType type);

#endif
