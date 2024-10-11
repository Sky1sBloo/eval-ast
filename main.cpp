#include "ParseTreeBuilder.hpp"

int main(int argc, char* argv[])
{
    ParseTreeBuilder parseTreeBuilder(argv[argc - 1]);
    parseTreeBuilder.generateParseTree(); 
}
