#include <iostream>
#include <map>
#include "TrieNode.h"

TrieNode::TrieNode(){
	next = std::map<char, TrieNode*>();
	character = 'a';
	isEnd = false;
}

TrieNode::TrieNode(char charToSet){
	character = charToSet;
	isEnd = false;
}

TrieNode::TrieNode(char charToSet, bool _isEnd){
	character = charToSet;
	isEnd = _isEnd;
}

TrieNode::~TrieNode(){

}

TrieNode* TrieNode::getNextNode(char charToSearch){
	std::map<char, TrieNode*>::iterator it = next.find(charToSearch);
	TrieNode* toReturn;
	if(it == next.end()){
		toReturn = new TrieNode(charToSearch);
		next.insert(std::map<char, TrieNode*>::value_type(charToSearch, toReturn));
	}
	else{
		toReturn = it->second;
	}

	return toReturn;
}

bool TrieNode::hasNode(char charToSearch){
	std::map<char, TrieNode*>::iterator it = next.find(charToSearch);
	if(it == next.end()){
		return false;
	}
	else{
		return true;
	}
}