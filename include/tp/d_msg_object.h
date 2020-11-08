/**	@file d_msg_object.h
 *	@brief Contains some of the functions used in getting the values for a message
 *
 *	@author Lunar Soap
 *	@bug No known bugs.
 */

#include <cstdint>

namespace libtp::tp::d_msg_object
{
	extern "C"
	{
        /**
         *	@brief Gets a pointer to the transparancy of the Z button
         *
         * @param param_1 - Unknown
         * @param itemIndex - The itemId of the item received + 0x65
         * @param param_3 - Unknown. I think it checks for a valid message but more research is needed
         */
		void setMessageIndex(uint32_t param_1, uint32_t itemIndex, bool param_3);
	}
}