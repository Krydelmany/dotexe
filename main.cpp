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
#include <vector>
#include <algorithm>
#include "id_manager.h"
#include "gravar-jogo.h"
#include "excluir-jogo.h"
#include "buscar-jogo.h"
#include "entra-programa.h"
#include "atualizar-jogo.h"

// Escolhemos em não utilizar o namespace std para evitar conflitos de nomes

/**
 * @brief Estrutura para armazenar informações de um jogo.
 */
struct Jogo {
    int id;
    std::string nome;
    std::string genero;
    std::string plataforma;
    std::string anoLancamento;
    std::string desenvolvedor;
};

/**
 * @brief Função para exibir o menu e obter a opção do usuário.
 
 * @return int A opção escolhida pelo usuário.
 */
int exibirMenu() {
    std::cout << "\n=================================" << std::endl;
    std::cout << "    GERENCIADOR DE JOGOS" << std::endl;
    std::cout << "=================================" << std::endl;
    std::cout << "1. Adicionar Novo Jogo" << std::endl;
    std::cout << "2. Excluir Jogo (ID)" << std::endl;
    std::cout << "3. Buscar Jogo (2 opcoes)" << std::endl;
    std::cout << "4. Editar informacoes do jogo" << std::endl;
    std::cout << "4. Abrir Lista de Jogos no Navegador" << std::endl;
    std::cout << "5. Ordenar Jogos por Nome" << std::endl;
    std::cout << "6. Abrir Arquivo de Jogos" << std::endl;
    std::cout << "7. Abrir Lista de Jogos no Navegador" << std::endl;
    std::cout << "8. Sair" << std::endl;
    std::cout << "=================================" << std::endl;
    std::cout << "Escolha uma opcao (1-7): ";
    int opcao;
    std::cin >> opcao;
    std::cin.ignore(); // Limpar buffer
    return opcao;
}

// Função para exibir o submenu de busca
int exibirSubmenuBusca() {
    std::cout << "\n===== Menu de Busca =====" << std::endl;
    std::cout << "1. Buscar por Nome" << std::endl;
    std::cout << "2. Buscar por ID" << std::endl;
    std::cout << "3. Voltar ao Menu Principal" << std::endl;
    std::cout << "Escolha uma opcao (1-3): ";
    int opcao;
    std::cin >> opcao;
    std::cin.ignore(); // Limpar buffer
    return opcao;
}

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
    initializeIdManager(); // Inicializa o gerenciador de IDs
    int opcao;
    std::vector<Jogo> jogos; // Vetor para armazenar os jogos
    Jogo jogo;


    while (true) {
        opcao = exibirMenu();

        switch (opcao) {
            case 1:
                // Adicionar novo jogo
                jogo.id = getNextId();

                if (jogo.id == -1) {
                    std::cerr << "Erro: Nao foi possivel obter o próximo ID. O jogo nao sera adicionado." << std::endl;
                    break;
                }

                std::cout << "Nome do Jogo: ";
                std::getline(std::cin, jogo.nome);

                std::cout << "Genero do Jogo: ";
                std::getline(std::cin, jogo.genero);

                std::cout << "Plataforma (PC, Console, etc.): ";
                std::getline(std::cin, jogo.plataforma);

                std::cout << "Ano de Lançamento: ";
                std::getline(std::cin, jogo.anoLancamento);

                std::cout << "Desenvolvedor: ";
                std::getline(std::cin, jogo.desenvolvedor);

                jogos.push_back(jogo);

                // Chama a função para gravar o jogo no arquivo
                gravarJogo(jogo.id, jogo.nome, jogo.genero, jogo.plataforma, jogo.anoLancamento, jogo.desenvolvedor);
                std::cout << "\nSucesso! O jogo '" << jogo.nome << "' foi adicionado com ID: " << jogo.id << ".\n";
                break;

            case 2:
                // Excluir jogo
                int idExcluir;
                std::cout << "\nDigite o ID do jogo que deseja excluir: ";
                std::cin >> idExcluir;
                excluirJogo(idExcluir);
                break;

            case 3:
                // Submenu de busca
                int opcaoBusca;
                opcaoBusca = exibirSubmenuBusca();

                switch (opcaoBusca) {
                    case 1:
                        // Buscar por nome
                        std::cout << "\nDigite o nome do jogo que deseja buscar: ";
                        std::getline(std::cin, jogo.nome);
                        buscarJogoPorNome(jogo.nome);
                        break;

                    case 2:
                        // Buscar por ID
                        int idBuscar;
                        std::cout << "\nDigite o ID do jogo que deseja buscar: ";
                        std::cin >> idBuscar;
                        buscarJogoPorID(idBuscar);
                        break;

                    case 3:
                        // Voltar ao menu principal
                        std::cout << "Voltando ao menu principal...\n";
                        break;

                    default:
                        std::cerr << "Opcao inválida. Voltando ao menu principal...\n";
                }
                break;

            case 4:
                int idAtualizar;
                std::cout << "Digite o ID do jogo que deseja atualizar: ";
                std::cin >> idAtualizar;
                if (atualizarJogo(idAtualizar)) {
                    std::cout << "Jogo atualizado com sucesso!" << std::endl;
                } else {
                    std::cout << "Não foi possível atualizar o jogo." << std::endl;
                }
                break;
            
            case 5:
                // Ordenar jogos por nome
                std::cout << "Jogos ordenados por nome! (ainda em desenvolvimento)" << std::endl;
                break;

            case 6:
                // Abrir arquivo de jogos
                system("start output/jogos.txt");
                std::cout << "Abrindo arquivo de jogos...\n";
                break;

            case 7:
                // Abrir lista de jogos no navegador
                char resposta;
                std::cout << "\nDeseja abrir a lista de jogos no navegador? (S/s para Sim, N/n para Não): ";
                std::cin >> resposta;
                std::cin.ignore(); // Limpar buffer

                if (resposta == 's' || resposta == 'S') {
                    system("start http://127.0.0.1:5500/output/index.html");
                    std::cout << "Abrindo lista de jogos no navegador...\n";
                } else if (resposta == 'n' || resposta == 'N') {
                    std::cout << "Operação cancelada.\n";
                } else {
                    std::cerr << "Opção inválida. Operação cancelada.\n";
                }
                break;
                
            case 8:
                // Sair do programa
                std::cout << "Saindo do programa. Até logo!\n";
                return 0;

            default:
                std::cerr << "Opcao invalida. Por favor, tente novamente.\n" << std::endl;
        }
    }

    return 0;
}