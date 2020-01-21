#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trie.h"

TrieNode *getNode(){
  TrieNode *node = (struct TrieNode*)malloc(sizeof(struct TrieNode));

  if(node){
    node->isWord = FALSE;
    node->count = 0;
    for (int i = 0; i < NUM_LETTERS; i++)
    node->children[i] = NULL;
  }
  return node;
}

void insert(TrieNode *root, const char *str){
  int index;
  int length = strlen(str);

  TrieNode *head = root;

  for (int i = 0; i < length; i++){
    char ch = str[i];

    if(ch >= 'a' && ch <='z'){
      index = CharToIndex(ch);
      if (!head->children[index]){
        head->children[index] = getNode();
      }
      head = head->children[index];
    }
  }
  if(isWord(str,length)){
    head->isWord = TRUE;
    head->count++;
  }
}

void printDufult(TrieNode *root, char str[], int level){
  if (root->isWord == TRUE){
    str[level] = '\0';
    printf("%s \t %ld \n" ,str,root->count);
  }

  for (int i = 0; i < NUM_LETTERS; i++){
    if (root->children[i])  {
      str[level] = i + 'a';
      printDufult(root->children[i], str, level + 1);
    }
  }
}

void printReverse(TrieNode *root, char str[], int level){
  if (root->isWord == TRUE){
    str[level] = '\0';
    printf("%s \t %ld \n" ,str,root->count);
  }

  for (int i = NUM_LETTERS-1; i > -1; i--){
    if (root->children[i])  {
      str[level] = i + 'a';
      printReverse(root->children[i], str, level + 1);
    }
  }
}

void freeTrie(TrieNode *root){
  if(!root)return;

  for(int i = 0; i < NUM_LETTERS; i++){
    if(root->children[i])
    freeTrie(root->children[i]);
  }
  free(root);
}

int isWord(const char *str, int length){
  for(int i = 0; i < length; i++){
    if(str[i] >= 'a' && str[i] <='z')
    return 1;
  }
  return 0;
}

int CharToIndex(char ch){
  return ch-'a';
}

char lowerChar(char ch){
  return ch+('a'-'A');
}
