#include<stdio.h>

int calcu_cars(int time);

int main(){
    int i=0;
    int m[32]={0};

    while(1){
        scanf("%d",&m[i]);
        if(m[i]==0) break;
        i++;
    }
    int j;
    for(j=0;j<i-1;j++)
        printf("%d ",calcu_cars(m[j]));
    printf("%d",calcu_cars(m[j]));
    return 0;
}

int calcu_cars(int time){
    int cars;
    cars = (time/90)*60*3;
    time = time%90;
    if(time>=60) cars += 180;
    else cars += time*3;
    return cars;
}