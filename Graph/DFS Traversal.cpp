// TC = O(N+E)
//SC= O(N)+O(N+E)+O(N) = O(N)

void dfs(int node, vector<int>&vis, vector<int>adj[],vector<int>&res){
      res.push_back(node);
      vis[node]=1;
      for(auto it: adj[node]){
        if(!vis[it])
          dfs(it,vis,adj,res);
         }
    } 

     public:
     vector<int> dfsOfGraph(int v, vector<int> adj[]) {
        // Code here
          vector<int>vis(v+1,0);
          vector <int>res;
          dfs(0,vis,adj,res);
       // for disconnected components
        //  for(int i=1; i<=v; i++)
        //  {
        //   if(!vis[i])
        //   dfs(i,vis,adj,res);
        //  }
      return res;

    }
