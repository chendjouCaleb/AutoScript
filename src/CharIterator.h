//
// Created by HP on 21/03/2022.
//

#ifndef AUTOSCRIPT_CHARITERATOR_H
#define AUTOSCRIPT_CHARITERATOR_H

#include <stdint.h>
#include <string.h>
#include <malloc.h>
#include <stdbool.h>
#include <stdio.h>
#include "index.h"

typedef struct CharIterator {
    char *text;

    int index;
    int lineIndex;
    int line;

    size_t length;
    char current;
} CharIterator;

/**
 * Create a new iterator.
 * @param text
 * @return A pointer to the created iterator.
 */
CharIterator *it_create(char *text) {
    CharIterator *it = malloc(sizeof(CharIterator));
    it->index = 0;
    it->line = 0;
    it->lineIndex = 0;
    it -> text = text;

    it->length = strlen(text);

    if (it->length > 0) {
        it->current = text[0];
    }

    return it;
}

/**
 * Destroy an iterator.
 * @param it  The iterator to destroy.
 */
void it_destroy(CharIterator *it) {
    free(it);
}


bool it_hasMore(CharIterator *it) {
    return it->index < it->length - 1;
}

char it_current(CharIterator *it) {
    return it->text[it->index];
}

bool it_hasCurrent(CharIterator *it) {
    return it->index <= it->length - 1;
}


void it_next(CharIterator *it) {
//    if (!it_hasMore(it)) {
//        return;
//    }

    if (it_current(it) == '\n') {
        it->line += 1;
        it->lineIndex = 0;
    } else {
        it->lineIndex += 1;
    }

    it->index += 1;

    if (it_current(it)) {
        it->current = it->text[it->index];
    }
}


bool it_is(CharIterator *it, char c) {
    return it_hasCurrent(it) && it_current(it) == c;
}


bool it_isIn(CharIterator* it, char* value) {
    return it_hasCurrent(it) && strchr(value, it_current(it)) != NULL;
}

bool it_isDigit(CharIterator *it) {
    return it_hasCurrent(it) && it_current(it) >= '0' && it_current(it) <= '9';
}


bool it_isLetter(CharIterator *it) {
    return it_hasCurrent(it) && (
            (it_current(it) >= 'a' && it_current(it) <= 'z') ||
            (it_current(it) >= 'A' && it_current(it) <= 'Z')
    );
}

bool it_isWhite(CharIterator* it) {
    return it_isIn(it, " \t\n\v\f\r");
}

bool it_isNumberChar(CharIterator* it) {
    return it_isDigit(it) || it_is(it, '\'');
}

Index it_getIndex(CharIterator* it) {
    Index index = {.index = it->index, .lineIndex = it->lineIndex, .line = it->line };
    return index;
}



#endif //AUTOSCRIPT_CHARITERATOR_H
