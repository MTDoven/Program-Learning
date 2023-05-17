#include<stdio.h>

int main(){
    int input;
    scanf("%d",&input);

    printf("%d ",input/100);
    input = input%100;
    printf("%d ",input/10);
    input = input%10;
    printf("%d",input);

    return 0;
}