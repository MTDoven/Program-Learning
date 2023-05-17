#include<stdio.h>
#define LENGTH 1000002
int search(int now);
int search_new_point(int now);
void init();

int tree[LENGTH+1][3];//储存数组
int tree_inview[LENGTH+1][3];
int dots=-1, view=-1;
int countmax=0, countmin=0;
int now=-1;

int main(){
    init();
    for(int i=dots-1; i>=0; i--){
        now = i;
        search_new_point(i);
    }
    printf("%d %d", tree[0][1], tree[0][2]);
    return 0;
}

int search(int now){
    if(now>=dots){
        updata:
        if(tree[now][1]<countmax)
            tree[now][1]=countmax;
        if(tree[now][2]>countmin)
            tree[now][2]=countmin;
        return 1;
    }//已经算到结尾做好记录
    countmax += tree[now][1];
    countmin += tree[now][2];
    goto updata;
}
   
int search_new_point(int now){
    if(tree[now][0]==0){
        for(int i=1; i<=view; i++){
            countmax=1; countmin=1;
            search(now+i);
        }
    }
    else{
        countmax=0; countmin=0;
        search(tree[now][0]+now);
    }
    return 1;
}

void init(){
    scanf("%d %d", &dots, &view);
    for(int i=1; i<=dots; i++){
        scanf("%d",&tree[i][0]);//原数据
        tree[i][1]=-1;//最大值
        tree[i][2]=2147483647;//最小值
    }
    tree[0][0]=0;
    tree[0][1]=-1;
    tree[0][2]=2147483647;
    tree[dots+1][0]=-1;
}




