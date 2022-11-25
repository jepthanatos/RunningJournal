//==============================================================================
// Name        : Run.cpp
// Author      : Jorge
// Copyright   : https://creativecommons.org/licenses/by/4.0/
// Description : Class to define a generic Run.
//==============================================================================

#include "Run.h"
#include "LogManager.h"

#include <string>
#include <sstream>

//==============================================================================
/* Run */
//==============================================================================

namespace runjour
{
    /*--------------------------------------------------------------------------
     * Default constructor.
     */
    Run::Run() : type{"Run"}, distance{0}, time{"0:00:00"}, pace{"00:00"}
    {
        static int cont{0};
        id = cont;
        ++cont;
    }

    /*--------------------------------------------------------------------------
     * Destructor.
     */
    Run::~Run() {}

    /*--------------------------------------------------------------------------
     * Get Run id.
     */
    int Run::getId(void) const
    {
        return id;
    }

    /*--------------------------------------------------------------------------
     * Set type identifier of Run.
     */
    void Run::setType(std ::string newType)
    {
        type = newType;
    }

    /*--------------------------------------------------------------------------
     *  Get type identifier of Run.
     */
    std::string Run::getType() const
    {
        return type;
    }

    /*--------------------------------------------------------------------------
     *  Function to know if this object is null.
     */
    bool Run::isNull()
    {
        return distance == 0 and time == "0:00:00" and pace == "00:00";
    }

    /*--------------------------------------------------------------------------
     *  Parse a run and return a Run object.
     */
    Run Run::parseRun(const std::string &text)
    {
        Run result;

        result.distance = 10;
        result.time = "50:00";
        result.pace = "5:00";

        return result;
    }

    /*--------------------------------------------------------------------------
     *  Print function for debug.
     */
    std::string Run::print()
    {

        std::string blankSpaces = LogManager::getInstance().increaseBlankSpaces();

        std::ostringstream message;
        message << blankSpaces << "++ " << type << " (id: " << id << ") ++" << std::endl
                << blankSpaces << "- Dist: " << distance << std::endl
                << blankSpaces << "- Time: " << time << std::endl
                << blankSpaces << "- Pace: " << pace;

        LogManager::getInstance().decreaseBlankSpaces();

        return message.str();
    }
}
