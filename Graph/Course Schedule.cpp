// 207. Course Schedule
// Medium

// There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

// For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
// Return true if you can finish all courses. Otherwise, return false.

 

// Example 1:

// Input: numCourses = 2, prerequisites = [[1,0]]
// Output: true
// Explanation: There are a total of 2 courses to take. 
// To take course 1 you should have finished course 0. So it is possible.

class Solution {
public:
      bool cycle(int node,vector<int>&vis,vector<int>&dfs, vector<int> adj[]){
        vis[node]=1;
        dfs[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]){
                if(cycle(it,vis,dfs,adj))
                    return true;
            }else if(dfs[it]) return true;
        }
        dfs[node]=0;
        return false;
    }
    
    
    bool canFinish(int n, vector<vector<int>>& p) {
           ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
                 vector<int> adj[n];
        for(int i=0;i<p.size();++i)
            adj[p[i][0]].push_back(p[i][1]);
       vector<int>vis(n,0);
         vector<int>dfs(n,0);
        for(int i=0; i<n; i++){
            if(!vis[i])
                if(cycle(i,vis,dfs,adj))
                    return false;
        }
        return true;
    
    }
};
