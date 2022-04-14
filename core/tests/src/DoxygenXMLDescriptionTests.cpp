/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/codesmithyide/doxygen/blob/main/LICENSE.txt
*/

#include "DoxygenXMLDescriptionTests.hpp"
#include "CodeSmithy/Doxygen/Core/DoxygenXMLDescription.hpp"

using namespace CodeSmithy;
using namespace Ishiko;

DoxygenXMLDescriptionTests::DoxygenXMLDescriptionTests(const TestNumber& number, const TestContext& context)
    : TestSequence(number, "DoxygenXMLDescription tests", context)
{
    append<HeapAllocationErrorsTest>("Constructor test 1", ConstructorTest1);
}

void DoxygenXMLDescriptionTests::ConstructorTest1(Test& test)
{
    DoxygenXMLDescription description;

    ISHIKO_TEST_PASS();
}
