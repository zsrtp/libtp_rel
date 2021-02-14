/**
 *
 * @brief Allows more items to be placed as a 3D actor with some exceptions (i.e. Master Sword)
 *
 */

#include <cstdint>

#include "tp/d_stage.h"

/**
 * Contains patch functions that take no parameters
 * and immediately perfom the described action
 */
namespace libtp::patches
{
    /**
     * Contains the values for the flags to be set to skip the animations of first getting specific items
     */
    extern uint8_t itemsWithNoFieldModel[0x6A];

    void changeFieldModels();
}     // namespace libtp::patches