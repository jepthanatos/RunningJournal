//==============================================================================
// Name        : ProgramManager.h
// Author      : Jorge
// Copyright   : https://creativecommons.org/licenses/by/4.0/
// Description : Manager of the program loop.
//==============================================================================

#ifndef __PROGRAM_MANAGER_H__
#define __PROGRAM_MANAGER_H__

// System includes.
#include <string>

// Local includes.
#include "Manager.h"

//==============================================================================
/* ProgramManager */
//==============================================================================

/*------------------------------------------------------------------------------
 * Manager of the program loop.
 */
namespace runjour
{
    class ProgramManager : public Manager
    {
    private:
        ProgramManager();
        ProgramManager(ProgramManager const &){};
        void operator=(ProgramManager const &){};

        bool finalize; // True, then program loop should stop.

    public:
        ~ProgramManager(){};

        // Get the singleton instance of the ProgramManager.
        static ProgramManager &getInstance();

        // Start up the ProgramManager services.
        void startUp();

        // Shut down the ProgramManager services.
        void shutDown();

        // Run program loop.
        void run();

        // Set program status to indicated value.
        // If true (default), will stop program loop.
        void setStatus(bool value = true);

        // Get program status.
        // Returns true if is running, false otherwise.
        bool getStatus() const;
    };
}

#endif // __PROGRAM_MANAGER_H__
