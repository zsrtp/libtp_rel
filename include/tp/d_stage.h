
/**	@file d_stage.h
 *	@brief Stage related functions and fields
 *
 *	@author AECX
 *  @author Zephiles
 *  @author Lunar Soap
 *	@bug No known bugs.
 */
#ifndef TP_D_STAGE_H
#define TP_D_STAGE_H

#include <cstdint>

#include "dzx.h"
#include "tp/d_kankyo_data.h"
#include "SSystem/SComponent/c_sxyz.h"
#include "SSystem/SComponent/c_xyz.h"
#include "dolphin/gx/GXStruct.h"

namespace libtp::tp::d_stage
{
    struct stage_vrboxcol_info_class
    {
        // VRB
    }; // Size: 0x18

    struct stage_camera2_data_class
    {
        /* 0x00 */ int field_0x0;
        /* 0x04 */ float field_0x4;
        /* 0x08 */ float field_0x8;
        /* 0x0C */ float field_0xc;
        /* 0x10 */ uint8_t field_0x10;
        /* 0x11 */ uint8_t field_0x11;
        /* 0x12 */ uint8_t field_0x12;
        /* 0x13 */ uint8_t field_0x13;
        /* 0x14 */ uint16_t field_0x14;
        /* 0x16 */ uint16_t field_0x16;
    }; // Size: 0x18

    struct stage_camera_class
    {
        /* 0x0 */ int field_0x0;
        /* 0x4 */ stage_camera2_data_class* mEntries;
    };

    struct stage_arrow_data_class
    {
        /* 0x00 */ cXyz mPosition;
        /* 0x0C */ csXyz mAngle;
    }; // Size: 0x14

    struct stage_arrow_class
    {
        /* 0x00 */ int mNum;
        /* 0x04 */ stage_arrow_data_class* mEntries;
    };

    struct stage_actor_data_class
    {
        /* 0x00 */ char mName[8];
        /* 0x08 */ uint32_t mParameter;
        /* 0x0C */ cXyz mSpawnPos;
        /* 0x18 */ csXyz mAngle;
        /* 0x1E */ uint16_t mEnemyNo;
    }; // Size: 0x20

    struct stage_actor_class
    {
       public:
        /* 0x0 */ int mEntryNum;
        /* 0x4 */ stage_actor_data_class* mEntries;
    };

    struct stage_tgsc_data_class: public stage_actor_data_class
    {
        /* 8002847C */ ~stage_tgsc_data_class() {}
        /* 800284B8 */ stage_tgsc_data_class() {}

        /* 0x20 */ uint8_t field_0x20;
        /* 0x21 */ uint8_t field_0x21;
        /* 0x22 */ uint8_t field_0x22;
    }; // Size: 0x24

    static_assert(sizeof(stage_tgsc_data_class) == 0x24);

    class stage_tgsc_class
    {
       public:
        /* 0x00 */ int mEntryNum;
        /* 0x04 */ stage_tgsc_data_class* mData;
    };

    struct roomRead_data_class
    {
        /* 0x0 */ uint8_t field_0x0;
        /* 0x1 */ uint8_t field_0x1;
        /* 0x2 */ uint8_t field_0x2;
        /* 0x4 */ uint8_t* field_0x4;
    };

    struct roomRead_class
    {
        /* 0x0 */ int field_0x0;
        /* 0x4 */ roomRead_data_class** field_0x4;
    };

    struct stage_map_info_class
    {
        /* 0x00 */ uint8_t field_0x0[0x35];
        /* 0x35 */ uint8_t field_0x35;
        /* 0x36 */ uint8_t field_0x36[2];
    }; // Size: 0x38

    struct stage_map_info_dummy_class
    {
        /* 0x0 */ int field_0x0;
        /* 0x4 */ stage_map_info_class* mData;
    };

    struct stage_stag_info_class
    {
        /* 0x00 */ float field_0x0;
        /* 0x04 */ float field_0x4;
        /* 0x08 */ uint8_t mCameraType;
        /* 0x09 */ uint8_t field_0x09;
        /* 0x0A */ uint16_t field_0x0a;
        /* 0x0C */ uint32_t field_0x0c;
        /* 0x10 */ uint32_t field_0x10;
        /* 0x14 */ uint8_t field_0x14[6]; // usually all 0xFF
        /* 0x1A */ int16_t mGapLevel;
        /* 0x1C */ int16_t mRangeUp;
        /* 0x1E */ int16_t mRangeDown;
        /* 0x20 */ float field_0x20;
        /* 0x24 */ float field_0x24;
        /* 0x28 */ uint8_t mMsgGroup;
        /* 0x2A */ uint16_t mStageTitleNo;
        /* 0x2C */ uint8_t mParticleNo[16];
    };

    struct stage_scls_info_class
    {
        /* 0x0 */ char mStage[8];
        /* 0x8 */ uint8_t mStart;
        /* 0x9 */ int8_t mRoom;
        /* 0xA */ uint8_t field_0xa;
        /* 0xB */ uint8_t field_0xb;
        /* 0xC */ int8_t mWipe;

        char* getStage() { return mStage; }

        int getRoom() { return mRoom; }
    }; // Size: 0xD

    struct stage_scls_info_dummy_class
    {
        /* 0x00 */ int numEntries;
        /* 0x04 */ stage_scls_info_class* mEntries;
    };

    struct stage_pure_lightvec_info_class
    {
        // LGT
        /* 0x00 */ Vec m_position;
        /* 0x0C */ float m_radius;
        /* 0x10 */ float m_directionX;
        /* 0x14 */ float m_directionY;
        /* 0x18 */ float m_spotCutoff;
        /* 0x1C */ uint8_t field_0x1c;
        /* 0x1D */ uint8_t field_0x1d;
        /* 0x1E */ uint8_t field_0x1e;
        /* 0x1F */ uint8_t field_0x1f;
    }; // Size: 0x20

    // Col
    struct stage_pselect_info_class
    {
        /* 0x0 */ uint8_t mPalIdx[8];
        /* 0x8 */ float mChangeRate;
    }; // Size: 0xC

    struct stage_plight_info_class
    {
        // LGHT
        /* 0x00 */ Vec m_position;
        /* 0x0C */ float m_radius;
        /* 0x10 */ uint8_t field_0x10[0x18 - 0x10];
        /* 0x18 */ d_kankyo_data::color_RGB_class m_color;
        /* 0x1B */ uint8_t m_fluctuation;
    }; // Size: 0x1C

    // PALE
    struct stage_palette_info_class
    {
        /* 0x00 */ d_kankyo_data::color_RGB_class mActorAmbColor;
        /* 0x03 */ d_kankyo_data::color_RGB_class mBgAmbColor[4];
        /* 0x0F */ d_kankyo_data::color_RGB_class mPlightColor[6];
        /* 0x21 */ d_kankyo_data::color_RGB_class mFogColor;
        /* 0x24 */ float mFogStartZ;
        /* 0x28 */ float mFogEndZ;
        /* 0x2C */ uint8_t mVirtIdx;
        /* 0x2D */ uint8_t mTerrainLightInfluence;
        /* 0x2E */ uint8_t mCloudShadowDensity;
        /* 0x2F */ uint8_t field_0x2f;
        /* 0x30 */ uint8_t mBloomTblIdx;
        /* 0x31 */ uint8_t mBgAmbColor1A;
        /* 0x32 */ uint8_t mBgAmbColor2A;
        /* 0x33 */ uint8_t mBgAmbColor3A;
    }; // Size: 0x34

    struct stage_envr_info_class
    {
        /* 0x0 */ uint8_t m_pselectID[65];
    }; // Size: 0x41

    // Virt
    struct stage_vrbox_info_class
    {
        /* 0x00 */ d_kankyo_data::color_RGB_class field_0x0;
        /* 0x03 */ d_kankyo_data::color_RGB_class field_0x3;
        /* 0x06 */ d_kankyo_data::color_RGB_class field_0x6;
        /* 0x09 */ GXColor field_0x9;
        /* 0x0D */ GXColor field_0xd;
        /* 0x11 */ GXColor field_0x11;
    }; // Size: 0x15

    struct stage_tresure_class
    {
        /* 0x00 */ char mName[8];
        /* 0x08 */ uint8_t field_0x8;
        /* 0x09 */ uint8_t mTypeFlag;
        /* 0x0A */ uint8_t field_0xa; // part of flag
        /* 0x0B */ uint8_t mAppearType;
        /* 0x0C */ Vec mPosition;
        /* 0x18 */ int16_t mRoomNo;
        /* 0x1A */ int16_t mRotation;
        /* 0x1C */ uint8_t mItem;
        /* 0x1D */ uint8_t mFlagID;
    }; // Size: 0x20

    struct dStage_FileList_dt_c
    {
        /* 0x00 */ uint32_t mParameters;
        /* 0x04 */ float mSeaLevel;
        /* 0x08 */ float field_0x8;
        /* 0x0C */ float field_0xc;
        /* 0x10 */ uint8_t field_0x10[10];
        /* 0x1A */ uint8_t mDefaultCamera;
        /* 0x1B */ uint8_t mBitSw;
        /* 0x1C */ uint16_t mMsg;
    }; // Size: 0x20

    // PPNT
    struct dStage_dPnt_c
    {
        /* 0x0 */ uint8_t field_0x0;
        /* 0x1 */ uint8_t field_0x1;
        /* 0x2 */ uint8_t field_0x2;
        /* 0x3 */ uint8_t field_0x3;
        /* 0x4 */ cXyz m_position;
    }; // Size: 0x10

    struct dStage_FloorInfo_c
    {
        // FLOR
    };

    struct dStage_Lbnk_dt_c
    {
        /* 0x0 */ uint8_t bank;
        /* 0x1 */ uint8_t bank2;
        /* 0x2 */ uint8_t field_0x2;
    };

    struct dStage_Lbnk_c
    {
        /* 0x0 */ int num;
        /* 0x4 */ dStage_Lbnk_dt_c* entries;
    };

    struct dStage_Elst_data
    {
        /* 0x0 */ uint8_t m_layerTable[15];
    };

    struct dStage_Elst_c
    {
        /* 0x0 */ int m_entryNum;
        /* 0x4 */ dStage_Elst_data* m_entries;
    };

    struct dStage_MemoryConfig_data
    {
        /* 0x0 */ uint8_t m_roomNo;
        /* 0x1 */ uint8_t m_blockID;
    }; // Size: 0x2

    struct dStage_MemoryConfig_c
    {
        /* 0x0 */ int m_num;
        /* 0x4 */ dStage_MemoryConfig_data* field_0x4;
    };

    struct dStage_DMap_c
    {
        // DMAP
    };

    struct dStage_MapEvent_dt_c
    {
        /* 0x00 */ uint8_t mType;
        /* 0x01 */ uint8_t field_0x1;
        /* 0x02 */ uint8_t field_0x2;
        /* 0x03 */ uint8_t field_0x3;
        /* 0x04 */ uint8_t field_0x4;
        /* 0x05 */ uint8_t field_0x5;
        /* 0x06 */ uint8_t mPriority;
        /* 0x07 */ uint8_t field_0x7;
        /* 0x08 */ uint8_t field_0x8;
        /* 0x09 */ uint8_t field_0x9;
        /* 0x0A */ uint8_t field_0xA;
        /* 0x0B */ uint8_t field_0xB;
        /* 0x0C */ uint8_t field_0xC;
        /* 0x0D */ char mName[7];
        /* 0x14 */ uint16_t field_0x14;
        /* 0x16 */ uint8_t field_0x16;
        /* 0x17 */ uint8_t field_0x17;
        /* 0x18 */ uint8_t mSeType; // 1: RIDDLE_A, 2: RIDDLE_B
        /* 0x19 */ uint8_t field_0x19[0x1B - 0x19];
        /* 0x1B */ uint8_t mSwitch;
    }; // SIZE = 0x1C

    struct dStage_MapEventInfo_c
    {
        // REVT
        int mCount;
        dStage_MapEvent_dt_c* mData;
    };

    struct dStage_FileList2_dt_c
    {
        /* 0x00 */ float mLeftRmX;
        /* 0x04 */ float mInnerRmZ;
        /* 0x08 */ float mRightRmX;
        /* 0x0C */ float mFrontRmZ;
        /* 0x10 */ uint8_t mMinFloorNo;
        /* 0x11 */ uint8_t mMaxFloorNo;
        /* 0x12 */ uint8_t field_0x12;
        /* 0x13 */ uint8_t field_0x13;
        /* 0x14 */ float field_0x14;
        /* 0x18 */ float field_0x18;
        /* 0x1C */ int16_t field_0x1c;
    }; // Size: 0x20

    struct dStage_MemoryMap_c
    {
        /* 0x0 */ int m_num;
        /* 0x4 */ uint32_t* field_0x4;
    };

    struct dPath;
    struct dStage_dPath_c
    {
        /* 0x0 */ int m_num;
        /* 0x4 */ dPath* m_path;
    };

    struct dStage_Mult_info
    {
        /* 0x0 */ float mTransX;
        /* 0x4 */ float mTransY;
        /* 0x8 */ int16_t mAngle;
        /* 0xA */ uint8_t mRoomNo;
    }; // Size: 0xC

    struct dStage_Multi_c
    {
        /* 0x0 */ int field_0x0;
        /* 0x4 */ dStage_Mult_info* mInfo;
    };

    struct stage_sound_data
    {
        /* 0x00 */ char field_0x0[8];
        /* 0x08 */ Vec field_0x8;
        /* 0x14 */ uint8_t field_0x14;
        /* 0x15 */ uint8_t field_0x15;
        /* 0x16 */ uint8_t field_0x16;
        /* 0x17 */ uint8_t field_0x17;
        /* 0x18 */ uint8_t field_0x18;
        /* 0x19 */ uint8_t field_0x19;
        /* 0x1A */ uint8_t field_0x1a;
    }; // Size: 0x1C

    struct dStage_SoundInfo_c
    {
        // SOND
        /* 0x0 */ int num;
        /* 0x4 */ stage_sound_data* entries;
    };

    struct dStage_dt_c
    {
        /* 0x00 */ void* vtable;
        /* 0x04 */ int8_t mRoomNo;
    };

    struct dStage_stageDt_c: dStage_dt_c
    {
        /* 0x08 */ stage_camera_class* mCamera;
        /* 0x0C */ stage_arrow_class* mArrow;
        /* 0x10 */ stage_actor_class* mPlayer;
        /* 0x14 */ roomRead_class* mRoom;
        /* 0x18 */ stage_map_info_class* mMapInfo;
        /* 0x1C */ stage_map_info_dummy_class* mMapInfoBase;
        /* 0x20 */ stage_palette_info_class* mPaletteInfo;
        /* 0x24 */ stage_pselect_info_class* mPselectInfo;
        /* 0x28 */ stage_envr_info_class* mEnvrInfo;
        /* 0x2C */ stage_vrbox_info_class* mVrboxInfo;
        /* 0x30 */ stage_vrboxcol_info_class* mVrboxcolInfo;
        /* 0x34 */ stage_plight_info_class* mPlightInfo;
        /* 0x38 */ dStage_MapEventInfo_c* mMapEventInfo;
        /* 0x3C */ uint32_t mPaletteNumInfo;
        /* 0x40 */ uint32_t mPselectNumInfo;
        /* 0x44 */ uint32_t mEnvrNumInfo;
        /* 0x48 */ uint32_t mVrboxNumInfo;
        /* 0x4C */ int mVrboxcolNumInfo;
        /* 0x50 */ uint32_t mPlightNumInfo;
        /* 0x54 */ uint16_t mPlayerNum;
        /* 0x56 */ uint16_t field_0x56;
        /* 0x58 */ uint16_t field_0x58;
        /* 0x5A */ uint16_t field_0x5a;
        /* 0x5C */ stage_stag_info_class* mStagInfo;
        /* 0x60 */ stage_scls_info_dummy_class* mSclsInfo;
        /* 0x64 */ dStage_dPnt_c* mPntInfo;
        /* 0x68 */ dStage_dPath_c* mPathInfo;
        /* 0x6C */ dStage_dPnt_c* mPnt2Inf;
        /* 0x70 */ dStage_dPath_c* mPath2Info;
        /* 0x74 */ dStage_SoundInfo_c* mSoundInf;
        /* 0x78 */ dStage_SoundInfo_c* mSoundInfCL;
        /* 0x7C */ dStage_FloorInfo_c* mFloorInfo;
        /* 0x80 */ dStage_MemoryConfig_c* mMemoryConfig;
        /* 0x84 */ dStage_MemoryMap_c* mMemoryMap;
        /* 0x88 */ dStage_Multi_c* mMulti;
        /* 0x8C */ dStage_Multi_c* mOldMulti;
        /* 0x90 */ stage_tresure_class* mTreasure;
        /* 0x94 */ dStage_DMap_c* mDMap;
        /* 0x98 */ stage_tgsc_class* mDrTg;
        /* 0x9C */ stage_tgsc_class* mDoor;
        /* 0xA0 */ dStage_Elst_c* mElst;
    } __attribute__((__packed__));
    static_assert(sizeof(dStage_stageDt_c) == 0xA4);

    struct dStage_roomControl
    {
        uint8_t field_0x0[164];
    } __attribute__((__packed__));

    struct dStage_startStage
    {
        /* 0x0 */ char mStage[8];
        /* 0x8 */ int16_t mPoint;
        /* 0xA */ int8_t mRoomNo;
        /* 0xB */ int8_t mLayer;
        /* 0xC */ int8_t mDarkArea;
#ifdef PLATFORM_WII
        /* 0xD */ int8_t enabled;
#else
        /* 0xD */ uint8_t padding;
#endif  // PLATFORM_WII
    } __attribute__((__packed__));

    struct dStage_nextStage: dStage_startStage
    {
#ifndef PLATFORM_WII
        int8_t enabled;
#endif  // PLATFORM_WII
        uint8_t wipe;
        uint8_t wipe_speed;
    } __attribute__((__packed__));

    struct stage_dzr_header_entry
    {
        /* 0x00 */ char mName[4];
        /* 0x04 */ int32_t mNumEntries;
        /* 0x08 */ stage_actor_data_class* mDzrDataPointer;
    } __attribute__((__packed__)); // size: 0xC

    extern "C"
    {
        /**
         *	@brief Used for treasure initialisation (not just chests)
         *
         *	@return Returns the maximum number of rupees Link can hold in his
         *current wallet
         */
        void setTresure(void* unk1); // Yes they spell it Tresure

        /**
         *  @brief Initialises TRES for a given room
         *
         *  @param chunkTypeInfo Pointer to the TRES chunk metadata
         */
        void roomTresureInit(void* unk1, dzx::ChunkTypeInfo* chunkTypeInfo, int32_t unk3, void* unk4);

        /**
         *  @brief Initialises Actors, can run multiple times per load - Global Based on
         * Room
         *
         *  @param mStatus_roomControl Pointer to roomControl data (unknown)
         *  @param chunkTypeInfo Pointer to dzxHeader
         *  @param unk3 unknown
         *  @param unk4 unknown
         */
        bool actorCommonLayerInit(void* mStatus_roomControl, dzx::ChunkTypeInfo* chunkTypeInfo, int32_t unk3, void* unk4);

        /**
         *  @brief Initialises Actors for current layer, can run multiple times per load
         *
         *  @param mStatus_roomControl Pointer to roomControl data (unknown)
         *  @param chunkTypeInfo Pointer to dzxHeader
         *  @param unk3 unknown
         *  @param unk4 unknown
         */
        bool actorInit(void* mStatus_roomControl, dzx::ChunkTypeInfo* chunkTypeInfo, int32_t unk3, void* unk4);

        /**
         *  @brief Initialises Actors for global layer, can run multiple times per load
         *
         *  @param mStatus_roomControl Pointer to roomControl data (unknown)
         *  @param chunkTypeInfo Pointer to dzxHeader
         *  @param unk3 unknown
         *  @param unk4 unknown
         */
        bool actorInit_always(void* mStatus_roomControl, dzx::ChunkTypeInfo* chunkTypeInfo, int32_t unk3, void* unk4);

        /**
         *  @brief Creates an actor
         *
         *  @param Actor Actor Object
         *  @param ActorMemoryPtr ActorPRMClass allocated for this Actor
         */
        int32_t ActorCreate(dzx::ACTR* actor, dzx::ActorPRMClass* actorMemoryPtr);

        /**
         *  @brief Creates a number of SCOBs defined in a list.
         *
         *  @param stageDt The pointer to the stage data.
         *  @param i_data The pointer to the list of SCOBs to be read in.
         *  @param entryNum The number of entries to be read in.
         *  @param param_3 Unknown at this time.
         */
        int32_t tgscInfoInit(void* stageDt, void* i_data, int32_t entryNum, void* param_3);

        /**
         *  @brief Loads the room file into memory to be used.
         *
         *  @param data A pointer to the data to be loaded.
         *  @param stageDt A pointer to the stage data file.
         *  @param roomNo The current room number.
         */
        void roomLoader(void* data, void* stageDt, int32_t roomNo);

        /**
         *  @brief Loads the stage file into memory to be used.
         *
         *  @param data A pointer to the data to be loaded.
         *  @param stageDt A pointer to the stage data file.
         */
        void stageLoader(void* data, void* stageDt);

        /**
         *  @brief Loads Link into the current stage.
         *
         *  @param stageDt A pointer to the stage data file
         *  @param i_data A pointer to the stage DZR header.
         *  @param num Unknown.
         *  @param raw_data A pointer to the raw data of the area.
         *
         *  @return BOOL returns True if successful and False otherwise.
         */
        int32_t dStage_playerInit(void* stageDt, stage_dzr_header_entry* i_data, int32_t num, void* raw_data);

        /**
         *  @brief Checks to see if time is currently passing on the current stage.
         *
         *  @return Bool returns True if time is passing, otherwise returns False.
         */
        bool GetTimePass();

        /**
         *  @brief Pointer to roomControl data
         */
        extern void* mStatus_roomControl;

        /**
         *  @brief A static value that represents the current room the player is in
         */
        extern int8_t mStayNo;
    }
} // namespace libtp::tp::d_stage
#endif