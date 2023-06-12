class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i = m ; i < m+n ;i++){
            nums1[i]=nums2[i-m] ;
        }
        int gap = m+n ;
        while(gap>1){
            int origin = ceil(gap/2.0) ;
            int left = 0 ;
            int right = origin ;
            while(right<m+n){
                if(nums1[left] > nums1[right]){
                    swap(nums1[left],nums1[right]) ;
                }
                left++ ;right++ ;
            }
            gap = origin ;
        }
    }
};

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m-1 ;
        int j = 0 ;
        while(i>=0 && j < n){
            if(nums1[i] > nums2[j]){
                swap(nums1[i],nums2[j]) ;i-- ; j++ ;
            }
            else break ;
        }
        sort(nums2.begin(),nums2.end()) ;
        sort(nums1.begin(),nums1.begin()+m) ;
        for(int i = m ; i < m+n ; i++){
            nums1[i] = nums2[i-m] ;
        }
    }
};