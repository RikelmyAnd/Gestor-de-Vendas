#include <stdio.h>
#include <string.h>

typedef struct {
    char produto[50];
    char categoria[30];
    int quantidade;
    double precoUnitario;
    char vendedor[30];
} Venda;