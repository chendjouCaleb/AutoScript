//
// Created by HP on 21/03/2022.
//

#ifndef AUTOSCRIPT_TOKEN_H
#define AUTOSCRIPT_TOKEN_H

#include <string.h>
#include "index.h"

typedef enum TokenType {
    TOKEN_WORD,
    TOKEN_NUMBER,
    TOKEN_MATH_OPERATOR,
    TOKEN_PARENTHESIS_OPEN,
    TOKEN_PARENTHESIS_CLOSE,

    OR_NULL,
    TOKEN_OR,
} TokenType;

typedef struct Token {
    char *text;
    Index index;
    TokenType type;
} Token;

#endif //AUTOSCRIPT_TOKEN_H
