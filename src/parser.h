//
// Created by HP on 02/04/2022.
//

#ifndef AUTOSCRIPT_PARSER_H
#define AUTOSCRIPT_PARSER_H
#include <malloc.h>
#include <string.h>
#include <stdio.h>
#include "token.h"
#include "tokenList.h"
#include "tokenIterator.h"
#include "operation.h"

typedef struct Parser Parser;

struct Parser {
    TokenList* tokens;
    TokenIterator* it;
};

Parser* parser_create(TokenList* tokens) {
    Parser* parser = malloc(sizeof(Parser));
    parser->tokens = tokens;
    parser->it = tkIt_create(tokens->tokens, tokens->length);
}


Operations* parser_build(Parser* parser) {
    Operations* operations = ops_create();
    TokenIterator* it = parser->it;

    //printf("L=%d; I=%d\n", parser->it->index, it->length);

    while (tkIt_has(it) && tkIt_current(it)->type != TOKEN_PARENTHESIS_CLOSE) {
        Token* token = tkIt_current(it);
        //printf("T=%s; ", tkIt_current(it)->text );
        Operation* op = op_create1();

        if(token->type == TOKEN_NUMBER) {
            op->value = toInt(token->text);
            op -> c_value = token->text;
            op->type = OPERATOR_NUMBER;
        } else if(token -> type == TOKEN_MATH_OPERATOR) {
            op -> operator = token->text;
            op -> c_value = token->text;
            op -> type = OPERATOR_OP;
        } else if (token->type == TOKEN_PARENTHESIS_OPEN) {
            tkIt_next(it);
            op -> operator = "(";
            op -> c_value = "(";
            op -> type = OPERATOR_SUB;
            op -> operations = parser_build(parser);
        }
        //printf("\n");
        ops_add(operations, op);
        tkIt_next(it);
    }

//    if(tkIt_has(it) && tkIt_current(it)->type == TOKEN_PARENTHESIS_CLOSE) {
//        printf("Close parenthesis\n");
//        tkIt_next(it);
//    }


    //printf("\nParser finished: Length=%d!\n", operations->length);

    return operations;
}

void parser_destroy(Parser* parser) {
    tkIt_destroy(parser->it);
    free(parser);
}

#endif //AUTOSCRIPT_PARSER_H
