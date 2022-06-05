#include "functions.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
  static struct RowData rowsData[540000];
  FILE *file;

  if ((file = fopen("municipios.csv", "r")) == NULL) {
    printf("Erro ao abrir o arquivo");
    return 1;
  };

  char rowContent[180];
  int columns[] = {1, 4, 8, 17};

  while (!feof(file)) {
    fgets(rowContent, 180, file);

    getColumnContentsInRow(rowContent, columns, rowsData);
  }

  menu();

  return 0;
}
