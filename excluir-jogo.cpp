#include "excluir-jogo.h"

// Função para excluir um jogo com base no ID
void excluirJogo(int id) {
    std::ifstream arquivoEntrada("jogos.txt"); // Arquivo original de jogos
    std::ofstream arquivoTemp("temp.txt");     // Arquivo temporário para armazenar os jogos restantes
    std::string linha;
    bool jogoEncontrado = false;

    if (!arquivoEntrada.is_open() || !arquivoTemp.is_open()) {
        std::cerr << "Erro ao abrir o arquivo!" << std::endl;
        return;
    }

    // Lê cada linha do arquivo original
    while (std::getline(arquivoEntrada, linha)) {
        std::istringstream stream(linha);
        int idJogo;
        stream >> idJogo;

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
        std::remove("jogos.txt");
        std::rename("temp.txt", "jogos.txt");
        std::cout << "Jogo com ID " << id << " excluído com sucesso!" << std::endl;
    } else {
        std::remove("temp.txt");
        std::cerr << "Jogo com ID " << id << " não encontrado!" << std::endl;
    }
}
