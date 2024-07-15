struct TrieNode {
    TrieNode* childNode[26];
    bool isWordEnd, isWordFound;
    TrieNode(){
        for(int i = 0; i < 26; ++i){
            isWordEnd = false, isWordFound = false;
            childNode[i] = NULL;
        }
    }
};


class Solution {
private:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0 , 0};

    void insertWord(string key, TrieNode* root){
        TrieNode* currNode = root;
        for(auto c : key){
            if(currNode -> childNode[c - 'a'] == NULL){
                TrieNode* newNode = new TrieNode();
                currNode -> childNode[c - 'a'] = newNode;
            }
            currNode = currNode -> childNode[c - 'a'];
        }
        currNode -> isWordEnd = true;
    };

    void search(int i,int j, TrieNode* node, int n, int m, vector<vector<char>>&board,vector<vector<int>>&vis){
        if(i < 0 || j < 0 || i >= n || j >= m || vis[i][j]) return;
        
        if(node -> childNode[board[i][j] - 'a'] == NULL) return;
        node = node -> childNode[board[i][j] - 'a'];

        if(node -> isWordEnd){
            node -> isWordFound = true;
        }

        vis[i][j] = 1;
        for(int k = 0; k < 4; ++k){
            search(i + dx[k], j + dy[k], node, n, m, board, vis);
        }
        vis[i][j] = 0;
    }
    void backtrack(TrieNode* node,string&s, vector<string>&ans){
        if(node -> isWordFound){
            ans.push_back(s);
        }
        for(int i = 0; i < 26; ++i){
            if(node -> childNode[i] != NULL){
                s += 'a' + i;
                backtrack(node -> childNode[i], s, ans);
                s.pop_back();
            }
        }
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int n = board.size(), m = board[0].size();
        vector<vector<int>> vis(n,vector<int>(m, 0));
        TrieNode* root = new TrieNode();

        for(int i = 0; i < words.size(); ++i){
            insertWord(words[i], root);
        }
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                search(i,j,root,n,m,board,vis);
            }
        }
        string s = "";
        vector<string> ans;
        backtrack(root, s, ans);

        return ans;
    }
};