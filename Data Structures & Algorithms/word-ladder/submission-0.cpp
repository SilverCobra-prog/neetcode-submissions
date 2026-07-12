class Solution {
public:

    unordered_map<string, vector<string>> graph;

    int bfs(string beginWord, string endWord) {
        if (beginWord == endWord) return 1; 

        unordered_map<string, bool> visited;
        queue<pair<string, int>> q;
        
        visited[beginWord] = true;
        q.push({beginWord, 1});

        while (!q.empty()) {
            auto [curr, dist] = q.front();
            q.pop();

            if (curr == endWord) {
                return dist;
            }

            for (const auto& neighbor : graph[curr]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push({neighbor, dist + 1}); 
                }
            }
        }
        return 0; 
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        wordList.push_back(beginWord);

        int n = wordList.size();
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                int diff = 0;
                for(int l = 0; l < wordList[i].size(); l++) {
                    if(wordList[i][l] != wordList[j][l]) diff++;
                }
                if(diff==1) {
                    graph[wordList[i]].push_back(wordList[j]);
                    graph[wordList[j]].push_back(wordList[i]);
                }
            }
        }
        return bfs(beginWord, endWord);
    }
};