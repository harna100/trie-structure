#include <iostream>
#include <map>
#include <list>
#include <fstream>
#include "TrieNode.h"
#include "Trie.h"

Trie importWords(std::string fileName);

int main(int argc, char **argv){
	if(argc != 2){
		std::cout << "Enter only 1 argument (filename containing words separated by lines)\n";
		return 1;
	}
	Trie trie = importWords(argv[1]);

	std::string userRaw;
	
	while(true){
		std::cout << "Enter prefix (-1 to quit): ";
		std::getline(std::cin, userRaw);
		
		if(userRaw == "-1"){
			break;
		}
		else{
			std::list<std::string>* returned = trie.prefixSearch(userRaw);
			for (std::list<std::string>::iterator i = returned->begin(); i != returned->end(); ++i){	
		    	std::cout << *i << '\n';
			}
		}
	}

	return 0;
}

Trie importWords(std::string fileName){
	Trie toReturn = Trie();
	std::ifstream infile(fileName);
	std::string line;
	while(std::getline(infile, line)){
		toReturn.insertWord(line);
	}

	return toReturn;
}