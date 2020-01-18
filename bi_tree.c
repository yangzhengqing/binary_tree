
#include "stdio.h"
#include "stdlib.h"

typedef char ElemType;

typedef struct BiTNode
{
	ElemType data;
	struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

//创建一颗二叉树,前序遍历方式输入数据
void create_BiTree(BiTree *T)
{
	ElemType c;

	scanf("%c",&c);
	if(c == ' ')
	{
		*T = NULL;
	}
	else
	{
		*T = (BiTNode *)malloc(sizeof(BiTNode));
		(*T)->data = c;
		create_BiTree(&(*T)->lchild);
		create_BiTree(&(*T)->rchild);
	}
}

//访问二叉树结点的具体操作
void visit(char c,int level)
{
	printf("%c 位于第 %d 层\n",c,level);

}

//前序遍历二叉树
void pre_order_traverse(BiTree T,int level)
{
	if(T)
	{
		visit(T->data,level);
		pre_order_traverse(T->lchild,level+1);
		pre_order_traverse(T->rchild,level+1);
	}
}

int main(int argc,char **argv)
{
	int level = 1;
	BiTree T = NULL;

	create_BiTree(&T);
	pre_order_traverse(T,level);
	return 0;
}

