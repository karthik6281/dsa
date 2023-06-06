class Solution
{
    public:
    //Function to find the nth catalan number.
    cpp_int findCatalan(int n) 
    {
        // vector<cpp_int>dp(n+1,1) ;
        // for(int i = 1 ; i <= n ; i++){
        //     dp[i] = (dp[i-1]*2*(2*i-1))/(i+1) ;
        // }
        cpp_int prev = 1 ;
        for(int i = 1 ; i <= n ;i++){
            prev = (prev*2*(2*i-1))/(i+1) ;
        }
        return prev ;
    }
};