class Solution{
    public:
    double MedianOfArrays(vector<int>& array1, vector<int>& array2)
    {
        if(array2.size() < array1.size())return MedianOfArrays(array2,array1) ;
        int n1 = array1.size() ;
        int n2 = array2.size() ;
        int s = 0 ;
        int e = n1 ;
        while(s<=e){
            int mid1 = (s+e)/2 ;
            int mid2 = (n1+n2+1)/2-mid1 ;
            int l1 = mid1 == 0 ?INT_MIN :array1[mid1-1] ;
            int l2 = mid2 == 0 ?INT_MIN :array2[mid2-1] ;
            int r1 = mid1 == n1?INT_MAX :array1[mid1] ;
            int r2 = mid2 == n2?INT_MAX :array2[mid2] ;
            
            if(l1>r2)e = mid1-1 ;
            else if(l2>r1)s = mid1+1 ;
            else if(l1 <= r2 && l2 <=r1){
                if((n1+n2)%2 == 0)return (max(l1,l2)+min(r1,r2))/2.0 ;
                else return max(l1,l2) ;
            }
        }
        return 0.0 ;
    
    }
};