#include<stdio.h>

void swap(int *p1,int *p2);		// 对swap函数的声明 

int main(){
	int a,b;
	int *pointer_1,*pointer_2;	// 定义两个int*型的指针变量 
	printf("please enter a and b:");
	scanf("%d,%d",&a,&b);		// 输入两个整数 
	
	pointer_1=&a;				// 使pointer_1指向a 
	pointer_2=&b;				// 使pointer_2指向b 
	if(a<b)						// 如果a<b 调用a<b 调用swap函数 
		swap(pointer_1,pointer_2);
	printf("max=%d,min=%d\n",a,b);// 输出结果 
	return 0;
} 

void swap(int *p1,int *p2){		// 定义swap函数 
	int temp;
	temp=*p1;					// 使*p1和*p2互换 
	*p1=*p2;
	*p2=temp;
}
