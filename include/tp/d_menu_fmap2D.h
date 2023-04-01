/**	@file d_menu_fmap2D.h
 *	@brief Symbols of the d_menu_fmap2D field
 *
 *	@author Lunar Soap
 *	@bug No known bugs.
 */
#ifndef TP_D_MENU_FMAP2D_H
#define TP_D_MENU_FMAP2D_H

namespace libtp::tp::d_menu_fmap2D
{
    extern "C"
    {
        /**
         *	@brief Checks to see if the player is trying to map warp.
         *
         *	@param mapPtr A pointer to the map resource.
         *
         *  @return Bool returns True if the player is trying to warp, otherwise returns False.
         */
        bool checkPlayerWarpAccept( void* mapPtr );
    }
}     // namespace libtp::tp::d_menu_fmap2D
#endif