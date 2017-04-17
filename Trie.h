#ifndef TRIE_H
#define TRIE_H
#include <list>
#include "TrieNode.h"

class Trie
{
	public:
		Trie();
		~Trie();
		void insert(std::string word, int index, TrieNode nextNode);
		bool exists(std::string word);
		std::list<std::string> prefixSearch(std::string prefix, int index, std::list<std::string> currWords);

	private:
		TrieNode root;
	protected:
	
	
};

#endif