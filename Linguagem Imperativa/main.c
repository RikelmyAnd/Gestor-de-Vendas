#include <stdio.h> 
#include <string.h>
#include "vendas.h"

void filtrarRoupasImperativo(Venda vendas[], int tamanho);
double calcularFaturamentoImperativo(Venda vendas[], int tamanho);
void vendasAcimaDe200Imperativo(Venda vendas[], int tamanho);
void nomesProdutosImperativo(Venda vendas[], int tamanho);
void totalPorVendedorImperativo(Venda vendas[], int tamanho);
Venda maiorVendaImperativo(Venda vendas[], int tamanho);
void ordenarPorTotalImperativo(Venda vendas[], int tamanho);

int main() {

    Venda vendas [] = {
     {"Camiseta Infantil", "Roupas", 10, 29.90, "Ana"},
     {"Short Infantil", "Roupas", 5, 34.90, "Bruno"},
     {"Tênis Infantil", "Calçados", 3, 119.90, "Ana"},
     {"Sandália Infantil", "Calçados", 4, 79.90, "Carlos"},
     {"Boneca", "Brinquedos", 7, 49.90, "Bruno"},
     {"Carrinho", "Brinquedos", 6, 39.90, "Ana"},
     {"Mochila Escolar", "Acessórios", 2, 89.90, "Carlos"},
     {"Boné Infantil", "Acessórios", 8, 24.90, "Ana"},
     {"Vestido Infantil", "Roupas", 4, 69.90, "Bruno"},
     {"Chinelo Infantil", "Calçados", 9, 29.90, "Carlos"}
    };

        printf("Produtos da categoria Roupas:\n");
        filtrarRoupasImperativo(vendas, 10);
    
        printf("\nFaturamento total: R$%.2f\n", calcularFaturamentoImperativo(vendas, 10));
    
        printf("\nVendas acima de R$200:\n");
        vendasAcimaDe200Imperativo(vendas, 10);
    
        printf("\nNomes dos produtos vendidos:\n");
        nomesProdutosImperativo(vendas, 10);
    
        printf("\nTotal vendido por cada vendedor:\n");
        totalPorVendedorImperativo(vendas, 10);
    
        Venda maiorVenda = maiorVendaImperativo(vendas, 10);
        double totalMaiorVenda = maiorVenda.quantidade * maiorVenda.precoUnitario;
        printf("\nMaior venda: %s - Total: R$%.2f\n", maiorVenda.produto, totalMaiorVenda);
    
        printf("\nVendas ordenadas por total (menor para maior):\n");
        ordenarPorTotalImperativo(vendas, 10);
        for (int i = 0; i < 10; i++) {
            double totalVenda = vendas[i].quantidade * vendas[i].precoUnitario;
            printf("%s - Total: R$%.2f\n", vendas[i].produto, totalVenda);
        }


    return 0;
}

void filtrarRoupasImperativo(Venda vendas[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        if (strcmp(vendas[i].categoria, "Roupas") == 0) {
            printf("%s\n", vendas[i].produto);
        }
    }
}

double calcularFaturamentoImperativo(Venda vendas[], int tamanho) {
    double total = 0;
    for (int i = 0; i < tamanho; i++) {
        total += vendas[i].quantidade * vendas[i].precoUnitario;
    }
    return total;
}

void vendasAcimaDe200Imperativo(Venda vendas[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        double totalVenda = vendas[i].quantidade * vendas[i].precoUnitario;
        if (totalVenda > 200) {
            printf("%s - Total: R$%.2f\n", vendas[i].produto, totalVenda);
        }
    }
}

void nomesProdutosImperativo(Venda vendas[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%s\n", vendas[i].produto);
    }
}

void totalPorVendedorImperativo(Venda vendas[], int tamanho) {
    typedef struct {
        char vendedor[30];
        double total;
    } TotalVendedor;

    TotalVendedor totais[10]; // Supondo no máximo 10 vendedores
    int numVendedores = 0;

    for (int i = 0; i < tamanho; i++) {
        double totalVenda = vendas[i].quantidade * vendas[i].precoUnitario;
        int j;
        for (j = 0; j < numVendedores; j++) {
            if (strcmp(totais[j].vendedor, vendas[i].vendedor) == 0) {
                totais[j].total += totalVenda;
                break;
            }
        }
        if (j == numVendedores) { // Novo vendedor
            strcpy(totais[numVendedores].vendedor, vendas[i].vendedor);
            totais[numVendedores].total = totalVenda;
            numVendedores++;
        }
    }

    for (int i = 0; i < numVendedores; i++) {
        printf("%s: R$%.2f\n", totais[i].vendedor, totais[i].total);
    }
}

Venda maiorVendaImperativo(Venda vendas[], int tamanho) {
    Venda maior = vendas[0];
    for (int i = 1; i < tamanho; i++) {
        double totalVenda = vendas[i].quantidade * vendas[i].precoUnitario;
        double totalMaior = maior.quantidade * maior.precoUnitario;
        if (totalVenda > totalMaior) {
            maior = vendas[i];
        }
    }
    return maior;
}

void ordenarPorTotalImperativo(Venda vendas[], int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = 0; j < tamanho - i - 1; j++) {
            double totalVendaJ = vendas[j].quantidade * vendas[j].precoUnitario;
            double totalVendaJ1 = vendas[j + 1].quantidade * vendas[j + 1].precoUnitario;
            if (totalVendaJ < totalVendaJ1) {
                Venda temp = vendas[j];
                vendas[j] = vendas[j + 1];
                vendas[j + 1] = temp;
            }
        }
    }
}

