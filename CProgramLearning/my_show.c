
/* Use this function to show all content int the array.
if length==0 it will check and stop at the -1. */
void ShowArray(int* array, int length){
    if(length!=0){
        for(int i=0; i<length; i++)
            printf("%d ", array[i]);
    } else{//if length is a number according to the number
        int index=-1;
        while(array[++index]!=-1)
            printf("%d ", array[index]);
    }//if length is 0 according to the -1
}

/* Use this function to Iter the array*/
int IterChar(char* array){
    static int index=-1; 
    return array[++index];
}//Different mode is used for different type of array
int IterInt(int* array){
    static int index=-1; 
    return array[++index];
}