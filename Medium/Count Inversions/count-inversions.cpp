//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long merge(long long arr[], int low, int mid, int high){
        vector<int> temp;
        int left = low;
        int right = mid+1;
        long long count = 0;
        while (left <= mid && right <= high){
            if (arr[left] > arr[right]){
                temp.push_back(arr[right]);
                right++;
                count += (mid - left + 1);
            }
            else {
                temp.push_back(arr[left]);
                left++;
            }
        }
        while (left <= mid){
            temp.push_back(arr[left]);
            left++;
        }
        while (right <= high){
            temp.push_back(arr[right]);
            right++;
        }
        for (int i = low; i <= high; i++){
            arr[i] = temp[i-low];
        }
        return count;
    }
    
    long long mergeSort(long long arr[], int low, int high){
        if (low >= high) return 0;
        int mid = low + (high - low)/2;
        long long count = 0;
        count += mergeSort(arr, low, mid);
        count += mergeSort(arr, mid+1, high);
        count += merge(arr, low, mid, high);
        return count;
    }
    
    
    long long int inversionCount(long long arr[], long long N) {
        return mergeSort(arr, 0, N - 1);
    }
};

// } Driver Code Ends
