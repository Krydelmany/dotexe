#include <iostream>
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
void gravarJogo(int id, const std::string& nomeJogo, const std::string& generoJogo) {
    std::ofstream arquivo("jogos.txt", std::ios::app); // Abre o arquivo em modo de adição
    if (arquivo.is_open()) {
        arquivo << id << ";nome: " << nomeJogo << ", Genero: " << generoJogo << ";" << std::endl; // Escreve o nome e o gênero do jogo no arquivo
        arquivo.close(); // Fecha o arquivo
        std::cout << "Jogo gravado com sucesso!" << std::endl;
    } else {
        std::cerr << "Erro ao abrir o arquivo!" << std::endl;
    }
}