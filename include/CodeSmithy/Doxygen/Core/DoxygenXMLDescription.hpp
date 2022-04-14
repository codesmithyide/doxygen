/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/codesmithyide/doxygen/blob/main/LICENSE.txt
*/

#ifndef _CODESMITHY_DOXYGEN_CORE_DOXYGENXMLDESCRIPTION_HPP_
#define _CODESMITHY_DOXYGEN_CORE_DOXYGENXMLDESCRIPTION_HPP_

#include <pugixml.hpp>

namespace CodeSmithy
{
    class DoxygenXMLDescription
    {
    public:
        DoxygenXMLDescription() = default;
        DoxygenXMLDescription(pugi::xml_node desciptionRoot);

    private:
        pugi::xml_document m_description;
    };
}

#endif
