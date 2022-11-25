//==============================================================================
// Name        : Journal.h
// Author      : Jorge
// Copyright   : https://creativecommons.org/licenses/by/4.0/
// Description : Class to define a Journal.
//==============================================================================

#ifndef __JOURNAL_H__
#define __JOURNAL_H__

// System includes.
#include <string>
#include <vector>

// Local includes.
#include "Activity.h"

//==============================================================================
/* Journal */
//==============================================================================

/*------------------------------------------------------------------------------
 * Class to define a journal.
 */
namespace runjour
{
    /*
     * Journal is a list of activities.
     */
    class Journal
    {
    private:
        Journal();
        Journal(Journal const &){};
        void operator=(Journal const &){};

        std::vector<Activity> activities;

    public:
        // Destroy journal.
        virtual ~Journal();

        // Get the singleton instance of the Journal.
        static Journal &getInstance();

        // Add an activity to the journal.
        void addActivity(const Activity &value);

        // Print all the activities of this week.
        void showWeek();

        // Print all the activities of this month.
        void showMonth();

        // Print function for debug.
        void print();
    };
}
//------------------------------------------------------------------------------
#endif /* __JOURNAL_H__ */
