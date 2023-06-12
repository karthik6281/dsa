class Solution {
public:
    static bool compare(vector<int>a,vector<int>b){
        if(a[0] == b[0])return a[1] < b[1] ;
        return a[0] < b[0] ;
    }
    bool func(vector<int>a,vector<int>b){
        if(a[1] >= b[0])return true ;
        return false ;
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),compare) ;
        int i = 1 ;
        int n = intervals.size() ;
        vector<vector<int>>ans ;
        vector<int>temp=intervals[0] ;
        ans.push_back(temp) ;
        while(true){
            int m = ans.size() ;
            if(i==n)break ;
            if(func(ans[m-1],intervals[i])){
                ans[m-1][1] = max(ans[m-1][1],intervals[i][1]) ;
            }
            else{
                ans.push_back(intervals[i]) ;
            }
            i++ ;
        }
        return ans ;
    }
};