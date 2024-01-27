#include<iostream>
#include<vector>

using namespace std;

vector<int> dp(100,-1);

// top down approach
int fib_top(int n){
    if(n==0||n==1)
        return dp[n]=n;

    if(dp[n]!=-1)
        return dp[n];

    return dp[n]=fib_top(n-1)+fib_top(n-2);
} 

//bottom up approach
int fib_bottom(int n){
    if(n==0||n==1){
        return n;
    }
    dp[0]=0;
    dp[1]=1;
    for(int i=2;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}

int main(){

    for(int i=0;i<=10;i++){
        cout<<fib_top(i)<< " ";
    }
    cout<<endl;
    for(int i=0;i<=10;i++){
        cout<<fib_bottom(i)<< " ";
    }
    cout<<endl;
    for(int i=0;i<=10;i++){
        cout<<dp[i]<< " ";
    }
    cout<<endl;
}