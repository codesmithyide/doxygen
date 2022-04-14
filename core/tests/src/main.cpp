/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/codesmithyide/doxygen/blob/main/LICENSE.txt
*/

#include "DoxygenXMLOutputTests.hpp"
#include <Ishiko/TestFramework.hpp>

using namespace Ishiko;

int main(int argc, char* argv[])
{
    TestHarness theTestHarness("CodeSmithyDoxygenCore Library Tests");

    TestSequence& theTests = theTestHarness.tests();
    theTests.append<DoxygenXMLOutputTests>();

    return theTestHarness.run();
}
