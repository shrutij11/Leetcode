// 1753. Maximum Score From Removing Stones
// Medium

// You are playing a solitaire game with three piles of stones of sizes a​​​​​​, b,​​​​​​ and c​​​​​​ respectively. Each turn you choose two different non-empty piles, take one stone from each, and add 1 point to your score. The game stops when there are fewer than two non-empty piles (meaning there are no more available moves).

// Given three integers a​​​​​, b,​​​​​ and c​​​​​, return the maximum score you can get.

 

// Example 1:

// Input: a = 2, b = 4, c = 6
// Output: 6
// Explanation: The starting state is (2, 4, 6). One optimal set of moves is:
// - Take from 1st and 3rd piles, state is now (1, 4, 5)
// - Take from 1st and 3rd piles, state is now (0, 4, 4)
// - Take from 2nd and 3rd piles, state is now (0, 3, 3)
// - Take from 2nd and 3rd piles, state is now (0, 2, 2)
// - Take from 2nd and 3rd piles, state is now (0, 1, 1)
// - Take from 2nd and 3rd piles, state is now (0, 0, 0)
// There are fewer than two non-empty piles, so the game ends. Total: 6 points.

Approch 1: Using max heap

class Solution {
public:
    int maximumScore(int a, int b, int c) {
        priority_queue<int> heap;
       heap.push(a);
       heap.push(b);
       heap.push(c);
       int cnt = 0;
       while (heap.size()>1) {
         auto u = heap.top(); heap.pop();
         auto v = heap.top(); heap.pop();
         if (--u>0)
             heap.push(u);
         if (--v>0)
             heap.push(v);
         cnt++;
       }
       return cnt;
    }
};

Approch 2:Maths

If one number if bigger that the sum of the remaning two. The sum of the remaining two is the answer. Reason: you have to take 1 from one of the two smaller numbers in each move, they eventuall run out first.
Otherwise, no more than 1 will be left at the end. You can first take 1 from the biggest one and 1 from the smallest one in each move until two bigger ones are the same. From there on you perform two moves together: 2 from the smallest one and 1 from each of the bigger ones until the smallest is 0 or 1.

  
  class Solution {
public:
    int maximumScore(int a, int b, int c) {
        int m = max(max(a, b), c);
        if (2*m > a+b+c) return a+b+c - m;
        return (a+b+c)/2;
    }
};
