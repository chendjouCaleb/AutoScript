//
// Created by HP on 21/03/2022.
//

#ifndef AUTOSCRIPT_NUMBER_H
#define AUTOSCRIPT_NUMBER_H

#include <stdio.h>
#include "CharIterator.h"
#include "string.h"

int get_intPart(CharIterator *it);

double get_decimalPart(CharIterator *it);

int char_to_int(char c) {
    return c - '0';
}

int toInt(char *text) {
    if (text == NULL || strlen(text) == 0) {
        return 0;
    }

    CharIterator *it = it_create(text);

    int value = get_intPart(it);

    it_destroy(it);

    return value;
}

double toDouble(char *text) {
    if (text == NULL || strlen(text) == 0) {
        return 0;
    }

    CharIterator *it = it_create(text);
    double value = get_intPart(it);

    if (it_is(it, '.')) {
        value += get_decimalPart(it);
    }

    it_destroy(it);

    return value;
}


int get_intPart(CharIterator *it) {
    int value = 0;
    while (it_isNumberChar(it)) {
        if (it_isDigit(it)) {
            value = value * 10 + (it_current(it) - '0');
            it_next(it);
        } else {
            it_next(it);
        }
    }
    return value;
}

double get_decimalPart(CharIterator *it) {
    double decimal = 0;
    double j = 1;
    if (it_is(it, '.')) {
        it_next(it);
    }
    while (it_isNumberChar(it)) {
        if (it_isDigit(it)) {
            decimal = decimal * 10 + (it_current(it) - '0');
            j = j * 10;
        }
        it_next(it);
    }

    return decimal / j;
}

#endif //AUTOSCRIPT_NUMBER_H
