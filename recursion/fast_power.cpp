#include<bits/stdc++.h>
using namespace std;

int fastPower(int a,int b){
	if(b==0)
		return 1;
	int ans;
	if(b&1){
		ans=fastPower(a,(b-1)/2);
		ans *= ans;
		return a*ans;
	}
	else{
		ans=fastPower(a,b/2);
		ans*=ans;
		return ans;
	}
}

//Normal way of finding power
int power(int a,int b){
	//base case
	if(b==0){
		return 1;
	}
	
	//recursive case
	return a*power(a,b-1);
	
}

int main(){
	int a,b;
	a=3;
	b=4;
	int ans=fastPower(a,b);
	cout<<ans<<endl;
	return 0;
} 