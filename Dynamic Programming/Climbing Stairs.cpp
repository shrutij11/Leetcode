// 70. Climbing Stairs
// Easy

// You are climbing a staircase. It takes n steps to reach the top.

// Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

 

// Example 1:

// Input: n = 2
// Output: 2
// Explanation: There are two ways to climb to the top.
// 1. 1 step + 1 step
// 2. 2 steps
// Example 2:

// Input: n = 3
// Output: 3
// Explanation: There are three ways to climb to the top.
// 1. 1 step + 1 step + 1 step
// 2. 1 step + 2 steps
// 3. 2 steps + 1 step

// 1. Recursive Solution
// It will give TLE but for better understanding to memoization we have to write it

class Solution {
public:
    int mk(int n)
    {
         if(n<0) return 0;
         if(n==0) return 1;
         return mk(n-1)+mk(n-2); 
    } 
    int climbStairs(int n) {
        return mk(n);
    }
};
// 2. Memoization of Recursive Solution

// Runtime: 0 ms .
// Memory Usage: 6.2 MB

class Solution {
public:
    int mk(int n,vector<int> &memo)
    {     
         if(n<0) return 0;
         if(memo[n]!=-1) return memo[n];
         if(n==0) return 1;
         return memo[n]=mk(n-1,memo)+mk(n-2,memo);
    }
     
    int climbStairs(int n) {
        vector<int> memo(n+1,-1);
        return mk(n,memo);
    }
};
// 3. Convert Memoization into dp

// Runtime: 4 ms
// Memory Usage: 5.9 MB

 class Solution {
public:
    
    int climbStairs(int n) {
	    if(n<1) return 0;
        int a[100];
        a[0]=1;
        a[1]=2;
        for(int i=2;i<n;i++)
            a[i]=a[i-1]+a[i-2];
        return a[n-1];
    }
};
