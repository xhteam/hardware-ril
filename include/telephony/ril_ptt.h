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

struct PttEmergencyInfo{
  int type;
  int pid;//for group call ,it's group id,for p2p call,it's callee id
};

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
	ePttCallStatusProgressing,       /* Normal voice call */
	ePttCallStatusQueued,           /* Not used in V2.2.0 */
	ePttCallStatusCalledPartyPaged, /* Group voice call */
	ePttCallStatusContinue,         /* Not used in V2.2.0 */
	ePttCallStatusHangTimeExpired,  /* Not used in V2.2.0 */
	ePttCallStatusIncoming,
};

struct ActionCauses {
	const int err;
	const char *cause;
};


/* end added */

#ifdef __cplusplus
}
#endif

#endif /*ANDROID_RIL_PTT_H*/
