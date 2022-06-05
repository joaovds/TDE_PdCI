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

void menu() {
  setlocale(LC_ALL, "Portuguese");
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
      printf("salve\n");
      break;

    case 0:
      printf("Bye bye!!!\n");
      break;

    default:
      printf("Digite uma opção válida\n");
    }
  } while (showMenu);
}

void getColumnContentsInRow(char *rowContent, int *columns,
                            struct RowData *rowsData) {
  printf("Hello\n");
}
