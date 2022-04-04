//
// Created by HP on 26/03/2022.
//

#ifndef AUTOSCRIPT_FUNCTION_H
#define AUTOSCRIPT_FUNCTION_H

#include "type.h"

typedef struct FunctionParam {
    Type* type;
    char* name;
} FunctionParam;


typedef struct Function {
    char* name;
    Type* returnType;
    FunctionParam** params;
} Function;

#endif //AUTOSCRIPT_FUNCTION_H
