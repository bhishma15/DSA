#include<bits/stdc++.h>
using namespace std;

bool check(string str){
	stack<char> s;
	int i=0;
	while(str[i]!='x'){
		s.push(str[i]);
		i++;
	}
	i++;
	while(!s.empty()&&i!=str.length()){
		if(str[i]!=s.top())
			return false;
		s.pop();
		i++;
	}
	if(s.empty()&&i==str.length())
		return true;
	return false;
}

int main(){
	string s="abxb";
	if(check(s)){
		cout<<"string is palindrom"<<endl;
	}
	else{
		cout<<"string is not palindrom"<<endl;
	}
}