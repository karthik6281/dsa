class Solution{
public:
    int equalPartition(int N, int arr[])
    {
        int sum  = accumulate(arr,arr+N,0) ;
        if(sum%2!=0)return false ;
        vector<vector<int>>dp(N,vector<int>(sum/2+1,-1)) ;
        return func(N-1,sum/2,arr,dp) ;
    }
    int func(int a , int target , int arr[] , vector<vector<int>>&dp){
        if(target==0)return 1 ;
        if(a==0){
            if(arr[a] == target)return 1 ;
            return 0 ;
        }
        if(dp[a][target]!=-1)return dp[a][target] ;
        int not_take = func(a-1,target,arr,dp) ;
        int take = 0 ; 
        if(arr[a] <= target){
           take = func(a-1,target-arr[a],arr,dp) ;
        }
        return dp[a][target] = max(not_take ,take) ;
    }
    
};