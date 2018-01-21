
/*
 * @copyright
 *
 *  Copyright 2014 Neo Natura
 *
 *  This file is part of the Share Library.
 *  (https://github.com/neonatura/share)
 *        
 *  The Share Library is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version. 
 *
 *  The Share Library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with The Share Library.  If not, see <http://www.gnu.org/licenses/>.
 *
 *  @endcopyright
 *
 *  @file sexe.h
 *  @brief Utilities to compile and run SEXE bytecode.
 *  @date 2014
 *
 */


#ifndef __SHARE_LIB__SEXE_H__
#define __SHARE_LIB__SEXE_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "share.h"

/**
 * @mainpage
 *
 *  <h3>The SEXE programming language reference manual.</h3>
 *
 *  SEXE is a libshare project which aims to introduce the ability to run compiled bytecode on local disk, sharefs partition, and on remote machines.
 *
 *  All source code for SEXE compiled bytecode is written in the Lua programming language syntax.
Reference: http://www.lua.org/ (PUC RIO)
 *
 *  The compiler "sxc", interpreter "sx", and symbol lister "readsexe" progams distributed with libshare will use your current working directory when reading and writing files.
 *
 *
 * <p>
 *  The following is a sub-set of the core SEXE functions provided:
 *
 *  - key = shkey(str|num)
 *    Generate a share key from a string or number.
 *
 *  - enc = shencode(str, key)
 *    Encode a text string based off a share key.
 *
 *  - str = shdecode(enc, key)
 *    Decode a text string based off a share key.
 *
 *  - t = time()
 *    Obtain a floating point respresentation of the current time.
 *
 *  - ctime(t)
 *    Obtain a generic string describing the current time.</dl>
 *
 *  - utime(t)
 *    Convert the floating-point representation into unix time-stamp (epoch seconds).
 *
 *  @defgroup sexe A programming language.
 *  @{
 */

/**
 * The length (including null terminator) of a generic sexe name.
 */
#define MAX_SEXE_NAME_LENGTH 24


/**
 *  @defgroup sexe_lua The lua runtime sub-system.
 *  @{
 */
#include "sexe_lua.h"
typedef lua_State sexe_t;
#ifdef SEXELIB
#include "lobject.h"
#include "llimits.h"
#include "lauxlib.h"
#include "lstate.h"
#include "ldo.h"
#endif
/**
 *  @}
 */

/* execution binary bytecode prefix */
#define SEXE_SIGNATURE "\033sEX"

#define EVENT_INIT 0xff0001
#define EVENT_TERM 0xff0002
#define EVENT_TIMER 0xff0003

#ifdef SEXELIB
#include "lobject.h"
#include "llimits.h"
#include "lauxlib.h"
#include "lstate.h"
#include "sexe_bin.h"
#include "sexe_compile.h"
#include "sexe_func.h"
#include "sexe_test.h"
#include "sexe_event.h"
#include "sys/sexe_sys.h"
#else
typedef uint32_t Instruction;
int sexe_execv(char *path, char **argv);
int sexe_execve(char *path, char **argv, char *const envp[]);
int sexe_execm(shbuf_t *buff, shjson_t *arg);

int sexe_exec_popen(shbuf_t *buff, shjson_t *arg, sexe_t **mod_p);
void sexe_exec_pclose(sexe_t *S);
int sexe_exec_pevent(sexe_t *S, int e_type, shjson_t *arg);
int sexe_exec_pset(sexe_t *S, char *name, shjson_t *arg);
int sexe_exec_pget(sexe_t *S, char *name, shjson_t **arg_p);
int sexe_exec_pgetdef(sexe_t *S, char *name, shjson_t **arg_p);

int sexe_exec_prun(sexe_t *S);

int sexe_exec_pcall(sexe_t *S, char *func, shjson_t *json);

void sexe_table_set(lua_State *L, shjson_t *json);

shjson_t *sexe_table_get(lua_State *L);

shjson_t *sexe_table_getdef(lua_State *L);

#endif


/* v1 instruction operations. (tx_vm_t.vm_op) */
#define SEOP_NONE 0
#define SEOP_REQ 1
#define SEOP 2
#define SEOP_WRITE 3
#define SEOP_COMPARE 4 
#define SEOP_SYN 5
/** Request for a session to be opened. */
#define SEOP_OPEN 10
/** An confirmation that a session may be established. */
#define SEOP_ACCEPT 11
/** An rejection that a session may be established. */
#define SEOP_REJECT 12
/** A notification that a session will be closed. */
#define SEOP_CLOSE 13
/** A confirmation that the session has been closed. */
#define SEOP_ABEND 14



/* task modes (tx_run_t.run_mode) */
#define SEM_NONE 0
#define SEM_PREP 1
#define SEM_REQUEST 2
#define SEM_CONFIRM 3 
#define SEM_REJECT 4 
#define SEM_REGISTER 5
#define SEM_RUN 10
#define SEM_STATUS 11
#define SEM_CHECK 12
#define SEM_TERM_INFO 13
#define SEM_TERMINATE 14
#define SEM_COMPLETE 15
#define SEM_INACTION 20
#define SEM_RELOAD 21
#define SEM_SUSPEND 22
#define SEM_RESUME 23
#define SEM_SIGNAL 24
#define SEM_TIMER 25

/* mem operations (tx_mem_t.mem_op) */
#define SEMEM_SEEK 1 /* request */
#define SEMEM_READ 2
#define SEMEM_WRITE 3
#define SEMEM_COMPARE 4
#define SHMEM_LOCK 5
#define SHMEM_UNLOCK 6



/* stack modes */
#define SESTACK_NONE 0
#define SESTACK_INSTRUCTION 1
#define SESTACK_UPVAL 2
#define SESTACK_DEBUG 3
#define SESTACK_CONSTANT 4
#define SESTACK_FUNCTION 5
#define SESTACK_LITERAL 6 
#define SESTACK_UPVAL_DEBUG 10
#define SESTACK_LOCALVAR_DEBUG 11
#define SESTACK_INSTRUCTION_DEBUG 12




#if 0
/* constant types */
#define SECON_NIL 0
#define SECON_LITERAL 1
#define SECON_BOOL 2
#define SECON_NUMBER 3
#endif






/* vm operations. */
/** Request a 'virtual machine' be utilized. */
#define SEVM_REQUEST 1
/** Inform that a 'virtual machine' may be utilized. */
#define SEVM_NOTIFY 2







/** Perform job's tasks simutaneously. */
#define SEF_FRAGMENT (1 << 0)
/** Perform job's tasks in a sequence. */
#define SEF_SEQUENCE (1 << 1)
/** Undo job's actions if result code is failure. */
#define SEF_TRANSACTION (1 << 2)



/**
 * A segment of data being transferred to another host. 
 * @note Not currently used.
 */
typedef struct sexe_data_t
{
  shkey_t data_sink;
  uint64_t data_sink_of;
  shkey_t data_src;
  uint64_t data_src_of;
  uint32_t data_len;
  unsigned char data[0];
} sexe_data_t;

/**
 * @note Not currently used.
 */
typedef struct sexe_mem_t
{
  /** The length of the virtual memory segment. */
  uint64_t seg_len;
  /** The 64-bit virtual memory address. */
  uint64_t seg_addr;
} sexe_mem_t;


struct sexe_upval_t
{
  /* upval in stack? */
  uint8_t upv_instack;
  uint8_t upv_reserved[3];
  /* index of upval */
  uint32_t upv_index;
};
typedef struct sexe_upval_t sexe_upval_t;


struct sexe_const_t
{
  uint32_t con_type;
  uint64_t con_val;
};
typedef struct sexe_const_t sexe_const_t; 

struct sexe_debug_lvar_t 
{
  char lvar_name[MAX_SEXE_NAME_LENGTH];
  uint32_t lvar_startpc;
  uint32_t lvar_endpc;
};
typedef struct sexe_debug_lvar_t sexe_debug_lvar_t;

#define SEPARAMF_VARARG (1 << 0)
struct sexe_func_t
{

  uint32_t func_source; /* checksum of 'source' name */

  uint32_t func_line;
  uint32_t func_lline;

  uint8_t param_max;
  uint8_t param_flag;
  uint8_t stack_max;
  uint8_t _reserved_;

};
typedef struct sexe_func_t sexe_func_t;

struct sexe_stack_t 
{
  uint8_t type; /* function, param, local, or constant */
  uint8_t size; /* number of members */
  union {
    Instruction instr[0];
    unsigned char lit[0];
    sexe_const_t con[0];
    sexe_upval_t upv[0];
    sexe_func_t func[0];
    sexe_debug_lvar_t dbg_lvar[0];
  } stack;
};
typedef struct sexe_stack_t sexe_stack_t;




struct sexe_mod_t
{
  uint8_t sig[4]; /* SEXE_SIGNATURE */
  uint8_t ver;
  uint8_t fmt; /* 0 */ 
  uint8_t end; /* 1 */
  uint8_t sz_int; /* sizeof(int) */
  uint8_t sz_sizet; /* sizeof(size_t) */
  uint8_t sz_instr; /* sizeof(Intruction) */
  uint8_t sz_lnum; /* sizeof(lua_Number) */
  uint8_t integral; /* (lua_Number)0.5 == 0 */ 
  char name[MAX_SEXE_NAME_LENGTH];
  uint8_t tail[6]; /* SEXE_TAIL */
};
typedef struct sexe_mod_t sexe_mod_t;


#if 0
/**
 * A task specifying a set of instructions to perform.
 */
struct sexe_task_t {
  shkey_t task_id;

  /** The input argument for the task. */
  sexe_mem_t task_arg;

  /** The version capability of the instruction set. */
  uint32_t instr_ver;

  uint32_t mod_max;
  sexe_mod_t mod[0];
};
typedef struct sexe_task_t sexe_task_t;

/**
 * A vm thread performing a task.
 */
typedef struct sexe_thread_t 
{
  /** The current task being performed by the session. */
  sexe_task_t th_task;
  /* The task's instruction sequence index. */
  uint32_t th_instr_idx;
  /** A key unique to the originating job. */
  shkey_t th_job;
  /** A key reference to the memory pool used by the thread. */
  shkey_t th_pool;
  /** The time-stamp of when the thread was generated. */
  shtime_t th_birth;
} sexe_thread_t;

/**
 * A single job requested by an application containing a set of tasks.
 * @note Each job has an isolated 64-bit virtual memory-address space. 
 * @note The tasks are not required to be ran on the same vm.
 */
typedef struct sexe_job_t 
{
  /* A unique key representing the job. */
  shkey_t job_id;

  /** The time the job was created. */
  shtime_t job_stamp;

  /** The maximum execution time of the job. */
  shtime_t job_expire;

  /** The operational parameters for processing the intructions. */
  uint32_t job_flags;

  /** The priority of the job. */
  uint32_t job_prio;

  /** The machine platform associated with this job's execution. */
  uint32_t job_arch;

#if 0
  /** A set of tasks the job is compiled of. */
  uint32_t stack_max;
  sexe_task_t *stack;
#endif
} sexe_job_t;


/**
 * A session dedicated to running tasks on a virtual machine.
 */
typedef struct sexe_sess_t {
  uint32_t sess_op;
  shkey_t sess_id;
} sexe_sess_t;


/**
 * A virtual machine capable of handling a session.
 */
typedef struct sexe_vm_t {
 /** The machine platform associated with this thread's execution. */
  uint32_t vm_arch;
  /** A general priority established to perform remote tasks. */
  uint32_t vm_prio;
  /** The priveleged peer identity of the process running the vm. */
  shpeer_t vm_app;
  /** The time-stamp that the vm went 'online'. */
  shtime_t vm_stamp;
} sexe_vm_t;
#endif

#if 0
#define SEXE_OP_JUMP 10
#define SEXE_OP_CALL 11
#define SEXE_OP_RETURN 12
#define SEXE_OP_NOP 13
#define SEXE_OP_PRINT 14 /* to log */
#define SEXE_OP_LIFETIME 15

#define SEXE_CODE_MOVE 21
#define SEXE_CODE_CALL 32

#define SEXE_MEM_ALLOC 30
#define SEXE_MEM_ADDR 31 /* info ack */
#define SEXE_MEM_FREE 32

#define SEXE_OBJ_DATA_REQ 40
#define SEXE_OBJ_WRITE 41
#define SEXE_OBJ_COMPARE 42
#define SEXE_OBJ_CALL_NUM 43
#define SEXE_OBJ_CALL_NAME 44
#define SEXE_OBJ_PROC_NUM 45 /* get name of procedure in obj */
#define SEXE_OBJ_NEW 46
#define SEXE_OBJ_SYN 47 /* response to 'new obj' op */
#define SEXE_OBJ_DELETE 48
#define SEXE_OBJ_SEEK 49
#define SEXE_OBJ_NAME 50
#endif


#ifdef SEXELIB
#define RUNF_TEST (1 << 0)
#define RUNF_STRIP (1 << 1)
#define RUNF_VERBOSE (1 << 2)
#define RUNF_INPUT (1 << 3)
#define RUNF_LOCAL (1 << 4)
#define RUNF_OUTPUT (1 << 5)

#define VERBOSE(_fmt, ...) \
  ((run_flags & RUNF_VERBOSE) ? \
   printf(_fmt, __VA_ARGS__) : 0)

extern int run_flags;

void sexe_header(lu_byte* h, char *name);
#else
#define VERBOSE(_fmt, ...) (0)
#endif

extern double SEXE_VERSION;


const char *sexe_checkstring(sexe_t *S, int narg);

lua_Number sexe_checknumber(sexe_t *S, int narg);

char ac_sexe(void);

/**
 *  @}
 */

#ifdef __cplusplus
}
#endif


#endif /* ndef __SHARE_LIB__SEXE_H__ */
