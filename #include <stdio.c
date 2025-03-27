#include <stdio.h>

#define MAX 50

void inserirOrdenado(int vetor[], int *tamanho, int valor) {
    if (*tamanho >= MAX) {
        printf("O vetor está cheio!\n");
        return;
    }
    int i;
    for (i = *tamanho - 1; i >= 0 && vetor[i] > valor; i--) {
        vetor[i + 1] = vetor[i];
    }
    vetor[i + 1] = valor;
    (*tamanho)++;
}

int buscaBinaria(int vetor[], int tamanho, int valor) {
    int inicio = 0, fim = tamanho - 1;
    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;
        if (vetor[meio] == valor) {
            return meio;
        } else if (vetor[meio] < valor) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    return -1;
}

void removerElemento(int vetor[], int *tamanho, int valor) {
    int pos = buscaBinaria(vetor, *tamanho, valor);
    if (pos == -1) {
        printf("Elemento não encontrado!\n");
        return;
    }
    for (int i = pos; i < *tamanho - 1; i++) {
        vetor[i] = vetor[i + 1];
    }
    (*tamanho)--;
}

void imprimirVetor(int vetor[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

int main() {
    int vetor[MAX];
    int tamanho, valor, opcao;

    do {
        printf("Digite o tamanho do vetor (entre 3 e 50): ");
        scanf("%d", &tamanho);
    } while (tamanho < 3 || tamanho > 50);

    printf("Digite %d valores inteiros ordenados:\n", tamanho);
    for (int i = 0; i < tamanho; i++) {
        scanf("%d", &valor);
        inserirOrdenado(vetor, &i, valor);
    }

    do {
        printf("\nMenu:\n");
        printf("1 - Imprimir vetor\n");
        printf("2 - Consultar elemento (busca binária)\n");
        printf("3 - Remover elemento\n");
        printf("4 - Inserir elemento\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            imprimirVetor(vetor, tamanho);
        } else if (opcao == 2) {
            printf("Digite o valor a buscar: ");
            scanf("%d", &valor);
            int pos = buscaBinaria(vetor, tamanho, valor);
            if (pos == -1) {
                printf("Elemento não encontrado!\n");
            } else {
                printf("Elemento encontrado na posição %d\n", pos);
            }
        } else if (opcao == 3) {
            printf("Digite o valor a remover: ");
            scanf("%d", &valor);
            removerElemento(vetor, &tamanho, valor);
        } else if (opcao == 4) {
            printf("Digite o valor a inserir: ");
            scanf("%d", &valor);
            inserirOrdenado(vetor, &tamanho, valor);
        } else if (opcao != 0) {
            printf("Opção inválida!\n");
        }
    } while (opcao != 0);
    
    printf("Saindo...\n");
    return 0;
}
