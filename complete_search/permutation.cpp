#include<bits/stdc++.h>
using namespace std;

vector<int> permutation;

//using recursion
void permute1(bool chosen[],int n){
	if(permutation.size()==n){
		for(auto x:permutation){
			cout<<x<<" ";
		}
		cout<<endl;
	}
	else{
		for(int i=0;i<n;i++){
			if(chosen[i])continue;
			chosen[i]=true;
			permutation.push_back(i);
			permute1(chosen,n);
			chosen[i]=false;
			permutation.pop_back();
		}
	}

	return ;
}

//using inbuilt function
void permute2(int n){
	vector<int> v;
	for(int i=0;i<n;i++){
		v.push_back(i);
	}
	do{
		for(auto x:v){
			cout<<x<<" ";
		}
		cout<<endl;
	}while(next_permutation(v.begin(),v.end()));
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	//write your code here
	int n=4;
    bool chosen[n];
	permute2(n);

	return 0;
}