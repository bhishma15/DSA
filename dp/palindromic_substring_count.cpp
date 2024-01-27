#include<iostream>
#include<vector>
using namespace std;

vector<vector<int> > dp(100,vector<int>(100,-1));

//Top down approach
int isPalindrom(string s,int i,int j){
    //Base case
    if(i>=j)
        return dp[i][j]=1;

    //memoization
    if(dp[i][j]!=-1)
        return dp[i][j];

    // recursive case
    if(s[i]==s[j]){
        return dp[i][j]=isPalindrom(s,i+1,j-1);
    }else{
        return dp[i][j]=0;
    }
}

int countSubstrings_top(string s){
    int n=s.length();
    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(isPalindrom(s,i,j))
                cnt++;
        }
    }
    return cnt;
}

// Bottom up approach
int countSubstrings_bottom(string s) {

    int n=s.length();
    int dp[n][n];
    for(int i=0;i<n;i++){
        dp[i][i]=1;
    }

    // check for string palindrom
    for(int len=1;len<=n;len++){
        for(int i=0;i<n-len;i++){
            int j=i+len;
            if(s[i]!=s[j])
                dp[i][j]=0;
            else{
                if(i+1 < j-1){
                    dp[i][j]=dp[i+1][j-1];
                }else{
                    dp[i][j]=1;
                }
            }
                
        }
    }
    int res=0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(dp[i][j])
                res++;
        }
    }  
    return res;
}

int main(){
    string str;
    cin>>str;
    int res=countSubstrings_top(str);
    cout<<"No of palindromic string = "<<res<<endl;
}