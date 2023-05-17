#include<stdio.h>

int main(){
    float hour,minute;
    float temp;
    scanf("%f %f",&hour,&minute);

    hour = hour+minute/60.0;
    temp = 4*hour*hour/(hour+2)-20;

    printf("%.2f",temp);
    return 0;
}