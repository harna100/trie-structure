#include <iostream>
#include <list>
#include <map>
#include "Trie.h"
#include "TrieNode.h"

Trie::Trie(){
	root = new TrieNode();
	root->character = '\0';
	root->next = std::map<char, TrieNode*>();
};

Trie::~Trie(){

}

void Trie::insertWord(std::string word){
	if(word.length() == 0){
		return;
	}
	insert(word, 1, root->getNextNode(word[0]));
}

void Trie::insert(std::string word, unsigned int index, TrieNode* nextNode){
	if(index == word.length()){
		nextNode->isEnd = true;
	}
	else{
		insert(word, index+1, nextNode->getNextNode(word[index]));
	}
}

bool Trie::exists(std::string word){
	return false;
}


std::list<std::string>* Trie::prefixSearch(std::string prefix){
	std::list<std::string>* toReturn = new std::list<std::string>();
	std::string currWord = "";
	if(!root->hasNode(prefix[0])){
		return toReturn;
	}

	TrieNode* currNode = root->getNextNode(prefix[0]);
	currWord += currNode->character;
	int index = 1;

	// should get us to the node where things diverge
	while(index != prefix.length()){
		if(!currNode->hasNode(prefix[index])){
			return toReturn;
		}
		currNode = currNode->getNextNode(prefix[index]);
		currWord += currNode->character;
		++index;
	}


	if(currNode->isEnd){
		toReturn->push_back(currWord);
	}

	return prefixRecurse(std::string(currWord), toReturn, currNode);
}

std::list<std::string>* Trie::prefixRecurse(std::string currWord, std::list<std::string>* currWords, TrieNode* node){
	for(std::map<char, TrieNode*>::const_iterator it = node->next.begin(); it != node->next.end(); ++it){
		TrieNode* currNode = it->second;
		currWord += currNode->character;
		std::cout << currWord << '\n';
		if(currNode->isEnd){
			currWords->push_back(currWord);
		}
		prefixRecurse(std::string(currWord), currWords, currNode);
	}
	return currWords;
}

/*std::list<std::string>* Trie::prefixSearch(std::string prefix){
	std::list<std::string>* toReturn = new std::list<std::string>();
	if(prefix.length() == 0){
		return toReturn;
	}
	if(root->hasNode(prefix[0])){
		return prefix(prefix, static_cast<unsigned int>(1), toReturn, "", root->getNextNode(prefix[0]));
	}
	return toReturn;


}
*/
/*std::list<std::string>* Trie::prefix(std::string prefix, unsigned int index, std::list<std::string>* currWords, std::string currWord, TrieNode* nextNode){
	currWord += nextNode->character;
	if(index != prefix.length()){
		if(nextNode->hasNode(prefix[index])){
			return prefix(prefix, index+1, currWords, currWord, nextNode->getNextNode(prefix[index]));
		}
		else{
			return currWords;
		}
	}

	if(nextNode->isEnd){
		currWords->push_back(currWord);
	}

	for(std::map<char, TrieNode*>::const_iterator it = nextNode->next.begin(); it != nextNode->next.end(); ++it){
		TrieNode* node = it->second;
		prefix(prefix, index, currWords, currWord, node);	
	}


	return currWords;
}*/
