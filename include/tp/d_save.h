/**	@file d_save.h
 *	@brief Holds symbols of the d_save field
 *
 *	@author AECX
 *	@author Lunar Soap
 *	@bug No known bugs.
 */
#ifndef TP_D_SAVE_H
#define TP_D_SAVE_H

#include <cstdint>

#include "d_com_inf_game.h"

namespace libtp::tp::d_save
{
    extern "C"
    {
        /**
         *	@brief Gets the maximum number of rupees
         *
         *	Warning! If this function is manipulated to return a higher number than
         *what
         *	the HUD can display (4 digits base 10) it causes serious issues (e.g.
         *random crashes)
         *
         *	@return Returns the maximum number of rupees Link can hold in his
         *current wallet
         */
        uint16_t getRupeeMax();

        /**
         *	@brief Sets the current AreaNode for region-specific flags
         *	by loading it from the ScratchPad/QuestLog
         *
         *	For more information about AreaNodes please refer to
         *	https://docs.google.com/spreadsheets/d/1OvlqH_OG_svcLZfuSDBjCLHFivcsBGpOD25o-_6vblA/edit#gid=0
         *
         *	@param gameInfoPtr Pointer to d_com_inf_game::gameInfo
         *	@param areaID ID of the current Area
         */
        void getSave( d_com_inf_game::GameInfo* gameInfoPtr, int32_t areaID );

        /**
         *	@brief Puts the previously set AreaNode for region-specific flags back
         *	into the ScratchPad/QuestLog
         *
         *	For more information about AreaNodes please refer to
         *	https://docs.google.com/spreadsheets/d/1OvlqH_OG_svcLZfuSDBjCLHFivcsBGpOD25o-_6vblA/edit#gid=0
         *
         *	@param gameInfoPtr Pointer to d_com_inf_game::gameInfo
         *	@param areaID ID of the current Area
         */
        void putSave( d_com_inf_game::GameInfo* gameInfoPtr, int32_t areaID );

        /**
         *  @brief Sets an eventBit for the currently active save
         *
         *  @param eventPtr The pointer to the event bits.
         *  @param flag Offset+Flag
         */

        void onEventBit( uint8_t* eventPtr, uint16_t flag );

        /**
         *  @brief Unsets an eventBit for the currently active save
         *
         *  @param eventPtr The pointer to the event bits.
         *  @param flag Offset+Flag
         */
        void offEventBit( uint8_t* eventPtr, uint16_t flag );

        /**
         *  @brief Checks whether the player has cleared the specified twilight.
         *
         *  @param playerStatusPtr The pointer to the PlayerStatus struct.
         *  @param twilightNode The twilight instance to be checked.
         */
        bool isDarkClearLV( void* playerStatusPtr, int32_t twilightNode );

        /**
         *  @brief Checks whether or not Link has been transformed into wolf by a
         * twilight CS
         *
         *  @param playerStatusPtr The pointer to the PlayerStatus struct.
         *  @param twilightEvent The twilight cutscene event to be checked.
         */
        bool isTransformLV( void* playerStatusPtr, int32_t twilightEvent );

        extern uint16_t saveBitLabels[0x336];     // saveBitLabels__16dSv_event_flag_c
    }
}     // namespace libtp::tp::d_save
#endif