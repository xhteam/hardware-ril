/*
 * Copyright (C) 2006 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/*
 * ISSUES:
 *
 */

/**
 * TODO
 *
 *
 */


#ifndef ANDROID_RIL_PTT_H
#define ANDROID_RIL_PTT_H 1

#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct PttGroupInfo{
  int gid;
  int gpriority;
  int gstate;
  char* gname;
}PttGroupInfo;

typedef struct PttGroups{
	  int groups_number;
	  int dyn_groups_number;
	  char* tun;
	  PttGroupInfo* ginfo;
}PttGroups;


enum PttState{
	ePttStateInactive,
	ePttStateNotGrouped,
	ePttStateGroupIdle,
	ePttStateGroupMonitor,
	ePttStateMasterGroupIdle,
	ePttStateMasterGroupMonitor,
	ePttStateGroupTransient,
	ePttStateP2PCallOriginate,
	ePttStateP2PCallTerminate,
	ePttStateP2PCallOriginateTransient,
	ePttStateP2PCallTerminateTransient,
};

/* added by ferri,s Jul6, 2014 */
enum PttCallStatus{
	ePttCallStatusProgessing,       /* Normal voice call */
	ePttCallStatusQueued,           /* Not used in V2.2.0 */
	ePttCallStatusCalledPartyPaged, /* Group voice call */
	ePttCallStatusContinue,         /* Not used in V2.2.0 */
	ePttCallStatusHangTimeExpired,  /* Not used in V2.2.0 */
};

struct ActionCauses {
	const int err;
	const char *cause;
}action_cause[] = { 
	/* common cuases */
	{0   , "ok"},
	{31  , "network timeout"},
	{1001, "network error"},
	{1002, "unsigned number error"},
	{1003, "user authentication failed"},
	{1004, "service option not supported"},
	{1005, "requested service option not subscribed"},
	{1006, "unspecified error"},
	{1007, "invalid parameter"},
	{1008, "network detach"},
	{1009, "high priority task interrupt"},
	{1010, "NAS Inner Error"},
	{1011, "IMSI is temporarily blocked"},
	{1012, "IMSI is permanently blocked"},
	{1013, "User Low Priority"},
	{1014, "No PTT Capability"},
	/* ptt causes */
	{1100, "Operation Success"},
	{1101, "group owner close"},
	{1102, "dispatcher close"},
	{1103, "timeout close"},
	{1104, "speaker token timeout"},
	{1105, "release for high priority user"},
	{1106, "queue timeout"},
	{1107, "force to cancel queue"},
	{1108, "requested group not subscribed"},
	{1109, "queue buffer is full"},
	{1110, "not group owner"},
	{1111, "user interrupt"},
	{1112, "Set Failure"},
	{1113, "Out of Service"},
	{1114, "Normal Release"},
	/* ptp causes */
	{1201, "Normal Call Clearing"},
	{1202, "User Busy"},
	{1203, "No User Responding"},
	{1204, "User Alerting No Answer"},
	{1205, "Call Rejected"},
	{1206, "Invalid Number Format"},
	{1207, "User In High Priority Task"},
	{1208, "Caller Permission Denied"},
	{1209, "Callee Permission Denied"},
};

#define MAX_BLOCK_INDICATOR 8

const char *BlockedIndicator[] = {
/* 0 */	"IMSI & IMEI both Remote ON",
/* 1 */	"IMSI temporarily Remote OFF, IMEI Remote ON",
/* 2 */	"IMSI permanently Remote OFF, IMEI Remote ON",
/* 3 */	"IMSI Remote ON, IMEI temporarily Remote OFF",
/* 4 */	"IMSI Remote ON, IMEI permanently Remote OFF",
/* 5 */	"IMSI temporarily Remote OFF, IMEI permanently Remote OFF",
/* 6 */ "IMSI permanently Remote OFF, IMEI temporarily Remote OFF",
/* 7 */ "IMSI & IMEI both temporarily Remote OFF",
/* 8 */ "IMSI &	IMEI both permanently Remote OFF",
};

/* end added */

#ifdef __cplusplus
}
#endif

#endif /*ANDROID_RIL_PTT_H*/
