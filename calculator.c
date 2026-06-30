#include<stdio.h>
float add(float a, float b);
float sub(float a, float b);
float mul(float a, float b);
float div(float a, float b);

int main(){
    float a, b, ans;
    char c;
    printf("Enter your first number: ");
    scanf("%f", &a);
    printf("Enter your second number: ");
    scanf("%f", &b);
    printf("Enter your operation(+, -, *, /): ");
    scanf(" %c", &c);

    if(c == '+'){
        ans = add(a, b);
    }else if (c == '-'){
        ans = sub(a, b);
    }else if (c == '*'){
        ans = mul(a, b);
    }else if (c == '/'){
        ans = div(a, b);
    }else
    {
        printf("Operation failed.");
    }
    printf("Your answer is: %f", ans);
}
float add(float a, float b){return a+b;}
float sub(float a, float b){return a-b;}
float mul(float a, float b){return a*b;}
float div(float a, float b){return a/b;}