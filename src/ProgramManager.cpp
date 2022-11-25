//==============================================================================
// Name        : ProgramManager.cpp
// Author      : Jorge
// Copyright   : https://creativecommons.org/licenses/by/4.0/
// Description : Manager of the program loop.
//==============================================================================

// System includes
#include <iostream>
#include <unistd.h>

// Local includes
#include "ProgramManager.h"
#include "LogManager.h"
#include "Journal.h"
#include "Activity.h"
#include "Run.h"

//==============================================================================
/* Manager */
//==============================================================================

namespace runjour
{
    /*--------------------------------------------------------------------------
     * Default constructor.
     */
    ProgramManager::ProgramManager()
    {
        Manager::setType("ProgramManager");
    }

    /*--------------------------------------------------------------------------
     * Get the singleton instance of the ProgramManager.
     */
    ProgramManager &ProgramManager::getInstance()
    {
        static ProgramManager instance;
        return instance;
    }

    /*--------------------------------------------------------------------------
     * Start up the ProgramManager services.
     */
    void ProgramManager::startUp()
    {
        LogManager::getInstance().startUp();
        LogManager::getInstance().writeLog(E_LEVEL::DEBUG, "Starting services...");
        started = LogManager::getInstance().isStarted();
        finalize = false;

        // Dump into the logs the C++ used.
        std::string version{"C++ version: " + std::to_string(__cplusplus) + " "};
        if (__cplusplus > 201703L)
            version += "C++20";
        else if (__cplusplus == 201703L)
            version += "C++17";
        else if (__cplusplus == 201402L)
            version += "C++14";
        else if (__cplusplus == 201103L)
            version += "C++11";
        else if (__cplusplus == 199711L)
            version += "C++98";
        else
            version += "pre-standard C++";

        LogManager::getInstance().writeLog(E_LEVEL::DEBUG, version);
    }

    /*--------------------------------------------------------------------------
     * Shut down the ProgramManager services.
     */
    void ProgramManager::shutDown()
    {
        finalize = true;
        LogManager::getInstance().writeLog(E_LEVEL::DEBUG, "Close program");
        LogManager::getInstance().shutDown();
    }

    /*--------------------------------------------------------------------------
     * Run program loop.
     */
    void ProgramManager::run()
    {
        LogManager::getInstance().writeLog(E_LEVEL::DEBUG, "Starting program...");

        // Welcome message
        std::cout << "Welcome to your Running Journal" << std::endl;
        std::cout << "Today is: " << std::endl;

        auto generalMenu = []()
        {
            std::cout << "----------------------------------" << std::endl;
            std::cout << "1- Add a Training Day " << std::endl;
            std::cout << "2- Add a Race Day " << std::endl;
            std::cout << "3- View this week " << std::endl;
            std::cout << "4- View this month " << std::endl;
            std::cout << "5- Exit" << std::endl;
            std::cout << "----------------------------------" << std::endl;
        };

        auto tdMenu = []()
        {
            int option = 0;
            std::string textToParse;
            Activity td(TRAINING);

            do
            {
                std::cout << "----------------------------------" << std::endl;
                std::cout << "1- Add the warmup " << std::endl;
                std::cout << "2- Add a run " << std::endl;
                std::cout << "3- Exit" << std::endl;
                std::cout << "----------------------------------" << std::endl;
                std::cin >> option;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                switch (option)
                {
                case 1:
                    std::getline(std::cin, textToParse);
                    td.addWarmup(Run::parseRun(textToParse));
                    break;
                case 2:
                    std::getline(std::cin, textToParse);
                    td.addRun(Run::parseRun(textToParse));
                    break;
                default:
                    std::cout << "Wrong option" << std::endl;
                }
            } while (option != 3);

            Journal::getInstance().addActivity(td);
        };

        auto trMenu = []()
        {
            int option = 0;
            std::string textToParse;
            Activity tr(RACE);

            do
            {
                std::cout << "----------------------------------" << std::endl;
                std::cout << "1- Add the warmup " << std::endl;
                std::cout << "2- Add the race run " << std::endl;
                std::cout << "3- Add a comment" << std::endl;
                std::cout << "4- Exit" << std::endl;
                std::cout << "----------------------------------" << std::endl;

                switch (option)
                {
                case 1:
                    std::getline(std::cin, textToParse);
                    tr.addWarmup(Run::parseRun(textToParse));
                    break;
                case 2:
                    std::getline(std::cin, textToParse);
                    tr.addRun(Run::parseRun(textToParse));
                    break;
                case 3:
                    std::getline(std::cin, textToParse);
                    tr.addComment(textToParse);
                    break;
                default:
                    std::cout << "Wrong option" << std::endl;
                }
            } while (option != 4);

            Journal::getInstance().addActivity(tr);
        };

        int option;
        std::string textToParse;

        do
        {
            generalMenu();
            std::cout << "Option: ";
            std::cin >> option;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            // std::cout << "\033[2J\033[1;1H";

            Activity rd(RACE);

            switch (option)
            {
            case 1:
                tdMenu();
                break;

            case 2:
                trMenu();
                break;

            case 3:
                Journal::getInstance().showWeek();
                break;

            case 4:
                Journal::getInstance().showMonth();
                break;

            case 5:
                setStatus(option == 5);
                break;

            default:

                // std::cout << "\033[2J\033[1;1H";
                std::cout << "Your choice is invalid " << std::endl;
                std::cin.clear();
                std::cin.ignore();
            }
        } while (!finalize);

        LogManager::getInstance().writeLog(E_LEVEL::DEBUG, "Ending program...");
    }

    /*--------------------------------------------------------------------------
     * Set program status to indicated value.
     * If true, will stop program loop.
     */
    void ProgramManager::setStatus(bool value)
    {
        LogManager::getInstance().writeLog(E_LEVEL::DEBUG, "Setting finalize to = " + std::to_string(value));
        finalize = value;
    }

    /*--------------------------------------------------------------------------
     * Get program over status.
     */
    bool ProgramManager::getStatus() const
    {
        return !finalize;
    }
}
