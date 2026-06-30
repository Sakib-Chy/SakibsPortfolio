#include<stdio.h>
#include<string.h>

int main() {
    char s[101], t[101];
    
    scanf("%s", s);
    scanf("%s", t);

    int len = strlen(s);

    // reverse check directly
    for(int i = 0; i < len; i++) {
        if(s[i] != t[len - i - 1]) {
            printf("NO\n");
            return 0;
        }
    }

    printf("YES\n");

    return 0;
}