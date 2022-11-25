//============================================================================
// Name        : RunningJournal.cpp
// Author      : Jorge
// Copyright   : https://creativecommons.org/licenses/by/4.0/
// Description : Main program of a running journal.
//============================================================================

// Includes.
#include <unistd.h>
#include <vector>
#include <iostream>
#include <chrono>
#include <thread>

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
    std::cout << __cplusplus << std::endl;
    if (__cplusplus > 201703L) std::cout << "C++20\n";
    else if (__cplusplus == 201703L) std::cout << "C++17\n";
    else if (__cplusplus == 201402L) std::cout << "C++14\n";
    else if (__cplusplus == 201103L) std::cout << "C++11\n";
    else if (__cplusplus == 199711L) std::cout << "C++98\n";
    else std::cout << "pre-standard C++\n";

    ProgramManager::getInstance().startUp();

    if (ProgramManager::getInstance().getStatus())
    {
        ProgramManager::getInstance().run();
    }

    ProgramManager::getInstance().shutDown();

    return 0;
}

//==============================================================================
