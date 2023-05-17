#include<stdio.h>

int main(){
    int day=0;
    int mist=0;
    int number=0;
    int allow=1;

    scanf("%d %d %d", &day, &mist, &number);

    number = number%10;

    if(day==6||day==7||mist<200){
        allow=1;
    }
    else if(mist>=200&&mist<400){
        if(day==1&&(number==1||number==6))
            allow=0;
        else if(day==2&&(number==2||number==7))
            allow=0;
        else if(day==3&&(number==3||number==8))
            allow=0;
        else if(day==4&&(number==4||number==9))
            allow=0;
        else if(day==5&&(number==5||number==0))
            allow=0;
        else
            allow=1;
    }
    else if(mist>=400){
        switch(number){
        case 1: case 3: case 5: case 7:
        case 9:allow=(day==1||day==3||day==5)?0:1;break;
        case 0: case 2: case 4: case 6:
        case 8:allow=(day==2||day==4)?0:1;break;
        default:break; }
    }
    else
        printf("Wrong!");
    
    if(allow==1)
        printf("%d no",number);
    else if(allow==0)
        printf("%d yes",number);

    return 0;
}

