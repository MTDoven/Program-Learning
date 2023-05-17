#include<stdio.h>
#define OBJECT 200
#define VALUE_MAX 20000
int array[OBJECT][VALUE_MAX]={0};
double destination=0;
int w[OBJECT]={0};

int main(){
    int n=-1;
    scanf("%d",&n);
    for(int i=0; i<OBJECT; i++)
        scanf("%d",&w[i]);
    for(int i=0; i<OBJECT; i++)
        destination += w[i];
    destination = destination/2;
    // To get close to destination


    return 0;
}

