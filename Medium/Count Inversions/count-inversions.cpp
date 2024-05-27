//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int inversionCount(long long arr[], long long N) {
    return mergeSort(arr, 0, N - 1);
}

long long mergeSort(long long arr[], long long low, long long high) {
    if (low >= high) return 0;
    long long mid = low + (high - low) / 2;
    long long count = 0;
    count += mergeSort(arr, low, mid);
    count += mergeSort(arr, mid + 1, high);
    count += merge(arr, low, mid, high);
    return count;
}

long long merge(long long arr[], long long low, long long mid, long long high) {
    std::vector<long long> temp;
    long long i = low, j = mid + 1;
    long long count = 0;
    
    while (i <= mid && j <= high) {
        if (arr[i] <= arr[j]) {
            temp.push_back(arr[i]);
            i++;
        } else {
            temp.push_back(arr[j]);
            j++;
            count += (mid - i + 1); // Increment count by the number of remaining elements in the left subarray
        }
    }
    
    while (i <= mid) {
        temp.push_back(arr[i]);
        i++;
    }
    
    while (j <= high) {
        temp.push_back(arr[j]);
        j++;
    }
    
    for (long long k = low; k <= high; k++) {
        arr[k] = temp[k - low];
    }
    
    return count;
}

};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends