#include <bits/stdc++.h> 

long long merge(long long *arr ,int s ,int mid ,int e){
    long long count = 0 ;
    vector<long long>v ;
    int i = s ;
    int j = mid+1 ;
    while(i<=mid && j <=e){
        if(arr[i] <= arr[j]){
            v.push_back(arr[i]) ;
            i++ ;
        }
        else{
            count += mid-i+1 ;
            v.push_back(arr[j]) ;
            j++ ;
        }
    }
    while(i<=mid){
        v.push_back(arr[i]) ;i++;
    }
    while(j<=e){
        v.push_back(arr[j]) ;j++;
    }
    for(int i = s ; i <=e ;i++){
        arr[i] = v[i-s] ;
    }
    return count ;
}
long long merge_sort(long long*arr ,int s , int e){
    if(s>=e)return 0 ;
    int mid = (s+e)/2 ;
    long long l = merge_sort(arr,s,mid) ;
    long long r = merge_sort(arr,mid+1,e) ;
    long long m = merge(arr,s,mid,e) ;
    return l+r+m ;
}
long long getInversions(long long *arr, int n){
    return merge_sort(arr , 0 , n-1) ;
}