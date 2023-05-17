#include<stdio.h>

int main(){
    float t,h;
    scanf("%f",&t);
    h = 1000-0.5*9.8*t*t;
    if(h<0) h=0.0;
    
    printf("%.2f",h);
    return 0;
}