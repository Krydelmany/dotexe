#include <iostream>
#include <fstream>
#include <string>
#include "../cabecalhos/gravar_jogo.h"

/**
 * @brief Função para gravar um jogo no arquivo.
 *
 * Esta função abre um arquivo contendo uma lista de jogos e adiciona um novo jogo
 * com os detalhes fornecidos. O arquivo é aberto em modo de anexação para garantir
 * que o novo jogo seja adicionado ao final do arquivo existente.
 *
 * @param id O ID do jogo.
 * @param nome O nome do jogo.
 * @param genero O gênero do jogo.
 * @param plataforma A plataforma do jogo.
 * @param anoLancamento O ano de lançamento do jogo.
 * @param desenvolvedor O desenvolvedor do jogo.
 */
void gravarJogo(int id, const std::string &nome, const std::string &genero,
                const std::string &plataforma, const std::string &anoLancamento,
                const std::string &desenvolvedor)
{
    std::ofstream arquivo("output/jogos.txt", std::ios::app); // Abre o arquivo em modo de anexação

    if (arquivo.is_open())
    {

        arquivo << "ID: " << id << "; "
                << "Nome: " << nome << "; "
                << "Genero: " << genero << "; "
                << "Plataforma: " << plataforma << "; "
                << "Ano: " << anoLancamento << "; "
                << "Desenvolvedor: " << desenvolvedor << "\n";

        arquivo.close();
        std::cout << "Jogo gravado com sucesso!" << std::endl;
    }
    else
    {
        std::cerr << "Erro ao abrir o arquivo para gravar o jogo." << std::endl;
    }
}