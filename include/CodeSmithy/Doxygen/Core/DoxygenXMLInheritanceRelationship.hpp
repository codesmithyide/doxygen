/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/codesmithyide/doxygen/blob/main/LICENSE.txt
*/

#ifndef _CODESMITHY_DOXYGEN_CORE_DOXYGENXMLINHERITANCERELATIONHSIP_HPP_
#define _CODESMITHY_DOXYGEN_CORE_DOXYGENXMLINHERITANCERELATIONHSIP_HPP_

#include <string>

namespace CodeSmithy
{
    class DoxygenXMLInheritanceRelationship
    {
    public:
        DoxygenXMLInheritanceRelationship(std::string baseClassName);

        const std::string& baseClassName() const;

    private:
        std::string m_baseClassName;
    };
}

#endif
