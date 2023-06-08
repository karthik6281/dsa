class Solution {
public:
    bool func(int n , int k , vector<int>stalls ,int diff){
        int cows = 1 ;
        int pos = 0 ;
        for(int i = 1 ; i < n ; i++){
            if(stalls[pos]+diff <= stalls[i]){
                cows++ ;
                pos = i ;
            }
        }
        if(cows < k)return false ;
        return true ;
    }
    int solve(int n, int k, vector<int> &stalls) {
        if(k>n)return 0 ;
        int s = 0 ;
        int e = 1e9 ;
        int ans = -1 ;
        sort(stalls.begin(),stalls.end()) ;
        int mini = stalls[0] ;
        int maxi = stalls[n-1] ;
        int maxDiff = maxi - mini ;
        while(s<=e){
            int mid = (s+e)/2 ;
            if(mid > maxDiff){
                e = mid-1 ;
            }
            else if(func(n,k,stalls,mid)){
                ans = mid ;
                s = mid+1 ;
            }
            else{
                e = mid-1 ;
            }
        }
        return ans ;
    }
};