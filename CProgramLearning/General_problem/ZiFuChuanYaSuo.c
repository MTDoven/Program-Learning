#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char *compress(char *src);

int main(){
	char src[100];
	scanf("%s",src);

	char *ps = compress(src);
	
	puts(ps);

    return 0;
}

char *compress(char *src){
    char save_string[101]={0};   char temp_string[101]={0};
    char temp_last_letter=-1;
    int count = 0;
    for(int i=0; i<strlen(src)+1; i++){
        if(temp_last_letter==src[i]){
            count++;
        } else if (temp_last_letter!=src[i]){
            if(count==0){
                sprintf(temp_string,"%c",temp_last_letter);
            } else if (count==1){
                sprintf(temp_string,"%c%c",temp_last_letter,temp_last_letter);
            } else {
                count++;
                sprintf(temp_string,"%c%d",temp_last_letter,count);
            }
            strcat(save_string,temp_string);
            count = 0; 
        }
        temp_last_letter = src[i];
    }
    strcpy(src,save_string+1);
    return src;
}