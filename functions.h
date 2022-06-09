#ifndef MENU_H
#define MENU_H

typedef struct {
  char cityName[50];
  int cases, deaths, population;
  float caseXPolulationRatio;
} RowData;

void menu(RowData rowsData[], int numberOfIndexes);

RowData getColumnContentsInRow(char *rowContent, int *columns,
                               RowData rowsData);

void sortCityName(RowData rowsData[], RowData sortedArray[],
                  int numberOfIndexes);

#endif
