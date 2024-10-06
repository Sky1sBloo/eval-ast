#pragma once

#include <string>

class ParseTreeBuilder
{
  public:
    ParseTreeBuilder(const std::string &parseString);
    void generateParseTree();

  private:
    std::string mParseString;
};
