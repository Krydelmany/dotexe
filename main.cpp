/**
 * @file main.cpp
 * @brief Gerenciador de Jogos - Programa para adicionar, excluir e buscar jogos.
 *
 * Este programa permite ao usuário gerenciar uma lista de jogos, oferecendo
 * funcionalidades para adicionar novos jogos, excluir jogos existentes por ID
 * e buscar jogos pelo nome. As informações dos jogos são persistidas em arquivos.
 *
 * @author Giovani Claro Moraes
 * @date 2024
 */

#include <iostream>
#include <string>
#include "gravar-jogo.h"
#include "excluir-jogo.h"
#include "buscar-jogo.h"
#include "entra-programa.h" 

// Escolhemos em não utilizar o namespace std para evitar conflitos de nomes

/**
 * @brief Função principal do programa.
 *
 * Esta função exibe um menu de opções para o usuário, permitindo a escolha
 * entre adicionar um novo jogo, excluir um jogo existente por ID, buscar um
 * jogo pelo nome ou sair do programa. As informações dos jogos são coletadas
 * através da entrada padrão e as operações são realizadas chamando funções
 * específicas para cada tarefa.
 *
 * @return int Retorna 0 ao sair do programa.
 */
int main() {
    int opcao;
    int id = 1;  // Contador de jogos, você pode carregar isso de um arquivo para persistência.
    std::string nomeJogo, generoJogo, plataforma, anoLancamento, desenvolvedor;

    while (true) {
        // Menu de opções
        //entraPrograma(); // Exibe o logo do programa
        std::cout << "\n===== Gerenciador de Jogos =====" << std::endl;
        std::cout << "1. Adicionar Jogo" << std::endl;
        std::cout << "2. Excluir Jogo por ID" << std::endl;
        std::cout << "3. Buscar Jogo por Nome" << std::endl;
        std::cout << "4. Abrir lista em site" << std::endl;
        std::cout << "5. Sair" << std::endl;
        std::cout << "Escolha uma opcao: ";
        std::cin >> opcao;
        std::cin.ignore(); // Limpa o buffer do teclado para evitar problemas com o getline

        switch (opcao) {
            case 1:
                // Adicionar novo jogo
                std::cout << "Digite o nome do jogo: ";
                std::getline(std::cin, nomeJogo);

                std::cout << "Digite o genero do jogo: ";
                std::getline(std::cin, generoJogo);

                std::cout << "Digite a plataforma (PC, Console, etc.): ";
                std::getline(std::cin, plataforma);

                std::cout << "Digite o ano de lancamento: ";
                std::getline(std::cin, anoLancamento);

                std::cout << "Digite o desenvolvedor do jogo: ";
                std::getline(std::cin, desenvolvedor);

                // Chama a função para gravar o jogo no arquivo
                gravarJogo(id, nomeJogo, generoJogo, plataforma, anoLancamento, desenvolvedor);
                id++; // Incrementa o ID do jogo

                break;

            case 2:
                // Excluir jogo
                int idExcluir;
                std::cout << "Digite o ID do jogo que deseja excluir: ";
                std::cin >> idExcluir;
                excluirJogo(idExcluir);
                break;

            case 3:
                // Buscar jogo por nome
                std::cout << "Digite o nome do jogo que deseja buscar: ";
                std::getline(std::cin, nomeJogo);
                buscarJogoPorNome(nomeJogo);
                break;

            case 4:
                // Abrir o arquivo index.html
                char resposta;
                std::cout << "Voce deseja abrir a lista em site? (S/s ou N/n): ";
                std::cin >> resposta;
                std::cin.ignore(); // Limpa o buffer do teclado

                if (resposta == 's' || resposta == 'S') {
                    system("start \"\" \"C:/Users/Giovani/Documents/Programming/Projeto Lucilena/dotexe/output/index.html\""); //TODO mudar o caminho para o usuario
                } else if (resposta == 'n' || resposta == 'N') {
                    std::cout << "Operacao cancelada." << std::endl;
                } else {
                    std::cout << "Resposta invalida. Operacao cancelada." << std::endl;
                }
                break;
            case 5:
                // Sair do programa
                std::cout << "Saindo..." << std::endl;  
                return 0;
            default:
                std::cout << "Opcao invalida. Tente novamente." << std::endl;
        }
    }

    return 0;
}
