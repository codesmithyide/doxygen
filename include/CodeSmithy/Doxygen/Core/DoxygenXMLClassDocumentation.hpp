/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/codesmithyide/doxygen/blob/main/LICENSE.txt
*/

#ifndef _CODESMITHY_DOXYGEN_CORE_DOXYGENXMLCLASSDOCUMENTATION_HPP_
#define _CODESMITHY_DOXYGEN_CORE_DOXYGENXMLCLASSDOCUMENTATION_HPP_

#include <boost/filesystem.hpp>
#include <string>

namespace CodeSmithy
{
    class DoxygenXMLClassDocumentation
    {
    public:
        static DoxygenXMLClassDocumentation FromFile(const boost::filesystem::path& path);

        const std::string& name() const;
        const std::string& briefDescription() const;

    private:
        std::string m_name;
        std::string m_briefDescription;
    };
}

#endif
