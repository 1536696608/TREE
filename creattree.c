#include<stdio.h>
#include<stdlib.h>
typedef char Myment;

typedef struct Two_tree
{
	Myment a;
	struct Two_tree* left;
	struct Two_tree* right;
}Mytree;

Mytree* creat_tree1()
{
	char c;
	printf("请按前序方法输入,空格为空\n");
	fflush(stdin);
	scanf("%c",&c);
	Mytree* head;
	if(c == ' ')
	{
		return NULL;
	}
	else
	{
		head = (Mytree*)malloc(sizeof(Mytree));
		head->a = c;
		head->left =  creat_tree1();
		head->right = creat_tree1();
	}
	return head;
}
void* creat_tree2(Mytree** T)
{
	char c;
	printf("请按前序方法输入,空格为空\n");
	fflush(stdin);
	scanf("%c",&c);
	if(c == ' ')
	{
		*T = NULL;
	}
	
	else
	{
		*T = (Mytree*)malloc(sizeof(Mytree));
		(*T)->a = c;
		creat_tree2(&(*T)->left);
		creat_tree2(&(*T)->right);
	}
}

void* Listtree(Mytree* T)
{
	if(T != NULL)
	{
		printf("%c",T->a);
		Listtree(T->left);
		Listtree(T->right);
	}
}
int main()
{
	Mytree* T;
	T = creat_tree1();
	//creat_tree2(&T);
	Listtree(T);
	return 0;
}
