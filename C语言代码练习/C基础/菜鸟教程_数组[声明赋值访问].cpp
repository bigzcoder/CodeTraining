#include<stdio.h>
int main(){
	int n[10]; /* n是一个包含10个证书的数组 */
	int i,j;
	
	/* 初始化 数组元素 */
	for(i = 0;i<10;i++){
		n[i] = i+100; /* 设置元素i为i+100 */
	}
	
	/* 输出数组中每个元素的值 */
	for(j=0;j<10;j++){
		printf("Element[%d] = %d\n",j,n[j]);
	} 
	return 0;
}
