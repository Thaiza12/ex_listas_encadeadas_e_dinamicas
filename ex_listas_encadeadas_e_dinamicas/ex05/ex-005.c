//Listas Encadeadas Dinâmicas
//Usando listas dinâmicas, crie um programa que guarde strings. Re-implemente todas as funcionalidades para que seja possível usar as funções básicas de inserção, remoção, busca e detecção de fim de lista;
//Implemente também a função que retorna o tamanho da lista (quantidade de elementos), e a perda de memória (total da lista - quantidade de itens vazios)


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição de um nó da lista
struct No {
    char dado[80];
    struct No* proximo;
};

// Função para criar um novo nó
struct No* criar_no(const char* str) {
    struct No* novo_no = (struct No*)malloc(sizeof(struct No)); // Cria um nó
    if (novo_no == NULL) {
        printf("Erro de alocação de memória\n");
        return NULL;
    }
    strcpy(novo_no->dado, str); // Copia a string para o nó
    novo_no->proximo = NULL; // Aponta para NULL porque é o último nó por enquanto
    return novo_no;
}

// Função para inserir na lista
void inserir(struct No** cabeca, const char* str) {
    struct No* novo_no = criar_no(str); // Cria o novo nó
    if (*cabeca == NULL) {
        *cabeca = novo_no; // Se a lista estiver vazia, o novo nó será a cabeça
    } else {
        struct No* temp = *cabeca;
        while (temp->proximo != NULL) { // Vai até o último nó
            temp = temp->proximo;
        }
        temp->proximo = novo_no; // Insere no final da lista
    }
}

// Função para imprimir a lista
void imprimir_lista(struct No* cabeca) {
    struct No* temp = cabeca;
    while (temp != NULL) {
        printf("%s -> ", temp->dado); // Imprime o dado do nó
        temp = temp->proximo; // Vai para o próximo nó
    }
    printf("NULL\n");
}

// Função para remover o primeiro nó
void remover_primeiro(struct No** cabeca) {
    if (*cabeca == NULL) {
        printf("Lista vazia\n");
        return;
    }
    struct No* temp = *cabeca;
    *cabeca = temp->proximo; // A cabeça agora é o próximo nó
    free(temp); // Libera a memória do nó removido
}

// Função para buscar por uma string na lista
int buscar(struct No* cabeca, const char* str) {
    struct No* temp = cabeca;
    while (temp != NULL) {
        if (strcmp(temp->dado, str) == 0) {
            return 1; // Encontrado
        }
        temp = temp->proximo; // Vai para o próximo nó
    }
    return 0; // Não encontrado
}

int main() {
    struct No* cabeca = NULL;

    // Inserir alguns produtos
    inserir(&cabeca, "Banana");
    inserir(&cabeca, "Maçã");
    inserir(&cabeca, "Laranja");

    // Imprimir lista
    printf("Lista de produtos: ");
    imprimir_lista(cabeca);

    // Buscar por um produto
    if (buscar(cabeca, "Maçã")) {
        printf("Produto 'Maçã' encontrado!\n");
    } else {
        printf("Produto 'Maçã' não encontrado.\n");
    }

    // Remover o primeiro produto
    remover_primeiro(&cabeca);
    printf("Lista após remoção do primeiro produto: ");
    imprimir_lista(cabeca);

    // Finalizar a lista
    while (cabeca != NULL) {
        remover_primeiro(&cabeca); // Remover todos os itens
    }

    return 0;
}
