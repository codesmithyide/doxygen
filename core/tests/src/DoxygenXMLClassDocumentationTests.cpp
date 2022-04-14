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
    append<HeapAllocationErrorsTest>("FromFile test 1", FromFileTest1);
}

void DoxygenXMLClassDocumentationTests::ConstructorTest1(Test& test)
{
    DoxygenXMLClassDocumentation classDocumentation;

    ISHIKO_TEST_PASS();
}

void DoxygenXMLClassDocumentationTests::FromFileTest1(Test& test)
{
    DoxygenXMLClassDocumentation classDocumentation =
        DoxygenXMLClassDocumentation::FromFile(test.context().getTestDataPath("cpp/cpp-code-1/xml/class_polygon.xml"));

    ISHIKO_TEST_FAIL_IF_NEQ(classDocumentation.name(), "Polygon");
    ISHIKO_TEST_PASS();
}
