//Francisco Rocha
//Iker Guerrero
//Juan Carlos Llanos

//Para los casos de prueba por favor pegas los archivos txt en la terminal

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;

// The number of children for each node
// We will construct a N-ary tree and make it
// a Trie
// Since we have 26 english letters, we need
// 26 children per node
#define N 26

typedef struct TrieNode TrieNode;

struct TrieNode {
    // The Trie Node Structure
    // Each node has N children, starting from the root
    // and a flag to check if it's a leaf node
    char data; // Storing for printing purposes only
    TrieNode* children[N];
    int is_leaf;
};

TrieNode* make_trienode(char data) {
    // Allocate memory for a TrieNode
    TrieNode* node = (TrieNode*) calloc (1, sizeof(TrieNode));
    for (int i=0; i<N; i++)
        node->children[i] = NULL;
    node->is_leaf = 0;
    node->data = data;
    return node;
}

TrieNode* insert_trie(TrieNode* root, string word) {
    // Inserts the word onto the Trie
    // ASSUMPTION: The word only has lower case characters
    TrieNode* temp = root;

    for (int i=0; word[i] != '\0'; i++) {
        // Get the relative position in the alphabet list
        int idx = (int) word[i] - 'a';
        if (temp->children[idx] == NULL) {
            // If the corresponding child doesn't exist,
            // simply create that child!
            temp->children[idx] = make_trienode(word[i]);
        }
        else {
            // Do nothing. The node already exists
        }
        // Go down a level, to the child referenced by idx
        // since we have a prefix match
        temp = temp->children[idx];
    }
    // At the end of the word, mark this node as the leaf node
    temp->is_leaf = 1;
    return root;
}

int search_trie(TrieNode* root, string word)
{
    // Searches for word in the Trie
    TrieNode* temp = root;

    for(int i=0; word[i]!='\0'; i++)
    {
        int position = word[i] - 'a';
        if (temp->children[position] == NULL)
            return 0;
        temp = temp->children[position];
    }
    if (temp != NULL && temp->is_leaf == 1)
        return 1;
    return 0;
}

//DFS Traverse the TRIE DATA STRUCTURE
void print_trie(TrieNode* root) {
    // Prints the nodes of the trie
    if (!root)
        return;
    TrieNode* temp = root;
    printf("%c -> ", temp->data);
    for (int i=0; i<N; i++) {
        print_trie(temp->children[i]);
    }
}

void print_search(TrieNode* root, string word) {
    if (search_trie(root, word) == 0)
        printf("False\n");
    else
        printf("True\n");
}

int main() {

    //We ask for n (Number of words to add)
    int n;
    cin>>n;

    //We add the words to an array
    string keys[n];
    string key;
    for (int i = 0; i < n; ++i) {
        cin>>key;
        keys[i] = key;
    }

    //We ask for m (Number of words to search)
    int m;
    cin>>m;

    //We add the words to search to an array
    string words[m];
    string word;
    for (int i = 0; i < m; ++i) {
        cin>>word;
        words[i] = word;
    }


    // Driver program for the Trie Data Structure Operations
    TrieNode* root = make_trienode('\0');

    //Construct TRIE
    for (int i = 0; i < n; ++i) {
        root = insert_trie(root, keys[i]);
    }

    //We print the TRIE
    print_trie(root);
    printf("\n");

    //Search words in Trie
    for (int i = 0; i < m; ++i) {
        //cout<<words[i]<<endl;
        print_search(root,words[i]);
    }


    return 0;
}