#include <iostream>
#include "trie.h"
using namespace std;

int main()
{
    Trie trie;
    trie.insert("jacky");
    trie.insert("andy");
    trie.insert("baidu");
    trie.insert("alibaba");
    trie.insert("jacky");
    trie.insert("andy");
    trie.insert("baidu");
    trie.insert("alibaba");
    trie.insert("taobao");
    trie.insert("baidu");
    trie.insert("suiqujiushen");
    trie.insert("chengpeipei");
    trie.insert("baidu");
    vector<string> strings = trie.startWith("a");
    for (size_t i = 0; i < strings.size(); ++i) {
        cout << strings[i] << endl;
    }
	if (trie.search("taobo")) {
		cout << "true\n";
	}
	trie.print();
    return 0;
}
