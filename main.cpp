#include <iostream>
#include <map>
#include "TrieNode.h"
#include "Trie.h"

Trie importWords(std::string fileName);

int main(int argc, char **argv){
	
	std::map<char, TrieNode> myMap2;
	myMap2['a'] = TrieNode();
	
	char c;
	std::cin >> c;
	std::map<char, TrieNode>::iterator it = myMap2.find(c);
	if(it == myMap2.end()){
		std::cout << "Not found\n";
	}
	else{
		std::cout << "\'" << it->second.character << "\'"  << std::endl;
	}


	return 0;
}

Trie importWords(std::string fileName){
	return Trie();
}