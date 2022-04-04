//
// Created by HP on 28/03/2022.
//

#ifndef AUTOSCRIPT_OPERATION_H
#define AUTOSCRIPT_OPERATION_H


#include <stdbool.h>
#include <malloc.h>
#include <stdio.h>

typedef enum OperatorType { OPERATOR_ADD,
                            OPERATOR_MINUS,
                            OPERATOR_MUL,
                            OPERATOR_DIV,
                            OPERATOR_MODULO,
                            OPERATOR_NUMBER,
                            OPERATOR_OP
} OperatorType;
typedef struct Operations Operations ;

typedef struct Operation {
    int value;
    OperatorType type;
    char* operator;
    char* c_value;

    bool sub;
    Operations* operations;
} Operation;

struct Operations {
    Operation** operations;
    int length;

    int index;

};


int run_div(Operations* ops, int init);


Operation* op_create1() {
    Operation* operation = malloc(sizeof(Operation));
    return operation;
}

Operation* op_create(int value, OperatorType type) {
    Operation* operation = malloc(sizeof(Operation));
    operation->value = value;
    operation->type = type;
    return operation;
}



void op_destroy(Operation* op) {
    free(op);
}

Operations* ops_create() {
    Operations* ops = malloc(sizeof(Operations));
    ops->index = 0;
    ops->length = 0;
    ops->operations = malloc(sizeof(Operation*) * 100);

    return ops;
}

void ops_destroy(Operations* ops) {
    for (int i = 0; i < ops->length; ++i) {
        op_destroy(ops->operations[i]);
    }

    free(ops->operations);
    free(ops);
}

Operation* ops_current(Operations* op) {
    return op->operations[op->index];
}

bool ops_has(Operations* op) {
    return op -> index <= op->length - 1;
}

void ops_next(Operations* op) {
    op->index += 1;
}

void ops_addOperation(Operations* ops, int value, OperatorType type) {
    Operation* op = op_create(value, type);
    ops->operations[ops->length] = op;
    ops->length += 1;
}

void ops_add(Operations* ops, Operation* op) {
    ops->operations[ops->length] = op;
    ops->length += 1;
}

#endif //AUTOSCRIPT_OPERATION_H
