#include<stdio.h>
void Record(int x, int y);
int Check(int x, int y);

int sheet[24][24]={0};
int record[1024][2]={0};
int lines, column;
int times=0;

int main(){
    int pos,count=0;
    scanf("%d %d %d", &lines, &column, &pos);
    //input line, column, position
    for(int i=1; i<=lines; i++){
        for(int j=0; j<=column; j++)
            scanf("%c", &sheet[i][j]);
    }//input the whole sheet

    int x=1, y=pos, check=-100;
    while(1){
        if(sheet[x][y]=='N') x -= 1;
        else if(sheet[x][y]=='S') x += 1;
        else if(sheet[x][y]=='E') y += 1;
        else if(sheet[x][y]=='W') y -= 1;
        check = Check(x,y);
        if(check==-1){
            printf("loop %d", count);
            return 0;
        } else if(check==1){
            printf("out %d", count+1);
            return 0;
        } else if(check==0){
            Record(x,y);
            count++;
            times++;
        } else{
            printf("Wrong!!!");
            return 0;
        }
    }//calculate and output
}

void Record(int x, int y){
    record[times][0] = x;
    record[times][1] = y;
}//record the pos passed

int Check(int x, int y){
    if(x>lines || x<=0 || y>column || y<=0)
        return 1;
    for(int i=0; i<times; i++){
        if(record[i][0]==x && record[i][1]==y)
            return -1;
    }
    return 0;
}//check if it have gone out or in a loop