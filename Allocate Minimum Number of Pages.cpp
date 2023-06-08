class Solution 
{
    public:
    
    bool func(int A[] , int n , int m , int sum){
        int minStudents = 1 ;
        int k = 0 ;
        for(int i = 0 ; i < n ; i++){
            if(A[i] + k > sum){
                k = A[i] ;
                minStudents++ ;
            }
            else{
                k+= A[i] ;
            }
        }
        if(minStudents > m)return false ;
        return true ;
    }
    int findPages(int A[], int N, int M) 
    {   if(M > N)return -1 ;
        int k = 0 ;
        int s = 0 ;
        for(int i = 0 ; i < N ;i++){
            s = max(s,A[i]) ;
            k+=A[i] ;
        }
        int e = k ;
        int ans = -1 ;
        while(s<=e){
            int mid = (s+e)/2 ;
            if(func(A,N,M,mid)){
                ans = mid ;
                e = mid-1 ;
            }
            else{
                s = mid+1 ;
            }
        }
        return ans ;
    }
};