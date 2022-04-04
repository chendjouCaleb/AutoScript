//
// Created by HP on 02/04/2022.
//

#ifndef AUTOSCRIPT_TOKENITERATOR_H
#define AUTOSCRIPT_TOKENITERATOR_H

#include <malloc.h>
#include "token.h"

typedef struct TokenIterator {
    size_t index;
    size_t length;
    Token** tokens;
}TokenIterator;


TokenIterator* tkIt_create(Token** tokens, size_t length) {
    TokenIterator* iterator = malloc(sizeof(TokenIterator));
    iterator->index = 0;
    iterator->length = length;
    iterator->tokens = tokens;

    return iterator;
}


bool tkIt_has(TokenIterator* it) {
    return it->index <= it->length - 1;
}

void tkIt_next(TokenIterator* it) {
    it->index += 1;
}

Token* tkIt_current(TokenIterator* it) {
    return it->tokens[it->index];
}


void tkIt_destroy(TokenIterator* it) {
    free(it);
}



#endif //AUTOSCRIPT_TOKENITERATOR_H
