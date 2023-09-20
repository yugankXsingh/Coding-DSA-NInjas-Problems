#include <iostream>
using namespace std;
#include "TrieNode.h"

class Trie
{
    TrieNode *root;

public:
    Trie()
    {
        root = new TrieNode('\0');
    }

    void insertWord(TrieNode *root, string word)
    {
        // base case
        if (word.size() == 0)
        {
            root->isTerminal = true;
            return;
        }

        // small calculation
        TrieNode *child;
        int index = word[0] - 'a';

        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // recursive call
        insertWord(child, word.substr(1));
    }

    bool search(TrieNode *root, string word)
    {
        // base case
        if (word.size() == 0)
        {
            return root->isTerminal;
        }

        // small calculation
        int index = word[0] - 'a';
        TrieNode *child;

        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            return false;
        }

        return search(child, word.substr(1));
    }

    // for the user
    void insertWord(string word)
    {
        insertWord(root, word);
    }

    bool search(string word)
    {
        return search(root, word);
    }
};