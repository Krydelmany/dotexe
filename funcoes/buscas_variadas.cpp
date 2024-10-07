#include "../main.h"
#include "../cabecalhos/buscas_variadas.h"

// Função para ordenar os jogos pelo ID antes de realizar a busca binária
void ordenarJogosPorID(std::vector<Jogo>& jogos)
{
    std::sort(jogos.begin(), jogos.end(), [](const Jogo& a, const Jogo& b) {
        return a.id < b.id;
    });
}

// Função de busca binária
int buscarJogoPorIDBinario(const std::vector<Jogo>& jogos, int id)
{
    int inicio = 0;
    int fim = jogos.size() - 1;

    while (inicio <= fim)
    {
        int meio = inicio + (fim - inicio) / 2;

        // Se o ID do meio for igual ao ID buscado, retorna o índice
        if (jogos[meio].id == id)
        {
            std::cout << "Jogo encontrado: " << jogos[meio].nome << " (ID: " << jogos[meio].id << ")\n";
            return meio;
        }

        // Se o ID do meio for menor, ignora a metade esquerda
        if (jogos[meio].id < id)
        {
            inicio = meio + 1;
        }
        // Se o ID do meio for maior, ignora a metade direita
        else
        {
            fim = meio - 1;
        }
    }

    // Se chegar aqui, o jogo não foi encontrado
    std::cout << "Jogo com ID " << id << " não encontrado.\n";
    return -1;
}
