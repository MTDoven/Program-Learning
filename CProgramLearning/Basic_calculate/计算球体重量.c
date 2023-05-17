#include<stdio.h>

int main(){
    double PI=3.1415926;
    float Fe,Au;  
    scanf("%f%f",&Fe,&Au);
    Fe = 4.0/3.0*PI*Fe*Fe*Fe*7.86/8000;
    Au = 4.0/3.0*PI*Au*Au*Au*19.3/8000;
    printf("%.3f  %.3f",Fe,Au);
    return 0;
}