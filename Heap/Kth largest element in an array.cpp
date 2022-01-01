// 215. Kth Largest Element in an Array
// Medium

// Given an integer array nums and an integer k, return the kth largest element in the array.

// Note that it is the kth largest element in the sorted order, not the kth distinct element.

// Input: nums = [3,2,1,5,6,4], k = 2
// Output: 5
  
  code:
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>>pq;
        for(int i=0; i<nums.size(); i++){
            pq.push(nums[i]);
            if(pq.size()>k)
                pq.pop();
        }
        return pq.top();
    }
};


   /* O(N lg K)  time complexity 
    O(K) memory
