#include <stdio.h>
#include <stdlib.h>

// Definição do nó da lista encadeada
struct No {
    int dado;
    struct No* proximo;
};

// Função para criar um novo nó
struct No* criar_no(int valor) {
    struct No* novo = (struct No*)malloc(sizeof(struct No));
    novo->dado = valor;
    novo->proximo = NULL;
    return novo;
}

// Função para inserir um valor na lista
void inserir_no_final(struct No** cabeca, int valor) {
    struct No* novo = criar_no(valor);
    if (*cabeca == NULL) {
        *cabeca = novo;
    } else {
        struct No* temp = *cabeca;
        while (temp->proximo != NULL) {
            temp = temp->proximo;
        }
        temp->proximo = novo;
    }
}

// Função para encontrar o ponto médio da lista (versão simples)
struct No* ponto_medio(struct No* cabeca) {
    struct No* temp = cabeca;
    int tamanho = 0;

    // Conta o número total de elementos
    while (temp != NULL) {
        tamanho++;
        temp = temp->proximo;
    }

    // Encontra o meio
    temp = cabeca;
    for (int i = 0; i < tamanho / 2; i++) {
        temp = temp->proximo;
    }

    return temp;
}

// Função para imprimir a lista
void imprimir_lista(struct No* cabeca) {
    while (cabeca != NULL) {
        printf("%d -> ", cabeca->dado);
        cabeca = cabeca->proximo;
    }
    printf("NULL\n");
}

int main() {
    struct No* lista = NULL;
    int n, valor;

    // Solicitar ao usuário a quantidade de elementos na lista
    printf("Digite o número de elementos na lista: ");
    scanf("%d", &n);

    // Solicitar ao usuário para digitar os valores da lista
    for (int i = 0; i < n; i++) {
        printf("Digite o valor do %dº elemento: ", i + 1);
        scanf("%d", &valor);
        inserir_no_final(&lista, valor);
    }

    // Imprimir a lista
    printf("Lista: ");
    imprimir_lista(lista);

    // Encontrar o ponto médio
    struct No* meio = ponto_medio(lista);
    if (meio != NULL) {
        printf("O ponto médio da lista é: %d\n", meio->dado);
    } else {
        printf("A lista está vazia.\n");
    }

    return 0;
}
