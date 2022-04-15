/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/codesmithyide/doxygen/blob/main/LICENSE.txt
*/

#ifndef _CODESMITHY_DOXYGEN_CORE_TESTS_DOXYGENXMLCLASSDOCUMENTATIONTESTS_HPP_
#define _CODESMITHY_DOXYGEN_CORE_TESTS_DOXYGENXMLCLASSDOCUMENTATIONTESTS_HPP_

#include <Ishiko/TestFramework.hpp>

class DoxygenXMLClassDocumentationTests : public Ishiko::TestSequence
{
public:
    DoxygenXMLClassDocumentationTests(const Ishiko::TestNumber& number, const Ishiko::TestContext& context);

private:
    static void ConstructorTest1(Ishiko::Test& test);
    static void FromFileTest1(Ishiko::Test& test);
    static void FromFileTest2(Ishiko::Test& test);
};

#endif
