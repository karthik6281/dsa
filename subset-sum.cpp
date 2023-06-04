class Solution
{
public:
    void func(int i,vector<int>arr,int n ,vector<int>&ans,int sum){
        if(i==n){
            ans.push_back(sum) ;
            return ;
        }
        func(i+1,arr,n,ans,sum) ;
        func(i+1,arr,n,ans,sum+arr[i]) ;
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int>ans ;
        func(0,arr,N,ans,0) ;
        return ans ;
    }
};