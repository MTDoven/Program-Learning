#include<stdio.h>
int count[1024]={0};


int main(){
    int n;
    scanf("%d",&n);
    int temp;
    for(int i=0; i<n; i++){
        scanf("%d",&temp);
        count[temp]++;
    }

    for(int i=1023; i>0; i--)
        for(int j=0; j<1024; j++)
            if(count[j]==i)
                printf("%d %d\n", j, i);

    return 0;
}