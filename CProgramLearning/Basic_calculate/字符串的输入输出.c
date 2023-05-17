#include<stdio.h>

int main(){
    char A,B,C,D,E;
    scanf("%c|%c|%c|%c|%c",&A,&B,&C,&D,&E);
    A += 32;
    B += 32;
    C += 32;
    D += 32;
    E += 32;
    printf("%c%c%c%c%c!",A,B,C,D,E);
    return 0;
}