/**
 * @brief Função para buscar um jogo com base no nome.
 * 
 * Esta função abre um arquivo contendo uma lista de jogos e procura por um jogo cujo nome
 * corresponda (case-insensitive) ao nome fornecido. Se o jogo for encontrado, ele será exibido
 * no console. Caso contrário, uma mensagem de erro será exibida.
 * 
 * @param nomeJogo O nome do jogo que deseja buscar.
 */
#include "buscar-jogo.h"
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

/**
 * @brief Função para buscar um jogo pelo nome.
 * 
 * Esta função realiza uma busca linear no arquivo de jogos para encontrar
 * jogos que contenham o nome especificado. A busca linear percorre todas as linhas
 * do arquivo e verifica se o nome do jogo está presente em cada linha.
 * 
 * @param nome O nome do jogo que deseja buscar.
 */
void buscarJogoPorNome(const std::string& nomeJogo) {
    std::ifstream arquivo("output/jogos.txt"); // Arquivo com a lista de jogos
    std::string linha;
    bool jogoEncontrado = false;

    if (!arquivo.is_open()) {
        std::cerr << "Erro ao abrir o arquivo!" << std::endl;
        return;
    }

    // Lê o arquivo linha por linha
    while (std::getline(arquivo, linha)) {
        // Converte para letras minúsculas para garantir uma busca case-insensitive
        std::string linhaLower = linha;
        std::string nomeJogoLower = nomeJogo;

        std::transform(linhaLower.begin(), linhaLower.end(), linhaLower.begin(), ::tolower);
        std::transform(nomeJogoLower.begin(), nomeJogoLower.end(), nomeJogoLower.begin(), ::tolower);

        // Verifica se o nome do jogo está contido na linha
        if (linhaLower.find(nomeJogoLower) != std::string::npos) {
            std::cout << "Jogo encontrado: " << linha << std::endl;
            jogoEncontrado = true;
        }
    }

    if (!jogoEncontrado) {
        std::cerr << "Jogo com nome '" << nomeJogo << "' não encontrado!" << std::endl;
    }

    arquivo.close();
}

/**
 * @brief Função para buscar um jogo pelo ID.
 * 
 * Esta função realiza uma busca linear no arquivo de jogos para encontrar
 * o jogo com o ID especificado. A busca linear percorre todas as linhas
 * do arquivo até encontrar o ID desejado ou até chegar ao final do arquivo.
 * 
 * @param id O ID do jogo que deseja buscar.
 */
void buscarJogoPorID(int id) {
    std::ifstream arquivo("output/jogos.txt");
    if (!arquivo.is_open()) {
        std::cerr << "Erro ao abrir o arquivo de jogos." << std::endl;
        return;
    }

    std::string linha;
    bool encontrado = false;
    std::string idStr = "ID: " + std::to_string(id);

    while (std::getline(arquivo, linha)) {
        // Verifica se a linha começa exatamente com o ID procurado
        if (linha.find(idStr) == 0) {
            std::cout << "\nJogo encontrado: " << std::endl;
            std::cout << linha << std::endl;

            // Exibir as próximas linhas (informações do jogo) até encontrar uma linha que comece com "ID: " ou o final do arquivo
            while (std::getline(arquivo, linha)) {
                if (linha.find("ID: ") == 0) {
                    break;
                }
                std::cout << linha << std::endl;
            }

            encontrado = true;
            break;
        }
    }

    if (!encontrado) {
        std::cout << "Jogo com o ID '" << id << "' nao encontrado." << std::endl;
    }

    arquivo.close();
}