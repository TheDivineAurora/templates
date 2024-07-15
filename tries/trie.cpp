#include <bits/stdc++.h>
using namespace std;


struct TrieNode {
	TrieNode* childNode[26];

	bool wordEnd;
	TrieNode(){
		wordEnd = false;
		for(int i = 0; i < 26; ++i){
			childNode[i] = NULL;
		}
	}
};

void insert_key(TrieNode* root, string& key){
	TrieNode* currentNode = root;

	for(auto c : key){
		if(currentNode -> childNode[c - 'a'] == NULL){
			TrieNode* newNode = new TrieNode();
			currentNode -> childNode[c - 'a'] = newNode;
		}

		currentNode = currentNode -> childNode[c - 'a'];
	}

	currentNode -> wordEnd = true;
}	


bool search_key(TrieNode* root, string& key, bool isPrefix){
	TrieNode* currentNode = root;

	for(auto c : key){
		if(currentNode -> childNode[c - 'a'] == NULL)
			return false;
		currentNode = currentNode -> childNode[c - 'a'];
	}

	return (currentNode -> wordEnd) && !isPrefix;
}
int main(){
	
	return 0;	
}