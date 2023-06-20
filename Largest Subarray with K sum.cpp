// positives + negatives

int getLongestSubarray(vector<int>& nums, int k){
    int n = nums.size() ;
    map<int,long long> m;
    long long sum = 0 ;
    int maxLen = 0 ;
    for(int i = 0 ; i < n ; i++){
        sum += nums[i] ;
        if(sum==k){
            maxLen = max(maxLen,i+1) ;
        }
        long long check = sum- k;
        if(m.find(check)!= m.end()){
            int ind = i - m[check] ;
            maxLen = max(maxLen,ind) ;
        }
        if(m.find(sum)==m.end()){
            m[sum] = i ;
        }
    }
    return maxLen ;
}

// positives

int longestSubarrayWithSumK(vector<int> a, long long k) {
    long long sum = a[0] ;
    int left = 0 ;
    int right = 0 ;
    int maxi = 0 ;
    int n = a.size() ;
    while(right<n){
        if(sum==k){
            maxi = max(maxi,right-left+1) ;
            right++ ;
            if(right!=n)sum+=a[right] ;
        }
        else if(sum>k){
            sum -= a[left] ;
            left++ ;
        }
        else{
            right++ ;
            if(right!=n)sum+=a[right] ;
        }

    }
    return maxi ;
}

