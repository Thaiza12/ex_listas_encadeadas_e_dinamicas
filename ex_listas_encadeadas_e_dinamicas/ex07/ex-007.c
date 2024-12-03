// Escreva uma função que verifique se uma lista encadeada que contém números inteiros está em ordem crescente.

#include <stdio.h>
#include <stdlib.h>

// Definindo a estrutura de um nó da lista
struct No {
    int dado;
    struct No* proximo;
};

// Função para criar um novo nó
struct No* criar_no(int valor) {
    struct No* novo_no = (struct No*)malloc(sizeof(struct No));
    novo_no->dado = valor;
    novo_no->proximo = NULL;
    return novo_no;
}

// Função para inserir um número no final da lista
void inserir(struct No** cabeca, int valor) {
    struct No* novo_no = criar_no(valor);
    if (*cabeca == NULL) {
        *cabeca = novo_no;
    } else {
        struct No* temp = *cabeca;
        while (temp->proximo != NULL) {
            temp = temp->proximo;
        }
        temp->proximo = novo_no;
    }
}

// Função para verificar se a lista está em ordem crescente
int verificar_ordem_crescente(struct No* cabeca) {
    struct No* temp = cabeca;
    while (temp != NULL && temp->proximo != NULL) {
        if (temp->dado > temp->proximo->dado) {
            return 0; // Lista não está em ordem crescente
        }
        temp = temp->proximo;
    }
    return 1; // Lista está em ordem crescente
}

// Função para imprimir a lista
void imprimir_lista(struct No* cabeca) {
    struct No* temp = cabeca;
    while (temp != NULL) {
        printf("%d -> ", temp->dado);
        temp = temp->proximo;
    }
    printf("NULL\n");
}

int main() {
    struct No* lista = NULL;
    int n, valor;

    // Solicitar ao usuário os 5 números da lista
    printf("Digite 5 números na lista? ");
    scanf("%d", &n);

    // Inserir os valores na lista
    for (int i = 0; i < 5; i++) {
        printf("Digite o valor %d: ", i + 1);
        scanf("%d", &valor);
        inserir(&lista, valor);
    }

    // Imprimir a lista
    printf("Lista inserida: ");
    imprimir_lista(lista);

    // Verificar se a lista está em ordem crescente
    if (verificar_ordem_crescente(lista)) {
        printf("A lista está em ordem crescente.\n");
    } else {
        printf("A lista não está em ordem crescente.\n");
    }

    return 0;
}
