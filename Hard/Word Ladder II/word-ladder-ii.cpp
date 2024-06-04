//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    void dfs(string& word, vector<vector<string>>& ans, string& beginWord, vector<string>& seq, unordered_map<string,int>& dict){
        if (word == beginWord) {
            reverse(seq.begin(),seq.end());
            ans.push_back(seq);
            reverse(seq.begin(),seq.end());
            return;
        }
        int len = word.size();
        int lvl = dict[word];
        for (int i = 0; i < len; i++){
            char org = word[i];
            for(char ch = 'a'; ch <= 'z'; ch++){
                word[i] = ch;
                if (dict.find(word) != dict.end() && dict[word] == lvl-1){
                    seq.push_back(word);
                    dfs(word,ans,beginWord,seq,dict);
                    seq.pop_back();
                }
            }
            word[i] = org;
        }
    }

    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,int> dict;
        unordered_set<string> lst(wordList.begin(),wordList.end());
        vector<vector<string>> ans;
        queue<string> q;
        q.push(beginWord);
        dict[beginWord] = 1;
        lst.erase(beginWord);
        int found = 0;
        int len = beginWord.size();
        while (!q.empty()){
            string word = q.front();
            int lvl = dict[word];
            if (word == endWord){
                found = 1;
                break;
            }
            q.pop();
            for (int i = 0; i < len; i++){
                char org = word[i];
                for(char ch = 'a'; ch <= 'z'; ch++){
                    word[i] = ch;
                    if (lst.find(word) != lst.end()){
                        q.push(word);
                        lst.erase(word);
                        dict[word] = lvl+1;
                    }
                }
                word[i] = org;
            }
        }
        if (found) {
            vector<string> seq;
            seq.push_back(endWord);
            dfs(endWord, ans, beginWord,seq,dict);
        }
        return ans;
    }
};

//{ Driver Code Starts.

bool comp(vector<string> a, vector<string> b)
{
    string x = "", y = "";
    for(string i: a)
        x += i;
    for(string i: b)
        y += i;
    
    return x<y;
}

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		vector<vector<string>> ans = obj.findSequences(startWord, targetWord, wordList);
		if(ans.size()==0)
		    cout<<-1<<endl;
		else
		{
		    sort(ans.begin(), ans.end(), comp);
            for(int i=0; i<ans.size(); i++)
            {
                for(int j=0; j<ans[i].size(); j++)
                {
                    cout<<ans[i][j]<<" ";
                }
                cout<<endl;
            }
		}
	}
	return 0;
}
// } Driver Code Ends