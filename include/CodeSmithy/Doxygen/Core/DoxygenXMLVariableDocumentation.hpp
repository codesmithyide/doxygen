/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/codesmithyide/doxygen/blob/main/LICENSE.txt
*/

#ifndef _CODESMITHY_DOXYGEN_CORE_DOXYGENXMLVARIABLEDOCUMENTATION_HPP_
#define _CODESMITHY_DOXYGEN_CORE_DOXYGENXMLVARIABLEDOCUMENTATION_HPP_

#include <string>

namespace CodeSmithy
{
    class DoxygenXMLVariableDocumentation
    {
    public:
        DoxygenXMLVariableDocumentation(std::string name);

        const std::string& name() const;

    private:
        std::string m_name;
    };
}

#endif
