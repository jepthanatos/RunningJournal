//============================================================================
// Name        : Activity.cpp
// Author      : Jorge
// Copyright   : https://creativecommons.org/licenses/by/4.0/
// Description : Class to define an Activity.
//============================================================================

#include "Activity.h"
#include "LogManager.h"

#include <string>
#include <sstream>
#include <iomanip>

//==============================================================================
/* Activity */
//==============================================================================

namespace runjour
{
    /*--------------------------------------------------------------------------
     * Default constructor.
     */
    Activity::Activity(int newType) : comments{"None"}
    {
        static int cont{0};
        id = cont;
        ++cont;
        type = newType;
        date = time(0);
    }

    /*--------------------------------------------------------------------------
     * Destructor.
     */
    Activity::~Activity()
    {
        // TODO
    }

    /*--------------------------------------------------------------------------
     * Get Activity id.
     */
    int Activity::getId(void) const
    {
        return id;
    }

    /*--------------------------------------------------------------------------
     * Set type identifier of Activity.
     */
    void Activity::setType(int newType)
    {
        type = newType;
    }

    /*--------------------------------------------------------------------------
     *  Get type identifier of Activity.
     */
    int Activity::getType() const
    {
        return type;
    }

    /*--------------------------------------------------------------------------
     * Add a warmup to the activity.
     */
    void Activity::addWarmup(const Run &value)
    {
        warmup = value;
        warmup.setType("Warmup");
    }

    /*--------------------------------------------------------------------------
     * Add a run to the activity.
     */
    void Activity::addRun(const Run &value)
    {
        runs.push_back(value);
    }

    /*--------------------------------------------------------------------------
     * Add a comment to the activity.
     */
    void Activity::addComment(const std::string &value)
    {
        comments = value;
    }

    /*--------------------------------------------------------------------------
     * Check if the activity is in this week.
     */
    bool Activity::isInThisWeek()
    {
        // Calculate the actual time.
        time_t timer;
        time(&timer);
        struct tm *now;
        now = localtime(&timer);

        // Convert the saved time of the activity.
        struct tm *timeinfo;
        time(&date);
        timeinfo = localtime(&date);

        std::string message =
            std::to_string(timeinfo->tm_yday) + " - " + std::to_string(timeinfo->tm_wday) +
            " == " + std::to_string(now->tm_yday) + " - " + std::to_string(now->tm_wday);

        LogManager::getInstance().writeLog(E_LEVEL::DEBUG, message);

        return ((timeinfo->tm_yday - timeinfo->tm_wday) == (now->tm_yday - now->tm_wday));
    }

    /*--------------------------------------------------------------------------
     * Check if the activity is in this month.
     */
    bool Activity::isInThisMonth()
    {
        // Calculate the actual time.
        time_t timer;
        time(&timer);
        struct tm *now;
        now = localtime(&timer);

        // Convert the saved time of the activity.
        struct tm *timeinfo;
        time(&date);
        timeinfo = localtime(&date);

        std::string message =
            std::to_string(timeinfo->tm_mon) + " == " + std::to_string(now->tm_mon);

        LogManager::getInstance().writeLog(E_LEVEL::DEBUG, message);

        return timeinfo->tm_mon == now->tm_mon;
    }

    /*--------------------------------------------------------------------------
     *  Print function for debug.
     */
    void Activity::print()
    {
        auto printRuns = [this]() -> std::string
        {
            for (auto run : runs)
            {
                std::cout << std::endl
                          << run.print();
            }
            return "";
        };

        std::string blankSpaces = LogManager::getInstance().increaseBlankSpaces();

        tm *local_time = localtime(&date);

        // std::ostringstream message;
        std::cout << blankSpaces << "-- " << types.at(type) << " (id: " << id << ") ++" << std::endl
                  << blankSpaces << "- Date: " << 1900 + local_time->tm_year << "/"
                  << 1 + local_time->tm_mon << "/" << local_time->tm_mday << std::endl;
        if (!warmup.isNull())
            std::cout << blankSpaces << "- Warmup: " << std::endl
                      << warmup.print() << std::endl;
        std::cout << blankSpaces << "- Runs: " << printRuns() << std::endl
                  << blankSpaces << "- Comments: " << comments << std::endl;

        // LogManager::getInstance().writeLog(E_LEVEL::DEBUG, message.str());

        LogManager::getInstance().decreaseBlankSpaces();
    }
}
