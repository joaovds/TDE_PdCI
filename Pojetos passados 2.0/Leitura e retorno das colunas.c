#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct Linha
{
    char nome[45];
    int casos, obitos, pop;
};
// Recebe um char com os numeros das colunas desejadas separadas por espaço
int *set_colunas(char *);
/*recebe os parametros na ordem:
  linha com todas as colunas
  um vetor com as colunas desejadas
  struct com os dados em ordem pelo tipo de dados desejado no parametro anterior
*/
void atribuir_colunas(char *, int *, struct Linha *);
int main()
{
    // cria a struct para receber os dados da linha
    static struct Linha linha[540000];
    // abre o arquivo
    FILE *p;
    if ((p = fopen("municipios.csv", "r")) == NULL)
    {
        printf("Erro ao abrir o arquivo");
        return 1;
    };
    // variavel que recebe linha por linha
    char ch[180];
    // vai retornar um vetor com as colunas desejadas
    int *colunas = set_colunas("1 4 8 17");
    // Le arquivo até o final
    int i = 0;
    while (!feof(p))
    {
        printf("%i ", i);
        // capetura linha por linha
        fgets(ch, 176, p);
        // atribui os valores das colunas setadas no struct
        atribuir_colunas(ch, colunas, linha);
        printf("%s %i %i %i\n", linha->nome, linha->casos, linha->obitos, linha->pop);
        i++;

    }
    system("pause");
    return 0;
}

int *set_colunas(char *colunas)
{
    int i = 0;
    int *coluna = malloc(sizeof(int *) * 4);
    char *token = strtok(strdup(colunas), " ");
    while (i < strlen(colunas) / 2)
    {
        coluna[i] = atoi(token);
        token = strtok(NULL, " ");
        i++;
    }
    return coluna;
}
void atribuir_colunas(char *linha, int *colunas_vet, struct Linha *linhas)
{
    int i = 0, j = colunas_vet[0], h = 0;
    char *nova_linha;
    char *valor_coluna = strtok(strdup(linha), ";");
    do
    {
        for (; j < colunas_vet[i]; j++)
        {
            valor_coluna = strtok(NULL, ";");
        }
        switch (i)
        {
        case 0:
            strcpy(linhas->nome, valor_coluna);
            break;
        case 1:
            linhas->casos = atoi(valor_coluna);
            break;
        case 2:
            linhas->obitos = atoi(valor_coluna);
            break;
        case 3:
            linhas->pop = atoi(valor_coluna);
            break;
        }
        i++;
        j = colunas_vet[i - 1];
    } while (i < sizeof(colunas_vet));
}