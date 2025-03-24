# Jogo da Velha em C

Um jogo da velha clássico implementado em C para terminal, com interface simples e intuitiva. O jogo oferece dois modos de jogo: jogador contra jogador ou jogador contra computador.

## Funcionalidades

- Interface de terminal amigável com grade numerada
- Dois modos de jogo:
  - Jogador vs Jogador: para jogar com um amigo
  - Jogador vs Computador: para jogar contra a "IA"
- Sistema inteligente para jogadas do computador
- Verificação automática de vitória e empate
- Opção para jogar novamente após o término de uma partida
- Compatível com sistemas Windows e Unix/Linux

## Como o código funciona

O código está organizado em funções que controlam os diferentes aspectos do jogo:

- `limpar_tela()`: Limpa a tela do terminal (compatível com Windows e Unix/Linux)
- `inicializar_tabuleiro()`: Prepara o tabuleiro com espaços vazios
- `mostrar_tabuleiro()`: Exibe o estado atual do tabuleiro no terminal
- `fazer_jogada()`: Verifica se uma jogada é válida e a executa
- `verificar_vitoria()`: Confere se algum jogador venceu (linhas, colunas ou diagonais)
- `verificar_empate()`: Verifica se o jogo terminou em empate (tabuleiro cheio)
- `jogada_computador()`: Implementa a lógica para as jogadas do computador, seguindo uma estratégia básica:
  1. Tenta vencer em um movimento
  2. Tenta bloquear uma possível vitória do oponente
  3. Tenta jogar no centro
  4. Tenta jogar nos cantos
  5. Tenta jogar nas laterais

A função `main()` controla o fluxo principal do jogo, incluindo a escolha do modo de jogo, a alternância entre os jogadores e a verificação de condições de término.

## Compilação e Execução

### Pré-requisitos

- Compilador GCC ou outro compilador C

### No Linux/macOS

1. Abra o terminal
2. Navegue até o diretório onde o arquivo `jogo_da_velha.c` está localizado
3. Compile o código com o comando:
   ```
   gcc jogo_da_velha.c -o jogo_da_velha
   ```
4. Execute o jogo com:
   ```
   ./jogo_da_velha
   ```

### No Windows

1. Abra o Prompt de Comando ou PowerShell
2. Navegue até o diretório onde o arquivo `jogo_da_velha.c` está localizado
3. Se estiver usando MinGW, compile com:
   ```
   gcc jogo_da_velha.c -o jogo_da_velha.exe
   ```
4. Execute o jogo com:
   ```
   jogo_da_velha.exe
   ```

## Como Jogar

1. Ao iniciar o jogo, escolha o modo de jogo:
   - Digite `1` para Jogador vs Jogador
   - Digite `2` para Jogador vs Computador

2. O tabuleiro é uma grade 3x3, com posições numeradas de 1 a 3 para linhas e colunas:
   ```
     1   2   3
   1   |   |   
    ---|---|---
   2   |   |   
    ---|---|---
   3   |   |   
   ```

3. Em seu turno, informe primeiro o número da linha (1-3) e depois o número da coluna (1-3) onde deseja marcar.

4. O jogador X sempre começa, seguido pelo jogador O.

5. No modo Jogador vs Computador, você será sempre o jogador X e o computador será o jogador O.

6. O jogo termina quando:
   - Um jogador consegue três símbolos em linha (horizontal, vertical ou diagonal) e vence
   - Todas as posições são preenchidas sem um vencedor (empate/"velha")

7. Após o fim do jogo, você pode escolher jogar novamente digitando 'S' ou sair digitando 'N'.
