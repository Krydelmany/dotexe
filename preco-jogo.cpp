#include "bibliotecas.h"

// Função para gravar o preço do jogo
void gravarPrecoJogo(float precoJogo) {
    std::ofstream arquivo("jogos.txt", std::ios::app); // Abre o arquivo em modo de adição
    if (arquivo.is_open()) {
        arquivo << precoJogo << " R$" << std::endl; // Escreve o preço do jogo no arquivo
        arquivo.close(); // Fecha o arquivo
        std::cout << "Valor do jogo gravado com sucesso!" << std::endl;
    } else {
        std::cerr << "Erro ao abrir o arquivo!" << std::endl;
    }
}