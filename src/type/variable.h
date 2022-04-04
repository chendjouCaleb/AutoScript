//
// Created by HP on 26/03/2022.
//

#ifndef AUTOSCRIPT_VARIABLE_H
#define AUTOSCRIPT_VARIABLE_H

#include <stdbool.h>
#include "type.h"

typedef struct Var {
    char* name;
    Type* declarationType;
    Type* currentType;
    bool isReadOnly;
    void* value;

} Var;

#endif //AUTOSCRIPT_VARIABLE_H
