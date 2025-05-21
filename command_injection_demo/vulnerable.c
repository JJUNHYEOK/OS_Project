#include <stdio.h>
#include <stdlib.h>


int main() {
    char input[100];
    printf("명령어 입력: ");
    scanf("%s", input);


    char cmd[150];
    sprintf(cmd, "ls %s", input);
    system(cmd); // 여기가 감시 대상
    return 0;
}
