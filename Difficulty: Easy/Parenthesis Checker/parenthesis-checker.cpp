//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string s)
    {
        if (s.size() % 2)
            return false;
        stack<char> stk;
        for (auto c : s) {
            if (c == '(' || c == '{' || c == '[')
                stk.push(c);
            else {
                if (stk.empty())
                    return false;
                else {
                    int diff = c - stk.top();
                    if (diff == 1 || diff == 2)
                        stk.pop();
                    else
                        return false;
                }
            }
        }
        if (stk.empty())
            return true;
        else
            return false;
    }

};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends