#ifndef  __TRIE_H_
#define  __TRIE_H_

#include <vector>
using namespace std;

const int CHILDREN_SIZE = 256;

struct TrieNode {
    int count;
    TrieNode *children[CHILDREN_SIZE];
    TrieNode() {
        count = 0;
		for (int i = 0; i < CHILDREN_SIZE; ++i) {
			children[i] = NULL;
		}
    }
};

class Trie {
public:
    //Trie()
    ~Trie();
	
	// Insert a word
    int insert(string word);

	// Search word if exists
    bool search(string word);

	// get all words with prefix
    vector<string> startWith(string prefix);

	// print all words
    void print();

private:
	void destroy(TrieNode *node);
	void getAllWords(TrieNode *node, string prefix, vector<string> &ret);
	void print(TrieNode *node, string prev);

private:
    TrieNode root;
};



#endif  //__TRIE_H_

