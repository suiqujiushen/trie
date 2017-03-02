# trie
A simple Trie C++ implemention

Trie can be used to count words in big files, or get supplement words by prefix effciently.

It is very easy to use:

Trie trie;
trie.insert("test");
bool exist = trie.search("test");
// get all 
vector<string> words = trie.startWith("te");
// print all words
trie.print();
