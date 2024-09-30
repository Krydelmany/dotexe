#include "excluir-jogo.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

/**
 * @brief Função para excluir um jogo pelo ID.
 * 
 * Esta função abre um arquivo contendo uma lista de jogos, procura pelo jogo com o ID especificado
 * e o remove do arquivo. Se o jogo for encontrado e removido, o arquivo original é substituído pelo
 * arquivo temporário atualizado. Caso contrário, o arquivo temporário é removido e uma mensagem de erro
 * é exibida.
 * 
 * @param id O ID do jogo que deseja excluir.
 */
void excluirJogo(int id) {
    std::ifstream arquivoEntrada("output/jogos.txt"); // Arquivo original de jogos
    std::ofstream arquivoTemp("output/temp/temp.txt");   // Arquivo temporário para armazenar os jogos restantes
    std::string linha;
    bool jogoEncontrado = false;

    if (!arquivoEntrada.is_open() || !arquivoTemp.is_open()) {
        std::cerr << "Erro ao abrir o arquivo!" << std::endl;
        return;
    }

    // Lê cada linha do arquivo original
    while (std::getline(arquivoEntrada, linha)) {
        std::istringstream stream(linha);
        std::string parte;
        int idJogo = -1;

        // Procura o ID do jogo na linha
        while (std::getline(stream, parte, ';')) {
            if (parte.find("ID:") != std::string::npos) {
                std::istringstream idStream(parte.substr(parte.find(":") + 1));
                idStream >> idJogo;
                break;
            }
        }

        // Se o ID não for o jogo a ser excluído, ele é gravado no arquivo temporário
        if (idJogo != id) {
            arquivoTemp << linha << std::endl;
        } else {
            jogoEncontrado = true;
        }
    }

    arquivoEntrada.close();
    arquivoTemp.close();

    // Substitui o arquivo original pelo temporário se o jogo foi encontrado
    if (jogoEncontrado) {
        if (std::remove("output/jogos.txt") != 0) {
            std::cerr << "Erro ao remover o arquivo original!" << std::endl;
            return;
        }
        if (std::rename("output/temp/temp.txt", "output/jogos.txt") != 0) {
            std::cerr << "Erro ao renomear o arquivo temporario!" << std::endl;
            return;
        }
        std::cout << "Jogo com ID " << id << " excluido com sucesso!" << std::endl;
    } else {
        std::remove("output/temp/temp.txt");
        std::cout << "Jogo com ID " << id << " nao encontrado!" << std::endl;
    }
}