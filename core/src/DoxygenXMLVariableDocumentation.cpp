/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/codesmithyide/doxygen/blob/main/LICENSE.txt
*/

#include "DoxygenXMLVariableDocumentation.hpp"

using namespace CodeSmithy;

DoxygenXMLVariableDocumentation::DoxygenXMLVariableDocumentation(std::string name)
    : m_name(std::move(name))
{
}

const std::string& DoxygenXMLVariableDocumentation::name() const
{
    return m_name;
}
