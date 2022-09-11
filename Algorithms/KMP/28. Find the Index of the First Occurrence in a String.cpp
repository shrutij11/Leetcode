// Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.


// Example 1:

// Input: haystack = "sadbutsad", needle = "sad"
// Output: 0
// Explanation: "sad" occurs at index 0 and 6.
// The first occurrence is at index 0, so we return 0.

//BRUTE FORCE
// TC: O(m*n)
//   SC:O(1)

class Solution {
public:
    int strStr(string h, string n) {
          int ind=0;
        int j=0,i=0;
        while(i<h.length() && j<n.length()){
            if(h[i++] == n[j]){
                j++;
            }
            else{
                i=i-j;
                j=0;
                ind=i;
            }
        }
        return (j==n.length())?ind:-1;
    }
};
