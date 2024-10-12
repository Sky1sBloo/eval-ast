#include <array>
#include <gtest/gtest.h>
#include <stdexcept>

#include "ParseTreeBuilder.hpp"

TEST (ParseTreeBuilderTest, BasicOperation)
{
    const std::string parseString = "1+5";
    ParseTreeBuilder builder(parseString);

    EXPECT_NO_THROW(builder.generateParseTree());
    EXPECT_NO_THROW(builder.runParseTree());
}

TEST (ParseTreeBuilderTest, WrongOperation)
{
    const std::array<std::string, 4> parseStrings = { "-+1", "1++", "123", "9++" };

    for (const std::string& parseStr : parseStrings)
    {
        ParseTreeBuilder builder(parseStr);
        EXPECT_THROW(builder.generateParseTree(), std::invalid_argument);
    }
}
