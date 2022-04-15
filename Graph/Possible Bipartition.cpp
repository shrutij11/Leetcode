// 886. Possible Bipartition
// Medium

// We want to split a group of n people (labeled from 1 to n) into two groups of any size. Each person may dislike some other people, and they should not go into the same group.

// Given the integer n and the array dislikes where dislikes[i] = [ai, bi] indicates that the person labeled ai does not like the person labeled bi, return true if it is possible to split everyone into two groups in this way.

 

// Example 1:

// Input: n = 4, dislikes = [[1,2],[1,3],[2,4]]
// Output: true
// Explanation: group1 [1,4] and group2 [2,3].

class Solution {
public:
    bool bipartite(int node,vector<vector<int>>&adj,vector<int>&color){
        queue<int>q;
        q.push(node);
        color[node]=1;
        while(!q.empty()){
            int n = q.front();
            q.pop();
            for(auto it:adj[n]){
                if(color[it]==-1){
                    color[it]=1-color[n];
                    q.push(it);
                }else if(color[it]==color[n]){
                    return false;
                }
            }
        }
        return true;
    }
    
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>>adj(n+1);
        for(int i=0; i<dislikes.size(); i++){
            adj[dislikes[i][0]].push_back(dislikes[i][1]);
             adj[dislikes[i][1]].push_back(dislikes[i][0]);
        }
        
        vector<int>color(n+1,-1);
        for(int i=1; i<=n; i++){
            if(color[i]==-1){
                if(!bipartite(i,adj,color)){
                    return false;
                }
            }
        }
       return true; 
    }
};
