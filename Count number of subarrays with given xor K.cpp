int subarraysXor(vector<int> &arr, int x)
{
    int n = arr.size() ;
    map<int,int>m ;
    long long xori = 0 ;
    int count = 0 ;
    for(int i = 0 ; i < n ; i++){
        xori ^= arr[i] ;
        if(xori==x){
            count++ ;
        }
        long long check = xori^x ;
        count+=m[check] ;
        m[xori]++ ;
    }

    return count ;
}