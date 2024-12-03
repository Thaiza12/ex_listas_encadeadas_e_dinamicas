#include <stdio.h>
#include <stdlib.h>

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

// Inserir nó no final da lista
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

// Encontrar valor mínimo (iterativo)
int encontrar_min_iterativo(struct No* cabeca) {
    if (cabeca == NULL) {
        printf("A lista está vazia.\n");
        return -1;
    }
    int min = cabeca->dado;
    struct No* temp = cabeca->proximo;
    while (temp != NULL) {
        if (temp->dado < min) {
            min = temp->dado;
        }
        temp = temp->proximo;
    }
    return min;
}

// Função para imprimir a lista
void imprimir_lista(struct No* cabeca) {
    printf("Lista: ");
    while (cabeca != NULL) {
        printf("%d -> ", cabeca->dado);
        cabeca = cabeca->proximo;
    }
    printf("NULL\n");
}

int main() {
    struct No* lista = NULL;
    int valor;

    printf("Digite 5 números para inserir na lista:\n");
    for (int i = 0; i < 5; i++) {
        printf("Número %d: ", i + 1);
        scanf("%d", &valor);
        inserir_no_final(&lista, valor);
    }

    imprimir_lista(lista);

    int minimo = encontrar_min_iterativo(lista);
    printf("O menor valor na lista (iterativo) é: %d\n", minimo);

    return 0;
}
