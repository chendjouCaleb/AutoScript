//
// Created by HP on 28/03/2022.
//

#ifndef AUTOSCRIPT_UTILITY_H
#define AUTOSCRIPT_UTILITY_H

#include <malloc.h>

char* toString(char c) {
    char* value = malloc(sizeof(char) * 2);
    value[0] = c;
    value[1] = '\0';

    return value;
}

#endif //AUTOSCRIPT_UTILITY_H
