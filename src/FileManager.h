//==============================================================================
// Name        : FileManager.h
// Author      : Jorge
// Copyright   : https://creativecommons.org/licenses/by/4.0/
// Description : Manager of the database files.
//==============================================================================

#ifndef __LOG_MANAGER_H__
#define __LOG_MANAGER_H__

// System includes.
#include <string>
#include <fstream>
#include <iostream>

// Engine includes.
#include "Manager.h"

//==============================================================================
/* FileManager */
//==============================================================================

/*------------------------------------------------------------------------------
 * Manager of the database files.
 */
namespace runjour
{
    const std::string LOGFILE_NAME = "runjour.log";

    class FileManager : public Manager
    {
    private:
        FileManager();
        FileManager(FileManager const &){};
        void operator=(FileManager const &){};

        std::ofstream logFile;
        int logLevel;

    public:
        // If database files are open, close them.
        ~FileManager();

        // Get the one and only instance of the FileManager.
        static FileManager &getInstance();

        // Start up the FileManager (open database files).
        void startUp();

        // Shut down the FileManager (close database files).
        void shutDown();

        // Write to database files.
        void write(int level, const std::string);

        // Get the log level.
        int getLevel();

        // Set the log level.
        void setLevel(int value);
    };
}
//------------------------------------------------------------------------------
#endif // __LOG_MANAGER_H__
