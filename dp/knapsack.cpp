/*
You are given weights and values of N items, put these items in a \
knapsack of capacity W to get the maximum total value in the knapsack.\
 Note that we have only one quantity of each item.
In other words, given two integer arrays val[0..N-1] and wt[0..N-1] \
which represent values and weights associated with N items \
respectively. Also given an integer W which represents knapsack \
capacity, find out the maximum value subset of val[] such that \
sum of the weights of this subset is smaller than or equal to W.\
 You cannot break an item, either pick the complete item, or don’t 
pick it (0-1 property).

*/
#include<iostream>
#include<vector>

using namespace std;

// dp table
vector<vector <int> > dp(1000,vector<int>(1000,-1));

// 0/1 knapsack top down (items can't be repeated)
int knapsack_top(int val[],int wt[],int n,int w){

	//Base case
    if(n==0||w==0)
    return dp[n][w]=0;

	// Memoization
    if(dp[n][w]!=-1)
    	return dp[n][w];

	//recursive case
    if (wt[n-1] > w) {
		// Not enough space for this element so skip it
        return dp[n][w]=knapsack_top(val,wt,n-1,w);
    } else {
		// Check the value with or without including the element and get max from both
        return dp[n][w]=max(knapsack_top(val,wt,n-1,w),val[n-1]+knapsack_top(val,wt,n-1,w-wt[n-1]));
    }
}

// 0/1 knapsack bottom up approach (items can't be repeated)

int knapsack_bottom(int val[],int wt[],int n,int w){

	for(int i=0;i<=w;i++){
		for(int j=0;j<=n;j++){

			if(i==0||j==0){
				dp[i][j]=0;
				continue;
			}

			if (wt[j-1] > i) {
				// Not enough space for this element so skip it
        		dp[i][j]=dp[i][j-1];
    		} else {
				// Check the value with or without including the element and get max from both
				dp[i][j]= max(dp[i][j-1],val[j-1]+dp[i-wt[j-1]][j-1]);
    		} 
		}
	}
	return dp[w][n];
}

// unbounded knapsack top down approach (items can be repeated)
int ub_knapsack_top(int val[],int wt[],int n,int w){

	//Base case
    if(n==0||w==0)
    return dp[n][w]=0;

	// Memoization
    if(dp[n][w]!=-1)
    	return dp[n][w];

	//recursive case
    if (wt[n-1] > w) {
		// Not enough space for this element so skip it
        return dp[n][w]=ub_knapsack_top(val,wt,n-1,w);
    } else {
		// Check the value with or without including the element and get max from both
        return dp[n][w]=max(ub_knapsack_top(val,wt,n-1,w),val[n-1]+ub_knapsack_top(val,wt,n,w-wt[n-1]));
    }
}

// unbounded knapsack bottom up approach (items can be repeated)
int ub_knapsack_bottom(int val[],int wt[],int n,int w){

	for(int i=0;i<=w;i++){
		for(int j=0;j<=n;j++){

			if(i==0||j==0){
				dp[i][j]=0;
				continue;
			}

			if (wt[j-1] > i) {
				// Not enough space for this element so skip it
        		dp[i][j]=dp[i][j-1];
    		} else {
				// Check the value with or without including the element and get max from both
				dp[i][j]= max(dp[i][j-1],val[j-1]+dp[i-wt[j-1]][j]);
    		} 
		}
	}
	return dp[w][n];
}

int main()
 {

	int n,w;
	cout<<"Enter the no of elements and weigth of knapsack"<<endl;
	cin>>n>>w;

	int val[n],wt[n];
	cout<<"Enter the elements values"<<endl;
	for(int i=0;i<n;i++){
		cin>>val[i];
	}

	cout<<"Enter the weight of each knapsack"<<endl;
	for(int i=0;i<n;i++){
		cin>>wt[i];
	}
	
	int ans=ub_knapsack_top(val,wt,n,w);
	cout<<"Ans = " <<ans<<endl;

	return 0;
}