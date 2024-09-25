#include "bibliotecas.h"

// Função para gravar o gênero do jogo em um arquivo
void gravarGeneroJogo(const std::string& generoJogo) {
    std::ofstream arquivo("jogos.txt", std::ios::app); // Abre o arquivo em modo de adição
    if (arquivo.is_open()) {
        arquivo << generoJogo << std::endl; // Escreve o gênero do jogo no arquivo
        arquivo.close(); // Fecha o arquivo
        std::cout << "Gênero do jogo gravado com sucesso!" << std::endl;
    } else {
        std::cerr << "Erro ao abrir o arquivo!" << std::endl;
    }
}