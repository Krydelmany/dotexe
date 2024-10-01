#include "FilaDeProcessamento.h"

void FilaDeProcessamento::adicionarJogo(const Jogo &jogo)
{
    filaJogos.push(jogo);
    std::cout << "Jogo '" << jogo.nome << "' adicionado a fila." << std::endl;
}

Jogo FilaDeProcessamento::removerJogo()
{
    if (filaVazia())
    {
        std::cerr << "A fila esta vazia. Nao ha jogos para remover." << std::endl;
        throw std::runtime_error("Fila vazia");
    }
    Jogo jogo = filaJogos.front();
    filaJogos.pop();
    std::cout << "Jogo '" << jogo.nome << "' removido da fila." << std::endl;
    return jogo;
}

Jogo FilaDeProcessamento::primeiroJogo() const
{
    if (filaVazia())
    {
        std::cerr << "A fila esta vazia. Nao ha jogos para exibir." << std::endl;
        throw std::runtime_error("Fila vazia");
    }
    return filaJogos.front();
}

bool FilaDeProcessamento::filaVazia() const
{
    return filaJogos.empty();
}

void FilaDeProcessamento::processarFila()
{
    while (!filaVazia())
    {
        Jogo jogo = removerJogo();
        std::cout << "Processando Jogo ID: " << jogo.id << ", Nome: " << jogo.nome << std::endl;
        // Simular algum processamento, por exemplo, atualizar informações do jogo
    }
}
