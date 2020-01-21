#ifndef TRIE
#define TRIE
#define NUM_LETTERS ((int)26)

typedef enum {FALSE=0, TRUE=1} boolean;

typedef struct TrieNode {
  unsigned int isWord;
  long unsigned int count;
  struct TrieNode *children[NUM_LETTERS];
}TrieNode;

TrieNode *getNode();

void insert(TrieNode *root, const char *str);
void printDufult(TrieNode *root, char str[], int level);
void printReverse(TrieNode *root, char str[], int level);
void freeTrie(TrieNode *root);
int isWord(const char *str, int length);
int CharToIndex(char ch);
char lowerChar(char ch);

#endif
