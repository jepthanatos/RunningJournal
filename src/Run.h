//==============================================================================
// Name        : Run.h
// Author      : Jorge
// Copyright   : https://creativecommons.org/licenses/by/4.0/
// Description : Class to define a generic Run.
//==============================================================================

#ifndef __RUN_H__
#define __RUN_H__

// System includes.
#include <string>

//==============================================================================
/* Run */
//==============================================================================

/*------------------------------------------------------------------------------
 * Class to define a run.
 */
namespace runjour
{
    class Run
    {
    private:
        int id;
        std::string type;
        float distance;   // In kilometers
        std::string time; // With this format h:mm:ss
        std::string pace; // With this format mm:ss

    public:
        // Construct run.
        Run();

        // Destroy run.
        ~Run();

        // Set run id.
        void setId(int newId);

        // Get run id.
        int getId() const;

        // Set type identifier of run.
        void setType(std ::string newType);

        // Get type identifier of run.
        std::string getType() const;

        // Function to know if this object is null.
        bool isNull();

        static Run parseRun(const std::string &text);

        // Print function for debug.
        std::string print();
    };
}
//------------------------------------------------------------------------------
#endif /* __RUN_H__ */
