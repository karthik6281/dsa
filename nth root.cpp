class Solution{
	public:
	long long func(int n , int num , int m){
	    long long k = 1 ;
	    for(int i = 0 ; i < n ; i++){
	        if(k>m)return 1 ;
	        k = k*num ;
	    }
	    if(k>m)return 1 ;
	    if(k<m)return 2 ;
	    return 3 ;
	}
	int NthRoot(int n, int m)
	{
	    if(n==1)return m ;
	    if(m==0)return -1 ;
	    long long s = 0 ;
	    long long e = m ;
	    while(abs(s-e)>1){
	       long long mid = (s+e)/2 ;
	       if(func(n,mid,m) == 1){
	           e = mid-1 ;
	       }
	       else if(func(n,mid,m) == 2){
	           s = mid+1 ;
	       }
	       else{
	           return mid ;
	       }
	    }
	   // cout << s << " " << e << endl ;
	    if(func(n,s,m)==3)return s ;
	    if(func(n,e,m)==3)return e ;
	    return -1 ;
	}  
};