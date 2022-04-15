/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/codesmithyide/doxygen/blob/main/LICENSE.txt
*/

#ifndef _CODESMITHY_DOXYGEN_CORE_DOXYGENXMLCLASSDOCUMENTATION_HPP_
#define _CODESMITHY_DOXYGEN_CORE_DOXYGENXMLCLASSDOCUMENTATION_HPP_

#include "DoxygenXMLDescription.hpp"
#include "DoxygenXMLFunctionDocumentation.hpp"
#include "DoxygenXMLInheritanceRelationship.hpp"
#include "DoxygenXMLVariableDocumentation.hpp"
#include <boost/filesystem.hpp>
#include <string>
#include <vector>

namespace CodeSmithy
{
    class DoxygenXMLClassDocumentation
    {
    public:
        static DoxygenXMLClassDocumentation FromFile(const boost::filesystem::path& path);

        const std::string& name() const;
        const std::string& header() const;
        const DoxygenXMLDescription& briefDescription() const;
        const std::vector<DoxygenXMLInheritanceRelationship>& baseClasses() const;
        const std::vector<DoxygenXMLFunctionDocumentation>& functions() const;
        const std::vector<DoxygenXMLVariableDocumentation>& variables() const;

    private:
        std::string m_name;
        std::string m_header;
        DoxygenXMLDescription m_briefDescription;
        std::vector<DoxygenXMLInheritanceRelationship> m_baseClasses;
        std::vector<DoxygenXMLFunctionDocumentation> m_functions;
        std::vector<DoxygenXMLVariableDocumentation> m_variables;
    };
}

#endif
