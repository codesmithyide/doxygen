/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/codesmithyide/doxygen/blob/main/LICENSE.txt
*/

#ifndef _CODESMITHY_DOXYGEN_CORE_DOXYGENXMLINDEX_HPP_
#define _CODESMITHY_DOXYGEN_CORE_DOXYGENXMLINDEX_HPP_

#include <boost/filesystem.hpp>
#include <string>
#include <vector>

namespace CodeSmithy
{

    class DoxygenXMLIndex
    {
    public:
        static DoxygenXMLIndex FromFile(const boost::filesystem::path& path);

        const std::vector<std::string>& classes() const;

    private:
        std::vector<std::string> m_classes;
    };

}

#endif
