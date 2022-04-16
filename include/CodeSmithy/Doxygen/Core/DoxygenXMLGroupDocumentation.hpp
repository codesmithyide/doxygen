/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/codesmithyide/doxygen/blob/main/LICENSE.txt
*/

#ifndef _CODESMITHY_DOXYGEN_CORE_DOXYGENXMLGROUPDOCUMENTATION_HPP_
#define _CODESMITHY_DOXYGEN_CORE_DOXYGENXMLGROUPDOCUMENTATION_HPP_

#include <boost/filesystem.hpp>
#include <string>

namespace CodeSmithy
{
    class DoxygenXMLGroupDocumentation
    {
    public:
        struct MemberInfo
        {
            MemberInfo(std::string name, std::string refId);

            std::string name;
            std::string refId;
        };

        static DoxygenXMLGroupDocumentation FromFile(const boost::filesystem::path& path);

        const std::string& name() const;
        const std::vector<MemberInfo>& members() const;

    private:
        std::string m_name;
        std::vector<MemberInfo> m_members;
    };
}

#endif
