/********************************************************************\

  Name:         experim.h
  Created by:   ODBedit program

  Contents:     This file contains C structures for the "Experiment"
                tree in the ODB and the "/Analyzer/Parameters" tree.

                Additionally, it contains the "Settings" subtree for
                all items listed under "/Equipment" as well as their
                event definition.

                It can be used by the frontend and analyzer to work
                with these information.

                All C structures are accompanied with a string represen-
                tation which can be used in the db_create_record function
                to setup an ODB structure which matches the C structure.

  Created on:   Thu Feb  1 21:20:48 2007
  $Id: experim.h 3551 2007-02-02 05:52:20Z amaudruz $
\********************************************************************/

#ifndef EXCL_TRIGGER

#define TRIGGER_SETTINGS_DEFINED

typedef struct {
  struct {
    WORD      threshold1[32];
  } v792;
} TRIGGER_SETTINGS;

#define TRIGGER_SETTINGS_STR(_name) char const *_name[] = {\
"[v792]",\
"threshold1 = WORD[32] :",\
"[0] 1",\
"[1] 511",\
"[2] 511",\
"[3] 511",\
"[4] 511",\
"[5] 511",\
"[6] 511",\
"[7] 511",\
"[8] 511",\
"[9] 511",\
"[10] 511",\
"[11] 511",\
"[12] 511",\
"[13] 511",\
"[14] 511",\
"[15] 511",\
"[16] 511",\
"[17] 511",\
"[18] 511",\
"[19] 511",\
"[20] 511",\
"[21] 511",\
"[22] 511",\
"[23] 511",\
"[24] 511",\
"[25] 511",\
"[26] 511",\
"[27] 511",\
"[28] 511",\
"[29] 511",\
"[30] 511",\
"[31] 511",\
NULL }

#define TRIGGER_COMMON_DEFINED

typedef struct {
  WORD      event_id;
  WORD      trigger_mask;
  char      buffer[32];
  INT       type;
  INT       source;
  char      format[8];
  BOOL      enabled;
  INT       read_on;
  INT       period;
  double    event_limit;
  DWORD     num_subevents;
  INT       log_history;
  char      frontend_host[32];
  char      frontend_name[32];
  char      frontend_file_name[256];
} TRIGGER_COMMON;

#define TRIGGER_COMMON_STR(_name) char const *_name[] = {\
"[.]",\
"Event ID = WORD : 1",\
"Trigger mask = WORD : 0",\
"Buffer = STRING : [32] SYSTEM",\
"Type = INT : 1",\
"Source = INT : 0",\
"Format = STRING : [8] MIDAS",\
"Enabled = BOOL : y",\
"Read on = INT : 1",\
"Period = INT : 1",\
"Event limit = DOUBLE : 0",\
"Num subevents = DWORD : 0",\
"Log history = INT : 0",\
"Frontend host = STRING : [32] laddvme05.triumf.ca",\
"Frontend name = STRING : [32] FEvf48",\
"Frontend file name = STRING : [256] fevf48.c",\
"",\
NULL }

#endif

#ifndef EXCL_SCALER

#define SCALER_COMMON_DEFINED

typedef struct {
  WORD      event_id;
  WORD      trigger_mask;
  char      buffer[32];
  INT       type;
  INT       source;
  char      format[8];
  BOOL      enabled;
  INT       read_on;
  INT       period;
  double    event_limit;
  DWORD     num_subevents;
  INT       log_history;
  char      frontend_host[32];
  char      frontend_name[32];
  char      frontend_file_name[256];
} SCALER_COMMON;

#define SCALER_COMMON_STR(_name) char const *_name[] = {\
"[.]",\
"Event ID = WORD : 2",\
"Trigger mask = WORD : 0",\
"Buffer = STRING : [32] SYSTEM",\
"Type = INT : 1",\
"Source = INT : 0",\
"Format = STRING : [8] MIDAS",\
"Enabled = BOOL : n",\
"Read on = INT : 377",\
"Period = INT : 10000",\
"Event limit = DOUBLE : 0",\
"Num subevents = DWORD : 0",\
"Log history = INT : 0",\
"Frontend host = STRING : [32] laddvme05.triumf.ca",\
"Frontend name = STRING : [32] FEvf48",\
"Frontend file name = STRING : [256] fevf48.c",\
"",\
NULL }

#endif

