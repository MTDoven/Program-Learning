//分块查找的程序代码
#include<stdio.h>
//类型定义
typedef int keytype;
typedef struct
{
	keytype key;
	int low,high;
}index;
typedef struct
{
	keytype key;
}record;
const int recN=18;
const int idxN=3;

int blksearch(record[],index[],keytype,int);
int main()
{
	record r[recN]={22,12,13,8,9,20,33,42,44,38,24,48,60,58,74,49,86,53};
	index idx[idxN]={{22,0,5},{48,6,11},{86,12,17}};
	keytype key;
	int loc,i;
	printf("待查找的记录关键字表：\n");
	for(i=0;i<recN;i++)
		printf("%5d",r[i]);
	printf("\n");
	printf("输入所要查找记录的关键字：");
	scanf("%d",&key);
	loc=blksearch(r,idx,key,idxN);
	if(loc!=-1) printf("查找到，是第%d个记录。\n",loc+1);
	else printf("记录查找不到！\n");
	return 0; 
}

//添加折半查找索引表，块内顺序查找算法
int blksearch(record r[], index idx[], keytype key, int idxN) {
    int i, block = -1;
    for (i = 0; i < idxN; i++) { // 在索引表中定位块
        if (key <= idx[i].key) {
            block = i;  break; } }
    if (block != -1) // 在找到的块内进行线性查找
        for (int k = idx[block].low; k <= idx[block].high; k++) 
            if (r[k].key == key) 
                return k; // 找到目标，返回位置
    return -1; // 未找到
}


