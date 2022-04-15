/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/codesmithyide/doxygen/blob/main/LICENSE.txt
*/

#include "DoxygenXMLFunctionDocumentation.hpp"

using namespace CodeSmithy;

DoxygenXMLFunctionDocumentation::DoxygenXMLFunctionDocumentation(std::string name)
    : m_name(std::move(name))
{
}

const std::string& DoxygenXMLFunctionDocumentation::name() const
{
    return m_name;
}
