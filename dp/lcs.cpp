/*
Given two strings X and Y. The task is to find the length of the \
longest common subsequence.
*/
#include<iostream>
#include<vector>
using namespace std;

//dp table
vector<vector<int> > dp(1000,vector<int>(1000,-1));

// Top down approach
int lcs_top(string a,int m,string b,int n){

	// Base case
	if(m==0||n==0)
		return dp[m][n]=0;

	// Memoization
	if(dp[m][n]!=-1)
		return dp[m][n];
	
	//recursive case
	if(a[m-1]==b[n-1])
		return dp[m][n]= 1+lcs_top(a,m-1,b,n-1);

	return dp[m-1][n-1]=max(lcs_top(a,m-1,b,n),lcs_top(a,m,b,n-1));
}

// bottom up approach
int lcs_bottom(string a,int m,string b,int n){

	for(int i=0;i<=m;i++){
		for(int j=0;j<=n;j++){
			if(i==0||j==0){
				dp[i][j]=0;
			}
			if(a[i-1]==b[j-1]){
				dp[i][j]=1+dp[i-1][j-1];
			}

			dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		}
	}

	return dp[m][n];
}

int main()
 {
	//code
	cout<<"Enter two strings"<<endl;
	string a,b;
	cin>>a>>b;
	int ans=lcs_bottom(a,a.length(),b,b.length());
	cout<<"LCS length = "<<ans<<endl;
	return 0;
}