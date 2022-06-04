// 1025. Divisor Game
// Easy

// Alice and Bob take turns playing a game, with Alice starting first.

// Initially, there is a number n on the chalkboard. On each player's turn, that player makes a move consisting of:

// Choosing any x with 0 < x < n and n % x == 0.
// Replacing the number n on the chalkboard with n - x.
// Also, if a player cannot make a move, they lose the game.

// Return true if and only if Alice wins the game, assuming both players play optimally.

 

// Example 1:

// Input: n = 2
// Output: true
// Explanation: Alice chooses 1, and Bob has no more moves.
// Example 2:

// Input: n = 3
// Output: false
// Explanation: Alice chooses 1, Bob chooses 1, and Alice has no more moves.

// 1st Approch - Recursion O(2^n) exponential time
class Solution {
public:
    bool divisorGame(int n) {
        if(n<=1)return false;
        for(int x=1; x<n; x++){
             if(n%x==0){
            if(!divisorGame(n-x))return true;
        }
        }
       
        return false;
    }
};

//2nd - DP (memoization) O(n^2)

class Solution {
public:
  int dp[1001];
    
    bool game(int n)
    {
        if (n == 1) {
            return (0);
        }
        if (dp[n] != -1) {
            return (dp[n]);
        }
        for (int x = 1; x < n; x++) {
            if (n % x == 0 && !game(n - x)) {
                return (dp[x] = 1);
            }
        }    
        return (dp[n] = 0);
    }
    
    bool divisorGame(int n) 
    {
        memset(dp, -1, sizeof(dp));
        return game(n);
    }
};

//3rd Approch reducing complexity to O(n^3/2)
class Solution {
public:
    int dp[1001];
    int helper(int n){
        if(n==1) return dp[1]=0;
        if(dp[n]!=-1) return dp[n];
        else{
            for(int i=1;i*i<=n;i++){
                if(n%i==0){
                    if(i!=1 && helper(n-(n/i))==0) return dp[n]=1;
                    if(helper(n-i)==0) return dp[n]=1;
                }
            }
            return dp[n]=0;
        }
    }
    bool divisorGame(int n) {
        memset(dp,-1,sizeof dp);
        return helper(n);
    }
};
//Bottom Up
class Solution {
public:
    bool divisorGame(int n) {
        if(n==1) 
            return false;                   //If n=1, there exists no x i.e. game lost
        vector<int> dp(n+1, 0);             //dp of size n+1 initialized with 0. For each index j, dp[j] tells if Alice won or not
        
        for(int j=2; j<=n; j++)             //j = each no that comes within n
            for(int i=1; i<=sqrt(j); i++)   //factors of j lie between 1 and sqrt(j)  
                if(j%i==0 && dp[j-i]==0)    //if i is a factor of j, then Bob gets j-i,so we choose this i only if Bob loses at j-i so that Alice wins.
                    dp[j]=1;                //Alice wins 
        
        if(dp[n] == 1)                      //if finally, by atleast one path, Alice wins then dp[n] would be = 1
            return true;                    //hence Alice won
        return false;                       //Else, Alice lost
    }
};

//4th Approch
// Conclusion
// If N is even, can win.
// If N is odd, will lose.

// Recursive Prove （Top-down)
// If N is even.
// We can choose x = 1.
// The opponent will get N - 1, which is a odd.
// Reduce to the case odd and he will lose.

// If N is odd,
// 2.1 If N = 1, lose directly.
// 2.2 We have to choose an odd x.
// The opponent will get N - x, which is a even.
// Reduce to the case even and he will win.

// So the N will change odd and even alternatively until N = 1.

// Mathematical Induction Prove （Bottom-up)
// N = 1, lose directly
// N = 2, will win choosing x = 1.
// N = 3, must lose choosing x = 1.
// N = 4, will win choosing x = 1.
// ....

// For N <= n, we have find that:
// If N is even, can win.
// If N is odd, will lose.

// For the case N = n + 1
// If N is even, we can win choosing x = 1,
// give the opponent an odd number N - 1 = n,
// force him to lose,
// because we have found that all odd N <= n will lose.

// If N is odd, there is no even x that N % x == 0.
// As a result, we give the opponent a even number N - x,
// and the opponent can win,
// because we have found that all even N <= n can win.

// Now we prove that, for all N <= n,
// If N is even, can win.
// If N is odd, will lose.



        return N % 2 == 0;
