#include<stdio.h>

int main(){
	char string[] = "I love China";  // 定义字符数组string 
	printf("%s\n",string);			 // 用%s格式声明输出string，可以输出整个字符串  string 也为首地址 
	printf("%c\n",string[7]);		 // 用%c格式输出一个字符数组元素

	char *string = "HelloWorld";
	printf("%s",string);

	return 0; 
} 
