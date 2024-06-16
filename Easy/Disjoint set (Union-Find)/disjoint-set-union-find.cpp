//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
int find(int a[],int x);
void unionSet(int a[],int x ,int z);
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n+1];
		for(int i=1;i<=n;i++)
			a[i]=i;
		int k;
		cin>>k;
		for(int i=0;i<k;i++){
			string s;
			cin>>s;
			if(s=="UNION"){
				int z,x;
				cin>>x>>z;
				unionSet(a,x,z);
			}
			else{
				int x;
				cin>>x;
				int parent=find(a,x);
				cout<<parent<<" ";
			}
		}
		cout<<endl;
	}
}
// } Driver Code Ends

// int findParent(int node, vector<int> parent){
//     if (parent[node] == node) return node;
//     return parent[node] = findParent(parent[node], parent);
// }

/*Complete the functions below*/


int find(int parent[],int node)
{
    if (parent[node] == node) return node;
    return parent[node] = find(parent, parent[node]);
}
void unionSet(int parent[],int X,int Z)
{
    parent[find(parent, X)] = find(parent, Z);
}