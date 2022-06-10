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

void menu(RowData rowsData[], int numberOfIndexes)
{
  setlocale(LC_ALL, "Portuguese");
  static RowData sortedArray[540000], copyRowData[540000];
  int showMenu = 0;

  do
  {
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

    switch (showMenu)
    {
    case 1:
      sortCityName(rowsData, copyRowData, numberOfIndexes);
      int i;

      for (i = 0; i < 100; i++)
      {
        printf("Cidade: %s \n", copyRowData[i].cityName);
      }

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
                               RowData rowsData)
{
  int i = 0, j = columns[0];
  char *columnContent = strtok(strdup(rowContent), ";");

  do
  {
    switch (i)
    {
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

void sortCityName(RowData rowsData[], RowData copyRowData[],
                  int numberOfIndexes)
{
  copyRowData = rowsData;
  int i = 0, j, k, x;
  /*
    for (i = 1; i < 540000; i++)
    {
      x = copyRowData[i].cases;
      j = i - 1;
      while ((j >= 0) && (copyRowData[j].cases > x))
      {
        copyRowData[j + 1].cases = copyRowData[j].cases;
        j--;
      }
      copyRowData[j + 1].cases = x;
      printf("%i  %i\n", copyRowData[i].cases, i);
    }




  */
  RowData auxRowDataCopy, tranferirParaFrente;

  for (i = 1; i < 100; i++)
  {
    int indexDoOrdenando = i;
    RowData ordenando = copyRowData[indexDoOrdenando];

    for (j = 0; j < 100; j++)
    {
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
  }
  printf("Vetor ordenado.. \n");
}
