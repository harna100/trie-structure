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

	std::cout << '\n';
	for(std::map<char, TrieNode>::const_iterator it = trie.root.next.begin(); it != trie.root.next.end(); ++it){
		std::cout << it->second.character << "\n";
		for(std::map<char, TrieNode>::const_iterator it2 = it->second.next.begin(); it2 != it->second.next.end(); ++it2){
			std::cout << it2->second.character << "\n";
		}
	}
	return 0;
}

Trie importWords(std::string fileName){
	return Trie();
}