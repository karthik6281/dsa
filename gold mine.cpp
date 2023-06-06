class Solution{
public:
    bool isValid(int row , int col , int n ,int m){
        if(row<0 || row >=n)return false ;
        if(col<0 || col >=m)return false ;
        return true ;
    }
    int func(int row , int col , vector<vector<int>> M ,vector<vector<int>>&dp,int n , int m){
        if(col == 0)return M[row][col] ;
        if(dp[row][col]!=-1)return dp[row][col] ;
        int a = 0 ;
        int b = 0 ;
        int c =0 ;
        if(isValid(row,col-1,n,m))a = M[row][col] + func(row,col-1,M,dp,n,m) ;
        if(isValid(row-1,col-1,n,m))b = M[row][col] + func(row-1,col-1,M,dp,n,m) ;
        if(isValid(row+1,col-1,n,m))c = M[row][col] + func(row+1,col-1,M,dp,n,m) ;
        return dp[row][col] = max(a,max(b,c)) ;
        
    }
    int maxGold(int n, int m, vector<vector<int>> M)
    {
        vector<vector<int>>dp(n,vector<int>(m,0)) ;
        int maxi = 0 ;
        for(int i = 0 ; i < n ; i++){
            dp[i][0] = M[i][0] ;
        }
        int a = 0 ;
        int b = 0 ;
        int c =0 ;
        for(int col =1 ; col < m ; col++){
            for(int row = 0 ; row < n ;row++){
                a=0;b=0;c=0;
                if(isValid(row,col-1,n,m))a = dp[row][col-1] ;
                if(isValid(row-1,col-1,n,m))b = dp[row-1][col-1] ;
                if(isValid(row+1,col-1,n,m))c = dp[row+1][col-1] ;
                dp[row][col] = M[row][col] + max(a,max(b,c)) ;
            }
        }
        for(int i = 0 ; i < n ; i++){
            maxi = max(maxi,dp[i][m-1]) ;
        }
        return maxi ;
    }
};