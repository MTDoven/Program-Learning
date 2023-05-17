#include<iostream>
using namespace std;

int main(){
    int array[5]={0};

    for(int i=0; i<4; i++){
        scanf("%d,", &array[i]);
    }scanf("%d", &array[4]);

    for(int i=4; i>0; i--){
        printf("%d ", array[i]);
    }printf("%d", array[0]);

    return 0;
}