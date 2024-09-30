#include "id-manager.h"
#include <fstream>
#include <iostream>

const std::string ID_FILE = "output/temp/last_id.txt";

/**
 * @brief Inicializa o gerenciador de IDs.
 * 
 * Esta função verifica se o arquivo de IDs existe. Se não existir, cria o arquivo
 * e inicializa o ID com o valor 0. Se o arquivo já existir, não faz nenhuma alteração.
 */
void initializeIdManager() {
    std::ifstream file(ID_FILE);
    if (!file) {
        // Se o arquivo não existe, cria-o com o ID inicial 0
        std::ofstream newFile(ID_FILE);
        if (newFile.is_open()) {
            newFile << "0";
            newFile.close();
        } else {
            std::cerr << "Erro ao criar o arquivo de IDs." << std::endl;
        }
    }
    file.close();
}

/**
 * @brief Obtém o próximo ID disponível.
 * 
 * Esta função lê o último ID utilizado a partir do arquivo de IDs, incrementa o valor
 * em 1, grava o novo ID de volta no arquivo e retorna o próximo ID disponível.
 * 
 * @return O próximo ID disponível, ou -1 em caso de erro.
 */
int getNextId() {
    int lastId = 0;
    std::ifstream inFile(ID_FILE);
    if (inFile.is_open()) {
        inFile >> lastId;
        inFile.close();
    } else {
        std::cerr << "Erro ao ler o arquivo de IDs." << std::endl;
        return -1;
    }
    
    int nextId = lastId + 1;

    std::ofstream outFile(ID_FILE);
    if (outFile.is_open()) {
        outFile << nextId;
        outFile.close();
    } else {
        std::cerr << "Erro ao atualizar o arquivo de IDs." << std::endl;
        return -1;
    }

    return nextId;
}