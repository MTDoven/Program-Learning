//������������
#include<stdio.h>
#include<malloc.h>
//����Ľṹ���Ͷ���
const int m=3;
const int n=3;
typedef struct{
	int A[m+1][n+1];
	int max[m+1],min[n+1];
}array;
void minmax(array*);

int main()
{
	array*pa=(array*)malloc(sizeof(array));
    int i, j;
    for (i=1;i<=m;i++)
      for (j=1;j<=n;j++)
        scanf("%d",&pa->A[i][j]);
    minmax(pa);
  return 0;
}

//����������㷨
void minmax(array *pa) {
    int i, j, k, saddlePointExists = 0;

    for (i = 1; i <= m; i++) {
        pa->max[i] = pa->A[i][1];
        for (j = 2; j <= n; j++) {
            if (pa->A[i][j] > pa->max[i])
                pa->max[i] = pa->A[i][j];
        }
    }// ��ʼ��ÿ�е����ֵ
    
    for (j = 1; j <= n; j++) {
        pa->min[j] = pa->A[1][j];
        for (i = 2; i <= m; i++) {
            if (pa->A[i][j] < pa->min[j])
                pa->min[j] = pa->A[i][j];
        }
    }// ��ʼ��ÿ�е���Сֵ
    
    for (i = 1; i <= m; i++) {
        for (j = 1; j <= n; j++) {
            if (pa->A[i][j] == pa->max[i] && pa->A[i][j] == pa->min[j]) {
                printf("������ [%d, %d] ��ֵ�� %d\n", i, j, pa->A[i][j]);
                saddlePointExists = 1;
            }
        }
    }// ��������

    if (!saddlePointExists) {
        printf("û������\n");
    }
}


