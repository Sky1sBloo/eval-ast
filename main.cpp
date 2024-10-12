#include "ParseTreeBuilder.hpp"

#include <iostream>


// TODO: Add argument handling
int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        std::cerr << "Arguments too few" << "\n" <<
            "Usage: eval-ast [equation]" << std::endl;
    }

    ParseTreeBuilder parseTreeBuilder("1+23.5*2");
    if (parseTreeBuilder.generateParseTree()) 
    {
        parseTreeBuilder.runParseTree();
    }
}
