#include <iostream>
#include <map>
#include "TrieNode.h"
#include "Trie.h"

int main(int argc, char **argv){
	
	std::map<char, int> myMap;

	std::map<char, TrieNode> myMap2;
	myMap2['a'] = TrieNode();
	
	char c;
	std::cin >> c;
	std::map<char, TrieNode>::iterator it = myMap2.find(c);
	if(it == myMap2.end()){
		std::cout << "Error\n";
	}
	else{
		std::cout << "\'" << it->second.character << "\'"  << std::endl;
	}


	return 0;
}