#include <stdio.h>
#include "src/CharIterator.h"
#include "src/number.h"
#include "src/tokenList.h"
#include "src/utility.h"
#include "src/tokenizer.h"
#include "src/operation.h"
#include "src/parser.h"
#include "src/runner.h"

int main() {

//    for (int i = 0; i < tokens->length; ++i) {
//        printf("%d => %s\n", i, tl_get(tokens, i)->text);
//    }





    Operations* operations = ops_create();

    ops_addOperation(operations, 10, OPERATOR_ADD);
    ops_addOperation(operations, 10, OPERATOR_ADD);

    ops_addOperation(operations, 10, OPERATOR_MINUS);
    ops_addOperation(operations, 10, OPERATOR_MINUS);

    ops_addOperation(operations, 10, OPERATOR_ADD);

    ops_addOperation(operations, 10, OPERATOR_ADD);
    ops_addOperation(operations, 2, OPERATOR_DIV);
    ops_addOperation(operations, 3, OPERATOR_MUL);

    int result = ops_run(operations);
    printf("Result = %d.\n", result);


    char* value = "2*2*2*2+4";

    Tokenizer* tokenizer = tk_create(value);
    tk_tokenizer(tokenizer);

    TokenList* tokens = tokenizer->tokenList;
    Parser* parser = parser_create(tokens);

    Operations* _ops = parser_build(parser);

//    for (int i = 0; i < _ops->length; ++i) {
//        Operation* op = _ops->operations[i];
//
//        printf("%d => %s\n", i, op->c_value);
//    }

    printf("Length: %d\n", tokens->length);
    printf("%s=%d", value, call_ops(_ops));


    ops_destroy(operations);
    tk_destroy(tokenizer);
    parser_destroy(parser);


    return 0;
}
