//
// Created by HP on 28/03/2022.
//

#ifndef AUTOSCRIPT_TOKENLIST_H
#define AUTOSCRIPT_TOKENLIST_H


#include "token.h"
#include <malloc.h>

typedef struct TokenList {
    int length;
    Token** tokens;
} TokenList;


TokenList* tl_createList(int size) {
    TokenList* tokenList = malloc(sizeof(TokenList));
    tokenList->tokens = malloc(sizeof(Token*) * size);
    tokenList->length = 0;

    return tokenList;
}

Token* tl_createToken() {
    Token* token = malloc(sizeof(Token));
    return token;
}

void tl_destroy(TokenList* list) {
    for (int i = 0; i < list->length; i++) {
        free(list->tokens[i]);
    }
    free(list->tokens);
    free(list);
}

void tl_addToken(TokenList* list, Token* token) {
    list->tokens[list->length] = token;
    list->length += 1;
}

Token* tl_get(TokenList* list, int index) {
    if(index >= 0 && index < list->length) {
        return list->tokens[index];
    }
    return NULL;
}


#endif //AUTOSCRIPT_TOKENLIST_H
