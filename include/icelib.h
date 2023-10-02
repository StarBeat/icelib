/*
 *  See License file
 */



#ifndef ICELIB_H
#define ICELIB_H

#include "xnet.h"
#include "icelibtypes.h"
#include "macro.h"

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __GNUC__
    #define FORMAT_CHECK(ff,ee)  __attribute__( ( format(printf, ff, ee) ) )
#else
    #define FORMAT_CHECK(ff,ee)
#endif




/* -----------------------------------------------------------------------------
 * */
/*  */
/* ===== Callback functions */
/*  */

/*  */
/* ----- Callback for sending a Binding Request message (STUN client role) */
/*  */
typedef ICELIB_Result (* ICELIB_outgoingBindingRequest)(void*
                                                        pUserData,
                                                        int
                                                        proto,
                                                        int socket,
                                                        const struct socket_addr*
                                                        destination,
                                                        const struct socket_addr*
                                                        source,
                                                        uint32_t
                                                        userValue1,
                                                        uint32_t
                                                        userValue2,
                                                        uint32_t
                                                        componentId,
                                                        bool
                                                        useRelay,
                                                        const char*
                                                        pUfragPair,
                                                        const char*
                                                        pPasswd,
                                                        uint32_t
                                                        peerPriority,
                                                        bool
                                                        useCandidate,
                                                        bool
                                                        iceControlling,
                                                        bool
                                                        iceControlled,
                                                        uint64_t
                                                        tieBreaker,
                                                        StunMsgId
                                                        transactionId);

/*  */
/* ----- Callback sending a Binding Response message (STUN server role) */
/*  */
typedef ICELIB_Result (* ICELIB_outgoingBindingResponse)(void*
                                                         pUserData,
                                                         uint32_t
                                                         userValue1,
                                                         uint32_t
                                                         userValue2,
                                                         uint32_t
                                                         componentId,
                                                         int
                                                         sockfd,
                                                         int
                                                         proto,
                                                         const struct socket_addr*
                                                         source,
                                                         const struct socket_addr*
                                                         destination,
                                                         const struct socket_addr*
                                                         MappedAddress,
                                                         uint16_t
                                                         errorResponse,
                                                         StunMsgId
                                                         transactionId,
                                                         bool
                                                         useRelay,
                                                         const char*
                                                         pPasswd);


/*  */
/* ----- Callback to signal ICE completion */
/*  */
typedef ICELIB_Result (* ICELIB_connectivityChecksComplete)(void*    pUserData,
                                                            uint32_t userValue1,
                                                            bool
                                                            isControlling,
                                                            bool     iceFailed);

/*  */
/* ----- Callback to signal that a canidate pair has been nominated */
/*  */
typedef ICELIB_Result (* ICELIB_nominated)(void*                  pUserData,
                                           uint32_t               userValue1,
                                           uint32_t               userValue2,
                                           uint32_t               componentId,
                                           uint64_t               priority,
                                           int32_t                proto,
                                           const struct socket_addr* local,
                                           const struct socket_addr* remote);

/*  */
/* ----- Callback used to generate keepalives */
/*  */
typedef ICELIB_Result (* ICELIB_sendKeepAlive)(void*    pUserData,
                                               uint32_t userValue1,
                                               uint32_t userValue2,
                                               uint32_t mediaIdx);

/*  */
/* ----- Callback for cancelling a Binding Request message (STUN client role) */
/*  */
typedef ICELIB_Result (* ICELIB_outgoingCancelRequest)(void*     pUserData,
                                                       uint32_t  userValue1,
                                                       StunMsgId transactionId);

/*  */
/* ----- Callback for updating password in the media stream (Used to validate
 * STUN packets) */
/*  */
typedef ICELIB_Result (* ICELIB_passwordUpdate)(void*    pUserData,
                                                uint32_t userValue1,
                                                uint32_t userValue2,
                                                char*    password);

/*  */
/* ----- Callback for logging */
/*  */
typedef void (* ICELIB_logCallback)(void*           pUserData,
                                    ICELIB_logLevel logLevel,
                                    const char*     str);



/*  */
/* ----- ICE callback function pointers and data */
/*  */
struct         tag_ICELIB_INSTANCE;
typedef struct tag_ICELIB_INSTANCE ICELIB_INSTANCE_;

typedef struct {
  ICELIB_connectivityChecksComplete pICELIB_connectivityChecksComplete;
  void*                             pConnectivityChecksCompleteUserData;
  ICELIB_INSTANCE_*                 pInstance;
} ICELIB_CALLBACK_COMPLETE;

typedef struct {
  ICELIB_nominated  pICELIB_nominated;
  void*             pNominatedUserData;
  ICELIB_INSTANCE_* pInstance;
} ICELIB_CALLBACK_NOMINATED;

typedef struct {
  ICELIB_outgoingBindingRequest pICELIB_sendBindingRequest;
  void*                         pBindingRequestUserData;
  ICELIB_INSTANCE_*             pInstance;
} ICELIB_CALLBACK_REQUEST;


typedef struct {
  ICELIB_outgoingBindingResponse pICELIB_sendBindingResponse;
  void*                          pBindingResponseUserData;
  ICELIB_INSTANCE_*              pInstance;
} ICELIB_CALLBACK_RESPONSE;


typedef struct {
  ICELIB_outgoingCancelRequest pICELIB_sendCancelRequest;
  void*                        pCancelRequestUserData;
  ICELIB_INSTANCE_*            pInstance;
} ICELIB_CALLBACK_CANCEL_REQUEST;

typedef struct {
  ICELIB_sendKeepAlive pICELIB_sendKeepAlive;
  void*                pUserDataKeepAlive;
  ICELIB_INSTANCE_*    pInstance;
} ICELIB_CALLBACK_KEEPALIVE;


typedef struct {
  ICELIB_passwordUpdate pICELIB_passwordUpdate;
  void*                 pUserDataPasswordUpdate;
  ICELIB_INSTANCE_*     pInstance;
} ICELIB_CALLBACK_PASSWORD_UPDATE;

typedef struct {
  ICELIB_logCallback pICELIB_logCallback;
  void*              pLogUserData;
  ICELIB_INSTANCE_*  pInstance;
} ICELIB_CALLBACK_LOG;


typedef struct {
  ICELIB_CALLBACK_REQUEST         callbackRequest;
  ICELIB_CALLBACK_RESPONSE        callbackResponse;
  ICELIB_CALLBACK_KEEPALIVE       callbackKeepAlive;
  ICELIB_CALLBACK_COMPLETE        callbackComplete;
  ICELIB_CALLBACK_NOMINATED       callbackNominated;
  ICELIB_CALLBACK_CANCEL_REQUEST  callbackCancelRequest;
  ICELIB_CALLBACK_PASSWORD_UPDATE callbackPasswordUpdate;
  ICELIB_CALLBACK_LOG             callbackLog;
} ICELIB_CALLBACKS;




/*  */
/* ----- ICE configuration data */
/*  */
typedef struct {
  unsigned int    tickIntervalMS;
  unsigned int    keepAliveIntervalS;
  unsigned int    maxCheckListPairs;
  bool            aggressiveNomination;
  bool            iceLite;
  bool            dropRflx;
  ICELIB_logLevel logLevel;
} ICELIB_CONFIGURATION;


/*  */
/* ----- ICE instance data */
/*  */
typedef struct tag_ICELIB_INSTANCE {
  ICELIB_STATE             iceState;
  ICELIB_CONFIGURATION     iceConfiguration;
  ICELIB_CALLBACKS         callbacks;
  ICE_MEDIA                localIceMedia;
  ICE_MEDIA                remoteIceMedia;
  bool                     roleHasSwapped;
  bool                     iceControlling;
  bool                     iceControlled;
  bool                     iceSupportVerified;
  uint64_t                 tieBreaker;
  ICELIB_STREAM_CONTROLLER streamControllers[ ICE_MAX_MEDIALINES];
  unsigned int             numberOfMediaStreams;
  unsigned int             roundRobinStreamControllerIndex;
  uint32_t                 tickCount;
  uint32_t                 keepAliveTickCount;
} ICELIB_INSTANCE;



FUNC_DECL void ICELIB_logString(const ICELIB_CALLBACK_LOG* pCallbackLog,
                 ICELIB_logLevel            logLevel,
                 const char*                str);

FUNC_DECL void FORMAT_CHECK(3,
               4) ICELIB_logVaString(const ICELIB_CALLBACK_LOG * pCallbackLog,
                                     ICELIB_logLevel logLevel,
                                     const char* fmt,
                                     ...);
/* -----------------------------------------------------------------------------
 * */
/*  */
/* ----- TEST API Functions */
/*  */
FUNC_DECL void ICELIB_timerConstructor(ICELIB_TIMER* timer,
                        unsigned int  tickIntervalMS);
FUNC_DECL void ICELIB_timerStart(ICELIB_TIMER* timer,
                  unsigned int  timeoutMS);
FUNC_DECL void ICELIB_timerStop(ICELIB_TIMER* timer);
FUNC_DECL void ICELIB_timerTick(ICELIB_TIMER* timer);
FUNC_DECL bool ICELIB_timerIsRunning(const ICELIB_TIMER* timer);
FUNC_DECL bool ICELIB_timerIsTimedOut(const ICELIB_TIMER* timer);


/* -----------------------------------------------------------------------------
 * */
/*  */
/* ----- API Functions */
/*  */


FUNC_DECL void ICELIB_Constructor(ICELIB_INSTANCE*            pInstance,
                   const ICELIB_CONFIGURATION* pConfiguration);
FUNC_DECL void ICELIB_Destructor (ICELIB_INSTANCE* pInstance);

FUNC_DECL bool ICELIB_Start(ICELIB_INSTANCE* pInstance,
             bool             controlling);
FUNC_DECL void ICELIB_Stop(ICELIB_INSTANCE* pInstance);

FUNC_DECL void ICELIB_ReStart(ICELIB_INSTANCE* pInstance);

FUNC_DECL void ICELIB_Tick(ICELIB_INSTANCE* pInstance);

FUNC_DECL void ICELIB_setCallbackConnecitivityChecksComplete(
  ICELIB_INSTANCE*                  pInstance,
  ICELIB_connectivityChecksComplete pICELIB_connectivityChecksComplete,
  void*                             userData);

FUNC_DECL void ICELIB_setCallbackNominated(ICELIB_INSTANCE* pInstance,
                            ICELIB_nominated pICELIB_nominated,
                            void*            userData);
FUNC_DECL void ICELIB_setCallbackOutgoingBindingRequest(
  ICELIB_INSTANCE*              pInstance,
  ICELIB_outgoingBindingRequest pICELIB_sendBindingRequest,
  void*                         pBindingRequestUserData);

FUNC_DECL void ICELIB_setCallbackOutgoingBindingResponse(
  ICELIB_INSTANCE*               pInstance,
  ICELIB_outgoingBindingResponse pICELIB_sendBindingResponse,
  void*                          pBindingResponseUserData);

FUNC_DECL void ICELIB_setCallbackOutgoingCancelRequest(ICELIB_INSTANCE*             pInstance,
                                        ICELIB_outgoingCancelRequest pICELIB_sendBindingCancelRequest,
                                        void*                        pCancelRequestUserData);


FUNC_DECL void ICELIB_setCallbackKeepAlive(ICELIB_INSTANCE*     pInstance,
                            ICELIB_sendKeepAlive pICELIB_sendKeepAlive,
                            void*                pUserDataKeepAlive);

FUNC_DECL void ICELIB_setCallbackPasswordUpdate(ICELIB_INSTANCE*      pInstance,
                                 ICELIB_passwordUpdate pICELIB_passwordUpdate,
                                 void*                 pUserDataPasswordUpdate);

FUNC_DECL void ICELIB_setCallbackLog(ICELIB_INSTANCE*   pInstance,
                      ICELIB_logCallback pICELIB_logCallback,
                      void*              pLogUserData,
                      ICELIB_logLevel    logLevel);

FUNC_DECL void ICELIB_incomingBindingResponse(ICELIB_INSTANCE*       pInstance,
                               uint16_t               errorResponse,
                               StunMsgId              transactionId,
                               const struct socket_addr* source,                /*
                                                                              * From
                                                                              * response
                                                                              **/
                               const struct socket_addr* destination,           /*
                                                                              * From
                                                                              * response
                                                                              **/
                               const struct socket_addr* mappedAddress);

FUNC_DECL void ICELIB_incomingTimeout(ICELIB_INSTANCE* pInstance,
                       StunMsgId        Transactionid);

FUNC_DECL void ICELIB_incomingBindingRequest(ICELIB_INSTANCE*       pInstance,
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
                              const struct socket_addr* peerAddr,
                              uint16_t               componentId);

FUNC_DECL ICE_TURN_STATE ICELIB_getTurnState(const ICELIB_INSTANCE* pInstance,
                    uint32_t               mediaIdx);

FUNC_DECL void ICELIB_setTurnState(ICELIB_INSTANCE* pInstance,
                    uint32_t         mediaIdx,
                    ICE_TURN_STATE   turnState);

FUNC_DECL int32_t ICELIB_getNumberOfLocalICEMediaLines(const ICELIB_INSTANCE* pInstance);
FUNC_DECL int32_t ICELIB_getNumberOfRemoteICEMediaLines(const ICELIB_INSTANCE* pInstance);

FUNC_DECL int32_t ICELIB_getNumberOfLocalCandidates(const ICELIB_INSTANCE* pInstance,
                                  uint32_t               idx);
FUNC_DECL int32_t ICELIB_getNumberOfRemoteCandidates(const ICELIB_INSTANCE* pInstance,
                                   uint32_t               idx);

FUNC_DECL const char* ICELIB_getLocalPassword(const ICELIB_INSTANCE* pInstance,
                        uint32_t               idx);

FUNC_DECL int32_t ICELIB_getLocalComponentId(const ICELIB_INSTANCE* pInstance,
                           uint32_t               mediaIdx,
                           uint32_t               candIdx);

FUNC_DECL int32_t  ICELIB_getRemoteComponentId(const ICELIB_INSTANCE* pInstance,
                            uint32_t               mediaIdx,
                            uint32_t               candIdx);

FUNC_DECL struct socket_addr const* ICELIB_getLocalConnectionAddr(const ICELIB_INSTANCE* pInstance,
                              uint32_t               mediaIdx,
                              uint32_t               candIdx);

FUNC_DECL struct socket_addr const* ICELIB_getRemoteConnectionAddr(const ICELIB_INSTANCE* pInstance,
                               uint32_t               mediaIdx,
                               uint32_t               candIdx);

FUNC_DECL ICE_CANDIDATE_TYPE ICELIB_getLocalCandidateType(const ICELIB_INSTANCE* pInstance,
                             uint32_t               mediaIdx,
                             uint32_t               candIdx);

FUNC_DECL ICE_CANDIDATE_TYPE ICELIB_getRemoteCandidateType(const ICELIB_INSTANCE* pInstance,
                              uint32_t               mediaIdx,
                              uint32_t               candIdx);

FUNC_DECL ICE_TRANSPORT ICELIB_getRemoteTransport(const ICELIB_INSTANCE* instance,
                          uint32_t               mediaIdx,
                          uint32_t               candIdx);

FUNC_DECL ICE_MEDIA const* ICELIB_getLocalIceMedia(const ICELIB_INSTANCE* pInstance);

FUNC_DECL void ICELIB_disableMediaStream(ICELIB_INSTANCE* pInstance);
FUNC_DECL int32_t ICELIB_addRemoteMediaStream(ICELIB_INSTANCE*       pInstance,
                            const char*            ufrag,
                            const char*            pwd,
                            const struct socket_addr* defaultAddr);

FUNC_DECL int32_t ICELIB_setRemoteMediaStream(ICELIB_INSTANCE*       pInstance,
                            uint32_t               mediaIdx,
                            const char*            ufrag,
                            const char*            pwd,
                            const struct socket_addr* defaultAddr);

FUNC_DECL int32_t ICELIB_addRemoteCandidate(ICELIB_INSTANCE*   pInstance,
                          uint32_t           mediaIdx,
                          const char*        foundation,
                          uint32_t           foundationLen,
                          uint32_t           componentId,
                          uint32_t           priority,
                          const char*        connectionAddr,
                          uint16_t           port,
                          ICE_TRANSPORT      transport,
                          ICE_CANDIDATE_TYPE candType);

FUNC_DECL int32_t ICELIB_updateLocalMediaStreamDefaultCandidate(ICELIB_INSTANCE*   pInstance,
                                              uint32_t           mediaIdx,
                                              ICE_CANDIDATE_TYPE defaultCandType);

FUNC_DECL int32_t ICELIB_addLocalMediaStream(ICELIB_INSTANCE*   pInstance,
                           uint32_t           userValue1,
                           uint32_t           userValue2,
                           ICE_CANDIDATE_TYPE defaultCandType);

FUNC_DECL int32_t ICELIB_setLocalMediaStream(ICELIB_INSTANCE*   pInstance,
                           uint32_t           mediaIdx,
                           uint32_t           userValue1,
                           uint32_t           userValue2,
                           ICE_CANDIDATE_TYPE defaultCandType);

FUNC_DECL int32_t ICELIB_addLocalCandidate(ICELIB_INSTANCE*       pInstance,
                         uint32_t               mediaIdx,
                         uint32_t               componentId,
                         int                    socket,
                         const struct socket_addr* connectionAddr,
                         const struct socket_addr* relAddr,
                         ICE_TRANSPORT          transport,
                         ICE_CANDIDATE_TYPE     candType,
                         uint16_t               local_pref);


FUNC_DECL bool ICELIB_isControlling(const ICELIB_INSTANCE* pInstance);


FUNC_DECL void ICELIB_checkListDumpAllLog(const ICELIB_CALLBACK_LOG* pCallbackLog,
                           ICELIB_logLevel            logLevel,
                           const ICELIB_INSTANCE*     pInstance);


FUNC_DECL bool ICELIB_isRestart(ICELIB_INSTANCE* pInstance,
                 unsigned int     mediaIdx,
                 const char*      ufrag,
                 const char*      passwd);


FUNC_DECL struct socket_addr const* ICELIB_getLocalRelayAddr(const ICELIB_INSTANCE* pInstance,
                         uint32_t               mediaIdx);
FUNC_DECL ICE_CANDIDATE const* ICELIB_getLocalRelayCandidate(const ICELIB_INSTANCE* pInstance,
                              uint32_t               mediaIdx,
                              uint32_t               componentId);

FUNC_DECL struct socket_addr const* ICELIB_getLocalRelayAddrFromHostAddr(const ICELIB_INSTANCE* pInstance,
                                     const struct socket_addr* hostAddr);

FUNC_DECL ICE_CANDIDATE const* ICELIB_getActiveCandidate(const ICELIB_INSTANCE* pInstance,
                          int                    mediaLineId,
                          uint32_t               componentId);

FUNC_DECL ICE_REMOTE_CANDIDATES const* ICELIB_getActiveRemoteCandidates(const ICELIB_INSTANCE* pInstance,
                                 int                    mediaLineId);

FUNC_DECL char* ICELIB_getCheckListRemoteUsernamePair(char*                   dst,
                                      int                     maxlength,
                                      const ICELIB_CHECKLIST* pCheckList,
                                      bool                    outgoing);



FUNC_DECL bool ICELIB_isRunning(const ICELIB_INSTANCE* pInstance);

FUNC_DECL bool ICELIB_isIceComplete(const ICELIB_INSTANCE* pInstance);

FUNC_DECL bool ICELIB_Mangled (const ICELIB_INSTANCE* pInstance);

FUNC_DECL bool ICELIB_UnsupportedByRemote (const ICELIB_INSTANCE* pInstance);

FUNC_DECL const ICE_MEDIA_STREAM* ICELIB_getLocalMediaStream(const ICELIB_INSTANCE* pInstance,
                           uint32_t               mediaIdx);

FUNC_DECL void ICELIB_dropRflx(ICELIB_INSTANCE* pInstance);

#ifdef __cplusplus
}
#endif

#endif
