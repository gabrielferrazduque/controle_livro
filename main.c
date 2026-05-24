#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX_TITULO 100

// ==================== STRUCT ====================
typedef struct {
    int codigo;
    char titulo[MAX_TITULO];
    int ano;
    int quantidade;
} Livro;

// ==================== PROTÓTIPOS ====================
void lerArquivo(Livro livros[], int *qtd);
void imprimirLivros(Livro livros[], int qtd);
void buscarPorCodigo(Livro livros[], int qtd);
void adicionarLivro(Livro livros[], int *qtd);
void ordenarPorAno(Livro livros[], int qtd);
void menu();

// ==================== MAIN ====================
int main() {
    Livro livros[MAX_LIVROS];
    int qtd = 0;

    lerArquivo(livros, &qtd);
    printf("✅ %d livros carregados com sucesso!\n\n", qtd);

    menu(livros, &qtd);

    return 0;
}

// ==================== FUNÇÕES ====================

void lerArquivo(Livro livros[], int *qtd) {
    FILE *arquivo = fopen("livros.txt", "r");
    if (arquivo == NULL) {
        printf("⚠️ Arquivo 'livros.txt' não encontrado. Iniciando com 0 livros.\n");
        *qtd = 0;
        return;
    }

    while (*qtd < MAX_LIVROS && 
           fscanf(arquivo, "%d\n", &livros[*qtd].codigo) == 1) {
        
        fgets(livros[*qtd].titulo, MAX_TITULO, arquivo);
        livros[*qtd].titulo[strcspn(livros[*qtd].titulo, "\n")] = 0; // remove \n
        
        fscanf(arquivo, "%d\n%d\n", &livros[*qtd].ano, &livros[*qtd].quantidade);
        (*qtd)++;
    }

    fclose(arquivo);
}

void imprimirLivros(Livro livros[], int qtd) {
    if (qtd == 0) {
        printf("Nenhum livro cadastrado.\n");
        return;
    }
    printf("\n=== LISTA DE LIVROS ===\n");
    for (int i = 0; i < qtd; i++) {
        printf("Código: %d | Título: %s | Ano: %d | Qtd: %d\n",
               livros[i].codigo, livros[i].titulo, livros[i].ano, livros[i].quantidade);
    }
}

void buscarPorCodigo(Livro livros[], int qtd) {
    int codigo;
    printf("\nDigite o código do livro: ");
    scanf("%d", &codigo);

    for (int i = 0; i < qtd; i++) {
        if (livros[i].codigo == codigo) {
            printf("✅ Livro encontrado!\n");
            printf("Título: %s\nAno: %d\nQuantidade: %d\n",
                   livros[i].titulo, livros[i].ano, livros[i].quantidade);
            return;
        }
    }
    printf("❌ Livro com código %d não encontrado.\n", codigo);
}

void adicionarLivro(Livro livros[], int *qtd) {
    if (*qtd >= MAX_LIVROS) {
        printf("❌ Limite máximo de livros atingido!\n");
        return;
    }

    printf("\n=== ADICIONAR NOVO LIVRO ===\n");
    printf("Código: ");
    scanf("%d", &livros[*qtd].codigo);
    getchar(); // limpa buffer

    printf("Título: ");
    fgets(livros[*qtd].titulo, MAX_TITULO, stdin);
    livros[*qtd].titulo[strcspn(livros[*qtd].titulo, "\n")] = 0;

    printf("Ano de publicação: ");
    scanf("%d", &livros[*qtd].ano);

    printf("Quantidade disponível: ");
    scanf("%d", &livros[*qtd].quantidade);

    (*qtd)++;
    printf("✅ Livro adicionado com sucesso!\n");
}

void ordenarPorAno(Livro livros[], int qtd) {
    for (int i = 0; i < qtd - 1; i++) {
        for (int j = i + 1; j < qtd; j++) {
            if (livros[i].ano > livros[j].ano) {
                Livro temp = livros[i];
                livros[i] = livros[j];
                livros[j] = temp;
            }
        }
    }
    printf("\n✅ Livros ordenados por ano!\n");
    imprimirLivros(livros, qtd);
}

void menu(Livro livros[], int *qtd) {
    int opcao;
    do {
        printf("\n=== SISTEMA DE CONTROLE DE LIVROS ===\n");
        printf("1. Adicionar livro\n");
        printf("2. Buscar livro por código\n");
        printf("3. Imprimir livros\n");
        printf("4. Ordenar por ano e imprimir\n");
        printf("5. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: adicionarLivro(livros, qtd); break;
            case 2: buscarPorCodigo(livros, *qtd); break;
            case 3: imprimirLivros(livros, *qtd); break;
            case 4: ordenarPorAno(livros, *qtd); break;
            case 5: printf("Saindo do sistema...\n"); break;
            default: printf("Opção inválida!\n");
        }
    } while (opcao != 5);
} 
 #include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LIVROS 50
#define MAX_TITULO 100

// ==================== STRUCT ====================
typedef struct {
    int codigo;
    char titulo[MAX_TITULO];
    int ano;
    int quantidade;
} Livro;

// ==================== PROTÓTIPOS ====================
void lerArquivo(Livro livros[], int *qtd);
void imprimirLivros(Livro livros[], int qtd);
void buscarPorCodigo(Livro livros[], int qtd);
void adicionarLivro(Livro livros[], int *qtd);
void ordenarPorAno(Livro livros[], int qtd);
void menu();

// ==================== MAIN ====================
int main() {
    Livro livros[MAX_LIVROS];
    int qtd = 0;

    lerArquivo(livros, &qtd);
    printf("✅ %d livros carregados com sucesso!\n\n", qtd);

    menu(livros, &qtd);

    return 0;
}

// ==================== FUNÇÕES ====================

void lerArquivo(Livro livros[], int *qtd) {
    FILE *arquivo = fopen("livros.txt", "r");
    if (arquivo == NULL) {
        printf("⚠️ Arquivo 'livros.txt' não encontrado. Iniciando com 0 livros.\n");
        *qtd = 0;
        return;
    }

    while (*qtd < MAX_LIVROS && 
           fscanf(arquivo, "%d\n", &livros[*qtd].codigo) == 1) {
        
        fgets(livros[*qtd].titulo, MAX_TITULO, arquivo);
        livros[*qtd].titulo[strcspn(livros[*qtd].titulo, "\n")] = 0; // remove \n
        
        fscanf(arquivo, "%d\n%d\n", &livros[*qtd].ano, &livros[*qtd].quantidade);
        (*qtd)++;
    }

    fclose(arquivo);
}

void imprimirLivros(Livro livros[], int qtd) {
    if (qtd == 0) {
        printf("Nenhum livro cadastrado.\n");
        return;
    }
    printf("\n=== LISTA DE LIVROS ===\n");
    for (int i = 0; i < qtd; i++) {
        printf("Código: %d | Título: %s | Ano: %d | Qtd: %d\n",
               livros[i].codigo, livros[i].titulo, livros[i].ano, livros[i].quantidade);
    }
}

void buscarPorCodigo(Livro livros[], int qtd) {
    int codigo;
    printf("\nDigite o código do livro: ");
    scanf("%d", &codigo);

    for (int i = 0; i < qtd; i++) {
        if (livros[i].codigo == codigo) {
            printf("✅ Livro encontrado!\n");
            printf("Título: %s\nAno: %d\nQuantidade: %d\n",
                   livros[i].titulo, livros[i].ano, livros[i].quantidade);
            return;
        }
    }
    printf("❌ Livro com código %d não encontrado.\n", codigo);
}

void adicionarLivro(Livro livros[], int *qtd) {
    if (*qtd >= MAX_LIVROS) {
        printf("❌ Limite máximo de livros atingido!\n");
        return;
    }

    printf("\n=== ADICIONAR NOVO LIVRO ===\n");
    printf("Código: ");
    scanf("%d", &livros[*qtd].codigo);
    getchar(); // limpa buffer

    printf("Título: ");
    fgets(livros[*qtd].titulo, MAX_TITULO, stdin);
    livros[*qtd].titulo[strcspn(livros[*qtd].titulo, "\n")] = 0;

    printf("Ano de publicação: ");
    scanf("%d", &livros[*qtd].ano);

    printf("Quantidade disponível: ");
    scanf("%d", &livros[*qtd].quantidade);

    (*qtd)++;
    printf("✅ Livro adicionado com sucesso!\n");
}

void ordenarPorAno(Livro livros[], int qtd) {
    for (int i = 0; i < qtd - 1; i++) {
        for (int j = i + 1; j < qtd; j++) {
            if (livros[i].ano > livros[j].ano) {
                Livro temp = livros[i];
                livros[i] = livros[j];
                livros[j] = temp;
            }
        }
    }
    printf("\n✅ Livros ordenados por ano!\n");
    imprimirLivros(livros, qtd);
}

void menu(Livro livros[], int *qtd) {
    int opcao;
    do {
        printf("\n=== SISTEMA DE CONTROLE DE LIVROS ===\n");
        printf("1. Adicionar livro\n");
        printf("2. Buscar livro por código\n");
        printf("3. Imprimir livros\n");
        printf("4. Ordenar por ano e imprimir\n");
        printf("5. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: adicionarLivro(livros, qtd); break;
            case 2: buscarPorCodigo(livros, *qtd); break;
            case 3: imprimirLivros(livros, *qtd); break;
            case 4: ordenarPorAno(livros, *qtd); break;
            case 5: printf("Saindo do sistema...\n"); break;
            default: printf("Opção inválida!\n");
        }
    } while (opcao != 5);
} 
 
return 0; 
