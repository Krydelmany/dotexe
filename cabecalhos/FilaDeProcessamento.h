#ifndef FILA_DE_PROCESSAMENTO_H
#define FILA_DE_PROCESSAMENTO_H

#include "../main.h"

/**
 * @brief Estrutura para armazenar informações de um jogo.
 */
struct Jogo
{ // Definição da estrutura Jogo
    int id;
    std::string nome;
    std::string genero;
    std::string plataforma;
    std::string anoLancamento;
    std::string desenvolvedor;
};

class FilaDeProcessamento
{
public:
    // Adiciona um jogo à fila
    void adicionarJogo(const Jogo &jogo);

    // Remove e retorna o jogo na frente da fila
    Jogo removerJogo();

    // Retorna o jogo na frente da fila sem removê-lo
    Jogo primeiroJogo() const;

    // Verifica se a fila está vazia
    bool filaVazia() const;

    // Processa todos os jogos na fila
    void processarFila();

private:
    std::queue<Jogo> filaJogos; // Fila para armazenar os jogos
};

#endif
