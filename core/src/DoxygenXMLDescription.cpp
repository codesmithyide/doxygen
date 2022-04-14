/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/codesmithyide/doxygen/blob/main/LICENSE.txt
*/

#include "DoxygenXMLDescription.hpp"

using namespace CodeSmithy;

DoxygenXMLDescription::DoxygenXMLDescription(pugi::xml_node desciptionRoot)
{
    m_description.append_copy(desciptionRoot);
}
