#include<stdio.h>

int main(){
    int n;
    scanf("%d",&n);
    int t[32]={0};
    float p[32]={0.0};
    for(int i=0; i<n; i++){
        scanf("%d",&t[i]);
        scanf("%f",&p[i]);
    }
    double sum=0;
    int t_sum=0;
    for(int i=0; i<n; i++)
        sum = sum+t[i]*p[i];
    for(int i=0; i<n; i++)
        t_sum = t_sum+t[i];
    printf("%.2f %.2f",sum,sum/t_sum);
    
    return 0;
}