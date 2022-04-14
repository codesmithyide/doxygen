/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/codesmithyide/doxygen/blob/main/LICENSE.txt
*/

#include "DoxygenXMLIndexTests.hpp"
#include "CodeSmithy/Doxygen/Core/DoxygenXMLIndex.hpp"

using namespace CodeSmithy;
using namespace Ishiko;

DoxygenXMLIndexTests::DoxygenXMLIndexTests(const TestNumber& number, const TestContext& context)
    : TestSequence(number, "DoxygenXMLIndex tests", context)
{
    append<HeapAllocationErrorsTest>("Constructor test 1", ConstructorTest1);
}

void DoxygenXMLIndexTests::ConstructorTest1(Test& test)
{
    DoxygenXMLIndex index;

    ISHIKO_TEST_PASS();
}
