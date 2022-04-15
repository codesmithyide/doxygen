/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/codesmithyide/doxygen/blob/main/LICENSE.txt
*/

#include "DoxygenXMLInheritanceRelationship.hpp"

using namespace CodeSmithy;

DoxygenXMLInheritanceRelationship::DoxygenXMLInheritanceRelationship(std::string baseClassName)
    : m_baseClassName(std::move(baseClassName))
{
}

const std::string& DoxygenXMLInheritanceRelationship::baseClassName() const
{
    return m_baseClassName;
}
