#include<stdio.h>
#include<string.h>

int main() {
    char str[101];
    scanf("%s", str);

    int count = 0;

    for(int i = 0; i < strlen(str); i++) {
        int unique = 1;

        for(int j = 0; j < i; j++) {
            if(str[i] == str[j]) {
                unique = 0;
                break;
            }
        }

        if(unique) {
            count++;
        }
    }

    if(count % 2 == 0) {
        printf("CHAT WITH HER!\n");
    } else {
        printf("IGNORE HIM!\n");
    }

    return 0;
}