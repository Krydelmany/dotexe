#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

/**
 * @brief Função para gravar o gênero do jogo em um arquivo.
 * 
 * Esta função abre um arquivo chamado "jogos.txt" em modo de adição (append) e escreve
 * o gênero do jogo fornecido como parâmetro no arquivo. Se o arquivo não puder ser aberto,
 * uma mensagem de erro será exibida.
 * 
 * @param generoJogo O gênero do jogo a ser gravado no arquivo.
 */
void gravarPrecoJogo(float precoJogo) {
    std::ofstream arquivo("output/temp/jogos.txt", std::ios::app); // Abre o arquivo em modo de adição
    if (arquivo.is_open()) {
        arquivo << precoJogo << " R$" << std::endl; // Escreve o preço do jogo no arquivo
        arquivo.close(); // Fecha o arquivo
        std::cout << "Valor do jogo gravado com sucesso!" << std::endl;
    } else {
        std::cerr << "Erro ao abrir o arquivo!" << std::endl;
    }
}