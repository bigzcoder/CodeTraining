#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
	FILE *fp;
	char str[3][10],temp[10];
	// str是用来存放字符串的二维数组，temp是临时数组
	int i,j,k,n=3;
	printf("Enter string:\n"); //提示输入字符串
	for(i=0;i<n;i++) 
		gets(str[i]); // 输入字符串
	for(i=0;i<n-1;i++){
		k=i;
		for(j=i+1;j<n;j++){
			if(strcmp(str[k],str[j])>0){
				// strcmp s1==s2 0 s1<s2 小于0 s1>s2 大于0 
				k=j;
			}
		}
		if(k!=j){
			strcpy(temp,str[i]);
			strcpy(str[i],str[k]);
			strcpy(str[k],temp);
		}
	}
	if((fp=fopen("D:\\a\\string.dat","w"))==NULL){
		printf("can't open file!\n");
		exit(0);
	}
 	printf("\nThe new sequence:\n");
 	for(i=0;i<n;i++){
 		fputs(str[i],fp);
 		fputs("\n",fp);
 		// 向磁盘文件写一个字符串，然后输出一个换行符 
 		printf("%s\n",str[i]); //在屏幕上显示 
	}
	return 0;
}
