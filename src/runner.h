//
// Created by HP on 02/04/2022.
//

#ifndef AUTOSCRIPT_RUNNER_H
#define AUTOSCRIPT_RUNNER_H

#include "operation.h"
#include <stdio.h>


int call_value(Operation* op, Operation* prev);
int call(Operation* op);
int op_order(char* op);
int call_operator(Operations* ops, int result, char* op);

int call_ops(Operations* ops) {
    int result = 0;
    if(ops_has(ops) && (ops_current(ops)->type == OPERATOR_NUMBER || ops_current(ops)->type == OPERATOR_SUB)) {
        result = call(ops_current(ops));
        ops_next(ops);
    }
//    if(ops_has(ops) && ops_current(ops)->type == OPERATOR_SUB) {
//        printf("\n\nCOUNT SUB OPS: %d!\n", ops_current(ops)->operations->length);
//        result = call_ops(ops_current(ops)->operations);
//    }
    while (ops_has(ops) && ops_current(ops) ->type == OPERATOR_OP) {
        result = call_operator(ops, result, ops_current(ops)->c_value);
    }

    return result;
}

int call_operator(Operations* ops, int current, char* op) {
    int result = 0;
    //Skip current operator.
    ops_next(ops);
    int value = call(ops_current(ops));
    ops_next(ops);
    //printf("OPERATOR: %s, VALUE=%d, More=%d\n", op, value, ops_has(ops));

    Operation* current_op = ops_current(ops);
    while(ops_has(ops) && current_op -> type == OPERATOR_OP && (op_order(current_op->c_value) > op_order(op))) {
        //printf("VALUE 0: %d, %s\n", value, current_op->c_value);
        value = call_operator(ops, value, current_op->c_value);
        current_op = ops_current(ops);
        //printf("VALUE 1: %d\n", value);
    }


    if(strcmp(op, "+") == 0 ) {
        result = current + value;
        //ops_next(ops);
    } else if(strcmp(op, "-") == 0 ) {
        result = current - value;
    } else if(strcmp(op, "*") == 0 ) {
        result = current * value;
        //ops_next(ops);
    } else if(strcmp(op, "/") == 0 ) {
        result = current / value;
    }

    return result;
}

int call_value(Operation* op, Operation* prev) {

}

int call(Operation* op) {
    if(op -> type == OPERATOR_NUMBER) {
        return toInt(op->c_value);
    }
    else if(op -> type == OPERATOR_SUB){
        return call_ops(op->operations);
    }
    return 0;
}

int op_order(char* op) {
    if(strcmp("+", op) == 0 || strcmp("-", op) == 0) {
        return 0;
    }

    if(strcmp("/", op) == 0 || strcmp("*", op) == 0) {
        return 1;
    }
    return 2;
}
#endif //AUTOSCRIPT_RUNNER_H
