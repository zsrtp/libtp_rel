/**	@file d_menu_collect.h
 *	@brief Symbols of the d_menu_collect field
 *
 *	@author AECX
 *	@bug No known bugs.
 */
#ifndef TP_D_MENU_COLLECT_H
#define TP_D_MENU_COLLECT_H

namespace libtp::tp::d_menu_collect
{
    extern "C"
    {
        /**
         *	@brief Sets the maximum number of rupees
         *
         *	Automatically gets the wallet size and fills it
         */
        void setWalletMaxNum();

        void dMenuCollect__draw( void* dMenuCollect );
    }
}     // namespace libtp::tp::d_menu_collect
#endif