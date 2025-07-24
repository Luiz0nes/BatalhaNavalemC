#include <stdio.h>

#define TAM 10
#define TAM_NAVIO 3
#define NAVIO 3

// ----------------------- Funções auxiliares -----------------------

// Inicializa o tabuleiro com 0 (água)
void inicializarTabuleiro(int tabuleiro[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

// Imprime o tabuleiro com alinhamento bonito
void imprimirTabuleiro(int tabuleiro[TAM][TAM]) {
    printf("\nTabuleiro:\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Verifica se pode posicionar um navio nas posições indicadas
int podePosicionar(int tabuleiro[TAM][TAM], int linhas[], int colunas[]) {
    for (int i = 0; i < TAM_NAVIO; i++) {
        int l = linhas[i];
        int c = colunas[i];
        if (l < 0 || l >= TAM || c < 0 || c >= TAM) {
            return 0; // Está fora dos limites
        }
        if (tabuleiro[l][c] != 0) {
            return 0; // Já tem navio aqui
        }
    }
    return 1; // Tudo certo!
}

// Marca as posições do navio no tabuleiro com o valor NAVIO (3)
void posicionarNavio(int tabuleiro[TAM][TAM], int linhas[], int colunas[]) {
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linhas[i]][colunas[i]] = NAVIO;
    }
}

// ----------------------- Função principal -----------------------
int main() {
    int tabuleiro[TAM][TAM];

    // Iniciando o tabuleiro com 0s (água)
    inicializarTabuleiro(tabuleiro);

    // ----------- Navio 1: Horizontal na linha 2, coluna 4 ----------
    int linhaH = 2, colunaH = 4;
    int navio1_linhas[TAM_NAVIO] = {linhaH, linhaH, linhaH};
    int navio1_colunas[TAM_NAVIO] = {colunaH, colunaH + 1, colunaH + 2};

    if (podePosicionar(tabuleiro, navio1_linhas, navio1_colunas)) {
        posicionarNavio(tabuleiro, navio1_linhas, navio1_colunas);
    } else {
        printf("Erro: não foi possível posicionar o navio horizontal!\n");
    }

    // ----------- Navio 2: Vertical na linha 6, coluna 1 ----------
    int linhaV = 6, colunaV = 1;
    int navio2_linhas[TAM_NAVIO] = {linhaV, linhaV + 1, linhaV + 2};
    int navio2_colunas[TAM_NAVIO] = {colunaV, colunaV, colunaV};

    if (podePosicionar(tabuleiro, navio2_linhas, navio2_colunas)) {
        posicionarNavio(tabuleiro, navio2_linhas, navio2_colunas);
    } else {
        printf("Erro: não foi possível posicionar o navio vertical!\n");
    }

    // ----------- Navio 3: Diagonal ↘ começando em (0,0) ----------
    int navio3_linhas[TAM_NAVIO] = {0, 1, 2};
    int navio3_colunas[TAM_NAVIO] = {0, 1, 2};

    if (podePosicionar(tabuleiro, navio3_linhas, navio3_colunas)) {
        posicionarNavio(tabuleiro, navio3_linhas, navio3_colunas);
    } else {
        printf("Erro: não foi possível posicionar o navio diagonal ↘!\n");
    }

    // ----------- Navio 4: Diagonal ↙ começando em (0,9) ----------
    int navio4_linhas[TAM_NAVIO] = {0, 1, 2};
    int navio4_colunas[TAM_NAVIO] = {9, 8, 7};

    if (podePosicionar(tabuleiro, navio4_linhas, navio4_colunas)) {
        posicionarNavio(tabuleiro, navio4_linhas, navio4_colunas);
    } else {
        printf("Erro: não foi possível posicionar o navio diagonal ↙!\n");
    }

    // ----------- Imprimindo o tabuleiro ao final ----------
    imprimirTabuleiro(tabuleiro);

    return 0;
}
