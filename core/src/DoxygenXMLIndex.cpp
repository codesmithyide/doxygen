/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/codesmithyide/doxygen/blob/main/LICENSE.txt
*/

#include "DoxygenXMLIndex.hpp"
#include <pugixml.hpp>
#include <exception>

using namespace CodeSmithy;

DoxygenXMLIndex::ClassInfo::ClassInfo(std::string name, std::string refId)
    : name(std::move(name)), refId(std::move(refId))
{
}

DoxygenXMLIndex::GroupInfo::GroupInfo(std::string name, std::string refId)
    : name(std::move(name)), refId(std::move(refId))
{
}

DoxygenXMLIndex DoxygenXMLIndex::FromFile(const boost::filesystem::path& path)
{
    DoxygenXMLIndex index;

    pugi::xml_document document;
    pugi::xml_parse_result result = document.load_file(path.string().c_str());
    if (!result)
    {
        // TODO: should use an error specific to XML file opening created in the Ishiko::XML project
        throw std::exception();
    }

    pugi::xml_node indexNode = document.root().child("doxygenindex");

    pugi::xml_node compoundNode = indexNode.first_child();
    while (compoundNode)
    {
        // TODO: handle not exist
        pugi::xml_attribute kindAttribute = compoundNode.attribute("kind");
        if (strncmp(kindAttribute.value(), "class", 5) == 0)
        {
            // TODO: robustness
            index.m_classes.emplace_back(compoundNode.child_value("name"), compoundNode.attribute("refid").value());
        }
        else if (strncmp(kindAttribute.value(), "group", 5) == 0)
        {
            // TODO: robustness
            index.m_groups.emplace_back(compoundNode.child_value("name"), compoundNode.attribute("refid").value());
        }
        compoundNode = compoundNode.next_sibling();
    }

    return index;
}

const std::vector<DoxygenXMLIndex::ClassInfo>& DoxygenXMLIndex::classes() const
{
    return m_classes;
}

const std::vector<DoxygenXMLIndex::GroupInfo>& DoxygenXMLIndex::groups() const
{
    return m_groups;
}
