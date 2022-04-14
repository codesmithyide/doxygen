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
    classDocumentation.m_name = classNode.child_value("compoundname");
    classDocumentation.m_header = classNode.child_value("includes");
    classDocumentation.m_briefDescription = DoxygenXMLDescription(classNode.child("briefdescription"));

    return classDocumentation;
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
