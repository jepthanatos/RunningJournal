//==============================================================================
// Name        : Activity.h
// Author      : Jorge
// Copyright   : https://creativecommons.org/licenses/by/4.0/
// Description : Class to define an Activity.
//==============================================================================

#ifndef __ACTIVITY_H__
#define __ACTIVITY_H__

// System includes.
#include <string>
#include <vector>
#include <map>
#include <ctime>

// Local includes.
#include "Run.h"

//==============================================================================
/* Activity */
//==============================================================================

/*------------------------------------------------------------------------------
 * Class to define an activity.
 */
namespace runjour
{
    // Activities can be of two types:
    // - Training Day
    // - Race Day
    enum E_TYPE
    {
        NONE = 0,
        TRAINING = 1,
        RACE = 2
    };

    class Activity
    {
    private:
        int id;
        int type;
        time_t date;
        Run warmup;
        std::vector<Run> runs;
        std::string comments;

        std::map<int, std::string> types = {
            {0, "none"}, {1, "Training day"}, {2, "Race day"}
        };

    public:
        // Construct activity.
        Activity(int newType);

        // Destroy activity.
        virtual ~Activity();

        // Get activity id.
        int getId() const;

        // Set type identifier of activity.
        void setType(int newType);

        // Get type identifier of activity.
        int getType() const;

        // Add a warmup to the activity.
        void addWarmup(const Run &value);

        // Add a run to the activity.
        void addRun(const Run &value);

        // Add a comment to the activity.
        void addComment(const std::string &value);

        // Check if the activity is in this week.
        bool isInThisWeek();

        // Check if the activity is in this month.
        bool isInThisMonth();

        // Print function for debug.
        void print();
    };
}
//------------------------------------------------------------------------------
#endif /* __ACTIVITY_H__ */
