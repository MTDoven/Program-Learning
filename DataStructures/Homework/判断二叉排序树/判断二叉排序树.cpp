//�ж϶����������ĳ������
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
//��������Ľṹ���Ͷ���
const int maxsize=1024;
typedef int keytype;
typedef struct node
{
	keytype key;
	struct node *lchild,*rchild;
}bitree;

bitree*creattree();
void preorder(bitree*);
int inorder(bitree*);

int main() {
    bitree* pb;
    pb = creattree();
    preorder(pb);
    printf("\n");
    if (inorder(pb))
        printf("�Ƕ�����������\n");
    else
        printf("���Ƕ�����������\n");
    return 0;
}

//�������Ľ���
bitree*creattree()
{
	keytype x;
	bitree*Q[maxsize];
	int front,rear;
	bitree*root,*s;
	root=NULL;
	front=1;rear=0;
	printf("�����������������������ͽ������,0��ʾ����,-1��ʾ����:\n");
	scanf("%d",&x);//����0��ʾ���㣬-1��ʾ����
	while(x!=-1)
	{
		s=NULL;
		if(x!=0)
		{
			s=(bitree*)malloc(sizeof(bitree));
			s->key=x;
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
		scanf("%d",&x);;
	}
	return root;
}

//�����������
void preorder(bitree*p){
	if(p!=NULL)	{
		printf("%d",p->key);
		if(p->lchild!=NULL||p->rchild!=NULL)		{
			printf("(");
			preorder(p->lchild);
			if(p->rchild!=NULL) printf(",");
			preorder(p->rchild);
			printf(")");
		}
	}
}

int inorder(bitree *node) {
	static int last_num=-1;
    if (node == NULL) return 1;
    if(!inorder(node->lchild)) return 0;  // ����������
	if (last_num <= node->key){
		last_num = node->key;
	} else return 0;
    if(!inorder(node->rchild)) return 0;  // ����������
	return 1;
}

// //�ж϶���������
// int isBST(bitree *root) {
// 	if (root==NULL) return 1;
// 	if (root->lchild!=NULL && root->lchild->key > root->key) return 0;
// 	if (root->rchild!=NULL && root->rchild->key < root->key) return 0;
//     if (!isBST(root->lchild)) return 0;
// 	if (!isBST(root->rchild)) return 0;
//     return 1;
// }
