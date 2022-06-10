#include "functions.h"
#include <locale.h>
#include <stdio.h>
#include <string.h>

#ifdef __unix__
#include <stdlib.h>
#include <unistd.h>

#elif defined(_WIN32) || defined(WIN32)
#define OS_Windows
#include <windows.h>
#endif

void menu(RowData rowsData[], int numberOfIndexes) {
  setlocale(LC_ALL, "Portuguese");
  static RowData sortedArray[540000], copyRowData[540000];
  int showMenu = 0;

  do {
    printf("|-----------------------------------------------------|\n");
    printf("|                         Menu                        |\n");
    printf("|-----------------------------------------------------|\n");
    printf("| 1. Pesquisa por nome de Município                   |\n");
    printf("|-----------------------------------------------------|\n");
    printf("| 2. Pesquisa por óbitos decrescente e nome município |\n");
    printf("|-----------------------------------------------------|\n");
    printf("| 3. Munícipio com maior proporção de Casos/População |\n");
    printf("|-----------------------------------------------------|\n");
    printf("| 0. Sair                                             |\n");
    printf("|-----------------------------------------------------|\n");

    scanf("%d", &showMenu);

#ifdef OS_Windows
    system("cls");
#else
    system("clear");
#endif

    switch (showMenu) {
    case 1:
      memcpy(copyRowData, rowsData, sizeof(sortedArray));

      sortCityName(copyRowData, numberOfIndexes);

      int i;
      for (i = 0; i < 10000; i++) {
        printf("%s  %i\n", copyRowData[i].cityName, copyRowData[i].cases);
      }

      writeFileWithData(copyRowData, numberOfIndexes);
      break;

    case 0:
      printf("Bye bye!!!\n");
      break;

    default:
      printf("Digite uma opção válida\n");
    }
  } while (showMenu);
}

RowData getColumnContentsInRow(char *rowContent, int *columns,
                               RowData rowsData) {
  int i = 0, j = columns[0];
  char *columnContent = strtok(strdup(rowContent), ";");

  do {
    switch (i) {
    case 0:
      strcpy(rowsData.cityName, columnContent);
      break;
    case 1:
      rowsData.cases = atoi(columnContent);
      break;
    case 2:
      rowsData.deaths = atoi(columnContent);
      break;
    case 3:
      rowsData.population = atoi(columnContent);
      break;
    }

    if ((rowsData.cases != 0) && (rowsData.population != 0))
      rowsData.caseXPolulationRatio =
          (float)rowsData.cases / rowsData.population;
    else
      rowsData.caseXPolulationRatio = 0;

    columnContent = strtok(NULL, ";");

    i++;
    j = columns[i];
  } while (i < sizeof(columns));

  return rowsData;
}

int writeFileWithData(RowData data[], int numberOfIndexes) {
  FILE *output;
  char row[200], buffer[sizeof(int) * 8 + 1];
  ;
  int i;

  output = fopen("output.csv", "w+");

  if (output == NULL) {
    printf("Erro ao tentar abrir o arquivo de saida !\n");
    return 1;
  }

  for (i = 0; i < numberOfIndexes; i++) {
    strcpy(row, data[i].cityName);
    strcat(row, ",");
    sprintf(buffer, "%i", data[numberOfIndexes].cases);
    // strcat(row, data[i].cases);
    strcat(row, "\n");

    printf("nome %s \n", row);

    fputs(row, output);
  }

  fclose(output);

  return 0;
}

void sortCityName(RowData *copyRowData, int numberOfIndexes) {
  int i = 0, j, k;

  for (i = 1; i < 10000; i++) {
    RowData x = copyRowData[i];
    j = i - 1;

    while ((j >= 0) && (strcmp(copyRowData[j].cityName, x.cityName) > 0)) {
      copyRowData[j + 1] = copyRowData[j];
      j--;
    }
    copyRowData[j + 1] = x;
  }

  /*
    RowData auxRowDataCopy, tranferirParaFrente;

    for (i = 1; i < 100; i++)
    {
      int indexDoOrdenando = i;
      RowData ordenando = copyRowData[indexDoOrdenando];

      for (j = 0; j < 100; j++)
      {
        printf("%s - %s", );
        if (strcmp(copyRowData[j].cityName, ordenando.cityName) > 0)
        {
          auxRowDataCopy = copyRowData[j];

          for (k = (numberOfIndexes - 1); k >= 0; k--)
          {
            if ((k >= j) && (k < indexDoOrdenando))
            {
              copyRowData[k + 1] = copyRowData[k];
            }
          }

          copyRowData[j] = ordenando;
          break;
        }
      }
      // printf("%s \n",copyRowData[i].cityName);
    }
    */
  printf("Vetor ordenado.. \n");
}
