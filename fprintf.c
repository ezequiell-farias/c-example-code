/*******************************************************************************
*
* Programa: Demonstração da função fprintf()
*
* Descrição: Exemplo de como usar a função fprintf() em C para escrever em arquivos.
*
* Autor: Kevin Browne @ https://portfoliocourses.com
* Adaptado por: Ezequiel Farias
*
*******************************************************************************/
#include <stdio.h>

int main(void)
{
    // Declara um ponteiro para FILE para manipular o arquivo
    FILE *file;

    // Tenta abrir o arquivo "file.txt" em modo de escrita ("w")
    file = fopen("file.txt", "w");

    // Verifica se o arquivo foi aberto com sucesso
    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return 1; // Retorna erro
    }

    // Escreve uma nova linha no arquivo
    fprintf(file, "\n");

    // Escreve uma tabulação seguida de texto
    fprintf(file, "\t ABC \n");

    // Exemplo com inteiro
    int i = 5;
    fprintf(file, "%d\n", i);

    // Exemplo com caractere
    char c = 'd';
    fprintf(file, "%c\n", c);

    // Exemplo com float
    float f = 2.125;
    fprintf(file, "%f\n", f);

    // Exemplo com double
    double d = 9.82;
    fprintf(file, "%f\n", d);

    // Exemplo com string
    char string[] = "abc";
    fprintf(file, "%s\n", string);

    // Vários fprintf na mesma linha
    fprintf(file, "%d ", 1);
    fprintf(file, "%d ", 2);
    fprintf(file, "%d\n", 3);

    // Número em campo de largura 4 (alinhado à direita)
    fprintf(file, "%4d\n", 22);

    // Número alinhado à esquerda
    fprintf(file, "%-4d<-end\n", 22);

    // Número preenchido com zeros
    fprintf(file, "%04d\n", 22);

    // Somente números negativos têm sinal
    fprintf(file, "%d %d\n", 1, -1);

    // Força exibição do sinal (+ ou -)
    fprintf(file, "%+d %+d\n", 1, -1);

    // Mais casas decimais do que o necessário
    fprintf(file, "%f\n", 1.2345);

    // Limita a duas casas decimais
    fprintf(file, "%.2f\n", 1.2345);

    // Usa um argumento para controlar precisão
    fprintf(file, "%.*f\n", 1, 1.2345);

    // Usando variável para definir precisão
    int digits = 3;
    fprintf(file, "%.*f\n", digits, 1.2345);

    // Em notação científica
    fprintf(file, "%e\n", 2.4123);

    // Endereço de memória
    fprintf(file, "%ls\n", &digits);

    // Número unsigned long
    unsigned long ul = 123456789012345;
    fprintf(file, "%lu\n", ul);

    // Array de resultados
    float results[] = {1.1, 1.2, 1.3, 1.4, 1.5};

    // Grava os valores do array formatados
    for (int j = 0; j < 5; j++)
        fprintf(file, "%07.2f\n", results[j]);

    // Matriz 3x3 de dados
    double data[3][3] = {
        {1.1, 1.2, 1.3},
        {2.1, 2.2, 2.3},
        {3.1, 3.2, 3.3}
    };

    // Grava matriz linha por linha
    for (int i = 0; i < 3; i++)
    {
        fprintf(file,
                "%.1f %.1f %.1f\n",
                data[i][0],
                data[i][1],
                data[i][2]);
    }

    // Linha em branco
    fprintf(file, "\n");

    // Cabeçalho de tabela formatado
    fprintf(file, "%-5s%-5s%-5s\n", "D1", "D2", "D3");

    // Separador com asteriscos
    for (int i = 0; i < 15; i++)
        fprintf(file, "*");
    fprintf(file, "\n");

    // Tabela formatada com loop aninhado
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            fprintf(file, "%-5.1f", data[i][j]);
        fprintf(file, "\n");
    }

    // Linha em branco
    fprintf(file, "\n");

    // Como imprimir barra invertida e aspas
    fprintf(file, " \\ \n");
    fprintf(file, " \" \n");

    // Imprime no terminal
    fprintf(stdout, "test\n");

    // Mostra quantidade de caracteres escritos
    int result = fprintf(file, "abc");
    printf("Resultado: %d\n", result);

    // Fecha o arquivo
    fclose(file);

    return 0;
}
