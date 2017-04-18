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

void Trie::insertWord(std::string word){
	if(word.length() == 0){
		return;
	}
	insert(word, 1, root.getNextNode(word[0]));
}

void Trie::insert(std::string word, int index, TrieNode nextNode){
	if(index == word.length()){
		nextNode.isEnd = true;
	}
	else{
		insert(word, index+1, nextNode.getNextNode(word[index]));
	}
}

bool Trie::exists(std::string word){
	return false;
}

std::list<std::string> Trie::prefixSearch(std::string prefix, int index, std::list<std::string> currWords, std::string currWord){
	return currWords;
}
