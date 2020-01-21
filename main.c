#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trie.h"

int main(int argc, char const *argv[]) {
  TrieNode *root = getNode();
  int physSize = 2,logicSize = 0;
  char ch = getchar();

  char *word = (char*)malloc(physSize*sizeof(char));
  if(!word){
    printf("Faild to allocate memory space!\n");
    return -1;
  }

  while(ch != EOF){
    if(physSize-1 == logicSize){
      physSize *= 2;
      word = (char*)realloc(word,physSize*sizeof(char));
      if(!word){
        printf("Faild to allocate memory space!\n");
        return -1;
      }
    }
    if(ch >= 'A' && ch <='Z'){
      ch = lowerChar(ch);
    }
    if((ch >= 'a' && ch <='z')){
      word[logicSize++] = ch;
    }
    if((ch == '\n') || (ch == '\t') || (ch == ' ')){
      word[logicSize] = '\0';
      insert(root,word);
      free(word);
      physSize = 2,logicSize = 0;
      word = (char*)malloc(physSize*sizeof(char));
      if(!word){
        printf("Faild to allocate memory space!\n");
        return -1;
      }
    }
    ch = getchar();
  }

  int level = 0;
  char str[NUM_LETTERS];

  if(((argc >= 2) && (strcmp(argv[1],"r") == 0)))
  printReverse(root,str,level);
  else
  printDufult(root,str,level);

  freeTrie(root);
  free(word);
  return 0;
}
