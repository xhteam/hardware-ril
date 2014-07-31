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

typedef struct PttEmergencyInfo{
  int type;
  int number;//for group call ,it's group id,for p2p call,it's callee id
}PttEmergencyInfo;

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
	  PttEmergencyInfo emerginfo;
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
	ePttCallStatusIncoming=99,
};

struct ActionCauses {
	const int err;
	const char *cause;
};

typedef struct PttInfo{
  int pttstate;
  
  //group info
  int givalid; //this value means how many following items is valid,it's bit mapping,e.g. 0x01 means gid is valid,
  #define PTT_BIZSTATE_GID_VALID 0x01
  #define PTT_BIZSTATE_GPRIORITY_VALID 0x02
  #define PTT_BIZSTATE_GDEMANDIND_VALID 0x04
  #define PTT_BIZSTATE_GGRANTSTATUS_VALID 0x08
  #define PTT_BIZSTATE_GSPKNUM_VALID 0x10
  #define PTT_BIZSTATE_GSPKNAME_VALID 0x20
  #define PTT_BIZSTATE_GOWNERIND_VALID 0x40
  int gid;
  int gpriority;
  int gdemandindicator;
  int ggrantstatus;
  char* gspeakernum;
  char* gspeakername;
  int gownerindicator;

  //personal call info
  int civalid; //this value means how many following items is valid,it's bit mapping
  #define PTT_BIZSTATE_CIPRIORITY_VALID 0x01
  #define PTT_BIZSTATE_CICALLEEID_VALID 0x02
  #define PTT_BIZSTATE_CICALLERID_VALID 0x04
  int cpriority;
  char* ccalleeid;
  char* ccallerid;  
}PttInfo;

/* end added */

#ifdef __cplusplus
}
#endif

#endif /*ANDROID_RIL_PTT_H*/
