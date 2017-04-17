#include <iostream>
#include <map>
#include "TrieNode.h"

TrieNode::TrieNode(){
	next = std::map<char, TrieNode>();
	character = 'a';
	isEnd = false;
}

TrieNode::TrieNode(char charToSet, bool _isEnd){

}

TrieNode::~TrieNode(){

}