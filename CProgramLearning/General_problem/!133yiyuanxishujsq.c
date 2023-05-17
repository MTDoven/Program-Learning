#include<stdio.h>
#define LENGTH 80000


int dxs1[LENGTH]={0};
int dxs2[LENGTH]={0};
int result[LENGTH]={0};
int length1,length2,sign;


int iter(){
    static int index=-1; 
    return result[++index]; }
int AddArray(int* result ,int* array1, int* array2, int length){
    for(int i=0; i<length; i++)
        result[i] = array1[i]+array2[i];
    return 0; }
int MineArray(int* result ,int* array1, int* array2, int length){
    for(int i=0; i<length; i++)
        result[i] = array1[i]-array2[i];
    return 0; }
void ShowArray(int* array, int length);


int main(){
    int bottom,upper;
    scanf("%d %d %d", &length1, &length2, &sign);
    //input basic info
    for(int i=0; i<length1; i++){
        scanf("%d%d",&bottom,&upper);
        dxs1[upper]=bottom;
    }//input the first dxs
    for(int i=0; i<length2; i++){
        scanf("%d%d",&bottom,&upper);
        dxs2[upper]=bottom;
    }//input the second dxs
    if(sign==0)
        AddArray(result, dxs1, dxs2, LENGTH);
    else if(sign==1)
        MineArray(result, dxs1, dxs2, LENGTH);
    //calculate
    ShowArray(result, LENGTH);
    //output
    return 0;
}


void ShowArray(int* array, int length){
    int now, index=0;

    process_zero:
    for(int i=0; i<length; i++)
        if(array[i]!=0) goto first_zero;
    printf("0");
    return;

    first_zero:
    now = iter(); 
    if(now==0){index++; goto first_one;}
    else if(now==1) printf("1");
    else if(now==-1) printf("-1");
    else if(now>0) printf("%d",now);
    else if(now<0) printf("%d",now);
    index++;
    goto remain_one;

    first_one:
    now = iter(); 
    if(now==0){index++; goto first_remain;}
    else if(now==1) printf("x");
    else if(now==-1) printf("-x");
    else if(now>0) printf("%dx",now);
    else if(now<0) printf("%dx",now);
    index++;
    goto remain_remain;

    remain_one:
    now = iter(); 
    if(now==0){index++; goto remain_remain;}
    else if(now==1) printf("+x");
    else if(now==-1) printf("-x");
    else if(now>0) printf("+%dx",now);
    else if(now<0) printf("%dx",now);
    index++;
    goto remain_remain;

    first_remain:
    while(index<length){
        now = iter();
        if(now==0){index++; continue;}
        else if(now==1) printf("x^%d",index);
        else if(now==-1) printf("-x^%d",index);
        else if(now>0) printf("%dx^%d",now,index);
        else if(now<0) printf("%dx^%d",now,index);
        index++;
        goto remain_remain;
    }

    remain_remain:
    while(index<length){
        now = iter();
        if(now==0){index++; continue;}
        else if(now==1) printf("+x^%d",index);
        else if(now==-1) printf("-x^%d",index);
        else if(now>0) printf("+%dx^%d",now,index);
        else if(now<0) printf("%dx^%d",now,index);
        index++;
    }
}





