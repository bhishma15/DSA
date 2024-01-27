/*
Find the minimum no of partitions required to separate 
the strings into multiple palindromic substrings
*/
#include<bits/stdc++.h>

using namespace std;

bool isPalindrom(string str,int i,int j){
    while(i<j){
        if(str[i]!=str[j])
            return false;
        i++;
        j--;
    }
    return true;
}

int calPartition(string str,int i,int j){
    if(i>j || isPalindrom(str,i,j))
        return 0;

    int ans=INT_MAX;
    for(int k=i;k<j;k++){
        int temp=calPartition(str,i,k)+calPartition(str,k+1,j)+1;
        ans=min(ans,temp);
    }
    return ans;
}

int main(){
    string str;
    cin>>str;
    int ans = calPartition(str,0,str.length()-1);
    cout<<"Count= "<<ans<<endl;
    return 0;
}