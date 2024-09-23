#include "buscar-jogo.h"
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

// Função para buscar um jogo com base no nome
void buscarJogoPorNome(const std::string& nomeJogo) {
    std::ifstream arquivo("jogos.txt"); // Arquivo com a lista de jogos
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
