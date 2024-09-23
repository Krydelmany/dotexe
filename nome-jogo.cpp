#include <iostream>
#include <fstream>
#include <string>

// Função para gravar o nome e o gênero do jogo em um arquivo
void gravarJogo(int id, const std::string& nomeJogo, const std::string& generoJogo) {
    std::ofstream arquivo("jogos.txt", std::ios::app); // Abre o arquivo em modo de adição
    if (arquivo.is_open()) {
        arquivo << id << ";nome: " << nomeJogo << ", Genero: " << generoJogo << ";" << std::endl; // Escreve o nome e o gênero do jogo no arquivo
        arquivo.close(); // Fecha o arquivo
        std::cout << "Jogo gravado com sucesso!" << std::endl;
    } else {
        std::cout << "Erro ao abrir o arquivo!" << std::endl;
    }
}