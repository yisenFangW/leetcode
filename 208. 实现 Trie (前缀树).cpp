实现一个 Trie (前缀树)，包含 insert, search, 和 startsWith 这三个操作。

示例:

Trie trie = new Trie();

trie.insert("apple");
trie.search("apple");   // 返回 true
trie.search("app");     // 返回 false
trie.startsWith("app"); // 返回 true
trie.insert("app");   
trie.search("app");     // 返回 true
说明:

你可以假设所有的输入都是由小写字母 a-z 构成的。
保证所有输入均为非空字符串。

题解：
//这题主要是什么是前缀树，这题因为都是小写英文字母，所以可以给数据结构设置为Tritree* next[26];
//设置一个bool标志，看这个是不是字符串的结尾；
//感觉这种题目比较有意思，多看看，

//前缀树学习实现
struct TrieNode{
    bool isWord;
    TrieNode* next[26];
    TrieNode(){
        memset(next, NULL, sizeof(next));
        isWord = false;
    }
    ~TrieNode(){
        for(int i=0;i<26;++i)
            delete next[i];
    }
};

class Trie {
    TrieNode* root;
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }

    ~Trie(){
        delete root;
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        if(word.empty()) return;
        TrieNode* p = root;
        for(int i=0;i<word.size();++i){
            if(p->next[word[i] - 'a'] == NULL){
                p->next[word[i] - 'a'] = new TrieNode();
            }
            p = p->next[word[i] - 'a'];
        }
        p->isWord = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        if(word.empty()) return true;
        TrieNode* p = root;
        for(int i=0;i<word.size() && p;++i)
            p = p->next[word[i] - 'a'];
        return p && p->isWord;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        if(prefix.empty()) return true;
        TrieNode* p = root;
        for(int i=0;i<prefix.size() && p;++i)
            p = p->next[prefix[i] - 'a'];
        return p;
    }
};
