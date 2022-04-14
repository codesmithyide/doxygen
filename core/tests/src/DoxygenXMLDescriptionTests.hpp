/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/codesmithyide/doxygen/blob/main/LICENSE.txt
*/

#ifndef _CODESMITHY_DOXYGEN_CORE_TESTS_DOXYGENXMLDESCRIPTIONTESTS_HPP_
#define _CODESMITHY_DOXYGEN_CORE_TESTS_DOXYGENXMLDESCRIPTIONTESTS_HPP_

#include <Ishiko/TestFramework.hpp>

class DoxygenXMLDescriptionTests : public Ishiko::TestSequence
{
public:
    DoxygenXMLDescriptionTests(const Ishiko::TestNumber& number, const Ishiko::TestContext& context);

private:
    static void ConstructorTest1(Ishiko::Test& test);
};

#endif
