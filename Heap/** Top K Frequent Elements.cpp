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

// Time complexity : O(Nlogk) if k <N and O(N) in the particular case of N =k. That ensures time complexity to be better than O(NlogN).

// Space complexity : O(N+k) to store the hash map with not more N elements and a heap with k elements.


// ** other approches to look at - https://leetcode.com/problems/top-k-frequent-elements/solution/
