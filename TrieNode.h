#ifndef TRIENODE_H
#define TRIENODE_H
#include <map>

class TrieNode
{
	public:
		TrieNode();
		TrieNode(char charToSet);
		TrieNode(char charToSet, bool _isEnd);
		~TrieNode();
		TrieNode getNextNode(char charToSearch);
		char character;
		bool isEnd;
		std::map<char, TrieNode> next;
	private:
	protected:
	
	
};

#endif