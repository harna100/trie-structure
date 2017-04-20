#ifndef TRIE_H
#define TRIE_H
#include <list>
#include "TrieNode.h"

class Trie
{
	public:
		Trie();
		~Trie();
		void insertWord(std::string word);
		bool exists(std::string word);
		std::list<std::string>* prefixSearch(std::string prefix);
		std::list<std::string>* prefixRecurse(std::string currWord, std::list<std::string>* currWords, TrieNode* node);
		TrieNode* root;

	private:
		void insert(std::string word, unsigned int index, TrieNode* nextNode);
	protected:
	
	
};

#endif