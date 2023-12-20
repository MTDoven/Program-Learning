//统计结点总数及叶子结点总数的程序代码
#include<stdio.h>
#include<malloc.h>
//二叉链表的结构类型定义
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
	printf("删除子树之前的二叉树：");
	preorder(root);
	printf("\n");
    nodenum=countnode(root);
    printf("结点总数是：%d\n",nodenum);
	leafnum=countleaf(root); 
    printf("叶子结点总数是：%d\n",leafnum);
	return 0;
}

//建立二叉树
bitree*creattree()
{
	datatype ch;
	bitree*Q[maxsize];
	int front,rear;
	bitree*root,*s;
	root=NULL;
	front=1;rear=0;
	printf("按层次输入结点值，虚结点输入'@'，以换行符结束：");
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

//先序遍历输出二叉树
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

//添加统计结点个数算法
int countnode(bitree *root) {
    if(root == NULL) return 0; //当前节点为空，返回0
    else {
        int left = countnode(root->lchild);   //统计左子树节点个数
        int right = countnode(root->rchild);  //统计右子树节点个数
        return left + right + 1;  //返回左右子树节点个数之和再加上自身一个节点，算一个树有多少节点
    }
}

//添加统计叶子结点个数算法
int countleaf(bitree *root) {
    if(root == NULL) return 0; //如果节点为空，则返回0
    else if(root->lchild == NULL && root->rchild == NULL) return 1; //如果节点为叶子节点，返回1
    else {
        int left = countleaf(root->lchild);   //统计左子树中叶子节点的个数
        int right = countleaf(root->rchild);  //统计右子树中叶子节点的个数
        return left + right;  //叶子节点的总数为左子树叶子节点个数加右子树叶子节点个数
    }
}
