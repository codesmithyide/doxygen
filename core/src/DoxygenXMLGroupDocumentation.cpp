/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/codesmithyide/doxygen/blob/main/LICENSE.txt
*/

#include "DoxygenXMLGroupDocumentation.hpp"
#include <pugixml.hpp>

using namespace CodeSmithy;

DoxygenXMLGroupDocumentation::MemberInfo::MemberInfo(std::string name, std::string refId)
    : name(std::move(name)), refId(std::move(refId))
{
}

DoxygenXMLGroupDocumentation DoxygenXMLGroupDocumentation::FromFile(const boost::filesystem::path& path)
{
    DoxygenXMLGroupDocumentation groupDocumentation;

    pugi::xml_document document;
    pugi::xml_parse_result result = document.load_file(path.string().c_str());
    if (!result)
    {
        // TODO: should use an error specific to XML file opening created in the Ishiko::XML project
        throw std::exception();
    }

    // TODO: robustness
    pugi::xml_node doxygenNode = document.root().child("doxygen");
    pugi::xml_node groupNode = doxygenNode.child("compounddef");
    groupDocumentation.m_name = groupNode.child_value("compoundname");

    pugi::xml_node node = groupNode.first_child();
    while (node)
    {
        if (strncmp(node.name(), "innerclass", 11) == 0)
        {
            groupDocumentation.m_members.emplace_back(node.text().as_string(), node.attribute("refid").value());
        }
        node = node.next_sibling();
    }

    return groupDocumentation;
}

const std::string& DoxygenXMLGroupDocumentation::name() const
{
    return m_name;
}

const std::vector<DoxygenXMLGroupDocumentation::MemberInfo>& DoxygenXMLGroupDocumentation::members() const
{
    return m_members;
}
