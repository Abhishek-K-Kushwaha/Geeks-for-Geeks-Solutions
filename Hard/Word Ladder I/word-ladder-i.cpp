//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool differByOneLetter(const string& word1, const string& word2) {
        int count = 0;
        for (int i = 0; i < word1.size(); ++i) {
            if (word1[i] != word2[i]) {
                ++count;
            }
            if (count > 1) {
                return false;
            }
        }
        return count == 1;
    }

    // Function to create the adjacency list
    unordered_map<string, unordered_set<string>>
    createAdj(const vector<string>& wordList) {
        unordered_map<string, unordered_set<string>> adjacencyList;
        for (const string& word : wordList) {
            adjacencyList[word] = unordered_set<string>();
        }

        for (const string& word1 : wordList) {
            for (const string& word2 : wordList) {
                if (differByOneLetter(word1, word2)) {
                    adjacencyList[word1].insert(word2);
                }
            }
        }

        return adjacencyList;
    }

    int wordLadderLength(string beginWord, string endWord, vector<string>& wordList) {
        wordList.push_back(beginWord);
        unordered_map<string, unordered_set<string>> adj = createAdj(wordList);
        // printAdjacencyList(adj);
        if (adj.find(endWord) == adj.end())
            return 0;
        if (adj[beginWord].empty())
            return 0;
        queue<pair<string, int>> q;
        unordered_map<string, int> visited;
        q.push({endWord, 1});
        visited[endWord] = 1;
        while (!q.empty()) {
            string word = q.front().first;
            int lvl = q.front().second;
            q.pop();
            if (word == beginWord)
                return lvl;
            for (auto nxt : adj[word]) {
                if (visited[nxt] == 0) {
                    q.push({nxt, lvl + 1});
                    visited[nxt] = 1;
                }
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.
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
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends