// secure_wrapper.c
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dlfcn.h>


int execve(const char *filename, char *const argv[], char *const envp[]) {
    // 원래 execve 가져오기
    static int (*real_execve)(const char *, char *const[], char *const[]) = NULL;
    if (!real_execve) {
        real_execve = dlsym(RTLD_NEXT, "execve");
    }


    // 로그 출력
    fprintf(stderr, "[LD_PRELOAD] execve 호출 감지: %s\n", filename);
   
    // 위험 명령어 감지 예시 (rm 실행 차단)
    if (strstr(filename, "rm") != NULL) {
        fprintf(stderr, "위험 명령어 실행 차단됨: %s\n", filename);
        return -1;
    }
    return real_execve(filename, argv, envp);
}
