/*
 *  See License file
 */


#ifndef ICELIB_INTERN_H
#define ICELIB_INTERN_H

#include "icelib.h"
#include "icelibtypes.h"
#include "macro.h"

#ifdef __cplusplus
extern "C" {
#endif


#define ICELIB_log1(pCallbacks, level, message, arg1) ICELIB_log_(pCallbacks, \
                                                                  level, \
                                                                  __func__, \
                                                                  __FILE__, \
                                                                  __LINE__, \
                                                                  message, \
                                                                  arg1)

#define ICELIB_log(pCallbacks, level, message) ICELIB_log_(pCallbacks,  \
                                                           level,       \
                                                           __func__, \
                                                           __FILE__,    \
                                                           __LINE__,    \
                                                           message)


FUNC_DECL char* ICELIB_strncpy(char*       dst,
               const char* src,
               int         maxlength);
FUNC_DECL char* ICELIB_strncat(char*       dst,
               const char* src,
               int         maxlength);

FUNC_DECL uint64_t ICELIB_random64(void);
FUNC_DECL ICELIB_uint128_t ICELIB_random128(void);

FUNC_DECL int ICELIB_compareTransactionId(const StunMsgId* pid1,
                            const StunMsgId* pid2);

FUNC_DECL bool ICELIB_veryfyICESupportOnStream(const ICELIB_INSTANCE*  pInstance,
                                const ICE_MEDIA_STREAM* stream);

FUNC_DECL bool ICELIB_verifyICESupport(const ICELIB_INSTANCE* pInstance,
                        const ICE_MEDIA*       iceRemoteMedia);

FUNC_DECL const char* pICELIB_splitUfragPair(const char* pUfragPair,
                       size_t*     pColonIndex);

FUNC_DECL bool ICELIB_compareUfragPair(const char* pUfragPair,
                        const char* pUfragLeft,
                        const char* pUfragRight);

FUNC_DECL void ICELIB_logStringBasic(const ICELIB_CALLBACK_LOG* pCallbackLog,
                      ICELIB_logLevel            logLevel,
                      const char*                str);

FUNC_DECL void ICELIB_log_(const ICELIB_CALLBACK_LOG* pCallbackLog,
            ICELIB_logLevel            logLevel,
            const char*                function,
            const char*                file,
            unsigned int               line,
            const char*                fmt,
            ...);

FUNC_DECL void ICELIB_startAllStoppingTimers(ICELIB_INSTANCE* pInstance);
FUNC_DECL void ICELIB_tickAllStoppingTimers(ICELIB_INSTANCE* pInstance);

FUNC_DECL void ICELIB_longToIcechar(long  data,
                     char* b64,
                     int   maxLength);
FUNC_DECL void ICELIB_createRandomString(char* dst,
                          int   maxlength);

FUNC_DECL uint32_t ICELIB_calculatePriority(ICE_CANDIDATE_TYPE type,
                         ICE_TRANSPORT      transport,
                         uint16_t           compid,
                         uint16_t           local_pref);

FUNC_DECL bool ICELIB_isEmptyCandidate(const ICE_CANDIDATE* pCandidate);
FUNC_DECL bool ICELIB_isNonValidCandidate(const ICE_CANDIDATE* pCandidate);
FUNC_DECL bool ICELIB_isEmptyOrNonValidCandidate(const ICE_CANDIDATE* pCandidate);

FUNC_DECL void ICELIB_clearRedundantCandidates(ICE_CANDIDATE candidates[]);
FUNC_DECL void ICELIB_compactTable(ICE_CANDIDATE candidates[]);
FUNC_DECL int ICELIB_countCandidates(ICE_CANDIDATE candidates[]);

FUNC_DECL int ICELIB_eliminateRedundantCandidates(ICE_CANDIDATE candidates[]);

FUNC_DECL void ICELIB_EliminateRedundantCandidates(ICELIB_INSTANCE* pInstance);

FUNC_DECL void ICELIB_fillLocalCandidate(ICE_CANDIDATE*         cand,
                          uint32_t               componentId,
                          int                    socket,
                          const struct socket_addr* connectionAddr,
                          const struct socket_addr* relAddr,
                          ICE_TRANSPORT          transport,
                          ICE_CANDIDATE_TYPE     candType,
                          uint16_t               local_pref);

FUNC_DECL void ICELIB_fillRemoteCandidate(ICE_CANDIDATE*     cand,
                           uint32_t           componentId,
                           const char*        foundation,
                           uint32_t           foundationLen,
                           uint32_t           priority,
                           struct socket_addr*   connectionAddr,
                           ICE_TRANSPORT      transport,
                           ICE_CANDIDATE_TYPE candType);

FUNC_DECL int ICELIB_candidateSort(const void* x,
                     const void* y);

FUNC_DECL const char* ICELIB_toString_CheckListState(ICELIB_CHECKLIST_STATE state);
FUNC_DECL const char* ICELIB_toString_CheckListPairState(ICELIB_PAIR_STATE state);

FUNC_DECL void ICELIB_resetCheckList(ICELIB_CHECKLIST* pCheckList,
                      unsigned int      checkListId);
FUNC_DECL void ICELIB_resetPair(ICELIB_LIST_PAIR* pPair);
FUNC_DECL void ICELIB_resetCandidate(ICE_CANDIDATE* pCandidate);

FUNC_DECL int ICELIB_comparePairsCL(const void* cp1,
                      const void* cp2);
FUNC_DECL void ICELIB_computePairPriority(ICELIB_LIST_PAIR* pCheckListPair,
                           bool              iceControlling);

FUNC_DECL bool ICELIB_isComponentIdPresent(const ICELIB_COMPONENTLIST* pComponentList,
                            uint32_t                    componentId);

FUNC_DECL bool ICELIB_addComponentId(ICELIB_COMPONENTLIST* pComponentList,
                      uint32_t              componentId);

FUNC_DECL bool ICELIB_addComponentIdIfUnique(ICELIB_COMPONENTLIST* pComponentList,
                              uint32_t              componentId);

FUNC_DECL bool ICELIB_collectEffectiveCompontIds(ICELIB_CHECKLIST* pCheckList);

FUNC_DECL void ICELIB_prunePairsReplaceWithBase(ICELIB_CHECKLIST*    pCheckList,
                                 const ICE_CANDIDATE* pBbaseServerReflexiveRtp,
                                 const ICE_CANDIDATE* pBaseServerReflexiveRtcp);

FUNC_DECL bool ICELIB_prunePairsIsEqual(const ICELIB_LIST_PAIR* pPair1,
                         const ICELIB_LIST_PAIR* pPair2);

FUNC_DECL bool ICELIB_prunePairsIsClear(const ICELIB_LIST_PAIR* pPair);
FUNC_DECL void ICELIB_prunePairsClear(ICELIB_LIST_PAIR* pPair);
FUNC_DECL void ICELIB_prunePairsClearDuplicates(ICELIB_CHECKLIST* pCheckList);
FUNC_DECL void ICELIB_prunePairsCompact(ICELIB_CHECKLIST* pCheckList);
FUNC_DECL unsigned intICELIB_prunePairsCountPairs(ICELIB_LIST_PAIR pairs[]);

FUNC_DECL void ICELIB_computeStatesSetState(ICELIB_CHECKLIST*    pCheckList,
                             ICELIB_PAIR_STATE    state,
                             ICELIB_CALLBACK_LOG* pCallbackLog);

FUNC_DECL void ICELIB_makeAllCheckLists(ICELIB_INSTANCE* pInstance);

FUNC_DECL bool ICELIB_isPairAddressMatchInChecklist(ICELIB_CHECKLIST* pCheckList,
                                     ICELIB_LIST_PAIR* pair);

FUNC_DECL ICELIB_LIST_PAIR* ICELIB_getPairById(ICELIB_CHECKLIST* pCheckList,
                   uint32_t          pairId);

FUNC_DECL bool ICELIB_isTriggeredFifoPairPresent(ICELIB_TRIGGERED_FIFO* pFifo,
                                  ICELIB_LIST_PAIR*      pPair,
                                  ICELIB_CALLBACK_LOG*   pCallbackLog);

FUNC_DECL bool ICELIB_triggeredFifoPutIfNotPresent(ICELIB_TRIGGERED_FIFO* pFifo,
                                    ICELIB_LIST_PAIR*      pPair,
                                    ICELIB_CALLBACK_LOG*   pCallbackLog);

FUNC_DECL void ICELIB_triggeredFifoRemove(ICELIB_TRIGGERED_FIFO* pFifo,
                           ICELIB_LIST_PAIR*      pPair);

FUNC_DECL void ICELIB_triggeredfifoIteratorConstructor(
  ICELIB_TRIGGERED_FIFO_ITERATOR* pIterator,
  ICELIB_TRIGGERED_FIFO*          pFifo);

FUNC_DECL ICELIB_LIST_PAIR* pICELIB_triggeredfifoIteratorNext(ICELIB_CHECKLIST*               pCheckList,
                                  ICELIB_CALLBACK_LOG*            pCallbackLog,
                                  ICELIB_TRIGGERED_FIFO_ITERATOR* pIterator);

FUNC_DECL void ICELIB_resetStreamController(ICELIB_STREAM_CONTROLLER* pStreamController,
                             unsigned int              tickIntervalMS);

FUNC_DECL ICELIB_LIST_PAIR* pICELIB_findPairToScedule(ICELIB_STREAM_CONTROLLER* pController,
                          ICELIB_CALLBACK_LOG*      pCallbackLog);

FUNC_DECL bool ICELIB_insertTransactionId(ICELIB_LIST_PAIR* pair,
                           StunMsgId         id);

FUNC_DECL void ICELIB_scheduleCheck(ICELIB_INSTANCE*  pInstance,
                     ICELIB_CHECKLIST* pCheckList,
                     ICELIB_LIST_PAIR* pPair);

FUNC_DECL void ICELIB_tickStreamController(ICELIB_INSTANCE* pInstance);

FUNC_DECL void ICELIB_unfreezeAllFrozenCheckLists(ICELIB_STREAM_CONTROLLER streamControllers[],
                                   unsigned int             numberOfMediaStreams,
                                   ICELIB_CALLBACK_LOG*     pCallbackLog);

FUNC_DECL void ICELIB_recomputeAllPairPriorities(ICELIB_STREAM_CONTROLLER streamControllers[],
                                  unsigned int             numberOfMediaStreams,
                                  bool                     iceControlling);

FUNC_DECL unsigned int ICELIB_findStreamByAddress(ICELIB_STREAM_CONTROLLER streamControllers[],
                           unsigned int             numberOfMediaStreams,
                           int                      proto,
                           const struct socket_addr*   pHostAddr);

FUNC_DECL int ICELIB_listCompareVL(const void* cp1,
                     const void* cp2);
FUNC_DECL void ICELIB_listSortVL(ICELIB_LIST_VL* pList);
FUNC_DECL void ICELIB_listConstructorVL(ICELIB_LIST_VL* pList);
FUNC_DECL unsigned int ICELIB_listCountVL(const ICELIB_LIST_VL* pList);

FUNC_DECL ICELIB_VALIDLIST_ELEMENT* pICELIB_listGetElementVL(ICELIB_LIST_VL* pList,
                         unsigned int    index);
FUNC_DECL bool ICELIB_listAddBackVL(ICELIB_LIST_VL*           pList,
                     ICELIB_VALIDLIST_ELEMENT* pPair);

FUNC_DECL bool ICELIB_listInsertVL(ICELIB_LIST_VL*           pList,
                    ICELIB_VALIDLIST_ELEMENT* pPair);

FUNC_DECL void ICELIB_validListConstructor(ICELIB_VALIDLIST* pValidList);

FUNC_DECL ICELIB_VALIDLIST_ELEMENT* pICELIB_validListGetElement(ICELIB_VALIDLIST* pValidList,
                            unsigned int      index);

FUNC_DECL uint32_t ICELIB_validListLastPairId(const ICELIB_VALIDLIST* pValidList);

FUNC_DECL void ICELIB_validListIteratorConstructor(ICELIB_VALIDLIST_ITERATOR* pIterator,
                                    ICELIB_VALIDLIST*          pValidList);

FUNC_DECL ICELIB_VALIDLIST_ELEMENT* pICELIB_validListIteratorNext(ICELIB_VALIDLIST_ITERATOR* pIterator);
FUNC_DECL ICELIB_VALIDLIST_ELEMENT* pICELIB_validListFindPairById(ICELIB_VALIDLIST* pValidList,
                              uint32_t          pairId);

FUNC_DECL void ICELIB_storeRemoteCandidates(ICELIB_INSTANCE* pInstance);

FUNC_DECL bool ICELIB_validListNominatePair(ICELIB_VALIDLIST*      pValidList,
                             ICELIB_LIST_PAIR*      pPair,
                             const struct socket_addr* pMappedAddress);

FUNC_DECL bool ICELIB_validListAddBack(ICELIB_VALIDLIST*         pValidList,
                        ICELIB_VALIDLIST_ELEMENT* pPair);

FUNC_DECL bool ICELIB_validListInsert(ICELIB_VALIDLIST*         pValidList,
                       ICELIB_VALIDLIST_ELEMENT* pPair);

FUNC_DECL unsigned int ICELIB_countNominatedPairsInValidList(ICELIB_VALIDLIST* pValidList);

FUNC_DECL ICELIB_VALIDLIST_ELEMENT* ICELIB_findElementInValidListByid(ICELIB_VALIDLIST* pValidList,
                                  uint32_t          id);

FUNC_DECL bool ICELIB_isPairForEachComponentInValidList(ICELIB_VALIDLIST*           pValidList,
                                         const ICELIB_COMPONENTLIST* pComponentList);

FUNC_DECL void ICELIB_unfreezePairsByMatchingFoundation(ICELIB_VALIDLIST*    pValidList,
                                         ICELIB_CHECKLIST*    pCheckList,
                                         ICELIB_CALLBACK_LOG* pCallbackLog);

FUNC_DECL bool ICELIB_atLeastOneFoundationMatch(ICELIB_VALIDLIST* pValidList,
                                 ICELIB_CHECKLIST* pCheckList);

FUNC_DECL void ICELIB_resetCallbacks(ICELIB_CALLBACKS* pCallbacks);

FUNC_DECL void ICELIB_callbackConstructor(ICELIB_CALLBACKS* pCallbacks,
                           ICELIB_INSTANCE*  pInstance);

FUNC_DECL bool ICELIB_checkSourceAndDestinationAddr(const ICELIB_LIST_PAIR* pPair,
                                     const struct socket_addr*  source,
                                     const struct socket_addr*  destination);

FUNC_DECL ICE_CANDIDATE* ICELIB_addDiscoveredCandidate(ICE_MEDIA_STREAM*    pMediaStream,
                              const ICE_CANDIDATE* pPeerCandidate);

FUNC_DECL void ICELIB_makePeerLocalReflexiveCandidate(ICE_CANDIDATE*         pPeerCandidate,
                                       ICELIB_CALLBACK_LOG*   pCallbackLog,
                                       const struct socket_addr* pMappedAddress,
                                       ICE_TRANSPORT          transport,
                                       int                    socketfd,
                                       uint16_t               componentId);

FUNC_DECL void
ICELIB_makePeerRemoteReflexiveCandidate(ICE_CANDIDATE*         pPeerCandidate,
                                        ICELIB_CALLBACK_LOG*   pCallbackLog,
                                        const struct socket_addr* sourceAddr,
                                        ICE_TRANSPORT          transport,
                                        uint32_t               peerPriority,
                                        uint16_t               componentId);

FUNC_DECL ICELIB_LIST_PAIR*
pICELIB_findPairInCheckList(ICELIB_CHECKLIST*       pCheckList,
                            const ICELIB_LIST_PAIR* pPair);

FUNC_DECL bool
ICELIB_isAllPairsFailedOrSucceded(const ICELIB_CHECKLIST* pCheckList);

FUNC_DECL  void
ICELIB_updateCheckListState(ICELIB_CHECKLIST*        pCheckList,
                            ICELIB_VALIDLIST*        pValidList,
                            ICELIB_STREAM_CONTROLLER streamControllers[],
                            unsigned int             numberOfMediaStreams,
                            ICELIB_CALLBACK_LOG*     pCallbackLog);

FUNC_DECL  void
ICELIB_processSuccessResponse(ICELIB_INSTANCE*        pInstance,
                              const ICE_MEDIA_STREAM* pLocalMediaStream,
                              ICE_MEDIA_STREAM*       pDiscoveredLocalCandidates,
                              ICELIB_CHECKLIST*       pCurrentCheckList,
                              ICELIB_VALIDLIST*       pValidList,
                              ICELIB_LIST_PAIR*       pPair,
                              const struct socket_addr*  pMappedAddress,
                              bool                    iceControlling);

FUNC_DECL  void
ICELIB_sendBindingResponse(ICELIB_INSTANCE*       pInstance,
                           int                    sockfd,
                           int                    proto,
                           const struct socket_addr* source,
                           const struct socket_addr* destination,
                           const struct socket_addr* MappedAddress,
                           uint32_t               userValue1,
                           uint32_t               userValue2,
                           uint16_t               componentId,
                           uint16_t               errorResponse,
                           StunMsgId              transactionId,
                           bool                   useRelay,
                           const char*            pPasswd);

FUNC_DECL  void
ICELIB_processSuccessRequest(ICELIB_INSTANCE*        pInstance,
                             StunMsgId               transactionId,
                             int                     sockfd,
                             int                     proto,
                             const struct socket_addr*  source,
                             const struct socket_addr*  destination,
                             const struct socket_addr*  relayBaseAddr,
                             uint32_t                userValue1,
                             uint32_t                userValue2,
                             uint32_t                peerPriority,
                             const ICE_MEDIA_STREAM* pLocalMediaStream,
                             const ICE_MEDIA_STREAM* pRemoteMediaStream,
                             ICE_MEDIA_STREAM*       pDiscoveredRemoteCandidates,
                             ICE_MEDIA_STREAM*       pDiscoveredLocalCandidates,
                             ICELIB_CHECKLIST*       pCurrentCheckList,
                             ICELIB_VALIDLIST*       pCurrentValidList,
                             ICELIB_TRIGGERED_FIFO*  pTriggeredFifo,
                             bool                    iceControlling,
                             bool                    useCandidate,
                             bool                    fromRelay,
                             uint16_t                componentId);

FUNC_DECL  void
ICELIB_processIncommingLite(ICELIB_INSTANCE*       pInstance,
                            uint32_t               userValue1,
                            uint32_t               userValue2,
                            const char*            pUfragPair,
                            uint32_t               peerPriority,
                            bool                   useCandidate,
                            bool                   iceControlling,
                            bool                   iceControlled,
                            uint64_t               tieBreaker,
                            StunMsgId              transactionId,
                            const struct socket_addr* source,
                            const struct socket_addr* destination,
                            uint16_t               componentId);

FUNC_DECL  void
ICELIB_processIncommingFull(ICELIB_INSTANCE*       pInstance,
                            uint32_t               userValue1,
                            uint32_t               userValue2,
                            const char*            pUfragPair,
                            uint32_t               peerPriority,
                            bool                   useCandidate,
                            bool                   iceControlling,
                            bool                   iceControlled,
                            uint64_t               tieBreaker,
                            StunMsgId              transactionId,
                            int                    sockfd,
                            int                    proto,
                            const struct socket_addr* source,
                            const struct socket_addr* destination,
                            bool                   fromRelay,
                            const struct socket_addr* relayBaseAddr,
                            uint16_t               componentId);

FUNC_DECL bool
ICELIB_isNominatingCriteriaMet(ICELIB_VALIDLIST* pValidList,
                               ICELIB_CHECKLIST* pChecklist);

FUNC_DECL bool
ICELIB_isNominatingCriteriaMetForAllMediaStreams(ICELIB_INSTANCE* pInstance);

FUNC_DECL  void
ICELIB_stopChecks(ICELIB_INSTANCE*       pInstance,
                  ICELIB_CHECKLIST*      pCheckList,
                  ICELIB_TRIGGERED_FIFO* pTriggeredChecksFifo);

FUNC_DECL ICELIB_LIST_PAIR*
pICELIB_pickValidPairForNominationNormalMode(ICELIB_VALIDLIST* pValidList,
                                             uint32_t          componentId);

FUNC_DECL ICELIB_LIST_PAIR*
pICELIB_pickValidPairForNomination(ICELIB_VALIDLIST* pValidList,
                                   uint32_t          componentId);


FUNC_DECL  void
ICELIB_enqueueValidPair(ICELIB_TRIGGERED_FIFO* pTriggeredChecksFifo,
                        ICELIB_CHECKLIST*      pCheckList,
                        ICELIB_CALLBACK_LOG*   pCallbackLog,
                        ICELIB_LIST_PAIR*      pValidPair);

FUNC_DECL  void
ICELIB_nominateAggressive(ICELIB_INSTANCE* pInstance);
FUNC_DECL  void
ICELIB_nominateRegularIfComplete(ICELIB_INSTANCE* pInstance);

FUNC_DECL  void
ICELIB_removePairFromCheckList(ICELIB_CHECKLIST*    pCheckList,
                               ICELIB_LIST_PAIR*    pPair,
                               ICELIB_CALLBACK_LOG* pCallbackLog);

FUNC_DECL  void
ICELIB_removeWaitingAndFrozenByComponentFromCheckList(
  ICELIB_CHECKLIST*    pCheckList,
  uint32_t             componentId,
  ICELIB_CALLBACK_LOG* pCallbackLog);

FUNC_DECL  void
ICELIB_removeWaitingAndFrozenByComponentFromTriggeredChecksFifo(
  ICELIB_CHECKLIST*      pCheckList,
  ICELIB_TRIGGERED_FIFO* pTriggeredChecksFifo,
  ICELIB_CALLBACK_LOG*   pCallbackLog,
  uint32_t               componentId);

FUNC_DECL  void
ICELIB_removeWaitingAndFrozen(ICELIB_CHECKLIST*      pCheckList,
                              ICELIB_VALIDLIST*      pValidList,
                              ICELIB_TRIGGERED_FIFO* pTriggeredChecksFifo,
                              ICELIB_CALLBACK_LOG*   pCallbackLog);

FUNC_DECL  void
ICELIB_ceaseRetransmissions(ICELIB_CHECKLIST*      pCheckList,
                            ICELIB_VALIDLIST*      pValidList,
                            ICELIB_TRIGGERED_FIFO* pTriggeredChecksFifo);

FUNC_DECL  void
ICELIB_updateCheckListStateConcluding(ICELIB_INSTANCE*       pInstance,
                                      ICELIB_CHECKLIST*      pCheckList,
                                      ICELIB_VALIDLIST*      pValidList,
                                      ICELIB_TRIGGERED_FIFO* pTriggeredChecksFifo,
                                      ICELIB_CALLBACK_LOG*   pCallbackLog);

FUNC_DECL  void
ICE_concludeFullIfComplete(ICELIB_INSTANCE* pInstance);
FUNC_DECL  void
ICE_concludingLite(ICELIB_INSTANCE* pInstance);
FUNC_DECL  void
ICELIB_concludeICEProcessingIfComplete(ICELIB_INSTANCE* pInstance);

FUNC_DECL  void
ICELIB_resetIceInstance(ICELIB_INSTANCE* pInstance);
FUNC_DECL  void
ICELIB_resetAllStreamControllers(ICELIB_INSTANCE* pInstance);

FUNC_DECL uint32_t
ICELIB_getWeightTimeMultiplier(ICELIB_INSTANCE* pInstance);


FUNC_DECL  void
ICELIB_PasswordUpdate(ICELIB_INSTANCE* pInstance);

FUNC_DECL unsigned int
ICELIB_numberOfMediaStreams(ICELIB_INSTANCE* pInstance);

FUNC_DECL  void
ICELIB_doKeepAlive(ICELIB_INSTANCE* pInstance);

FUNC_DECL  void
ICELIB_generateTransactionId(StunMsgId* transactionId);

FUNC_DECL char*
ICELIB_makeUsernamePair(char*       dst,
                        int         maxlength,
                        const char* ufrag1,
                        const char* ufrag2);

FUNC_DECL uint64_t
ICELIB_makeTieBreaker(void);

FUNC_DECL  void
ICELIB_createUfrag (char* dst,
                    int   maxLength);
FUNC_DECL  void
ICELIB_createPasswd(char* dst,
                    int   maxLength);

FUNC_DECL  void
ICELIB_createFoundation(char*              dst,
                        ICE_CANDIDATE_TYPE type,
                        ICE_TRANSPORT      transport,
                        int                socketfd,
                        size_t             maxlength);

FUNC_DECL  void
ICELIB_removChecksFromCheckList(ICELIB_CHECKLIST* pCheckList);

FUNC_DECL  void
ICELIB_resetCheckList(ICELIB_CHECKLIST* pCheckList,
                      unsigned int      checkListId);

FUNC_DECL  void
ICELIB_resetCandidate(ICE_CANDIDATE* pCandidate);

FUNC_DECL  void
ICELIB_saveUfragPasswd(ICELIB_CHECKLIST*       pCheckList,
                       const ICE_MEDIA_STREAM* pLocalMediaStream,
                       const ICE_MEDIA_STREAM* pRemoteMediaStream);

FUNC_DECL  void
ICELIB_formPairs(ICELIB_CHECKLIST*       pCheckList,
                 ICELIB_CALLBACK_LOG*    pCallbackLog,
                 const ICE_MEDIA_STREAM* pLocalMediaStream,
                 const ICE_MEDIA_STREAM* pRemoteMediaStream,
                 unsigned int            maxPairs);

FUNC_DECL uint64_t
ICELIB_pairPriority(uint32_t G,
                    uint32_t D);

FUNC_DECL  void
ICELIB_computeListPairPriority(ICELIB_CHECKLIST* pCheckList,
                               bool              iceControlling);

FUNC_DECL  void
ICELIB_sortPairsCL(ICELIB_CHECKLIST* pCheckList);

FUNC_DECL bool
ICELIB_findReflexiveBaseAddresses(
  const ICE_CANDIDATE**   ppBaseServerReflexiveRtp,
  const ICE_CANDIDATE**   ppBaseServerReflexiveRtcp,
  const ICE_MEDIA_STREAM* pLocalMediaStream);

FUNC_DECL  void
ICELIB_prunePairs(ICELIB_CHECKLIST*    pCheckList,
                  const ICE_CANDIDATE* pBbaseServerReflexiveRtp,
                  const ICE_CANDIDATE* pBaseServerReflexiveRtcp);

FUNC_DECL  void
ICELIB_computeStatesSetWaitingFrozen(ICELIB_CHECKLIST*    pCheckList,
                                     ICELIB_CALLBACK_LOG* pCallbackLog);

FUNC_DECL bool
ICELIB_makeCheckList(ICELIB_CHECKLIST*       pCheckList,
                     ICELIB_CALLBACK_LOG*    pCallbackLog,
                     const ICE_MEDIA_STREAM* pLocalMediaStream,
                     const ICE_MEDIA_STREAM* pRemoteMediaStream,
                     bool                    iceControlling,
                     unsigned int            maxPairs,
                     unsigned int            checkListId);

FUNC_DECL bool
ICELIB_insertIntoCheckList(ICELIB_CHECKLIST* pCheckList,
                           ICELIB_LIST_PAIR* pPair);

FUNC_DECL ICELIB_LIST_PAIR*
pICELIB_findPairByState(ICELIB_CHECKLIST* pCheckList,
                        ICELIB_PAIR_STATE pairState);

FUNC_DECL ICELIB_LIST_PAIR*
pICELIB_chooseOrdinaryPair(ICELIB_CHECKLIST* pCheckList);

FUNC_DECL bool
ICELIB_isActiveCheckList(const ICELIB_CHECKLIST* pCheckList);
FUNC_DECL bool
ICELIB_isFrozenCheckList(const ICELIB_CHECKLIST* pCheckList);

FUNC_DECL  void
ICELIB_unfreezeFrozenCheckList(ICELIB_CHECKLIST*    pCheckList,
                               ICELIB_CALLBACK_LOG* pCallbackLog);
FUNC_DECL  void
ICELIB_unfreezePairsByFoundation(ICELIB_CHECKLIST*    pCheckList,
                                 const char           pairFoundationToMatch[],
                                 ICELIB_CALLBACK_LOG* pCallbackLog);

FUNC_DECL  void
ICELIB_fifoClear(ICELIB_TRIGGERED_FIFO* pFifo);
FUNC_DECL unsigned int
ICELIB_fifoCount(const ICELIB_TRIGGERED_FIFO* pFifo);
FUNC_DECL bool
ICELIB_fifoIsEmpty(const ICELIB_TRIGGERED_FIFO* pFifo);
FUNC_DECL bool
ICELIB_fifoIsFull(const ICELIB_TRIGGERED_FIFO* pFifo);
FUNC_DECL bool
ICELIB_fifoPut(ICELIB_TRIGGERED_FIFO* pFifo,
               ICELIB_FIFO_ELEMENT    element);
FUNC_DECL ICELIB_FIFO_ELEMENT
ICELIB_fifoGet(ICELIB_TRIGGERED_FIFO* pFifo);

FUNC_DECL  void
ICELIB_fifoIteratorConstructor(ICELIB_TRIGGERED_FIFO_ITERATOR* pIterator,
                               ICELIB_TRIGGERED_FIFO*          pFifo);
FUNC_DECL ICELIB_FIFO_ELEMENT*
pICELIB_fifoIteratorNext(ICELIB_TRIGGERED_FIFO_ITERATOR* pIterator);

FUNC_DECL  void
ICELIB_triggeredFifoClear(ICELIB_TRIGGERED_FIFO* pFifo);
FUNC_DECL unsigned int
ICELIB_triggeredFifoCount(const ICELIB_TRIGGERED_FIFO* pFifo);
FUNC_DECL bool
ICELIB_triggeredFifoIsEmpty(const ICELIB_TRIGGERED_FIFO* pFifo);
FUNC_DECL bool
ICELIB_triggeredFifoIsFull(const ICELIB_TRIGGERED_FIFO* pFifo);
FUNC_DECL bool
ICELIB_triggeredFifoPut(ICELIB_TRIGGERED_FIFO* pFifo,
                        ICELIB_LIST_PAIR*      pPair);
FUNC_DECL ICELIB_LIST_PAIR*
pICELIB_triggeredFifoGet(ICELIB_CHECKLIST*      pCheckList,
                         ICELIB_CALLBACK_LOG*   pCallbackLog,
                         ICELIB_TRIGGERED_FIFO* pFifo);


FUNC_DECL bool
ICELIB_scheduleSingle(ICELIB_INSTANCE*          pInstance,
                      ICELIB_STREAM_CONTROLLER* pController,
                      ICELIB_CALLBACK_LOG*      pCallbackLog);


FUNC_DECL char*
ICELIB_getCheckListLocalUsernamePair(char*                   dst,
                                     int                     maxlength,
                                     const ICELIB_CHECKLIST* pCheckList);

FUNC_DECL char*
ICELIB_getCheckListRemoteUsernamePair(char*                   dst,
                                      int                     maxlength,
                                      const ICELIB_CHECKLIST* pCheckList,
                                      bool                    outgoing);

const FUNC_DECL char*
ICELIB_getCheckListRemotePasswd(const ICELIB_CHECKLIST* pCheckList);
const FUNC_DECL char*
ICELIB_getCheckListLocalPasswd(const ICELIB_CHECKLIST* pCheckList);

FUNC_DECL bool
ICELIB_isPairAddressMatch(const ICELIB_LIST_PAIR* pPair1,
                          const ICELIB_LIST_PAIR* pPair2);

FUNC_DECL ICELIB_LIST_PAIR*
pICELIB_correlateToRequest(unsigned int*    pStreamIndex,
                           ICELIB_INSTANCE* pInstance,
                           const StunMsgId* pTransactionId);

FUNC_DECL unsigned int
ICELIB_validListCount(const ICELIB_VALIDLIST* pValidList);

FUNC_DECL  void
ICELIB_updatingStates(ICELIB_INSTANCE* pInstance);

FUNC_DECL uint32_t
ICELIB_getCandidateTypeWeight(ICE_CANDIDATE_TYPE type);

FUNC_DECL uint32_t
ICELIB_calculateReadyWeight(ICE_CANDIDATE_TYPE localType,
                            ICE_CANDIDATE_TYPE remoteType,
                            uint32_t           timeMultiplier);

FUNC_DECL const ICE_CANDIDATE*
pICELIB_findCandidate(const ICE_MEDIA_STREAM* pMediaStream,
                      int                     proto,
                      const struct socket_addr*  address,
                      unsigned                componentId);

FUNC_DECL void
ICELIB_validListIteratorConstructor(ICELIB_VALIDLIST_ITERATOR* pIterator,
                                    ICELIB_VALIDLIST*          pValidList);
ICELIB_VALIDLIST_ELEMENT*
pICELIB_validListIteratorNext(ICELIB_VALIDLIST_ITERATOR* pIterator);
const FUNC_DECL char*
ICELIB_toString_CheckListPairState(ICELIB_PAIR_STATE state);


FUNC_DECL char*
ICELIB_getPairFoundation(char*                   dst,
                         int                     maxlength,
                         const ICELIB_LIST_PAIR* pPair);


FUNC_DECL void
ICELIB_netAddrDumpLog(const ICELIB_CALLBACK_LOG* pCallbackLog,
                      ICELIB_logLevel            logLevel,
                      const struct socket_addr*     netAddr);
FUNC_DECL void
ICELIB_transactionIdDumpLog(const ICELIB_CALLBACK_LOG* pCallbackLog,
                            ICELIB_logLevel            logLevel,
                            StunMsgId                  tId);
FUNC_DECL void
ICELIB_candidateDumpLog(const ICELIB_CALLBACK_LOG* pCallbackLog,
                        ICELIB_logLevel            logLevel,
                        const ICE_CANDIDATE*       candidate);
FUNC_DECL void
ICELIB_componentIdsDumpLog(const ICELIB_CALLBACK_LOG*  pCallbackLog,
                           ICELIB_logLevel             logLevel,
                           const ICELIB_COMPONENTLIST* pComponentList);
FUNC_DECL void
ICELIB_pairDumpLog(const ICELIB_CALLBACK_LOG* pCallbackLog,
                   ICELIB_logLevel            logLevel,
                   const ICELIB_LIST_PAIR*    pPair);
FUNC_DECL void
ICELIB_checkListDumpLog(const ICELIB_CALLBACK_LOG* pCallbackLog,
                        ICELIB_logLevel            logLevel,
                        const ICELIB_CHECKLIST*    pCheckList);
FUNC_DECL void
ICELIB_checkListDumpLogLog(const ICELIB_CALLBACK_LOG* pCallbackLog,
                           ICELIB_logLevel            logLevel,
                           const ICELIB_CHECKLIST*    pCheckList);
FUNC_DECL void
ICELIB_validListDumpLog(const ICELIB_CALLBACK_LOG* pCallbackLog,
                        ICELIB_logLevel            logLevel,
                        ICELIB_VALIDLIST*          pValidList);

FUNC_DECL void
ICELIB_netAddrDump(const struct socket_addr* netAddr);
FUNC_DECL void
ICELIB_transactionIdDump(StunMsgId tId);
FUNC_DECL void
ICELIB_candidateDump(const ICE_CANDIDATE* candidate);
FUNC_DECL void
ICELIB_componentIdsDump(const ICELIB_COMPONENTLIST* pComponentList);
FUNC_DECL void
ICELIB_checkListDumpPair(const ICELIB_LIST_PAIR* pPair);
FUNC_DECL void
ICELIB_checkListDump(const ICELIB_CHECKLIST* pCheckList);
FUNC_DECL void
ICELIB_checkListDumpAll(const ICELIB_INSTANCE* pInstance);
FUNC_DECL void
ICELIB_validListDump(ICELIB_VALIDLIST* pValidList);

#ifdef __cplusplus
}
#endif


#endif  /* ICELIB_INTERN_H */
