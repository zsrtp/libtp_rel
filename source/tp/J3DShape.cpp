#include <tp/J3DShape.h>

#include <cstdint>

namespace libtp::tp::J3DShape
{
    void onFlag(J3DShape* shapePtr, uint32_t flaag) {
        shapePtr->mFlags |= flaag;
    }

    void offFlag(J3DShape* shapePtr, uint32_t flaag) {
        shapePtr->mFlags &= ~flaag;
    }

    void showMesh(J3DShape* shapePtr) {
        offFlag(shapePtr, J3DShpFlag_Visible);
    }

    void hideMesh(J3DShape* shapePtr) {
        onFlag(shapePtr, J3DShpFlag_Visible);
    }

} // namespace libtp::tp::J3DShape
