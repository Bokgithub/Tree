

#include "module.h"

int main() {  
  trees* data = readTxt("input.txt");


  for (int i = 0; i < data->num; i++) {
    node *root = makeTreeBFS(data->line[i]);
    printf("\nPreOrder\n");
    printPreOrder(root);
    printf("\nInOrder\n");
    printInOrder(root);
    printf("\nPostOrder\n");
    printPostOrder(root);
    freeTree(root);
  }

  freeTxt(data);
  return 0;
}