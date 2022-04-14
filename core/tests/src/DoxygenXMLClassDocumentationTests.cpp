/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/codesmithyide/doxygen/blob/main/LICENSE.txt
*/

#include "DoxygenXMLClassDocumentationTests.hpp"
#include "CodeSmithy/Doxygen/Core/DoxygenXMLClassDocumentation.hpp"

using namespace CodeSmithy;
using namespace Ishiko;

DoxygenXMLClassDocumentationTests::DoxygenXMLClassDocumentationTests(const TestNumber& number, const TestContext& context)
    : TestSequence(number, "DoxygenXMLClassDocumentation tests", context)
{
    append<HeapAllocationErrorsTest>("Constructor test 1", ConstructorTest1);
}

void DoxygenXMLClassDocumentationTests::ConstructorTest1(Test& test)
{
    DoxygenXMLClassDocumentation classDocumentation;

    ISHIKO_TEST_PASS();
}
