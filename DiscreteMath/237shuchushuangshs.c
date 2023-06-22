#include<stdio.h>
#include<string.h>
#define RESULT_LENGTH 1000
#define SET_LENGTH 100
int PopSort(int* array, int length);
void next(int index);
void process();
void show();
void init();

int A[SET_LENGTH]={0};
int B[SET_LENGTH]={0};
int result[RESULT_LENGTH][SET_LENGTH]={0};
int layer=0; int a,b;

int main(){
    scanf("%d %d",&a,&b);
    for (int i=0; i<a; i++) scanf("%d",&A[i]); 
    for (int i=0; i<b; i++) scanf("%d",&B[i]);
    PopSort(A,a);
    PopSort(B,b);

    init();
    next(0);
    process();

    show();

    return 0;
}


void init(){
    int counter = 0;
    int* i = &result[0][0];
    while(counter<SET_LENGTH*RESULT_LENGTH){
        *i = -2147483647;
        i++;counter++;
    }
}
void process(){
    int counter = 0;
    int* i = &result[0][0];
    while(counter<SET_LENGTH*RESULT_LENGTH){
        if (*i==-2147483647) *i = *(i-SET_LENGTH);
        i++; counter++;
    }
}
void next(int index){
    for(int i=0; i<b; i++){
        result[layer][index]=B[i];
        if (index<a-1) {
            next(index+1);
            continue;
        }
        layer++;
    }
}
int PopSort(int* array, int length){
    int temp;
    for(int i=0; i<length; i++)
        for(int j=0; j<length-i-1; j++){
            if(array[j]>array[j+1]){
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp; }
        }//the upper is small2big the lower is big2small
    return 0;
}
int contain(int series[], int n, int number){
    for (int i=0; i<n; i++){
        if(series[i]==number) return 1;
    } return 0;
}
int duplicated(int series[], int n) {
    int i,j;
    for(i=0; i<n-1; ++i) {
        for(j=i+1; j<n; ++j)
            if(series[i]==series[j]) return 1;
    } return 0;
}

void show(){
    int flag = 0;
    for (int i=0; i<layer; i++){

        flag=0;
        for (int j=0; j<b; j++)
            if(!contain(result[i], a, B[j])) {
                flag=1; break; }
        if(flag==1) continue;

        if(duplicated(result[i], a)) continue;

        printf("{");
        for (int j=0; j<a-1; j++){
            printf("<%d,%d>,",A[j],result[i][j]);
        } printf("<%d,%d>",A[a-1],result[i][a-1]);
        printf("}\n");
    }
}
