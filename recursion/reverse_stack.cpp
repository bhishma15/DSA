#include<bits/stdc++.h>

using namespace std;

void insert(stack<int>& s, int tmp){
    if(s.size()==0){
        s.push(tmp);
        return;
    }
    int val=s.top();
    s.pop();
    insert(s,tmp);
    s.push(val);
}

void reverse_stack(stack<int>& s){
    if(s.size() <=1 )
        return;
    int tmp = s.top();
    s.pop();
    reverse_stack(s);
    insert(s,tmp);
}
int main(){
    stack<int> s;
    s.push(1);
    s.push(5);
    s.push(2);
    s.push(4);
    s.push(3);
    s.push(6);
    reverse_stack(s);
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}