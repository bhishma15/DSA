#include<bits/stdc++.h>

using namespace std;

vector <int> bfs(vector<int> g[], int N) {

    // Your code here
    bool *vis=new bool[N];
    vector<int> v;
    
    for(int i=0;i<N;i++){
        vis[i]=false;
    }
    queue<int> q;
    q.push(0);
    vis[0]=true;
    while(!q.empty()){
        int s=q.front();
        q.pop();
        v.push_back(s);
        for(auto u:g[s]){
            if(vis[u])continue;
            vis[u]=true;
            q.push(u);
        }
    }
    return v;
}

int32_t main()
{
  ios_base::sync_with_stdio(0); 
  cin.tie(0); cout.tie(0);
 
 //write your code here
  int v,e;
  cin>>v>>e;
  vector<int> adj[v];
  for(int i=0;i<e;i++){
    int x,y;
    cin>>x>>y;
    adj[x].push_back(y);
  }
  vector<int> v=bfs(adj,v);
  return 0;
}