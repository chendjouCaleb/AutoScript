//
// Created by HP on 20/03/2022.
//

#ifndef AUTOSCRIPT_REAL_H
#define AUTOSCRIPT_REAL_H

#include <malloc.h>

typedef struct Real {
    long i;
    long d;
} Real;

Real* create(long i, long d) {
    Real* p = malloc(sizeof(Real));
    p -> d = d;
    p -> i = i;

    return p;
}

void destroy(Real* r) {
    free(r);
}

char* to_str(Real* p) {
    char* value = malloc(sizeof(char) * 50);

}

#endif //AUTOSCRIPT_REAL_H
