// 347. Top K Frequent Elements
// Medium

// Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

 

// Example 1:

// Input: nums = [1,1,1,2,2,3], k = 2
// Output: [1,2]

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>res;
        
        unordered_map<int,int>mp;
        priority_queue<pair<int,int>>pq;
        
        for(int i=0; i<nums.size(); i++){
            mp[nums[i]]++;
        }
                 for(auto it: mp){
            pq.push({it.second, it.first});
        }
               
               while(k--){
                   res.push_back(pq.top().second);
                   pq.pop();
               }
            return res;   
    }
};

// Time complexity : \mathcal{O}(N \log k)O(Nlogk) if k < Nk<N and \mathcal{O}(N)O(N) in the particular case of N = kN=k. That ensures time complexity to be better than \mathcal{O}(N \log N)O(NlogN).

// Space complexity : \mathcal{O}(N + k)O(N+k) to store the hash map with not more NN elements and a heap with kk elements.


// other approches to look at - https://leetcode.com/problems/top-k-frequent-elements/solution/
