/*
	本实验主要实现二叉树的基本操作，二叉树中结点值的类型为char
	本实验主要实现5个操作：
	1、void CreatBitree(BiTree &T)  //输入二叉树的先序遍历序列（空树用字符'#'表示），创建二叉链表T
	2、void InOrderTraverse(BiTree T)   //中序遍历二叉树T
	3、void PreOrderTraverse(BiTree T)  //先序遍历二叉树T
	4、void PostOrderTraverse(BiTree T)  //后序遍历二叉树T
	5、bool SearchTree(BiTree T,char ch,BiTree &p)  //在二叉树T中查找值为ch的结点，查找成功，函数返回true,p指向该结点,否则函数返回false，p为空
	6、int Depth(BiTree T) //求二叉树T的深度
	7、int NodeCount(BiTree T)  //求二叉树T中结点的个数
	8、int LeafCount(BiTree T)  //求二叉树T中叶子结点的数量
	9、int NodeCount1(BiTree T)  //求二叉树T中度为1的结点的数量
	10、int NodeCount2(BiTree T)   //求二叉树T中度为2的结点的数量
*/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
//二叉链表结构
typedef struct BiTNode {
	char data;      //数据域,存放结点值
	struct BiTNode *lchild,*rchild;  //左右孩子指针
} BiTNode,*BiTree; // 二叉链表
//输入二叉树的先序遍历序列（空树用字符'#'表示），创建二叉链表T
void CreatBitree(BiTree &T) {
	// 请同学们补充此操作
	// 按先序次序输入二叉树中结点的值（一个字符），创建二叉树表示的二叉树T
	char ch;
	scanf("%c",&ch);
	if(ch=='#')
		T=NULL;		// 递归结束建量帐�
	else {
		T=(BiTree)malloc(sizeof(BiTNode));	// 生成父岬�
		T->data=ch; 			// 根结点数据域置为ch
		CreatBitree(T->lchild);	// 递归创建左子树
		CreatBitree(T->rchild); // 递归创建右子树
	}

}

//求二叉树T中值为ch的结点的层次，结果用p表示，curlevel表示当前T所在的层数，
//求值成功返回true,失败返回false
bool level(BiTree T,char ch,int curlevel,int &p) {
	if(T==NULL)  //若T为空树，返回false
		return false;
	if(T->data==ch) {  //若T的值为ch,则结点层数p为curlevel
		p=curlevel;
		return true;
	} else { //若T的值为ch,则先在T的左子树中求ch结点的层数，若ch结点不在T的左子树中，再在T的右子树中求ch结点的层数
		if(level(T->lchild,ch,curlevel+1,p))
			return true;
		else
			return level(T->rchild,ch,curlevel+1,p);
	}
}

//中序遍历二叉树T，输出其中序遍历序列
void InOrderTraverse(BiTree T) {
	//请同学们补充此操作
	// 中序遍历二叉树T的递归算法
	if(T) {
		InOrderTraverse(T->lchild); // 中序遍历左子树
		printf("%c ",T->data);
		InOrderTraverse(T->rchild); // 中序遍历右子树
	}
}

//先序遍历二叉树T，输出其先序遍历序列
void PreOrderTraverse(BiTree T) {
	//请同学们补充此操作
	if(T) {
		printf("%c ",T->data);
		PreOrderTraverse(T->lchild); // 中序遍历左子树
		PreOrderTraverse(T->rchild); // 中序遍历右子树
	}
}

//后序遍历二叉树T，输出其后序遍历序列
void PostOrderTraverse(BiTree T) {
	//请同学们补充此操作
	if(T) {
		PostOrderTraverse(T->lchild); // 中序遍历左子树
		PostOrderTraverse(T->rchild); // 中序遍历右子树
		printf("%c ",T->data);
	}
}

bool flag=false;
//在二叉树T中查找值为ch的结点，查找成功，函数返回true,p指向该结点,否则函数返回false，p为空
void SearchTree(BiTree T,char ch,BiTree &p) {
	//请同学们补充此操作
	if(T) {
		if(T->data==ch) {
			p=T;
			flag=true;
		}
		SearchTree(T->lchild,ch,p);
		SearchTree(T->rchild,ch,p);
	}
}

//求二叉树T的深度
int Depth(BiTree T) {
	//请同学们补充此操作
	int m,n;
	if(T==NULL)
		return 0; 		// 如果是空树，深度为0，递归结束
	else {
		m=Depth(T->lchild);
		n=Depth(T->rchild);
		if(m>n)
			return (m+1);
		else
			return (n+1);
	}
	return 0;  //补充完该操作后，请修改此行代码
}

//求二叉树T中结点总数
int NodeCount(BiTree T) {
	//请同学们补充此操作
	if(T==NULL)
		return 0;
	else
		return NodeCount(T->lchild)+NodeCount(T->rchild)+1;
	return 0;  //补充完该操作后，请修改此行代码
}

//求二叉树T中叶子结点总数
int LeafCount(BiTree T) {
	//请同学们补充此操作
	// 先序遍历二叉树，求二叉树中叶子结点的数目
	int m,n; // m,n分别表示左右子树中叶子的数目
	if(T==NULL)
		return 0;
	else if(T->lchild==NULL&&T->rchild==NULL)
		return 1;
	else {
		m=LeafCount(T->lchild);
		n=LeafCount(T->rchild);
		return m+n;
	}
	return 0;  //补充完该操作后，请修改此行代码
}


int a1=0,a2;
//求二叉树T中度为1的结点总数
void NodeCount1(BiTree T) {
	//请同学们补充此操作
	if(T) {
		if((T->lchild!=NULL&&T->rchild==NULL)||(T->lchild==NULL&&T->rchild!=NULL)) {
			a1++;
		}
		NodeCount1(T->lchild);
		NodeCount1(T->rchild);
	}
}

//求二叉树T中度为2的结点总数
void NodeCount2(BiTree T) {
	if(T) {
		if(T->lchild!=NULL&&T->rchild!=NULL) {
			a2++;
		}
		NodeCount2(T->lchild);
		NodeCount2(T->rchild);
	}
}

int main() {
	BiTree T,p=NULL;       //T为本程序中要操作的二叉链表
	char ch;    //ch表示在二叉树中要查询的结点
	cout<<"请输入要创建的二叉树，按先序序列输入，空树用字符'#'代替"<<endl;
	CreatBitree(T);  //根据输入的二叉树先序序列，创建二叉链表T
	cout<<"请输入要查询的结点"<<endl;
	cin>>ch;
	int n;
	level(T,ch,1,n);  //求值为ch结点的层数，初始时根的层数为1
	cout<<"该结点的层次为"<<n<<endl;
	cout<<endl<<"中序遍历结果为："<<endl;
	InOrderTraverse(T);      //输出二叉树T的中序遍历序列
	cout<<endl<<"先序遍历结果为："<<endl;
	PreOrderTraverse(T);     //输出二叉树T的先序遍历序列
	cout<<endl<<"后序遍历结果为："<<endl;
	PostOrderTraverse(T);    //输出二叉树T的后序遍历序列
	cout<<endl<<"请输入在二叉树中要查找的结点："<<endl;
	rewind(stdin);   //清空输入缓冲区
	cin>>ch;
	SearchTree(T,ch,p);   //在二叉树T中查找值为ch的结点
	if(flag)
		cout<<"在二叉树中查找成功,返回值为"<<p->data<<endl;
	else
		cout<<"二叉树中不存在值为"<<ch<<"的结点"<<endl;

	cout<<"二叉树的深度为"<<Depth(T)<<endl;
	cout<<"二叉树中总结点数为"<<NodeCount(T)<<endl;
	NodeCount1(T);
	NodeCount2(T);
	cout<<"叶子结点数、度为1结点数、度为2结点数分别为："<<LeafCount(T)<<","<<a1<<","<<a2<<endl;
	return 0;
}
