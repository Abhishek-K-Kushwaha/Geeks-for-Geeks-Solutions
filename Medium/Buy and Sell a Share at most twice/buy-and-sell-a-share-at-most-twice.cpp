//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
        int maxProfit(vector<int>&prices){
            int n = prices.size();
            vector<int> prev(5,0);
            for (int ind = n-1; ind >= 0; ind--){
                for (int cnt = 3; cnt >= 0; cnt--){
                    if (cnt % 2) { // cannot buy
                        int sell = prices[ind] + prev[cnt+1]; 
                        int notsell = prev[cnt]; 
                        prev[cnt] = max(sell, notsell);
                    } else { // can buy
                        int buy = -prices[ind] + prev[cnt+1]; 
                        int notbuy = prev[cnt]; 
                        prev[cnt] = max(buy, notbuy);
                    }
                }
            }
            return prev[0];
        }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        vector<int> price(n);
        for(int i=0;i<n;i++) cin>>price[i];
        Solution obj;
        cout<<obj.maxProfit(price)<<endl;
    }

}

// } Driver Code Ends