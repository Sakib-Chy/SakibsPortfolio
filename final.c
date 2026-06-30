#include<stdio.h>

int func(int arr[], int n, int value){
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == value)
        {
            return i;
        }
    }
    return -1;
}

int main(){
    int n, value;

    printf("Enter size of array: ");
    scanf("%d", &n);

    int array[n];

    for (int i = 0; i < n; i++)
    {
        printf("Enter the %d no. value: ", i+1);
        scanf("%d", &array[i]);
    }

    printf("Enter the number you want to search: ");
    scanf("%d", &value);

    int result = func(array, n, value);

    if (result == -1)
    {
        printf("Not found!");
    }
    else
    {
        printf("Number found at position %d", result + 1);
    }

    return 0;
}