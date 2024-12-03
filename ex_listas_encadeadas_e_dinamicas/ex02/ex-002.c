//Utilize uma lista estática como a que implementamos em sala de aula, com 50 slots;
//Crie uma nova função de inserção de dados na lista de inteiros, garantindo que o novo elemento 
//x seja inserido antes do valor maior que ele e depois do valor menor que ele, para que a lista 
//sempre fique em ordem crescente;
//Crie uma outra função que garanta a inserção de números em ordem decrescente. Inspire-se na letra
// anterior;


#include <stdio.h>
#define TAM 10

typedef struct {
    int elementos[TAM];
    int tamanho;
} Lista;

// Função para inicializar a lista
void inicializar_lista(Lista *lista) {
    lista->tamanho = 0;
}

// Função para exibir a lista
void exibir_lista(Lista *lista) {
    for (int i = 0; i < lista->tamanho; i++) {
        printf("%d ", lista->elementos[i]);
    }
    printf("\n");
}

// Função para inserir em ordem crescente
int inserir_ordenado_crescente(Lista *lista, int x) {
    if (lista->tamanho == TAM) {
        printf("Erro: lista cheia.\n");
        return 0;
    }

    int posicao = 0;
    while (posicao < lista->tamanho && lista->elementos[posicao] < x) {
        posicao++;
    }

    for (int i = lista->tamanho; i > posicao; i--) {
        lista->elementos[i] = lista->elementos[i - 1];
    }

    lista->elementos[posicao] = x;
    lista->tamanho++;

    return 1;
}

// Função para inserir em ordem decrescente
int inserir_ordenado_decrescente(Lista *lista, int x) {
    if (lista->tamanho == TAM) {
        printf("Erro: lista cheia.\n");
        return 0;
    }

    int posicao = 0;
    while (posicao < lista->tamanho && lista->elementos[posicao] > x) {
        posicao++;
    }

    for (int i = lista->tamanho; i > posicao; i--) {
        lista->elementos[i] = lista->elementos[i - 1];
    }

    lista->elementos[posicao] = x;
    lista->tamanho++;

    return 1;
}

// Programa principal
int main() {
    Lista lista;
    int opcao, numero;

    inicializar_lista(&lista);

    printf("Bem-vindo ao gerenciador de lista ordenada!\n");
    printf("Escolha o tipo de ordenação:\n");
    printf("1 - Crescente\n");
    printf("2 - Decrescente\n");
    printf("Opção: ");
    scanf("%d", &opcao);

    if (opcao != 1 && opcao != 2) {
        printf("Opção inválida! Encerrando o programa.\n");
        return 0;
    }

    printf("Digite números para inserir na lista (digite -1 para parar):\n");

    while (1) {
        printf("Número: ");
        scanf("%d", &numero);

        if (numero == -1) {
            break;
        }

        if (opcao == 1) {
            inserir_ordenado_crescente(&lista, numero);
        } else {
            inserir_ordenado_decrescente(&lista, numero);
        }
    }

    printf("\nLista resultante:\n");
    exibir_lista(&lista);

    return 0;
}
