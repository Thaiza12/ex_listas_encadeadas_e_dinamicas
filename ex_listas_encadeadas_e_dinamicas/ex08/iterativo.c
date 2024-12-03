//Escreva uma função que faça uma busca em uma lista encadeada crescente. Faça versões recursiva e iterativa.

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

// Inserir um nó no final da lista
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

// Buscar um valor na lista (iterativo)
int buscar_iterativo(struct No* cabeca, int valor) {
    while (cabeca != NULL) {
        if (cabeca->dado == valor) {
            return 1; // Encontrado
        }
        cabeca = cabeca->proximo;
    }
    return 0; // Não encontrado
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
    int valor, buscar;

    printf("Digite 5 números para inserir na lista:\n");
    for (int i = 0; i < 5; i++) {
        printf("Número %d: ", i + 1);
        scanf("%d", &valor);
        inserir_no_final(&lista, valor);
    }

    imprimir_lista(lista);

    printf("Digite um número para buscar na lista (iterativo): ");
    scanf("%d", &buscar);

    if (buscar_iterativo(lista, buscar)) {
        printf("Número encontrado!\n");
    } else {
        printf("Número não encontrado.\n");
    }

    return 0;
}

