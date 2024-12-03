//Fazer um programa em C que lê uma lista de 20 produtos e de preços e armazena-os em um array 
//do tipo da estrutura abaixo. O programa deve, em seguida, ordenar o vetor em ordem alfabética 
//de nome de produto e inflacionar os produtos cujo valor for menor que 100 em 5%. Por fim, a lista 
//de produtos/preços deve ser impressa.

#include <stdio.h>
#include <string.h>

#define TAM 2

typedef struct {
    char nome[80];
    float preco;
} PROD;

// Função para ler os dados de um produto
void ler_produto(PROD *produto) {
    printf("Digite o nome do produto: ");
    getchar(); // Limpa o buffer
    fgets(produto->nome, 80, stdin);
    produto->nome[strcspn(produto->nome, "\n")] = '\0'; // Remove o '\n'
    printf("Digite o preço do produto: ");
    scanf("%f", &produto->preco);
}

// Função para inflacionar os preços menores que 100
void inflacionar_preco(PROD *produto) {
    if (produto->preco < 100.0) {
        produto->preco *= 1.05; // Acrescenta 5%
    }
}

// Função para imprimir os dados de um produto
void imprimir_produto(PROD produto) {
    printf("Produto: %-20s | Preço: R$ %.2f\n", produto.nome, produto.preco);
}

// Função para ordenar o vetor de produtos em ordem alfabética
void ordenar_produtos(PROD produtos[], int n) {
    PROD temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(produtos[i].nome, produtos[j].nome) > 0) {
                temp = produtos[i];
                produtos[i] = produtos[j];
                produtos[j] = temp;
            }
        }
    }
}

// Programa principal
int main() {
    PROD produtos[TAM];
    int n = TAM;

    // Ler os produtos
    printf("Digite os dados de %d produtos:\n", n);
    for (int i = 0; i < n; i++) {
        printf("\nProduto %d:\n", i + 1);
        ler_produto(&produtos[i]);
    }

    // Inflacionar preços menores que 100
    for (int i = 0; i < n; i++) {
        inflacionar_preco(&produtos[i]);
    }

    // Ordenar os produtos em ordem alfabética
    ordenar_produtos(produtos, n);

    // Imprimir a lista de produtos
    printf("\nLista de produtos ordenada e com preços atualizados:\n");
    for (int i = 0; i < n; i++) {
        imprimir_produto(produtos[i]);
    }

    return 0;
}
