#include<stdio.h>

int main(){
    float kwh=0;
    float money=0;

    scanf("%f",&kwh);
    
    if(kwh>=0&&kwh<=110)
        money = kwh*0.5;
    else if(kwh>110&&kwh<=210)
        money = 55+(kwh-110)*0.55;
    else if(kwh>210)
        money = 110+(kwh-210)*0.7;
    else
        printf("Wrong!");
    
    printf("%.2f",money);

    return 0;
}