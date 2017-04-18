#include <iostream>
#include <map>
#include "TrieNode.h"
#include "Trie.h"

Trie importWords(std::string fileName);

int main(int argc, char **argv){
	Trie trie = Trie();
	trie.insertWord("Hello");
	std::cout << '\n';
	trie.insertWord("Hell");
	std::cout << '\n';
	trie.insertWord("blah");
	std::cout << '\n';
	trie.insertWord("bla");

	char c;
	std::cin >> c;
	return 0;
}

Trie importWords(std::string fileName){
	return Trie();
}