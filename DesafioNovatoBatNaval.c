#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3

// -------------------- Funções auxiliares --------------------

// Função para inicializar o tabuleiro com água (0 em todas as posições)
void inicializarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int linha = 0; linha < TAMANHO_TABULEIRO; linha++) {
        for (int coluna = 0; coluna < TAMANHO_TABULEIRO; coluna++) {
            tabuleiro[linha][coluna] = 0; // 0 representa água
        }
    }
}

// Função para imprimir o tabuleiro de forma legível
void imprimirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("Tabuleiro Batalha Naval:\n");
    for (int linha = 0; linha < TAMANHO_TABULEIRO; linha++) {
        for (int coluna = 0; coluna < TAMANHO_TABULEIRO; coluna++) {
            printf("%d ", tabuleiro[linha][coluna]); // Mostra água (0) ou navio (3)
        }
        printf("\n"); // Quebra de linha para mostrar cada linha do tabuleiro
    }
}

// Função para posicionar um navio horizontalmente
void posicionarNavioHorizontal(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linhaInicial, int colunaInicial) {
    // Verifica se o navio cabe no tabuleiro (horizontalmente)
    if (colunaInicial + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
        printf("Erro: Navio horizontal ultrapassa os limites do tabuleiro!\n");
        return;
    }

    // Verifica se já tem algo nas posições (evita sobreposição)
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (tabuleiro[linhaInicial][colunaInicial + i] != 0) {
            printf("Erro: Sobreposição detectada no navio horizontal!\n");
            return;
        }
    }

    // Posiciona o navio horizontal (valor 3 representa parte do navio)
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linhaInicial][colunaInicial + i] = 3;
    }
}

// Função para posicionar um navio verticalmente
void posicionarNavioVertical(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linhaInicial, int colunaInicial) {
    // Verifica se o navio cabe no tabuleiro (verticalmente)
    if (linhaInicial + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
        printf("Erro: Navio vertical ultrapassa os limites do tabuleiro!\n");
        return;
    }

    // Verifica se já tem algo nas posições (evita sobreposição)
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (tabuleiro[linhaInicial + i][colunaInicial] != 0) {
            printf("Erro: Sobreposição detectada no navio vertical!\n");
            return;
        }
    }

    // Posiciona o navio vertical (valor 3 representa parte do navio)
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linhaInicial + i][colunaInicial] = 3;
    }
}

// -------------------- Função principal --------------------
int main() {
    // -------------------- Parte do Batalha Naval --------------------
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    // Inicializa o tabuleiro com água (0 em todas as posições)
    inicializarTabuleiro(tabuleiro);

    // Coordenadas iniciais dos navios (definidas no código)
    int linhaHorizontal = 2;
    int colunaHorizontal = 4;

    int linhaVertical = 6;
    int colunaVertical = 1;

    // Posicionando os navios no tabuleiro
    posicionarNavioHorizontal(tabuleiro, linhaHorizontal, colunaHorizontal);
    posicionarNavioVertical(tabuleiro, linhaVertical, colunaVertical);

    // Mostrando o tabuleiro após o posicionamento
    printf("\n");
    imprimirTabuleiro(tabuleiro);

    return 0;
}
