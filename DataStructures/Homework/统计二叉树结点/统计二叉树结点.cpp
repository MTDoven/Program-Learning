//ͳ�ƽ��������Ҷ�ӽ�������ĳ������
#include<stdio.h>
#include<malloc.h>
//��������Ľṹ���Ͷ���
const int maxsize=1024;
typedef char datatype;
typedef struct node
{
	datatype data;
	struct node *lchild,*rchild;
}bitree;

bitree*creattree();
void preorder(bitree*);
int countnode(bitree*); 
int countleaf(bitree*); 

int main()
{
	bitree*root;
	int leafnum,nodenum;
	root=creattree();
	printf("ɾ������֮ǰ�Ķ�������");
	preorder(root);
	printf("\n");
    nodenum=countnode(root);
    printf("��������ǣ�%d\n",nodenum);
	leafnum=countleaf(root); 
    printf("Ҷ�ӽ�������ǣ�%d\n",leafnum);
	return 0;
}

//����������
bitree*creattree()
{
	datatype ch;
	bitree*Q[maxsize];
	int front,rear;
	bitree*root,*s;
	root=NULL;
	front=1;rear=0;
	printf("�����������ֵ����������'@'���Ի��з�������");
	while((ch=getchar())!='\n')
	{
		s=NULL;
		if(ch!='@')
		{
			s=(bitree*)malloc(sizeof(bitree));
			s->data=ch;
			s->lchild=NULL;
			s->rchild=NULL;
		}
		rear++;
		Q[rear]=s;
		if(rear==1)root=s;
		else
		{
			if(s&&Q[front])
				if(rear%2==0)Q[front]->lchild=s;
				else Q[front]->rchild=s;
			if(rear%2==1)front++;
		}
	}
	return root;
}

//����������������
void preorder(bitree*p)
{
	if(p!=NULL)
	{
		printf("%c",p->data);
		if(p->lchild!=NULL||p->rchild!=NULL)
		{
			printf("(");
			preorder(p->lchild);
			if(p->rchild!=NULL) printf(",");
			preorder(p->rchild);
			printf(")");
		}
	}
}

//���ͳ�ƽ������㷨
int countnode(bitree *root) {
    if(root == NULL) return 0; //��ǰ�ڵ�Ϊ�գ�����0
    else {
        int left = countnode(root->lchild);   //ͳ���������ڵ����
        int right = countnode(root->rchild);  //ͳ���������ڵ����
        return left + right + 1;  //�������������ڵ����֮���ټ�������һ���ڵ㣬��һ�����ж��ٽڵ�
    }
}

//���ͳ��Ҷ�ӽ������㷨
int countleaf(bitree *root) {
    if(root == NULL) return 0; //����ڵ�Ϊ�գ��򷵻�0
    else if(root->lchild == NULL && root->rchild == NULL) return 1; //����ڵ�ΪҶ�ӽڵ㣬����1
    else {
        int left = countleaf(root->lchild);   //ͳ����������Ҷ�ӽڵ�ĸ���
        int right = countleaf(root->rchild);  //ͳ����������Ҷ�ӽڵ�ĸ���
        return left + right;  //Ҷ�ӽڵ������Ϊ������Ҷ�ӽڵ������������Ҷ�ӽڵ����
    }
}
