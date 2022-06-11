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
  int i;
  do
  {
    printf("|-----------------------------------------------------|\n");
    printf("|                         Menu                        |\n");
    printf("|-----------------------------------------------------|\n");
    printf("| 1. Pesquisa por nome de Município                   |\n");
    printf("|-----------------------------------------------------|\n");
    printf("| 2. Munícipio com maior proporção de Casos/População |\n");
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
      memcpy(copyRowData, rowsData, sizeof(sortedArray));

      sortCityName(copyRowData);

      for (i = 0; i < 100; i++)
      {
        printf("%s %i %i %i %lf\n", copyRowData[i].cityName, copyRowData[i].cases, copyRowData[i].deaths, copyRowData[i].population, copyRowData[i].caseXPolulationRatio);
      }
      printf("Deseja salvar o arquivo ? (1 = sim) (0 = nao)\n");
      scanf("%d", &showMenu);

      if (showMenu == 1)
      {
        printf("salvando\n");
        writeFileWithData(copyRowData, numberOfIndexes);
      }

      break;

    case 2:
      memcpy(copyRowData, rowsData, sizeof(sortedArray));

      sortCasesPopulation(copyRowData);

      for (i = 0; i < 100; i++)
      {
        printf("%s %i %i %i %lf\n", copyRowData[i].cityName, copyRowData[i].cases, copyRowData[i].deaths, copyRowData[i].population, copyRowData[i].caseXPolulationRatio);
      }

      printf("Deseja salvar o arquivo ? (1 = sim) (0 = nao)\n");
      scanf("%d", &showMenu);

      if (showMenu == 1)
      {
        printf("salvando\n");
        writeFileWithData(copyRowData, numberOfIndexes);
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
//Insere colunas na struct
RowData getColumnContentsInRow(char *rowContent, int *columns,
                               RowData rowsData)
{
  int i = 0, j = columns[0];
  char *columnContent = strtok(strdup(rowContent), ";");

  strcpy(rowsData.cityName, columnContent);
  strtok(NULL, ";");
  strtok(NULL, ";");
  columnContent = strtok(NULL, ";");

  rowsData.cases = atoi(columnContent);
  strtok(NULL, ";");
  strtok(NULL, ";");
  strtok(NULL, ";");
  columnContent = strtok(NULL, ";");
  rowsData.deaths = atoi(columnContent);

  strtok(NULL, ";");
  strtok(NULL, ";");
  strtok(NULL, ";");
  strtok(NULL, ";");
  strtok(NULL, ";");
  strtok(NULL, ";");
  strtok(NULL, ";");
  strtok(NULL, ";");
  columnContent = strtok(NULL, ";");
  rowsData.population = atoi(columnContent);

  if ((rowsData.cases != 0) && (rowsData.population != 0))
    rowsData.caseXPolulationRatio = (float)rowsData.cases / rowsData.population;
  else
    rowsData.caseXPolulationRatio = 0;

  i++;
  j = columns[i];

  return rowsData;
}
//salva arquivo 
int writeFileWithData(RowData data[], int numberOfIndexes)
{
  FILE *output;
  char row[200], buffer[sizeof(int) * 8 + 1];
  ;
  int i;

  output = fopen("output.csv", "w+");

  if (output == NULL)
  {
    printf("Erro ao tentar abrir o arquivo de saida !\n");
    return 1;
  }

  for (i = 0; i < numberOfIndexes; i++)
  {
    fprintf (output, "%s;%i;%i;%i;%lf\n", data[i].cityName,data[i].cases,data[i].deaths,data[i].population,data[i].caseXPolulationRatio);
    /*
    strcpy(row, data[i].cityName);
    strcat(row, ",");
    strcat(row, itoa(data[i].cases));
    strcat(row, ",");
    strcat(row, itoa(data[i].deaths));
    strcat(row, ",");
    strcat(row, itoa(data[i].population));
    strcat(row, ",");
    strcat(row, itoa(data[i].caseXPolulationRatio));
    strcat(row, "\n");
    fputs(row, output);
    */
  }

  fclose(output);

  return 0;
}
//ordena por nome e casos
void sortCityName(RowData *copyRowData)
{
  int i = 0, j, k;

  for (i = 1; i < 520031; i++)
  {
    RowData x = copyRowData[i];
    j = i - 1;

    while ((j >= 0) && (strcmp(copyRowData[j].cityName, x.cityName) > 0))
    {
      copyRowData[j + 1] = copyRowData[j];
      j--;
    }
    copyRowData[j + 1] = x;
  }
}
//ordena por casos/população
void sortCasesPopulation(RowData *copyRowData)
{

  int i = 0, j, k;

  for (i = 1; i < 520031; i++)
  {
    RowData x = copyRowData[i];
    j = i - 1;

    while ((j >= 0) && (copyRowData[j].caseXPolulationRatio < x.caseXPolulationRatio))
    {
      copyRowData[j + 1] = copyRowData[j];
      j--;
    }
    copyRowData[j + 1] = x;
  }
}
