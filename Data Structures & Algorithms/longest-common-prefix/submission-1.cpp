class TrieNode {
    public:

    unordered_map<char, TrieNode*> child;
    bool isEnd;

    TrieNode() {
        isEnd = false;
    }
};


class Trie {
    public:

    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* curr = root;

        for (char c : word) {
            if (curr->child.count(c) == 0) {
                curr->child[c] = new TrieNode();
            }
            curr = curr->child[c];
        }
        curr->isEnd = true;
    }

    string longestPrefix() {
        string prefix = "";
        TrieNode* curr = root;

        while (curr->child.size() == 1 && not curr->isEnd) {
            auto it = curr->child.begin();
            prefix.push_back(it->first);
            curr = curr->child[it->first];
        }
        return prefix;
    }

};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string s;

        Trie tree;

        for (string str : strs) {
            tree.insert(str);
        }

        return tree.longestPrefix();
    }
};