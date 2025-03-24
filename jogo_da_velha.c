#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
// Tabuleiro e jogadores
char tabuleiro[3][3];
char jogador = 'X';
int modo_jogo;

// Limpa a tela do terminal
void limpar_tela(void) {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

// Inicializa o tabuleiro vazio
void inicializar_tabuleiro(void) {
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            tabuleiro[i][j] = ' ';
        }
    }
}
 
// Mostra o tabuleiro e jogada atual
void mostrar_tabuleiro(void) {
    printf("\n");
    printf("  1   2   3  \n");
    printf("1 %c | %c | %c \n", tabuleiro[0][0], tabuleiro[0][1], tabuleiro[0][2]);
    printf(" ---|---|---\n");
    printf("2 %c | %c | %c \n", tabuleiro[1][0], tabuleiro[1][1], tabuleiro[1][2]);
    printf(" ---|---|---\n");
    printf("3 %c | %c | %c \n", tabuleiro[2][0], tabuleiro[2][1], tabuleiro[2][2]);
    printf("\n");
}

// Faz uma jogada se for válida
int fazer_jogada(int linha, int coluna) {
    // Verifica se está dentro do tabuleiro
    if (linha < 0 || linha > 2 || coluna < 0 || coluna > 2) {
        return 0;
    }
    
    // Verifica se a posição está vazia
    if (tabuleiro[linha][coluna] != ' ') {
        return 0;
    }
    
    // Faz a jogada
    tabuleiro[linha][coluna] = jogador;
    return 1;
}

// Verifica se alguém venceu
int verificar_vitoria(void) {
    int i;
    
    // Verifica linhas
    for (i = 0; i < 3; i++) {
        if (tabuleiro[i][0] != ' ' && tabuleiro[i][0] == tabuleiro[i][1] && tabuleiro[i][1] == tabuleiro[i][2]) {
            return 1;
        }
    }
    
    // Verifica colunas
    for (i = 0; i < 3; i++) {
        if (tabuleiro[0][i] != ' ' && tabuleiro[0][i] == tabuleiro[1][i] && tabuleiro[1][i] == tabuleiro[2][i]) {
            return 1;
        }
    }
    
    // Verifica diagonal principal
    if (tabuleiro[0][0] != ' ' && tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2]) {
        return 1;
    }
    
    // Verifica diagonal secundária
    if (tabuleiro[0][2] != ' ' && tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0]) {
        return 1;
    }
    
    return 0;
}

// Verifica se deu velha
int verificar_empate(void) {
    int i, j;
    
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (tabuleiro[i][j] == ' ') {
                return 0; // Ainda há espaços vazios
            }
        }
    }
    
    return 1; // Tabuleiro cheio = velha
}

// Faz a jogada do computador
void jogada_computador(void) {
    int i, j;
    char oponente = 'X';  // O computador é sempre 'O'
    
    // Tenta vencer em um movimento
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (tabuleiro[i][j] == ' ') {
                tabuleiro[i][j] = jogador;  // Testa a jogada
                if (verificar_vitoria()) {
                    return;  // Encontrou jogada vencedora
                }
                tabuleiro[i][j] = ' ';  // Desfaz a jogada
            }
        }
    }
    
    //Tenta bloquear uma vitória do oponente
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (tabuleiro[i][j] == ' ') {
                tabuleiro[i][j] = oponente;  // Testa como se fosse o oponente
                if (verificar_vitoria()) {
                    tabuleiro[i][j] = jogador;  // Bloqueia a jogada
                    return;
                }
                tabuleiro[i][j] = ' ';  // Desfaz a jogada
            }
        }
    }
    
    // Tenta jogar no centro
    if (tabuleiro[1][1] == ' ') {
        tabuleiro[1][1] = jogador;
        return;
    }
    
    // Tenta jogar nos cantos
    if (tabuleiro[0][0] == ' ') { tabuleiro[0][0] = jogador; return; }
    if (tabuleiro[0][2] == ' ') { tabuleiro[0][2] = jogador; return; }
    if (tabuleiro[2][0] == ' ') { tabuleiro[2][0] = jogador; return; }
    if (tabuleiro[2][2] == ' ') { tabuleiro[2][2] = jogador; return; }
    
    // Tenta jogar nas laterais
    if (tabuleiro[0][1] == ' ') { tabuleiro[0][1] = jogador; return; }
    if (tabuleiro[1][0] == ' ') { tabuleiro[1][0] = jogador; return; }
    if (tabuleiro[1][2] == ' ') { tabuleiro[1][2] = jogador; return; }
    if (tabuleiro[2][1] == ' ') { tabuleiro[2][1] = jogador; return; }
}
 
int main() {
    int linha, coluna;
    char jogar_novamente;
    
    // Inicializa o rand
    srand(time(NULL));
    
    do {
        // Menu inicial
        limpar_tela();
        printf("==== JOGO DA VELHA MAIS TOP DE TODOS ====\n\n");
        printf("1. Jogador vs Jogador\n");
        printf("2. Jogador vs Computador\n");
        printf("Escolha: ");
        scanf("%d", &modo_jogo);
        
        // Inicializa o jogo
        inicializar_tabuleiro();
        jogador = 'X';
        
        // Loop principal do jogo
        while (1) {
            limpar_tela();
            mostrar_tabuleiro();
            
            // verifica de quem e a vez de jogar
            if (jogador == 'X' || modo_jogo == 1) {
                printf("\nJogador %c, sua vez\n", jogador);
                
                int jogada_valida = 0;
                do {
                    printf("Linha (1-3): ");
                    scanf("%d", &linha);
                    printf("Coluna (1-3): ");
                    scanf("%d", &coluna);
                    
                    // Verifica se a jogada é válida
                    jogada_valida = fazer_jogada(linha-1, coluna-1);
                    if (!jogada_valida) {
                        printf("Jogada inválida! Tente novamente.\n");
                    }
                } while (!jogada_valida);
            } else {
                printf("\nVez do computador (O)...\n");
                jogada_computador();
            }
            
            // Verifica fim de jogo
            if (verificar_vitoria()) {
                limpar_tela();
                mostrar_tabuleiro();
                printf("\nJogador %c venceu!\n", jogador);
                break;
            }
            
            //Verifica se deu velha
            if (verificar_empate()) {
                limpar_tela();
                mostrar_tabuleiro();
                printf("\nEmpate!\n");
                break;
            }
            
            // Troca de jogador
            jogador = (jogador == 'X') ? 'O' : 'X';
        }
        
        // Pergunta se quer jogar novamente
        printf("\nJogar novamente? (S/N): ");
        scanf(" %c", &jogar_novamente);
        
    } while (jogar_novamente == 'S' || jogar_novamente == 's');
    
    printf("\nObrigado por jogar!\n");
    return 0;
}

