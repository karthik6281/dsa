class Solution{
    int m = 1000000007;
public:
    int func (int n ,int r ,vector<vector<int>>&dp){
        if(r>n)return 0;
        if(r==0)return 1;
        if(dp[n][r]!=-1)return dp[n][r]%m ;
        return dp[n][r] = (func(n-1,r-1,dp)+func(n-1,r,dp))%m;
        
    }
    int nCr(int n, int r){
        vector<vector<int>>dp(n+1,vector<int>(r+1,-1));
        return func (n,r,dp);
    }
};