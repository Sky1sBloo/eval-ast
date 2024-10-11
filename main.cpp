#include "ParseTreeBuilder.hpp"

// TODO: Add argument handling
int main(int argc, char* argv[])
{
    ParseTreeBuilder parseTreeBuilder("1+23.5*2");
    if (parseTreeBuilder.generateParseTree()) 
    {
        parseTreeBuilder.runParseTree();
    }
}
