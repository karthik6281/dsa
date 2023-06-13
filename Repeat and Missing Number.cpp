class Solution{
public:
    long long sumDiff(vector<int>arr , int n){
        long long sum1 = 0 ; 
        long long sum2 = 0 ;
        for(int i = 0 ; i < n ; i++){
            sum1+=arr[i] ;
            sum2+=i+1 ;
        }
        return sum1-sum2 ;
    }
    long long squareDiff(vector<int>arr,long long sum,int n){
        long long sum1 = 0 ;
        long long sum2 = 0 ;
        for(int i = 0 ; i < n ; i++){
            sum1+=(long long)(arr[i])*(long long)(arr[i]) ;
            sum2+=(long long)(i+1)*(long long)(i+1) ;
        }
        return (sum1-sum2)/sum ;
    }
    vector<int> findTwoElement(vector<int> arr, int n) {
        long long a = sumDiff(arr,n) ;
        long long b = squareDiff(arr,a,n) ;
        vector<int>ans ;
        ans.push_back((int)(a+b)/2) ;
        ans.push_back((int)(b-a)/2) ;
        return ans ;
    }
};

class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        int xor_  = 0 ;
        for(int i = 0 ; i < n ; i++){
            xor_ = xor_^(i+1) ;
            xor_ = xor_^(arr[i]) ;
        }
        int bit = 0 ;
        while(true){
            if((xor_>>bit)&1)break ;
            bit++ ;
        }
        int a = 0 ;
        int b = 0 ;
        for(int i = 0 ; i < n ;i++){
            if((arr[i]>>bit)&1)a ^=arr[i] ;
            else b ^=arr[i] ;
        }
        for(int i = 0 ; i < n ;i++){
            if(((i+1)>>bit)&1)a ^=(i+1) ;
            else b ^=(i+1) ;
        }
        vector<int>ans ;
        int count = 0 ;
        for(int i = 0 ; i < n ; i++){
            if(arr[i]==a)count++ ;
        }
        if(count==0)swap(a,b) ;
        ans.push_back(a) ;
        ans.push_back(b) ;
        return ans ;
    }
};