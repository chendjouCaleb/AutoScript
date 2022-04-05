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

    char* value = "(2*2*2*2+4+(1+(2+(2)))+(10)+((3*3)))";
    //char* value = "(((1+1)+1)*2)";
    //char* value = "11";

    Tokenizer* tokenizer = tk_create(value);
    tk_tokenizer(tokenizer);

    TokenList* tokens = tokenizer->tokenList;
    Parser* parser = parser_create(tokens);

    Operations* _ops = parser_build(parser);

//    printf("Parser finished: Length=%d!\n", _ops->length);
//    for (int i = 0; i < _ops->length; ++i) {
//        Operation* op = _ops->operations[i];
//
//        printf("%d => %s\n", i, op->c_value);
//    }
//    printf("\nFinish.");
//
//    printf("Length: %d\n", tokens->length);
    printf("%s=%d", value, call_ops(_ops));


    tk_destroy(tokenizer);
    parser_destroy(parser);


    return 0;
}
