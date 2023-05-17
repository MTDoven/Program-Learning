#include<stdio.h>
#define LENGTH 10
void shuffle_add_one(char compute[LENGTH-1]);
void concentate(int pos, int array[LENGTH]);

int main(){
    int length;
    scanf("%d",&length);
    // input

    int array[LENGTH]={0};
    char compute[LENGTH]={0};
    int number_of_zero=0;
    int count=0;
    // initiate

    while (compute[length-1]!=1) {
        for (int i=0; i<length; i++)
            array[i] = i+1;
        count=0;
        for (int i=0; i<length; i++)
            if (compute[i]==2){
                concentate(i-count, array);
                count++;
            }
        int result=array[0];
        count=0;
        for (int i=0; i<length-1; i++) {
            if (compute[i]==2){
                count++;
                continue;
            }
            if (compute[i]==0)
                result = result + array[i+1-count];
            else if (compute[i]==1)
                result = result - array[i+1-count];
        }
        // printf("%d ",result);
        if (result==0)
            number_of_zero++;
        shuffle_add_one(compute);
    } // compute

    printf("%d", number_of_zero);
    return 0;
}


void shuffle_add_one(char compute[LENGTH-1]){
    static int index=0;
    compute[0] += 1;
    for (int i=0; i<LENGTH-1; i++) {
        if (compute[i]>=3) {
            compute[i] -= 3;
            compute[i+1] += 1;
        } else break;
    } // shuffle
}
void concentate(int pos, int array[LENGTH]){
    array[pos] = array[pos]*10+array[pos+1];
    for (int i=pos+1; i<LENGTH-1; i++)
        array[i] = array[i+1];
}

