#include<stdio.h>

int main(){
    int a,b,c,d;
    int max;
    scanf("%d%d%d%d",&a,&b,&c,&d);
    
    max=a;
    max=(max>b)?max:b;
    max=(max>c)?max:c;
    max=(max>d)?max:d;

    printf("%d",max);
    return 0;
}