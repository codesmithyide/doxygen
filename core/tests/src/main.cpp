/*
    Copyright (c) 2022-2023 Xavier Leclercq
    Released under the MIT License
    See https://github.com/codesmithyide/doxygen/blob/main/LICENSE.txt
*/

#include "DoxygenXMLClassDocumentationTests.hpp"
#include "DoxygenXMLDescriptionTests.hpp"
#include "DoxygenXMLGroupDocumentationTests.hpp"
#include "DoxygenXMLIndexTests.hpp"
#include "DoxygenXMLOutputTests.hpp"
#include "CodeSmithy/Doxygen/Core/linkoptions.hpp"
#include <Ishiko/TestFramework.hpp>

using namespace Ishiko;

int main(int argc, char* argv[])
{
    TestHarness theTestHarness("CodeSmithyDoxygenCore Library Tests");

    theTestHarness.context().setDataDirectory("${CODESMITHYIDE}/doxygen-test-data");

    TestSequence& theTests = theTestHarness.tests();
    theTests.append<DoxygenXMLIndexTests>();
    theTests.append<DoxygenXMLClassDocumentationTests>();
    theTests.append<DoxygenXMLGroupDocumentationTests>();
    theTests.append<DoxygenXMLDescriptionTests>();
    theTests.append<DoxygenXMLOutputTests>();

    return theTestHarness.run();
}
