#include <iostream>
#include "trie.h"
using namespace std;

Trie::~Trie() {
	TrieNode *node = &root;
	for (int i = 0; i < CHILDREN_SIZE; ++i) {
		if (node->children[i] != NULL) {
			destroy(node->children[i]); 
		}
	}
}

void Trie::destroy(TrieNode *node) {
	for (int i = 0; i < CHILDREN_SIZE; ++i) {
		if (node->children[i] != NULL) {
			destroy(node->children[i]);
		}
	}
	delete node;
}

int Trie::insert(string word) {
    if (word.empty()) return 0;
    TrieNode *node = &root;
    for (size_t i = 0; i < word.size(); ++i) {
        if (node->children[(int)word[i]] == NULL) {
            TrieNode *child = new TrieNode();
            if (!child) return -1;
            node->children[(int)word[i]] = child;
        }
        node = node->children[(int)word[i]];
    }
    node->count++;
    return 0;
}

bool Trie::search(string word) {
	TrieNode *node = &root;
	for (size_t i = 0; i < word.size(); ++i) {
		if (node->children[(int)word[i]] == NULL) {
			return false;
		}
		else {
			node = node->children[(int)word[i]];
		}
	}
	return (node->count > 0);
}

vector<string> Trie::startWith(string prefix) {
	vector<string> ret;
	if (prefix.empty()) return ret;
	TrieNode *node = &root;
	for (size_t i = 0; i < prefix.size(); ++i) {
		if (node->children[(int)prefix[i]] == NULL) {
			return ret;
		}
		else {
			node = node->children[(int)prefix[i]];
		}
	}
	getAllWords(node, prefix, ret);

	return ret;
}

void Trie::getAllWords(TrieNode *node, string prefix, vector<string> &ret) {
	if (node->count > 0) {
		ret.push_back(prefix);
	}
	for (int i = 0; i < CHILDREN_SIZE; ++i) {
		if (node->children[i] != NULL) {
			getAllWords(node->children[i], prefix + string(1, char(i)), ret);
		}
	}
}

void Trie::print() {
    print(&root, string(""));
}

void Trie::print(TrieNode *node, string prev) {
    if (node->count > 0) {
        cout << prev << " : " << node->count << endl;
    }
    for (int i = 0; i < CHILDREN_SIZE; ++i) {
        if (node->children[i] != NULL) {
			print(node->children[i], prev + string(1, char(i)));
		}
	}
}
