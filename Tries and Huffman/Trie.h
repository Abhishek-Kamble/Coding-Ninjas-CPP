#include "TrieNode.h"

class Trie{
    TrieNode* root;

    public:

    Trie()
    {
        root = new TrieNode('\0');
    }

    void insertWord(TrieNode root, string word)
    {
        //base case
        if(word.size()==0)
        {
            root->isTerminal = true;
            return;
        }

        //small calculation
        int index = word[0] - 'a'; //getting index
        TrieNode *child;
        if(root->children[index] != '\0')
        {
            child = root->children[index];
        }
        else
        {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        //Recursive call
        insertWord(child, word.substr(1));
    }

    void insertWord(string word)
    {
        insertWord(root, word);
    }

    bool search(TrieNode* root, string word)
    {
        //base case
        if(word.size()==0)
            return root->isTerminal;

        //small calculation
        int index = word[0] - 'a';
        if(root->children[index] != '\0')
        {
            return search(root->children[index], word.substr(1));
        }
        else
            return false;
    }

    bool search(string word)
    {
        return search(root, word);
    }

    void removeWord(TrieNode *root, string word)
    {
        //base case
        if(word.size()==0)
        {
            root->isTerminal = false;
            return;
        }

        //small calc.
        int index = word[0] - 'a';
        TrieNode* child;
        if(root->children[index] != '\0')
        {
            child = root->children[index];
        }
        else
            return; // word not found
        
        removeWord(child, word.substr(1));
    }

    void removeWord(string word)
    {
        removeWord(root, word);
    }
}