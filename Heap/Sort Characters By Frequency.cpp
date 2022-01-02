// 451. Sort Characters By Frequency
// Medium

// Share
// Given a string s, sort it in decreasing order based on the frequency of the characters. The frequency of a character is the number of times it appears in the string.

// Return the sorted string. If there are multiple answers, return any of them.


// Input: s = "tree"
// Output: "eert"
// Explanation: 'e' appears twice while 'r' and 't' both appear once.
// So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.

code
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>freq;
        priority_queue <pair<int,char>> pq;
        
        for(char c:s){
            freq[c]++;
        }
        for(auto it: freq){
            pq.push({it.second, it.first});
        }
        s="";
         while(!pq.empty()){
            s+=string(pq.top().first,pq.top().second); 
            pq.pop();
        }
        return s;
    }
};

// Time Complexity: O(n)
// O(26log(n)) = O(log(n)) For Construction and extraction from heap
// O(n) For storing the frequency in hashmap.
