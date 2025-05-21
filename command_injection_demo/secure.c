// secure.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>


int is_safe_input(const char *input) {
    // 위험한 메타문자 차단: ; & | > < ` $ 등
    const char *blacklist = ";|&><`$";
    for (int i = 0; input[i]; i++) {
        if (strchr(blacklist, input[i])) {
            return 0; // 위험함
        }
    }
    return 1; // 안전함
}


int main() {
    char input[100];
    printf("디렉터리 입력: ");
    scanf("%99s", input);


    if (!is_safe_input(input)) {
        printf("위험한 입력이 감지되었습니다.\n");
        return 1;
    }


    char *args[] = {"ls", input, NULL};
    execvp("ls", args); // 안전한 방식: 쉘을 거치지 않음


    perror("execvp 실패");
    return 1;
}
