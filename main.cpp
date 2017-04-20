#include <iostream>
#include <map>
#include <list>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include "TrieNode.h"
#include "Trie.h"

Trie importWords(std::string fileName);

int main(int argc, char **argv){
	if(argc != 2){
		std::cout << "Enter only 1 argument (filename containing words separated by lines)\n";
		return 1;
	}
	clock_t t;

	t = clock();
	Trie trie = importWords(argv[1]);
	t = clock() - t;
	std::cout << "Took " << t << " clicks (" << ((float)t)/CLOCKS_PER_SEC << " seconds) to insert words from file\n";
	std::string userRaw;
	srand(time(NULL));
	
	while(true){
		int prefixLength = rand() % 5 + 1;
		std::cout << "Enter prefix of length '" << prefixLength << "' or -1 to quit: ";
		std::getline(std::cin, userRaw);

		if(userRaw == "-1"){
			break;
		}
		if(userRaw.length() != prefixLength){
			continue;
		}
		else{
			std::cout << "Words found: \n"; 
			clock_t t2 = clock();
			std::list<std::string>* returned = trie.prefixSearch(userRaw);
			t2 = clock() - t2;

			for (std::list<std::string>::iterator i = returned->begin(); i != returned->end(); ++i){	
		    	std::cout << *i << '\n';
			}
			std::cout << "Took " << t2 << " clicks (" << ((float)t2)/CLOCKS_PER_SEC << " seconds) to find words\n";
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