class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        if(m < n)return kthElement(arr2,arr1,m,n,k) ;
        int s = 0 ;
        int e = n ;
        while(s<=e){
            int mid1 = (s+e)/2 ;
            int mid2 = k-1-mid1 ;
            if(mid2 > m)s = mid1 ;
            else if (mid2 < 0)e = mid1 ;
            else{
                int l1 = mid1 == 0 ?INT_MIN :arr1[mid1-1] ;
                int l2 = mid2 == 0 ?INT_MIN :arr2[mid2-1] ;
                int r1 = mid1 == n?INT_MAX :arr1[mid1] ;
                int r2 = mid2 == m?INT_MAX :arr2[mid2] ;
                
                if(l1>r2)e = mid1-1 ;
                else if(l2>r1)s = mid1+1 ;
                else if(l1 <= r2 && l2 <=r1){
                    return min(r1,r2) ;
                }
            }
        }
        return 0.0 ;
    }
};