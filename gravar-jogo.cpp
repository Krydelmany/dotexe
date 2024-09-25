#include "gravar-jogo.h"

void gravarJogo(int id, const std::string& nomeJogo, const std::string& generoJogo, const std::string& plataforma, const std::string& anoLancamento, const std::string& desenvolvedor) {
    std::ofstream arquivo("jogos.txt", std::ios::app);
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
