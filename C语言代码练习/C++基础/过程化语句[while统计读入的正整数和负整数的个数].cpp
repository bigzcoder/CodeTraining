#include<iostream>
#include<stdio.h>
using namespace std; 
int main() {
	int i=0,j=0,n;
	cout<<"请输入若干整数（输入0则结束）：";
	cin>>n;
	while(n!=0){
		if(n>0)
			i+=1;
		if(n<0)
			j+=1;
		cin>>n;
	}
	cout<<"正整数个数："<<i<<endl;
	cout<<"负整数个数："<<j<<endl;
	return 0;
}


