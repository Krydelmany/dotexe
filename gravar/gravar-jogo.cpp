#include "gravar-jogo.h"
#include <iostream>
#include <fstream>
#include <string>

void gravarJogo(int id, const std::string& nomeJogo, const std::string& generoJogo, const std::string& plataforma, const std::string& anoLancamento, const std::string& desenvolvedor) {
    std::ofstream arquivo("output/jogos.txt", std::ios::app);
    if (arquivo.is_open()) {
        arquivo << id << "; Nome: " << nomeJogo 
                << ", Genero: " << generoJogo 
                << ", Plataforma: " << plataforma 
                << ", Ano: " << anoLancamento 
                << ", Desenvolvedor: " << desenvolvedor << ";"
                << std::endl;
        arquivo.close();
        std::cout << "Jogo gravado com sucesso!" << std::endl;
    } else {
        std::cerr << "Erro ao abrir o arquivo!" << std::endl;
    }
}
