//模式匹配的程序代码
#include<stdio.h>
#include<string.h>
#include<malloc.h>
//顺序串的结构类型定义
#define maxsize 100
typedef struct
{  
	char str[maxsize];
    int len;
}seqstring;

int  Index(seqstring*, seqstring*);

int main()
{
	seqstring*S,*subS;
	S=(seqstring*)malloc(sizeof(seqstring));
	subS=(seqstring*)malloc(sizeof(seqstring));
	printf("输入串："); gets(S->str);
	S->len=strlen(S->str);
	printf("输入子串："); gets(subS->str);
	subS->len=strlen(subS->str);
	if(Index(S,subS)>0) printf("匹配成功！\n");
	else printf("匹配失败！\n");
	return 0;
}

//添加顺序串的朴素模式匹配算法
int Index(seqstring *S, seqstring *subS) {
    int i = 0, j = 0;

    while (i < S->len && j < subS->len) {
        if (S->str[i] == subS->str[j]) { // 当前字符匹配
            i++; j++;
        } else {
            i=i-j+1; j=0;  // 主串回溯，子串从头开始
        }
    }

    if (j == subS->len) return i - subS->len; // 匹配成功，返回子串在主串中的位置
    else return -1; // 匹配失败
}














