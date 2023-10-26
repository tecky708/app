// User function Template for C++

class Solution{
public:
  bool isPalindrome(int i, int j, string& str) {
        while(i<j) {
            if(str[i]!=str[j]) return false;
            i++,j--;
        }
        return true;
    }
    int solve(int i,int n,string &str,vector<int>&dp) {
        if(i==n) {
            return 0;
        }
        int mini = INT_MAX;
        if(dp[i]!=-1) return dp[i];
        
        for(int j = i; j<n; j++) {
            if(isPalindrome(i,j,str)) {
                int cost = 1 + solve(j+1, n, str,dp);
                mini = min(mini,cost);
            }
               }
        return dp[i]=mini;
    }
    int palindromicPartition(string str)
    {
        int n = str.size();
        vector<int>dp(n,-1);
        return solve(0,n,str,dp)-1;
    }
};
