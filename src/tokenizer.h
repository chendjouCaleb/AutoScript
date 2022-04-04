//
// Created by HP on 21/03/2022.
//

#ifndef AUTOSCRIPT_TOKENIZER_H
#define AUTOSCRIPT_TOKENIZER_H

#include "token.h"
#include "CharIterator.h"
#include "tokenList.h"
#include "utility.h"

#include <string.h>
#include <malloc.h>
#include <stdio.h>


typedef struct Tokenizer {
    TokenList *tokenList;
    CharIterator *it;
    char *text;

} Tokenizer;

Token *tk_takeMathOperator(Tokenizer *tokenizer);

Token *tk_takeParenthesis(Tokenizer *tokenizer);

Token *tk_takeNumber(Tokenizer *tokenizer);


Tokenizer *tk_create(char *text) {
    Tokenizer *tokenizer = malloc(sizeof(Tokenizer));
    tokenizer->text = text;
    tokenizer->it = it_create(text);
    tokenizer->tokenList = tl_createList(10000);

    return tokenizer;
}

void tk_destroy(Tokenizer* tokenizer) {
    tl_destroy(tokenizer->tokenList);
    it_destroy(tokenizer->it);
    free(tokenizer);
}


void tk_tokenizer(Tokenizer *tokenizer) {
    CharIterator *it = tokenizer->it;

    while (it_hasCurrent(it)) {
        if (it_isIn(it, "+*-/%")) {
            tk_takeMathOperator(tokenizer);
        } else if (it_isIn(it, "()")) {
            tk_takeParenthesis(tokenizer);
        } else if (it_isDigit(it)) {
            tk_takeNumber(tokenizer);
        } else {
            it_next(it);
        }
    }
}

Token *tk_takeMathOperator(Tokenizer *tokenizer) {
    CharIterator *it = tokenizer->it;

    if (it_isIn(it, "+*-/%")) {
        Token *plus = tl_createToken();
        plus->text = toString(it_current(it));
        plus->type = TOKEN_MATH_OPERATOR;
        plus->index = it_getIndex(it);
        tl_addToken(tokenizer->tokenList, plus);
        it_next(it);
        return plus;
    }
    return NULL;
}

Token *tk_takeParenthesis(Tokenizer *tokenizer) {
    CharIterator *it = tokenizer->it;

    if (it_isIn(it, "()")) {
        Token *plus = tl_createToken();
        plus->text = toString(it_current(it));
        plus->type = TOKEN_PARENTHESIS;
        plus->index = it_getIndex(it);
        tl_addToken(tokenizer->tokenList, plus);
        it_next(it);
        return plus;
    }
    return NULL;
}

Token *tk_takeNumber(Tokenizer *tokenizer) {
    CharIterator *it = tokenizer->it;
    if (it_isDigit(it)) {
        Index index = it_getIndex(it);
        char *value = malloc(sizeof(char) * 100);
        int i = 0;

        while (it_hasCurrent(it) && (it_isDigit(it) || it_isIn(it, "'."))) {
            value[i] = it_current(it);
            it_next(it);
            i++;
        }
        value[i] = '\0';

        Token *number = tl_createToken();
        number->index = index;
        number->text = value;
        number->type = TOKEN_NUMBER;

        tl_addToken(tokenizer->tokenList, number);

        return number;
    }
    return NULL;
}

#endif //AUTOSCRIPT_TOKENIZER_H
