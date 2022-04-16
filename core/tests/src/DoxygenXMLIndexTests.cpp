/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/codesmithyide/doxygen/blob/main/LICENSE.txt
*/

#include "DoxygenXMLIndexTests.hpp"
#include "CodeSmithy/Doxygen/Core/DoxygenXMLIndex.hpp"
#include <boost/filesystem.hpp>

using namespace CodeSmithy;
using namespace Ishiko;

DoxygenXMLIndexTests::DoxygenXMLIndexTests(const TestNumber& number, const TestContext& context)
    : TestSequence(number, "DoxygenXMLIndex tests", context)
{
    append<HeapAllocationErrorsTest>("Constructor test 1", ConstructorTest1);
    append<HeapAllocationErrorsTest>("FromFile test 1", FromFileTest1);
    append<HeapAllocationErrorsTest>("FromFile test 2", FromFileTest2);
}

void DoxygenXMLIndexTests::ConstructorTest1(Test& test)
{
    DoxygenXMLIndex index;

    ISHIKO_TEST_PASS();
}

void DoxygenXMLIndexTests::FromFileTest1(Test& test)
{
    DoxygenXMLIndex index = DoxygenXMLIndex::FromFile(test.context().getTestDataPath("cpp/cpp-code-1/xml/index.xml"));

    const std::vector<DoxygenXMLIndex::ClassInfo>& classes = index.classes();

    ISHIKO_TEST_ABORT_IF_NEQ(classes.size(), 1);
    ISHIKO_TEST_FAIL_IF_NEQ(classes[0].name, "Polygon");
    ISHIKO_TEST_FAIL_IF_NEQ(classes[0].refId, "class_polygon");
    ISHIKO_TEST_PASS();
}

void DoxygenXMLIndexTests::FromFileTest2(Test& test)
{
    DoxygenXMLIndex index = DoxygenXMLIndex::FromFile(test.context().getTestDataPath("cpp/cpp-group-1/xml/index.xml"));

    const std::vector<DoxygenXMLIndex::GroupInfo>& groups = index.groups();

    ISHIKO_TEST_ABORT_IF_NEQ(groups.size(), 1);
    ISHIKO_TEST_FAIL_IF_NEQ(groups[0].name, "Shapes");
    ISHIKO_TEST_FAIL_IF_NEQ(groups[0].refId, "group___shapes");
    ISHIKO_TEST_PASS();
}
