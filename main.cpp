#include "ParseTreeBuilder.hpp"

int main()
{
    std::string operation("1+11");
    ParseTreeBuilder parseTreeBuilder(operation);
    parseTreeBuilder.generateParseTree();
}
