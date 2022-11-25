//==============================================================================
// Name        : RunningJournal.cpp
// Author      : Jorge
// Copyright   : https://creativecommons.org/licenses/by/4.0/
// Description : Main program of a running journal.
//==============================================================================

// Local includes.
#include "ProgramManager.h"

//==============================================================================
/* RunningJournal */
//==============================================================================

/*------------------------------------------------------------------------------
 * Main program
 */
using namespace runjour;

int main()
{
    // Run the services of the program.
    ProgramManager::getInstance().startUp();

    // Check if the program has started.
    if (ProgramManager::getInstance().isStarted())
    {
        ProgramManager::getInstance().run();
    }

    // Shut down the services of the program.
    ProgramManager::getInstance().shutDown();

    return EXIT_SUCCESS;
}

//==============================================================================
