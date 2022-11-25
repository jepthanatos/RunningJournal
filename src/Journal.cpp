//==============================================================================
// Name        : Journal.cpp
// Author      : Jorge
// Copyright   : https://creativecommons.org/licenses/by/4.0/
// Description : Class to define an Journal.
//==============================================================================

#include "Journal.h"

// Local includes.
#include "LogManager.h"

// System includes.
#include <string>
#include <sstream>

//==============================================================================
/* Journal */
//==============================================================================

namespace runjour
{
    /*--------------------------------------------------------------------------
     * Default constructor.
     */
    Journal::Journal()
    {
        // TODO
    }

    /*--------------------------------------------------------------------------
     * Destructor.
     */
    Journal::~Journal()
    {
        // TODO
    }

    /*--------------------------------------------------------------------------
     * Get the singleton instance of the Journal.
     */
    Journal &Journal::getInstance()
    {
        static Journal instance;
        return instance;
    }

    /*--------------------------------------------------------------------------
     * Add a warmup to the Journal.
     */
    void Journal::addActivity(const Activity &value)
    {
        activities.push_back(value);
    }

    /*--------------------------------------------------------------------------
     * Print all the activities of this week.
     */
    void Journal::showWeek()
    {
        std::cout << "Printing this week activities" << std::endl;
        for (auto activity : activities)
        {
            if (activity.isInThisWeek())
                activity.print();
        }
    }

    /*--------------------------------------------------------------------------
     * Print all the activities of this month.
     */
    void Journal::showMonth()
    {
        std::cout << "Printing this month activities" << std::endl;
        for (auto activity : activities)
        {
            if (activity.isInThisMonth())
                activity.print();
        }
    }

    /*--------------------------------------------------------------------------
     *  Print function for debug.
     */
    void Journal::print()
    {
        std::ostringstream message;
        message << "Printing an Journal info: " << std::endl;

        LogManager::getInstance().writeLog(E_LEVEL::DEBUG, message.str());
    }
}
