//ģʽƥ��ĳ������
#include<stdio.h>
#include<string.h>
#include<malloc.h>
//˳�򴮵Ľṹ���Ͷ���
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
	printf("���봮��"); gets(S->str);
	S->len=strlen(S->str);
	printf("�����Ӵ���"); gets(subS->str);
	subS->len=strlen(subS->str);
	if(Index(S,subS)>0) printf("ƥ��ɹ���\n");
	else printf("ƥ��ʧ�ܣ�\n");
	return 0;
}

//���˳�򴮵�����ģʽƥ���㷨
int Index(seqstring *S, seqstring *subS) {
    int i = 0, j = 0;

    while (i < S->len && j < subS->len) {
        if (S->str[i] == subS->str[j]) { // ��ǰ�ַ�ƥ��
            i++; j++;
        } else {
            i=i-j+1; j=0;  // �������ݣ��Ӵ���ͷ��ʼ
        }
    }

    if (j == subS->len) return i - subS->len; // ƥ��ɹ��������Ӵ��������е�λ��
    else return -1; // ƥ��ʧ��
}














