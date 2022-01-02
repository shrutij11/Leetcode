// 973. K Closest Points to Origin
// Medium

// Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane and an integer k, return the k closest points to the origin (0, 0).

// The distance between two points on the X-Y plane is the Euclidean distance (i.e., √(x1 - x2)2 + (y1 - y2)2).

// You may return the answer in any order. The answer is guaranteed to be unique (except for the order that it is in).
  
//   Input: points = [[1,3],[-2,2]], k = 1
// Output: [[-2,2]]
// Explanation:
// The distance between (1, 3) and the origin is sqrt(10).
// The distance between (-2, 2) and the origin is sqrt(8).
// Since sqrt(8) < sqrt(10), (-2, 2) is closer to the origin.
// We only want the closest k = 1 points from the origin, so the answer is just [[-2,2]].

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>>res(k);
        priority_queue<vector<int>>pq;
       for(int i=0;i<points.size();i++){
            pq.push(Point(points[i][0], points[i][1]));
        }
           
            pq.push({x*x + y*y,x,y});
            if(pq.size()>k){
                pq.pop();
            }
        }
        
        for (int i = 0; i < k; ++i) {
            vector<int> top = pq.top();
            pq.pop();
            res[i] = {top[1], top[2]};
        }
        
        return res;
        
    }
};


// Time Complexity:- O(NlogK)
// Space Complexity:- O(K)
