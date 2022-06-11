#ifndef MENU_H
#define MENU_H

typedef struct {
  char cityName[50];
  int cases, deaths, population;
  double caseXPolulationRatio;
} RowData;

void menu(RowData rowsData[], int numberOfIndexes);

RowData getColumnContentsInRow(char *rowContent, int *columns,
                               RowData rowsData);

int writeFileWithData(RowData data[], int numberOfIndexes);

void sortCasesPopulation(RowData *copyRowData);

void sortCityName(RowData *sortedArray);

#endif
