#ifndef __KSU_H_ADB_ROOT
#define __KSU_H_ADB_ROOT
#include <asm/ptrace.h>
#include "runtime/ksud.h"

#ifdef CONFIG_KSU_TRACEPOINT_HOOK
long ksu_adb_root_handle_execve_tracepoint(struct pt_regs *regs);
long ksu_adb_root_handle_execveat_tracepoint(struct pt_regs *regs);
#else
long ksu_adb_root_handle_execve_manual(const char *filename, struct user_arg_ptr *envp_p);
#endif

#ifdef CONFIG_KSU_ADB_ROOT_SHELL_ESCAPE
void ksu_adb_root_handle_shell_exec(const char *filename);
#else
static inline void ksu_adb_root_handle_shell_exec(const char *filename)
{
}
#endif

void ksu_adb_root_init(void);

void ksu_adb_root_exit(void);

#endif
