#ifndef TRIENODE_H
#define TRIENODE_H
#include <map>

class TrieNode
{
	public:
		TrieNode();
		TrieNode(char charToSet, bool _isEnd);
		~TrieNode();
		char character;
		bool isEnd;
		std::map<char, TrieNode> next;
	private:
	protected:
	
	
};

#endif