/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/codesmithyide/doxygen/blob/main/LICENSE.txt
*/

#include "DoxygenXMLClassDocumentation.hpp"
#include <pugixml.hpp>

using namespace CodeSmithy;

DoxygenXMLClassDocumentation DoxygenXMLClassDocumentation::FromFile(const boost::filesystem::path& path)
{
    DoxygenXMLClassDocumentation classDocumentation;

    pugi::xml_document document;
    pugi::xml_parse_result result = document.load_file(path.string().c_str());
    if (!result)
    {
        // TODO: should use an error specific to XML file opening created in the Ishiko::XML project
        throw std::exception();
    }

    // TODO: robustness
    pugi::xml_node doxygenNode = document.root().child("doxygen");
    pugi::xml_node classNode = doxygenNode.child("compounddef");
    classDocumentation.m_id = classNode.attribute("id").value();
    classDocumentation.m_name = classNode.child_value("compoundname");
    classDocumentation.m_header = classNode.child_value("includes");
    classDocumentation.m_briefDescription = DoxygenXMLDescription(classNode.child("briefdescription"));

    pugi::xml_node node = classNode.first_child();
    while (node)
    {
        if (strncmp(node.name(), "basecompoundref", 16) == 0)
        {
            classDocumentation.m_baseClasses.emplace_back(node.text().as_string());
        }
        else if (strncmp(node.name(), "sectiondef", 11) == 0)
        {
            // TODO robustness
            if (strncmp(node.attribute("kind").value(), "public-func", 12) == 0)
            {
                pugi::xml_node memberNode = node.first_child();
                while (memberNode)
                {
                    if (strncmp(memberNode.name(), "memberdef", 10) == 0)
                    {
                        classDocumentation.m_functions.emplace_back(memberNode.child_value("name"));
                    }
                    memberNode = memberNode.next_sibling();
                }
            }
            else if (strncmp(node.attribute("kind").value(), "private-attrib", 15) == 0)
            {
                pugi::xml_node memberNode = node.first_child();
                while (memberNode)
                {
                    if (strncmp(memberNode.name(), "memberdef", 10) == 0)
                    {
                        classDocumentation.m_variables.emplace_back(memberNode.child_value("name"));
                    }
                    memberNode = memberNode.next_sibling();
                }
            }
        }

        node = node.next_sibling();
    }

    return classDocumentation;
}

const std::string& DoxygenXMLClassDocumentation::id() const
{
    return m_id;
}

const std::string& DoxygenXMLClassDocumentation::name() const
{
    return m_name;
}

const std::string& DoxygenXMLClassDocumentation::header() const
{
    return m_header;
}

const DoxygenXMLDescription& DoxygenXMLClassDocumentation::briefDescription() const
{
    return m_briefDescription;
}

const std::vector<DoxygenXMLInheritanceRelationship>& DoxygenXMLClassDocumentation::baseClasses() const
{
    return m_baseClasses;
}

const std::vector<DoxygenXMLFunctionDocumentation>& DoxygenXMLClassDocumentation::functions() const
{
    return m_functions;
}

const std::vector<DoxygenXMLVariableDocumentation>& DoxygenXMLClassDocumentation::variables() const
{
    return m_variables;
}
