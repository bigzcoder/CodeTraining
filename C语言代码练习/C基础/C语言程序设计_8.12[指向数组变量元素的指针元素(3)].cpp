#include<stdio.h>

/*
	注意第5行不应写成p=a，因为这样写表示p的值是&a[0]  

*/ 
 
int main(){
	int a[4]={1,3,5,7};		// 定义一维数组a 包含4个元素 
	int(*p)[4];				// 定义指向包含4个数组元素的一维数组的指针变量中 
	p=&a;
	printf("%d\n",(*p)[3]); // 输出a3 
	return 0;
	
}
