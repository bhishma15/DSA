/*
Given a connected undirected graph. Perform a Depth First Traversal \
of the graph.
*/
#include<bits/stdc++.h>

using namespace std;
 

void solve(vector<int> g[],bool vis[],int s,vector<int>& v){
    if(vis[s])return;
    v.push_back(s);
    vis[s]=true;
    for(auto u:g[s]){
        solve(g,vis,u,v);
    }
}

vector <int> dfs(vector<int> g[], int N)
{
    // Your code here
   vector<int> v;
   bool *vis=new bool[N];
   for(int i=0;i<N;i++){
       vis[i]=false;
   }
   
   solve(g,vis,0,v);
   return v;
    
}
 
int32_t main()
{
  ios_base::sync_with_stdio(0); 
  cin.tie(0); cout.tie(0);
 
 //write your code here

  return 0;
}