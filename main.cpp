//Francisco Rocha
//Iker Guerrero
//Juan Carlos Llanos

// C++ implementation of search and insert
// operations on Trie
#include <iostream>
using namespace std;
  
const int ALPHABET_SIZE = 26;
  
// trie node
struct TrieNode
{
    struct TrieNode *children[ALPHABET_SIZE];
  
    // isEndOfWord is true if the node represents
    // end of a word
    bool isEndOfWord;
};
  
// Returns new trie node (initialized to NULLs)
struct TrieNode *getNode(void)
{
    struct TrieNode *pNode =  new TrieNode;
  
    pNode->isEndOfWord = false;
  
    for (int i = 0; i < ALPHABET_SIZE; i++)
        pNode->children[i] = NULL;
  
    return pNode;
}
  
// If not present, inserts key into trie
// If the key is prefix of trie node, just
// marks leaf node
void insert(struct TrieNode *root, string key)
{
    struct TrieNode *pCrawl = root;
  
    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (!pCrawl->children[index])
            pCrawl->children[index] = getNode();
  
        pCrawl = pCrawl->children[index];
    }
  
    // mark last node as leaf
    pCrawl->isEndOfWord = true;
}
  
// Returns true if key presents in trie, else
// false
bool search(struct TrieNode *root, string key)
{
    struct TrieNode *pCrawl = root;
  
    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (!pCrawl->children[index])
            return false;
  
        pCrawl = pCrawl->children[index];
    }
  
    return (pCrawl->isEndOfWord);
}

  
int main()
{
    //We ask the number of words to be inserted
    int n;
    cin>>n;

    //We declare the array to save the words to be inserted
    string keys[n];
    string key;
    for (int i = 0; i < n; i++)
    {
        cin>>key;
        keys[i] = key;
    }
    

    //We ask for the number of words to be searched
    int m;
    cin>>m;

    //We declare an array to save words to be searched
    string words[m];
    string word;
    for (int i = 0; i < m; i++)
    {
        cin>>word;
        words[i] = word;
    }

  
    struct TrieNode *root = getNode();
  
    // Construct trie
    for (int i = 0; i < n; i++)
        insert(root, keys[i]);
  
    // Search for different keys
    for (int i = 0; i < m; i++)
    {
        search(root, words[i])? cout << "Yes\n" :
                         cout << "No\n";
    }
    

    return 0;
}