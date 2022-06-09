#ifndef SYMBOL_DEFINES_H
#define SYMBOL_DEFINES_H

// OS.h
#define mDoPrintf_OSReportInit OSReportInit__Fv
#define mDoPrintf_OSSwitchFiberEx OSSwitchFiberEx__FUlUlUlUlUlUl
#define mDoPrintf_OSVAttention OSVAttention__FPCcP16__va_list_struct

// c_xyz.h
#define cXyz_Zero Zero__4cXyz
#define cXyz_BaseX BaseX__4cXyz
#define cXyz_BaseY BaseY__4cXyz
#define cXyz_BaseZ BaseZ__4cXyz
#define cXyz_BaseXY BaseXY__4cXyz
#define cXyz_BaseXZ BaseXZ__4cXyz
#define cXyz_BaseYZ BaseYZ__4cXyz
#define cXyz_BaseXYZ BaseXYZ__4cXyz
#define cXyz_dt __dt__4cXyzFv
#define cXyz_operator_plus_vec __pl__4cXyzCFRC3Vec
#define cXyz_operator_minus_vec __mi__4cXyzCFRC3Vec
#define cXyz_operator_multiply_float __ml__4cXyzCFf
#define cXyz_operator_multiply_vec __ml__4cXyzCFRC3Vec
#define cXyz_operator_divide_float __dv__4cXyzCFf
#define cXyz_getCrossProduct getCrossProduct__4cXyzCFRC3Vec
#define cXyz_outprod outprod__4cXyzCFRC3Vec
#define cXyz_norm norm__4cXyzCFv
#define cXyz_normZP normZP__4cXyzCFv
#define cXyz_normZC normZC__4cXyzCFv
#define cXyz_normalize normalize__4cXyzFv
#define cXyz_normalizeZP normalizeZP__4cXyzFv
#define cXyz_normalizeRS normalizeRS__4cXyzFv
#define cXyz_operator_equal_equal_vec __eq__4cXyzCFRC3Vec
#define cXyz_operator_not_equal_vec __ne__4cXyzCFRC3Vec
#define cXyz_isZero isZero__4cXyzCFv
#define cXyz_atan2sX_Z atan2sX_Z__4cXyzCFv
#define cXyz_atan2sY_XZ atan2sY_XZ__4cXyzCFv

// c_sxyz.h
#define csXyz_dt __dt__5csXyzFv
#define csXyz_ct __ct__5csXyzFsss
#define csXyz_operator_plus_csXyz __pl__5csXyzFR5csXyz
#define csXyz_operator_plus_equal_csXyz __apl__5csXyzFR5csXyz
#define csXyz_operator_minus_csXyz __mi__5csXyzFR5csXyz
#define csXyz_operator_multiply_float __ml__5csXyzFf

// JKRHeap.h
#define JKRHeap_vt __vt__7JKRHeap
#define JKRHeap_sSystemHeap sSystemHeap__7JKRHeap
#define JKRHeap_sCurrentHeap sCurrentHeap__7JKRHeap
#define JKRHeap_sRootHeap sRootHeap__7JKRHeap
#define JKRHeap_mErrorHandler mErrorHandler__7JKRHeap
#define JKRHeap_mCodeStart mCodeStart__7JKRHeap
#define JKRHeap_mCodeEnd mCodeEnd__7JKRHeap
#define JKRHeap_mUserRamStart mUserRamStart__7JKRHeap
#define JKRHeap_mUserRamEnd mUserRamEnd__7JKRHeap
#define JKRHeap_mMemorySize mMemorySize__7JKRHeap
#define JKRHeap_ct __ct__7JKRHeapFPvUlP7JKRHeapb
#define JKRHeap_dt __dt__7JKRHeapFv
#define JKRHeap_becomeSystemHeap becomeSystemHeap__7JKRHeapFv
#define JKRHeap_becomeCurrentHeap becomeCurrentHeap__7JKRHeapFv
#define JKRHeap_destroy destroy__7JKRHeapFv
#define JKRHeap_alloc2 alloc__7JKRHeapFUli
#define JKRHeap_free2 free__7JKRHeapFPv
#define JKRHeap_freeAll freeAll__7JKRHeapFv
#define JKRHeap_freeTail freeTail__7JKRHeapFv
#define JKRHeap_resize2 resize__7JKRHeapFPvUl
#define JKRHeap_getSize2 getSize__7JKRHeapFPv
#define JKRHeap_getFreeSize getFreeSize__7JKRHeapFv
#define JKRHeap_getMaxFreeBlock getMaxFreeBlock__7JKRHeapFv
#define JKRHeap_getTotalFreeSize getTotalFreeSize__7JKRHeapFv
#define JKRHeap_changeGroupID changeGroupID__7JKRHeapFUc
#define JKRHeap_getMaxAllocatableSize getMaxAllocatableSize__7JKRHeapFi
#define JKRHeap_find find__7JKRHeapCFPv
#define JKRHeap_findAllHeap findAllHeap__7JKRHeapCFPv
#define JKRHeap_dispose_subroutine dispose_subroutine__7JKRHeapFUlUl
#define JKRHeap_dispose1 dispose__7JKRHeapFPvUl
#define JKRHeap_dispose2 dispose__7JKRHeapFPvPv
#define JKRHeap_dispose3 dispose__7JKRHeapFv
#define JKRHeap_setErrorFlag setErrorFlag__7JKRHeapFb
#define JKRHeap_isSubHeap isSubHeap__7JKRHeapCFP7JKRHeap
#define JKRHeap_callAllDisposer callAllDisposer__7JKRHeapFv
#define JKRHeap_do_changeGroupID do_changeGroupID__7JKRHeapFUc
#define JKRHeap_do_getCurrentGroupId do_getCurrentGroupId__7JKRHeapFv
#define JKRHeap_state_register state_register__7JKRHeapCFPQ27JKRHeap6TStateUl
#define JKRHeap_state_compare state_compare__7JKRHeapCFRCQ27JKRHeap6TStateRCQ27JKRHeap6TState
#define JKRHeap_state_dump state_dump__7JKRHeapCFRCQ27JKRHeap6TState
#define JKRHeap_initArena initArena__7JKRHeapFPPcPUli
#define JKRHeap_alloc1 alloc__7JKRHeapFUliP7JKRHeap
#define JKRHeap_free1 free__7JKRHeapFPvP7JKRHeap
#define JKRHeap_resize1 resize__7JKRHeapFPvUlP7JKRHeap
#define JKRHeap_getSize1 getSize__7JKRHeapFPvP7JKRHeap
#define JKRHeap_findFromRoot findFromRoot__7JKRHeapFPv
#define JKRHeap_copyMemory copyMemory__7JKRHeapFPvPvUl
#define JKRHeap_JKRDefaultMemoryErrorRoutine JKRDefaultMemoryErrorRoutine__FPvUli
#define JKRHeap_setErrorHandler setErrorHandler__7JKRHeapFPFPvUli_v
#define JKRHeap_operator_new __nw__FUl
#define JKRHeap_operator_new_alignment __nw__FUli
#define JKRHeap_operator_new_heap __nw__FUlP7JKRHeapi
#define JKRHeap_operator_new_array __nwa__FUl
#define JKRHeap_operator_new_alignment_array __nwa__FUli
#define JKRHeap_operator_new_heap_array __nwa__FUlP7JKRHeapi
#define JKRHeap_operator_delete __dl__FPv
#define JKRHeap_operator_delete_array __dla__FPv

// JKRDisposer.h
#define JKRDisposer_ct __ct__11JKRDisposerFv
#define JKRDisposer_dt __dt__11JKRDisposerFv
#define JKRDisposer_vt __vt__11JKRDisposer

// JKRFileLoader.h
#define JKRFileLoader_sVolumeList sVolumeList__13JKRFileLoader
#define JKRFileLoader_sCurrentVolume sCurrentVolume__13JKRFileLoader
#define JKRFileLoader_ct __ct__13JKRFileLoaderFv
#define JKRFileLoader_dt1 __dt__13JKRFileLoaderFv
// #define JKRFileLoader_dt2 __dt__24JSUList<13JKRFileLoader>Fv
#define JKRFileLoader_unmount unmount__13JKRFileLoaderFv
#define JKRFileLoader_getGlbResource1 getGlbResource__13JKRFileLoaderFPCc
#define JKRFileLoader_getGlbResource2 getGlbResource__13JKRFileLoaderFPCcP13JKRFileLoader
#define JKRFileLoader_removeResource removeResource__13JKRFileLoaderFPvP13JKRFileLoader
#define JKRFileLoader_detachResource detachResource__13JKRFileLoaderFPvP13JKRFileLoader
#define JKRFileLoader_findVolume findVolume__13JKRFileLoaderFPPCc
#define JKRFileLoader_fetchVolumeName fetchVolumeName__13JKRFileLoaderFPclPCc

// JKRFileFinder.h
#define JKRDvdFinder_vt __vt__12JKRDvdFinder
#define JKRArcFinder_vt __vt__12JKRArcFinder
#define JKRFileFinder_vt __vt__13JKRFileFinder
#define JKRFileFinder_dt __dt__13JKRFileFinderFv
#define JKRArcFinder_ct __ct__12JKRArcFinderFP10JKRArchivell
#define JKRArcFinder_dt __dt__12JKRArcFinderFv
#define JKRArcFinder_findNextFile findNextFile__12JKRArcFinderFv
#define JKRDvdFinder_ct __ct__12JKRDvdFinderFPCc
#define JKRDvdFinder_dt __dt__12JKRDvdFinderFv
#define JKRDvdFinder_findNextFile findNextFile__12JKRDvdFinderFv

// JKRFile.h
#define JKRFile_read read__7JKRFileFPvll

// JSUList.h
#define JSUPtrLink_ct __ct__10JSUPtrLinkFPv
#define JSUPtrLink_dt __dt__10JSUPtrLinkFv
#define JSUPtrList_ct __ct__10JSUPtrListFb
#define JSUPtrList_dt __dt__10JSUPtrListFv
#define JSUPtrList_initiate initiate__10JSUPtrListFv
#define JSUPtrList_setFirst setFirst__10JSUPtrListFP10JSUPtrLink
#define JSUPtrList_append append__10JSUPtrListFP10JSUPtrLink
#define JSUPtrList_prepend prepend__10JSUPtrListFP10JSUPtrLink
#define JSUPtrList_insert insert__10JSUPtrListFP10JSUPtrLinkP10JSUPtrLink
#define JSUPtrList_remove remove__10JSUPtrListFP10JSUPtrLink
#define JSUPtrList_getNthLink getNthLink__10JSUPtrListCFUl

#endif