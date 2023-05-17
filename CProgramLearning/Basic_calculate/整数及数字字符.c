#include<stdio.h>

int main(){
    int a;
    char b;
    char c;
    scanf("%d,%c,%c",&a,&b,&c);
    printf("%d %c %d",a+b+c,b+c,b+c);

    return 0;
}