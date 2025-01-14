#include<iostream>
using namespace std;

class RMB{
	private:
		unsigned int yuan; // 元
		unsigned int jf;   // 角分 
	public:
		RMB(double d){
			yuan=d;
			jf=(d-yuan)*100;
		}
		
		RMB interest(double rate); // 计算利息 
		RMB add(RMB &d); // 人名币加 
		RMB operator+(RMB& d){ // 人民币加的运算符重载 
			return RMB(yuan+d.yuan+(jf+d.jf)/100.0);
		}
		RMB operator*(double rate){
			return RMB((yuan+jf/100.0)*rate);
		}
		
		void display(){
			cout <<(yuan + jf / 100.0) << endl; 
		}
};

RMB RMB::interest(double rate){ // 计算利息 
	return RMB((yuan+jf/100.0)*rate);
}

RMB RMB::add(RMB& d){ // 人民币加
 	return RMB(yuan+d.yuan+jf/100.0+d.jf/100.0); 
} 

// 以下是计算应付人民币的两个版本
RMB expense1(RMB& principle,double rate){ // 计算本息和 
	RMB interest=principle.interest(rate);	
	return principle.add(interest);
} 

RMB expense2(RMB& principle,double rate){ // 计算本息和 
	RMB interest=principle*rate; // 本金乘利息 
	return principle+interest;   // 连本带利  
}

int main(){
	RMB x=10000.0;
	double yrate=0.035;
	expense1(x,yrate).display();
	expense2(x,yrate).display();
}
