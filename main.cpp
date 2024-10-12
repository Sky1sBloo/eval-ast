#include "ParseTreeBuilder.hpp"

#include <iostream>
#include <stdexcept>


// TODO: Add argument handling
int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        std::cerr << "Arguments too few" << "\n" <<
            "Usage: eval-ast [equation]" << std::endl;

        return 1;
    }

    std::string parseString;
    for (int i = 1; i < argc; i++)
    {
        parseString.append(argv[i]);
    }

    ParseTreeBuilder parseTreeBuilder(parseString);
    try {
        parseTreeBuilder.generateParseTree();
        parseTreeBuilder.runParseTree();
    } catch (const std::invalid_argument& ex) {
        std::cerr << ex.what() << std::endl;
        return 1;
    }

    return 0;
}
