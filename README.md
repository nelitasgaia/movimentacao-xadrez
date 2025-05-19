# Batalha Naval em C

Projeto desenvolvido como parte da disciplina de Programação em C da Estácio, com o objetivo de aplicar lógica condicional, laços e arrays.

## 🎯 Objetivo

Simular uma versão simples do jogo Batalha Naval em um tabuleiro 5x5 com 3 navios posicionados aleatoriamente. O jogador realiza jogadas até destruir todos os navios.

## 🔧 Como funciona

- Tabuleiro 5x5
- 3 navios escondidos
- O jogador digita posições como `A3`, `D5` etc.
- O programa responde com:
  - 💥 Acertou
  - 🌊 Água
  - Já atirou aqui

## 🖥️ Como compilar

```bash
gcc batalha_naval.c -o batalha_naval
./batalha_naval
```

## 📌 Exemplo de execução

```
Digite sua jogada (ex: B3): C2
🌊 Água...

Digite sua jogada (ex: B3): A5
💥 ACERTOU o navio!

🎉 PARABÉNS! Você afundou todos os navios em 9 tentativas.
```

## 📂 Arquivos

- `batalha_naval.c` – Código-fonte principal
- `README.md` – Explicação do projeto e instruções
