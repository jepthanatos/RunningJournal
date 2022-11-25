//============================================================================
// Name        : LogManager.h
// Author      : Jorge
// Copyright   : https://creativecommons.org/licenses/by/4.0/
// Description : Manager of the logfile.
//============================================================================

#ifndef __LOG_MANAGER_H__
#define __LOG_MANAGER_H__

// System includes.
#include <string>
#include <fstream>
#include <iostream>

// Engine includes.
#include "Manager.h"

//==============================================================================
/* LogManager */
//==============================================================================

/*------------------------------------------------------------------------------
 * Manager of the logfile.
 */
namespace runjour
{
    const std::string LOGFILE_NAME = "runjour.log";

    enum E_LEVEL
    {
        DEBUG = INT8_MAX,
        INFO = INT64_MAX
    };

    class LogManager : public Manager
    {
    private:
        LogManager();
        LogManager(LogManager const &){};
        void operator=(LogManager const &){};

        std::ofstream logFile;
        int logLevel;
        int contBlankSpaces = 0;

    public:
        // If logfile is open, close it.
        ~LogManager();

        // Get the one and only instance of the LogManager.
        static LogManager &getInstance();

        // Start up the LogManager (open logfile).
        void startUp();

        // Shut down the LogManager (close logfile).
        void shutDown();

        // Write to logfile.
        void writeLog(int level, const std::string);

        // Get the log level.
        int getLevel();

        // Set the log level.
        void setLevel(int value);

        const std::string getBlankSpaces() {
            std::string result = "";
            for (int i = 0; i < contBlankSpaces; ++i)
                result += " ";
            return result;
        }

        const std::string increaseBlankSpaces() {
            contBlankSpaces += 2;
            return getBlankSpaces();
        }

        const std::string decreaseBlankSpaces() {
            contBlankSpaces -= 2;
            if (contBlankSpaces < 0)
                contBlankSpaces = 0;
            return getBlankSpaces();
        }
    };
}

#endif // __LOG_MANAGER_H__
