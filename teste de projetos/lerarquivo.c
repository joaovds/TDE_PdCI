#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Linha
{

    char nome[45];
    int casos, obitos, pop, linha;
};
void proxima_linha(char *, FILE *);
void pula_linha(char *, FILE *, int);
void eliminar_coluna(char *, char *);
int main()
{
    register FILE *p, *arquivo1, *arquivo2, *arquivo3, *arquivo4, *arquivo5, *arquivo6, *arquivo7, *arquivo8;

    int i;

    struct Linha linha_atual, dados_arquivo1[8], dados_arquivo2[8], dados_arquivo3[8], dados_arquivo4[8], dados_arquivo5[8], dados_arquivo6[8], dados_arquivo7[8], dados_arquivo8[8];
    if ((p = fopen("municipios.csv", "r")) == NULL)
    {
        printf("Erro ao abrir o arquivo");
        return 1;
    };

    if ((arquivo1 = fopen("arquivos temporarios/arquivo1.csv", "wb")) == NULL)
    {
        printf("Erro ao abrir o arquivo");
        return 1;
    };
    if ((arquivo2 = fopen("arquivos temporarios/arquivo2.csv", "wb")) == NULL)
    {
        printf("Erro ao abrir o arquivo");
        return 1;
    };
    if ((arquivo3 = fopen("arquivos temporarios/arquivo3.csv", "wb")) == NULL)
    {
        printf("Erro ao abrir o arquivo");
        return 1;
    };
    if ((arquivo4 = fopen("arquivos temporarios/arquivo4.csv", "wb")) == NULL)
    {
        printf("Erro ao abrir o arquivo");
        return 1;
    };
    if ((arquivo5 = fopen("arquivos temporarios/arquivo5.csv", "wb")) == NULL)
    {
        printf("Erro ao abrir o arquivo");
        return 1;
    };
    if ((arquivo6 = fopen("arquivos temporarios/arquivo6.csv", "wb")) == NULL)
    {
        printf("Erro ao abrir o arquivo");
        return 1;
    };
    if ((arquivo7 = fopen("arquivos temporarios/arquivo7.csv", "wb")) == NULL)
    {
        printf("Erro ao abrir o arquivo");
        return 1;
    };
    if ((arquivo8 = fopen("arquivos temporarios/arquivo8.csv", "wb")) == NULL)
    {
        printf("Erro ao abrir o arquivo");
        return 1;
    };

    char ch[180];
    proxima_linha(ch, p);
    printf("%s", ch);
    /*
        for (i = 0; i < 100; i++)
        {
            proxima_linha(ch, p);
            printf("%s %i\n", ch, i);
        }
    while (!feof(p))
    {
    }
    */

    return 0;
}
void proxima_linha(char *linha, FILE *arquivo)
{
    fgets(linha, 175, arquivo);
    eliminar_coluna(linha, "1;4;8;17\n");
};
void pula_linha(char *linha, FILE *arquivo, int qtr_lin)
{
    int i;
    for (i = 0; i < qtr_lin; i++)
    {
        fgets(linha, 175, arquivo);
    }
};

void eliminar_coluna(char *linha, char *colunas)
{

    int i = 0;
    char ch[100];

    int coluna[strlen(colunas)];
    printf("%s\n", colunas);
  

    char *token = strtok(colunas, " ");

        while (*token != NULL)
        {
            printf("%s\n", token);
            token = strtok(NULL, " ");
        }
}
