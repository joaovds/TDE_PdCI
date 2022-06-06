#ifndef MENU_H
#define MENU_H

struct RowData {
  char cityName[50];
  int cases, deaths, population;
  float caseXPolulationRatio;
};

void menu();

void getColumnContentsInRow(char *rowContent, int *columns,
                            struct RowData *rowsData);

#endif
