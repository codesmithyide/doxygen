/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/codesmithyide/doxygen/blob/main/LICENSE.txt
*/

#include "DoxygenXMLGroupDocumentationTests.hpp"
#include "CodeSmithy/Doxygen/Core/DoxygenXMLGroupDocumentation.hpp"

using namespace CodeSmithy;
using namespace Ishiko;

DoxygenXMLGroupDocumentationTests::DoxygenXMLGroupDocumentationTests(const TestNumber& number,
    const TestContext& context)
    : TestSequence(number, "DoxygenXMLGroupDocumentation tests", context)
{
    append<HeapAllocationErrorsTest>("Constructor test 1", ConstructorTest1);
    append<HeapAllocationErrorsTest>("FromFile test 1", FromFileTest1);
}

void DoxygenXMLGroupDocumentationTests::ConstructorTest1(Test& test)
{
    DoxygenXMLGroupDocumentation groupDocumentation;

    ISHIKO_TEST_PASS();
}

void DoxygenXMLGroupDocumentationTests::FromFileTest1(Test& test)
{
    DoxygenXMLGroupDocumentation groupDocumentation =
        DoxygenXMLGroupDocumentation::FromFile(
            test.context().getTestDataPath("cpp/cpp-group-1/xml/group___shapes.xml"));

    const std::vector<DoxygenXMLGroupDocumentation::MemberInfo>& members = groupDocumentation.members();

    ISHIKO_TEST_FAIL_IF_NEQ(groupDocumentation.name(), "Shapes");
    ISHIKO_TEST_ABORT_IF_NEQ(members.size(), 2);
    ISHIKO_TEST_FAIL_IF_NEQ(members[0].name, "Polygon");
    ISHIKO_TEST_FAIL_IF_NEQ(members[0].refId, "class_polygon");
    ISHIKO_TEST_FAIL_IF_NEQ(members[1].name, "Rectangle");
    ISHIKO_TEST_FAIL_IF_NEQ(members[1].refId, "class_rectangle");
    ISHIKO_TEST_PASS();
}
