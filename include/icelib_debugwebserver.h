/*
 *  See License file
 */

#ifndef ICELIB_DEBUGWEBSERVER_H
#define ICELIB_DEBUGWEBSERVER_H
#include "macro.h"
FUNC_DECL void ICELIB_FormatIcePage(char* resp,
                     char* resp_head);
FUNC_DECL void ICELIB_FormatValidCheckListsBodyTable(ICELIB_INSTANCE* icelib,
                                      char*            s,
                                      char*            content);
#endif
