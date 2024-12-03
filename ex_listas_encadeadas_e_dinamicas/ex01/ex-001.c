//Dada uma lista sequencial ordenada estática L1, escreva métodos em C que:
//Verifique se L1 está ordenada ou não (a ordem pode ser crescente ou decrescente)
//Faça uma cópia da lista L1 em uma outra lista L2;
//Faça uma cópia da Lista L1 em L2, eliminando elementos repetidos;
//Inverta L1 colocando o resultado em L2;
//Inverta L1 colocando o resultado na própria L1;
//Intercale L1 com a lista L2, gerando a lista L3. considere que L1, L2 e L3 são ordenadas.
//Gere uma lista L2 onde cada registro contém dois campos de informação: elem contém um elemento de L1, e count contém quantas vezes este elemento aparece em L1.
//Elimine de L1 todas as ocorrências de um elemento dado, L1 ordenada.
//Assumindo que os elementos da lista L1 são inteiros positivos, forneça os elementos que aparecem o maior e o menor número de vezes (forneça os elementos e o número de vezes correspondente)

#include <stdio.h>
#define TAM_MAX 100 // Tamanho máximo das listas

// Função para verificar se a lista está ordenada
int esta_ordenada(int L1[], int tamanho) {
    int i, crescente = 1, decrescente = 1;
    for (i = 1; i < tamanho; i++) {
        if (L1[i] < L1[i - 1]) crescente = 0;
        if (L1[i] > L1[i - 1]) decrescente = 0;
    }
    return crescente || decrescente;
}

// Função para copiar L1 em L2
void copiar_lista(int L1[], int tamanho, int L2[], int *tamanho2) {
    int i;
    *tamanho2 = tamanho;
    for (i = 0; i < tamanho; i++) {
        L2[i] = L1[i];
    }
}

// Função para copiar L1 em L2 eliminando repetidos
void copiar_unicos(int L1[], int tamanho, int L2[], int *tamanho2) {
    int i, j, repetido;
    *tamanho2 = 0;
    for (i = 0; i < tamanho; i++) {
        repetido = 0;
        for (j = 0; j < *tamanho2; j++) {
            if (L1[i] == L2[j]) {
                repetido = 1;
                break;
            }
        }
        if (!repetido) {
            L2[*tamanho2] = L1[i];
            (*tamanho2)++;
        }
    }
}

// Função para inverter L1 em L2
void inverter_lista(int L1[], int tamanho, int L2[], int *tamanho2) {
    int i;
    *tamanho2 = tamanho;
    for (i = 0; i < tamanho; i++) {
        L2[i] = L1[tamanho - i - 1];
    }
}

// Função para inverter L1 na própria lista
void inverter_em_L1(int L1[], int tamanho) {
    int i, temp;
    for (i = 0; i < tamanho / 2; i++) {
        temp = L1[i];
        L1[i] = L1[tamanho - i - 1];
        L1[tamanho - i - 1] = temp;
    }
}

// Função para intercalar L1 e L2 em L3
void intercalar_listas(int L1[], int tam1, int L2[], int tam2, int L3[], int *tam3) {
    int i = 0, j = 0, k = 0;
    while (i < tam1 && j < tam2) {
        if (L1[i] <= L2[j]) {
            L3[k] = L1[i];
            i++;
        } else {
            L3[k] = L2[j];
            j++;
        }
        k++;
    }
    while (i < tam1) {
        L3[k] = L1[i];
        i++;
        k++;
    }
    while (j < tam2) {
        L3[k] = L2[j];
        j++;
        k++;
    }
    *tam3 = k;
}

// Função para contar elementos e armazenar em L2
void contar_elementos(int L1[], int tamanho, int L2[][2], int *tamanho2) {
    int i, j, encontrado;
    *tamanho2 = 0;
    for (i = 0; i < tamanho; i++) {
        encontrado = 0;
        for (j = 0; j < *tamanho2; j++) {
            if (L2[j][0] == L1[i]) {
                L2[j][1]++;
                encontrado = 1;
                break;
            }
        }
        if (!encontrado) {
            L2[*tamanho2][0] = L1[i];
            L2[*tamanho2][1] = 1;
            (*tamanho2)++;
        }
    }
}

// Função para remover todas as ocorrências de um elemento
void remover_elemento(int L1[], int *tamanho, int elemento) {
    int i, j = 0;
    for (i = 0; i < *tamanho; i++) {
        if (L1[i] != elemento) {
            L1[j] = L1[i];
            j++;
        }
    }
    *tamanho = j;
}

// Função principal para testar as operações
int main() {
    int L1[TAM_MAX] = {1, 2, 2, 3, 4, 4, 5};
    int L2[TAM_MAX], L3[TAM_MAX], contagem[TAM_MAX][2];
    int tamanho1 = 7, tamanho2, tamanho3;

    printf("Lista L1 está ordenada? %s\n", esta_ordenada(L1, tamanho1) ? "Sim" : "Não");

    copiar_lista(L1, tamanho1, L2, &tamanho2);
    printf("L2 (cópia de L1): ");
    for (int i = 0; i < tamanho2; i++) printf("%d ", L2[i]);
    printf("\n");

    copiar_unicos(L1, tamanho1, L2, &tamanho2);
    printf("L2 (sem repetidos): ");
    for (int i = 0; i < tamanho2; i++) printf("%d ", L2[i]);
    printf("\n");

    inverter_lista(L1, tamanho1, L2, &tamanho2);
    printf("L2 (inverso de L1): ");
    for (int i = 0; i < tamanho2; i++) printf("%d ", L2[i]);
    printf("\n");

    inverter_em_L1(L1, tamanho1);
    printf("L1 invertida: ");
    for (int i = 0; i < tamanho1; i++) printf("%d ", L1[i]);
    printf("\n");

    return 0;
}
