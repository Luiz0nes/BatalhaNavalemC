#include <stdio.h>
#include <stdlib.h>

#define TAM 10
#define TAM_NAVIO 3
#define NAVIO 3
#define HABILIDADE 5
#define TAM_HAB 5 // Matrizes de habilidade são 5x5

// ---------- Funções utilitárias de tabuleiro ----------
void inicializarTabuleiro(int tabuleiro[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

void imprimirTabuleiro(int tabuleiro[TAM][TAM]) {
    printf("\nTabuleiro com habilidades aplicadas:\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            if (tabuleiro[i][j] == 0)
                printf(". "); // Água
            else if (tabuleiro[i][j] == NAVIO)
                printf("N "); // Navio
            else if (tabuleiro[i][j] == HABILIDADE)
                printf("* "); // Área de habilidade
        }
        printf("\n");
    }
}

// Verifica se pode posicionar um navio
int podePosicionar(int tabuleiro[TAM][TAM], int linhas[], int colunas[]) {
    for (int i = 0; i < TAM_NAVIO; i++) {
        int l = linhas[i];
        int c = colunas[i];
        if (l < 0 || l >= TAM || c < 0 || c >= TAM || tabuleiro[l][c] != 0)
            return 0;
    }
    return 1;
}

// Posiciona um navio no tabuleiro
void posicionarNavio(int tabuleiro[TAM][TAM], int linhas[], int colunas[]) {
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linhas[i]][colunas[i]] = NAVIO;
    }
}

// ---------- Criação de habilidades (0 = não atinge, 1 = afeta) ----------

// Cone: forma de V invertido, crescendo de cima para baixo
void criarMatrizCone(int cone[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (j >= 2 - i && j <= 2 + i)
                cone[i][j] = 1;
            else
                cone[i][j] = 0;
        }
    }
}

// Cruz: linha e coluna central marcadas
void criarMatrizCruz(int cruz[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (i == 2 || j == 2)
                cruz[i][j] = 1;
            else
                cruz[i][j] = 0;
        }
    }
}

// Octaedro (losango): forma simétrica ao redor do centro
void criarMatrizOctaedro(int oct[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (abs(i - 2) + abs(j - 2) <= 2)
                oct[i][j] = 1;
            else
                oct[i][j] = 0;
        }
    }
}

// ---------- Aplica habilidade no tabuleiro ----------

void aplicarHabilidade(int tabuleiro[TAM][TAM], int hab[TAM_HAB][TAM_HAB], int origem_l, int origem_c) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            // Mapeia cada célula da matriz de habilidade no tabuleiro
            int linhaTab = origem_l + i - 2; // centraliza a matriz
            int colunaTab = origem_c + j - 2;

            // Garante que estamos dentro do tabuleiro
            if (linhaTab >= 0 && linhaTab < TAM && colunaTab >= 0 && colunaTab < TAM) {
                // Só sobrescreve se for água (não sobrescreve navio ou outra habilidade)
                if (tabuleiro[linhaTab][colunaTab] == 0 && hab[i][j] == 1) {
                    tabuleiro[linhaTab][colunaTab] = HABILIDADE;
                }
            }
        }
    }
}

// ---------- Função principal ----------
int main() {
    int tabuleiro[TAM][TAM];
    inicializarTabuleiro(tabuleiro);

    // --------- Posicionando navios (fixos para este exemplo) ---------

    // Horizontal
    int l1[] = {2, 2, 2}, c1[] = {4, 5, 6};
    if (podePosicionar(tabuleiro, l1, c1)) posicionarNavio(tabuleiro, l1, c1);

    // Vertical
    int l2[] = {6, 7, 8}, c2[] = {1, 1, 1};
    if (podePosicionar(tabuleiro, l2, c2)) posicionarNavio(tabuleiro, l2, c2);

    // Diagonal ↘
    int l3[] = {0, 1, 2}, c3[] = {0, 1, 2};
    if (podePosicionar(tabuleiro, l3, c3)) posicionarNavio(tabuleiro, l3, c3);

    // Diagonal ↙
    int l4[] = {0, 1, 2}, c4[] = {9, 8, 7};
    if (podePosicionar(tabuleiro, l4, c4)) posicionarNavio(tabuleiro, l4, c4);

    // --------- Criando habilidades ---------
    int cone[TAM_HAB][TAM_HAB];
    int cruz[TAM_HAB][TAM_HAB];
    int octaedro[TAM_HAB][TAM_HAB];

    criarMatrizCone(cone);
    criarMatrizCruz(cruz);
    criarMatrizOctaedro(octaedro);

    // --------- Aplicando habilidades ---------
    aplicarHabilidade(tabuleiro, cone, 4, 4);      // Cone no meio
    aplicarHabilidade(tabuleiro, cruz, 7, 7);      // Cruz mais embaixo
    aplicarHabilidade(tabuleiro, octaedro, 5, 8);  // Octaedro à direita

    // --------- Mostrar o resultado final ---------
    imprimirTabuleiro(tabuleiro);

    return 0;
}
