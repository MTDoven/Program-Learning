//�Գƾ�����˵ĳ������
#include<stdio.h>
#include<malloc.h>
//����ṹ���͵Ķ���.h
const int n=3;
const int size=n*(n+1)/2;
typedef int datatype;
typedef struct{
	datatype A[size],B[size],C[n][n];
}array;

void input(datatype[]);
void output(datatype[][n]);
void mult(array*);

int main()
{
	array*pa;
	pa=(array*)malloc(sizeof(array));
	printf("����Ϊ�����������A��������:\n");
    input(pa->A);//����Ϊ�����������A��������
	printf("����Ϊ�����������B��������:\n");
	input(pa->B);//����Ϊ�����������B��������
	mult(pa);
	output(pa->C);//�������C
	return 0;
}

//�Գƾ��������
void input(datatype x[])
{
	for(int i=0;i<size;i++)
		scanf("%d",&x[i]);
}

//��������
void output(datatype x[][n])
{
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			printf("%5d",x[i][j]); 
		printf("\n");
	}
}

//��ӶԳƾ�������㷨
void mult(array *pa) {
    // �������˻�
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                int a_ik = (i >= k) ? pa->A[i * (i + 1) / 2 + k] : pa->A[k * (k + 1) / 2 + i];
                int b_kj = (k >= j) ? pa->B[k * (k + 1) / 2 + j] : pa->B[j * (j + 1) / 2 + k];
                pa->C[i][j] += a_ik * b_kj;
}   }   }   }




