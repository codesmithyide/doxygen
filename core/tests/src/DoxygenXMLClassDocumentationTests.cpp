/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/codesmithyide/doxygen/blob/main/LICENSE.txt
*/

#include "DoxygenXMLClassDocumentationTests.hpp"
#include "CodeSmithy/Doxygen/Core/DoxygenXMLClassDocumentation.hpp"

using namespace CodeSmithy;
using namespace Ishiko;

DoxygenXMLClassDocumentationTests::DoxygenXMLClassDocumentationTests(const TestNumber& number,
    const TestContext& context)
    : TestSequence(number, "DoxygenXMLClassDocumentation tests", context)
{
    append<HeapAllocationErrorsTest>("Constructor test 1", ConstructorTest1);
    append<HeapAllocationErrorsTest>("FromFile test 1", FromFileTest1);
    append<HeapAllocationErrorsTest>("FromFile test 2", FromFileTest2);
    append<HeapAllocationErrorsTest>("FromFile test 3", FromFileTest3);
    append<HeapAllocationErrorsTest>("FromFile test 4", FromFileTest4);
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
    ISHIKO_TEST_FAIL_IF_NEQ(classDocumentation.header(), "Polygon.h");
    ISHIKO_TEST_FAIL_IF_NEQ(classDocumentation.functions().size(), 0);
    ISHIKO_TEST_PASS();
}

void DoxygenXMLClassDocumentationTests::FromFileTest2(Test& test)
{
    DoxygenXMLClassDocumentation classDocumentation =
        DoxygenXMLClassDocumentation::FromFile(test.context().getTestDataPath("cpp/cpp-code-2/xml/class_polygon.xml"));
    const std::vector<DoxygenXMLFunctionDocumentation>& functions = classDocumentation.functions();

    ISHIKO_TEST_FAIL_IF_NEQ(classDocumentation.name(), "Polygon");
    ISHIKO_TEST_FAIL_IF_NEQ(classDocumentation.header(), "Polygon.h");
    ISHIKO_TEST_ABORT_IF_NEQ(functions.size(), 1);
    ISHIKO_TEST_FAIL_IF_NEQ(functions[0].name(), "draw");
    ISHIKO_TEST_PASS();
}

void DoxygenXMLClassDocumentationTests::FromFileTest3(Test& test)
{
    DoxygenXMLClassDocumentation classDocumentation =
        DoxygenXMLClassDocumentation::FromFile(test.context().getTestDataPath("cpp/cpp-code-3/xml/class_rectangle.xml"));
    const std::vector<DoxygenXMLInheritanceRelationship>& baseClasses = classDocumentation.baseClasses();
    const std::vector<DoxygenXMLFunctionDocumentation>& functions = classDocumentation.functions();

    ISHIKO_TEST_FAIL_IF_NEQ(classDocumentation.name(), "Rectangle");
    ISHIKO_TEST_FAIL_IF_NEQ(classDocumentation.header(), "Rectangle.h");

    ISHIKO_TEST_ABORT_IF_NEQ(baseClasses.size(), 1);
    ISHIKO_TEST_FAIL_IF_NEQ(baseClasses[0].baseClassName(), "Polygon");

    ISHIKO_TEST_ABORT_IF_NEQ(functions.size(), 5);
    ISHIKO_TEST_FAIL_IF_NEQ(functions[0].name(), "draw");
    ISHIKO_TEST_FAIL_IF_NEQ(functions[1].name(), "width");
    ISHIKO_TEST_FAIL_IF_NEQ(functions[2].name(), "height");
    ISHIKO_TEST_FAIL_IF_NEQ(functions[3].name(), "setWidth");
    ISHIKO_TEST_FAIL_IF_NEQ(functions[4].name(), "setHeight");

    ISHIKO_TEST_PASS();
}

void DoxygenXMLClassDocumentationTests::FromFileTest4(Test& test)
{
    DoxygenXMLClassDocumentation classDocumentation =
        DoxygenXMLClassDocumentation::FromFile(test.context().getTestDataPath("cpp/cpp-code-4/xml/class_canvas.xml"));
    const std::vector<DoxygenXMLVariableDocumentation>& variables = classDocumentation.variables();

    ISHIKO_TEST_FAIL_IF_NEQ(classDocumentation.name(), "Canvas");
    ISHIKO_TEST_FAIL_IF_NEQ(classDocumentation.header(), "Canvas.h");

    ISHIKO_TEST_ABORT_IF_NEQ(variables.size(), 1);
    ISHIKO_TEST_ABORT_IF_NEQ(variables[0].name(), "m_polygons");

    ISHIKO_TEST_PASS();
}
