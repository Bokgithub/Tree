#include "module.h"

trees *readTxt(char *fileName) {

  char buf[255];
  FILE *fp = fopen(fileName, "r");
  trees *ret = malloc(sizeof(trees));
  int lineNum = 0;

  while (fgets(buf, 255, fp) != NULL) {
    lineNum++;
    ret->line = (lineNum <= 1) ? malloc(sizeof(char *))
                               : realloc(ret->line, lineNum * sizeof(char *));
    if (buf[strlen(buf) - 1] == '\n')
      buf[strlen(buf) - 1] = '\0';

    ret->line[lineNum - 1] = malloc((strlen(buf) + 1) * sizeof(char));
    strcpy(ret->line[lineNum - 1], buf);
  }

  ret->num = lineNum;

  fclose(fp);
  return ret;
}

void freeTxt(trees *data) {
  int lineNum = data->num;
  for (int i = 0; i < lineNum; i++)
    free(data->line[i]);
  free(data->line);
  free(data);
}