//============================================================================
// Name        : FileManager.cpp
// Author      : Jorge
// Copyright   : https://creativecommons.org/licenses/by/4.0/
// Description : Manager of the database files.
//============================================================================

#include "FileManager.h"

#include <chrono>
#include <iomanip>
#include <sstream>

//==============================================================================
/* Manager */
//==============================================================================

namespace runjour
{
    /*--------------------------------------------------------------------------
     * Constructor.
     */
    FileManager::FileManager()
    {
        Manager::setType("FileManager");
    }

    /*--------------------------------------------------------------------------
     * Destructor.
     */
    FileManager::~FileManager()
    {
        if (logFile.is_open())
            logFile.close();
    }

    /*--------------------------------------------------------------------------
     * Get the one and only instance of the FileManager.
     */
    FileManager &FileManager::getInstance()
    {
        static FileManager instance;
        return instance;
    }

    /*--------------------------------------------------------------------------
     * Start up the FileManager (open logfile).
     */
    void FileManager::startUp()
    {
        // Open the logfile.
        logFile.open(LOGFILE_NAME, std::ofstream::out);
        if (!logFile)
        {
            std::cout << "File creation failed";
        }
    }

    /*--------------------------------------------------------------------------
     * Shut down the FileManager (close logfile).
     */
    void FileManager::shutDown()
    {
        // Close the logfile.
        logFile.close();
    }

    /*--------------------------------------------------------------------------
    /* This is a private function.
    /* Returns a nicely-formatted time string.
     */
    std::string prettyTime()
    {
        const auto now = std::chrono::system_clock::now();
        const auto nowAsTimeT = std::chrono::system_clock::to_time_t(now);
        const auto nowMs =
            std::chrono::duration_cast<std::chrono::milliseconds>
                (now.time_since_epoch()) % 1000;
        std::stringstream nowSs;
        nowSs
            << std::put_time(std::localtime(&nowAsTimeT), "%a %b %d %Y %T")
            << '.' << std::setfill('0') << std::setw(3) << nowMs.count();
        return nowSs.str();
    }

    /*--------------------------------------------------------------------------
     * Write to logfile.
     */
    void FileManager::write(int level, const std::string message)
    {
        if (level >= logLevel)
            logFile << prettyTime() << " : " << message << std::endl;
    }

    /*--------------------------------------------------------------------------
     * Get the log level.
     */
    int FileManager::getLevel()
    {
        return logLevel;
    }

    /*--------------------------------------------------------------------------
     * Set the log level.
     */
    void FileManager::setLevel(int value)
    {
        logLevel = value;
    }
}
