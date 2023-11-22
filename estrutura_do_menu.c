#include <stdio.h>
#include <string.h>

// Definindo a estrutura para armazenar informações do hospede
struct Hospede {
    char nome[50];
    int idade;
    char endereco[100];
    char cpf[15];
};

// Definindo o numero de quartos no hotel
#define NUM_QUARTOS 20

// Funcao para imprimir o menu
void imprimirMenu() {
    printf("\nMenu:\n");
    printf("1. Inserir um novo hospede em um quarto vazio\n");
    printf("2. Lista de hospedes\n");
    printf("3. Buscar hospede\n");
    printf("4. Editar hospede\n");
    printf("5. Remover hospede\n");
    printf("6. Mostrar numeros dos quartos\n");
    printf("7. Salvar lista de hospedes com respectivos quartos em arquivo\n");
    printf("0. Sair\n");
}

int main() {
    struct Hospede hotel[NUM_QUARTOS]; // Matriz para representar os quartos do hotel
    int opcao;

    // Inicializar todos os quartos como vazios
    for (int i = 0; i < NUM_QUARTOS; i++) {
        hotel[i].idade = -1; // Uma idade de -1 indica que o quarto está vazio
    }

    do {
        imprimirMenu();
        printf("\nEscolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                // Inserir um novo hospede em um quarto vazio
                // Implementar...
                break;
            case 2:
                // Lista de hospedes
                // Implementar...
                break;
            case 3:
                // Buscar hospede
                // Implementar...
                break;
            case 4:
                // Editar hospede
                // Implementar...
                break;
            case 5:
                // Remover hospede
                // Implementar...
                break;
            case 6:
                // Mostrar numeros dos quartos
                // Implementar...
                break;
            case 7:
                // Salvar lista de hospedes com respectivos quartos em arquivo
                // Implementar...
                break;
            case 0:
                printf("Saindo do programa. Ate mais!\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }

    } while (opcao != 0);

    return 0;
}
