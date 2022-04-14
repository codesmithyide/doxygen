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
        struct ClassInfo
        {
            ClassInfo(std::string name, std::string refId);

            std::string name;
            std::string refId;
        };

        static DoxygenXMLIndex FromFile(const boost::filesystem::path& path);

        const std::vector<ClassInfo>& classes() const;

    private:
        std::vector<ClassInfo> m_classes;
    };

}

#endif
