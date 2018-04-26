#include <stdio.h>

#include <sapi/sys.hpp>
#include "num_test.h"

u32 decode_cli(const Cli & cli, u32 & execute_flags);
void show_usage(const Cli & cli);

int main(int argc, char * argv[]){
    Cli cli(argc, argv);
    cli.set_publisher("Stratify Labs, Inc");
    cli.handle_version();
    u32 o_flags;
    u32 o_execute_flags;

    o_flags = decode_cli(cli, o_execute_flags);

    if( o_flags == 0 ){
       show_usage(cli);
       exit(0);
    }

    return num_test_execute(o_flags, o_execute_flags);
}

u32 decode_cli(const Cli & cli, u32 & execute_flags){
    u32 o_flags = 0;

    execute_flags = 0;

    if(cli.is_option("-all") ){
        o_flags = 0xffffffff;
        execute_flags |= EXECUTE_ALL_TEST_FLAG;
        return o_flags;
    }
    if(cli.is_option("-execute_all")){ execute_flags |= EXECUTE_ALL_TEST_FLAG; }
    if(cli.is_option("-comp") ){ execute_flags |= COMPARISON_TEST_FLAG; }
    if(cli.is_option("-arithm") ){ execute_flags |= ARITHMETIC_TEST_FLAG; }
    if(cli.is_option("-logic") ){ execute_flags |= LOGICAL_TEST_FLAG; }
    if(cli.is_option("-shift") ){ execute_flags |= SHIFT_TEST_FLAG; }
    if(cli.is_option("-typecast") ){ execute_flags |= TYPE_CAST_TEST_FLAG; }

    if(cli.is_option("-test_all") ){ o_flags = 0xffffffff; }
    if(cli.is_option("-u8") ){ o_flags |= U8_TEST_FLAG; }
    if(cli.is_option("-u16") ){ o_flags |= U16_TEST_FLAG; }
    if(cli.is_option("-u32") ){ o_flags |= U32_TEST_FLAG; }
    if(cli.is_option("-u64") ){ o_flags |= U64_TEST_FLAG; }
    if(cli.is_option("-i8") ){ o_flags |= I8_TEST_FLAG; }
    if(cli.is_option("-s16") )  { o_flags |= S16_TEST_FLAG; }
    if(cli.is_option("-s32") ) { o_flags |= S32_TEST_FLAG; }
    if(cli.is_option("-s64") ){ o_flags |= S64_TEST_FLAG; }
    if(cli.is_option("-float") ){ o_flags |= FLOAT_TEST_FLAG; }
    if(cli.is_option("-double") ){ o_flags |= DOUBLE_TEST_FLAG; }
    if(cli.is_option("-int") ){ o_flags |= INT_TEST_FLAG; }

    return o_flags;

}

void show_usage(const Cli & cli){
    printf("\n");
    printf("usage: %s\n", cli.name());
    printf("    -all            execute all test for all data type.\n");
//test type
    printf("    -execute_all    execute all type of test.\n");
    printf("    -comp           comparison operations : =,!=,>=,<=,>,<.\n");
    printf("    -arithm         arithmetic : +,-,/,*,%%.\n");
    printf("    -logic          logical: |,&,~,^.\n");
    printf("    -shift          shift operation: >>,<<.\n");
    printf("    -typecast       type cast operation (type)(value)\n");
//data type
    printf("    -test_all       execute test for all data type.\n");
    printf("    -u8             execute test for u8.\n");
    printf("    -u16            execute test for u16.\n");
    printf("    -u32            execute test for u32.\n");
    printf("    -u64            execute test for u64.\n");
    printf("    -i8             execute test for i8.\n");
    printf("    -s16            execute test for s16.\n");
    printf("    -s32            execute test for s32.\n");
    printf("    -s64            execute test for s64.\n");
    printf("    -float          execute test for float.\n");
    printf("    -double         execute test for double.\n");
    printf("    -int            execute test for int.\n");
}
