#include <iostream>
#include <list>
#include <map>
#include "Trie.h"
#include "TrieNode.h"

Trie::Trie(){
	root = TrieNode();
	root.character = '\0';
	root.next = std::map<char, TrieNode>();
};

Trie::~Trie(){

}

void Trie::insert(std::string word, int index, TrieNode nextNode){

}

bool Trie::exists(std::string word){
	return false;
}

std::list<std::string> Trie::prefixSearch(std::string prefix, int index, std::list<std::string> currWords){
	return currWords;
}
