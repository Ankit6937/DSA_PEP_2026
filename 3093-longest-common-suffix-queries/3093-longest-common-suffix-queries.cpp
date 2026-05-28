class Solution {
public:

    struct Node {
        int child[26];
        int idx;

        Node() {
            memset(child, -1, sizeof(child));
            idx = -1;
        }
    };

    vector<Node> trie;

    // update best index according to:
    // 1. smaller length
    // 2. earlier index
    void updateIndex(int &storedIdx,int newIdx,vector<string>& wordsContainer) {
        if(storedIdx == -1) {
            storedIdx = newIdx;
            return;
        }

        int oldLen =wordsContainer[storedIdx].size();
        int newLen =wordsContainer[newIdx].size();

        if(newLen < oldLen) {
            storedIdx = newIdx;
        }
        else if(newLen == oldLen && newIdx < storedIdx) {
            storedIdx = newIdx;
        }
    }

    vector<int> stringIndices(vector<string>& wordsContainer,vector<string>& wordsQuery) {
        trie.push_back(Node());

        // build reverse trie
        for(int i = 0;i < wordsContainer.size();i++) {
            string word = wordsContainer[i];
            reverse(word.begin(),word.end());

            int node = 0;

            // update root answer also
            updateIndex(trie[node].idx,i,wordsContainer);

            for(char ch : word) {
                int c = ch - 'a';

                if(trie[node].child[c] == -1) {
                    trie[node].child[c] = trie.size(); //index of the new node
                    //child['a'] = 5, means go to trie[5]
                    trie.push_back(Node());
                }

                node = trie[node].child[c];
                updateIndex(trie[node].idx,i,wordsContainer);
            }
        }

        vector<int> ans;

        // process queries
        for(string query : wordsQuery) {
            reverse(query.begin(),query.end());

            int node = 0;

            for(char ch : query) {
                int c = ch - 'a';

                if(trie[node].child[c] == -1) {
                    break;
                }
                node = trie[node].child[c];
            }

            ans.push_back(trie[node].idx);
        }

        return ans;
    }
};