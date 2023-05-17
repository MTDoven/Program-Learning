#include<stdio.h>

int main(){
    int a,sum=0;
    scanf("%d",&a);
    sum = sum+a/100;
    a = a%100;
    sum = sum+a/10;
    a = a%10;
    sum = sum+a/1;

    printf("%d",sum);
    return 0;
}