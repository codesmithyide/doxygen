/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/codesmithyide/doxygen/blob/main/LICENSE.txt
*/

#include "DoxygenXMLOutputTests.hpp"

using namespace Ishiko;

DoxygenXMLOutputTests::DoxygenXMLOutputTests(const TestNumber& number, const TestContext& context)
    : TestSequence(number, "DoxygenXMLOutput tests", context)
{
    append<HeapAllocationErrorsTest>("Constructor test 1", ConstructorTest1);
}

void DoxygenXMLOutputTests::ConstructorTest1(Test& test)
{
}
