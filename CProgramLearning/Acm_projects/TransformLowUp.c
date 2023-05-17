#include<stdio.h>


int main(){
    short T=-1;
    short n=-1;
    char character_list[100]="";
    char character = 0;
    short count = 0;
    char is_up = -1;
    char flag = 'l';
    
    char result[10000] = {0};
    scanf("%hd", &T);
    
    for(int i=0; i<T; i++){
        scanf("%hd", &n);
        scanf("%s", &character_list);
        for(int k=0; k<n; k++){
            character = character_list[k];

            if(character>=65 && character<=90)
                is_up = 1;
            else if (character==95){
                if(flag=='l') is_up=0;
                if(flag=='u') is_up=1;
                }
            else is_up=0;

            if((!is_up) && flag=='u'){
                flag = 'l';
                count = count+1;
            }
            if(is_up && flag=='o'){
                count = count+1;
                flag = 'u';
            }
            else if(flag=='o'){
                count = count+1;
                flag = 'l';
            }
            if(is_up && flag=='l')
                flag = 'o';
        }
        result[i] = (char)count;
        count = 0;
        flag = 'l';
    }

    for(int i=0; i<T; i++){
        printf("%d\n", result[i]);
    }
    return 0;
}

