#include<iostream> 
#include<math.h>
using namespace std;

int main(){
	int x,y;
	cout<<"Enter x and y:";
	cin>>x>>y;
	if(x!=y){
		if(x>y)
			cout<<"x>y"<<endl;
		else
			cout<<"x<y"<<endl;
	}else{
		cout<<"x=y"<<endl;	
	} 
}
