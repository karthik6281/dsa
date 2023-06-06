class Solution
{
    public:
    // 1 1d array
    int knapSack(int W, int wt[], int val[], int n) 
    { 
    //   vector<vector<int>> dp(n,vector<int>(W+1,0)) ;
       vector<int>prev(W+1,0) ;
       for(int i = 0 ; i <=W ;i++){
           if(wt[0] <= i)prev[i] = val[0] ;
       }
       for(int i = 1 ; i < n ; i++){
            for(int w = W ; w > 0 ;w-- ){
                int not_take = prev[w] ;
                int take = 0 ;
                if(wt[i] <= w){
                   take = val[i] + prev[w-wt[i]] ;
                }
                prev[w] = max(take,not_take) ;
            }
       }
       return prev[W] ;
    }
    // 2 1d array 
    int knapSack(int W, int wt[], int val[], int n) 
    { 
    //   vector<vector<int>> dp(n,vector<int>(W+1,0)) ;
       vector<int>prev(W+1,0) ;
       vector<int>cur(W+1,0) ;
       for(int i = 0 ; i <=W ;i++){
           if(wt[0] <= i)prev[i] = val[0] ;
       }
       for(int i = 1 ; i < n ; i++){
            for(int w = 1 ; w <= W ;w++ ){
                int not_take = prev[w] ;
                int take = 0 ;
                if(wt[i] <= w){
                   take = val[i] + prev[w-wt[i]] ;
                }
                cur[w] = max(take,not_take) ;
            }
            prev = cur ;
       }
       return prev[W] ;
    }
// tabulation
    int knapSack(int W, int wt[], int val[], int n) 
    { 
      vector<vector<int>> dp(n,vector<int>(W+1,0)) ;
      for(int i = 0 ; i <=W ;i++){
          if(wt[0] <= i)dp[0][i] = val[0] ;
      }
      for(int i = 0 ; i<n ;i++){
          dp[i][0] = 0 ;
      }
      for(int i = 1 ; i < n ; i++){
          for(int w = 1 ; w <= W ;w++ ){
              int not_take = dp[i-1][w] ;
              int take = 0 ;
              if(wt[i] <= w){
                  take = val[i] + dp[i-1][w-wt[i]] ;
              }
              dp[i][w] = max(take,not_take) ;
          }
      }
      return dp[n-1][W] ;
    }
    //memo 
    int func(int i ,int n , int W , int wt[] , int val[] ,vector<vector<int>>&dp){
        if(i==0){
            if(wt[0] <= W)return val[0] ;
            else return 0 ;
        }
        if(W==0)return 0 ;
        if(dp[i][W]!=-1)return dp[i][W] ;
        int not_take = func(i-1,n,W,wt,val,dp) ;
        int take = 0 ;
        if(wt[i] <= W){
            take = val[i] + func(i-1,n,W-wt[i],wt,val,dp) ;
        }
        return dp[i][W] = max(not_take,take) ;
    }
};