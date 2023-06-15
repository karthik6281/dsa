// TLE
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size() ;
        return inversion_count(nums,0,n-1) ;
    }
    void merge(vector<int>&arr,int s,int e){
    int i = s ;
    int m = (s+e)/2 ;
    int j = m+1 ;
    vector<int>temp;
    while(i<=m and j<=e){
        if(arr[i]<=arr[j]){
            temp.push_back(arr[i]) ;
            i++ ;
        }
        else{
            temp.push_back(arr[j]);
            j++ ;
        }
    }
    while(i<=m){
        temp.push_back(arr[i++]) ;
    }
    while(j<=e){
        temp.push_back(arr[j++]) ;
    }
    int k = 0 ;
    for(int i = s;i<=e;i++){
        arr[i] = temp[k++] ;
    }
    return;
}
    int inversion_count(vector<int>&arr,int s,int e){
        if(s>=e)return 0;
        int count = 0 ;
        int mid = (s+e)/2 ;
        count+= inversion_count(arr,s,mid);
        count+= inversion_count(arr,mid+1,e) ;
        count+= req(arr,s,e) ;
        merge(arr,s,e) ;
        return count ;
    }
    int req(vector<int>arr , int s ,int e){
        int count = 0 ;
        int mid = (s+e)/2 ;
        int right = mid+1 ;
        for(int i = s ; i <= mid ;i++){
            while(right <= e && 0.5*arr[i] > arr[right]){right++ ;}
            count+= right-(mid+1) ;
        }
        return count ;
    }
};