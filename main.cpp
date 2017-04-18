#include <iostream>
#include <map>
#include <list>
#include <fstream>
#include "TrieNode.h"
#include "Trie.h"

Trie importWords(std::string fileName);

int main(int argc, char **argv){
/*	Trie trie = Trie();
	trie.insertWord("Hello");
	std::cout << '\n';
	trie.insertWord("Hell");
	std::cout << '\n';
	trie.insertWord("blah");
	std::cout << '\n';
	trie.insertWord("bla");
	std::cout << '\n';

	std::list<std::string>* returned = trie.prefixSearch("Hel");
	for (std::list<std::string>::iterator i = returned->begin(); i != returned->end(); ++i){	
    	std::cout << *i << '\n';
	}

	std::cout << "\n\n";
	returned = trie.prefixSearch("bl");
	for (std::list<std::string>::iterator i = returned->begin(); i != returned->end(); ++i){	
    	std::cout << *i << '\n';
	}
*/
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
	int count = 0;
	while(std::getline(infile, line)){
		// std::cout << "inserting: " << line << '\n';
		toReturn.insertWord(line);
		std::cout << '\n';
		if(count == 21){
			break;
		}
		++count;
	}

	return toReturn;
}