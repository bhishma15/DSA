#include<bits/stdc++.h>
using namespace std;

void insert(vector<int>& v,int temp){
    //base case
    if(v.size()==0||v[v.size()-1]<=temp){
        v.push_back(temp);
        return;
    }
    //hypothesis
    int val=v[v.size()-1];
    v.pop_back();

    //induction
    insert(v,temp);
    v.push_back(val);
}

void sort_array(vector<int>& v){
    //base
    if(v.size()==1)
    return;

    //hypothesis
    int temp=v[v.size()-1];
    v.pop_back();
    sort_array(v);
    insert(v,temp);
}
int main(){

    int n;
    cout<<"Enter the array size"<<endl;
    cin>>n;
    vector<int> v(n);
    cout<<"Enter the elements"<<endl;
    for(int i=0;i<v.size();i++){
        cin>>v[i];
    }
    sort_array(v);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    return 0;
}