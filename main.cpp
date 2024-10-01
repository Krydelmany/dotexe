/**
 * @file main.cpp
 * @brief Gerenciador de Jogos - Programa para adicionar, excluir, buscar, atualizar e gerar relatórios de jogos.
 *
 * Este programa permite ao usuário gerenciar uma lista de jogos, oferecendo
 * funcionalidades para adicionar novos jogos, excluir jogos existentes por ID,
 * buscar jogos pelo nome ou ID, atualizar informações dos jogos e gerar relatórios.
 * As informações dos jogos são persistidas em arquivos.
 *
 * Funcionalidades:
 * - Adicionar jogo
 * - Excluir jogo
 * - Buscar jogo por nome ou ID
 * - Atualizar informações do jogo
 * - Gerar relatórios
 *
 * @note Este programa não utiliza o namespace std para evitar conflitos de nomes.
 *
 * @version 0.1
 * @date 2024
 * @author Giovani Claro Moraes
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "id_manager.h"
#include "gravar_jogo.h"
#include "excluir_jogo.h"
#include "buscar_jogo.h"
#include "entra_programa.h"
#include "atualizar_jogo.h"
#include "relatorio_jogo.h"
#include "FilaDeProcessamento.h"

/**
 * @brief Funcao para exibir o menu e obter a opcao do usuario.

 * @return int A opcao escolhida pelo usuario.
 */
int exibirMenu()
{
    std::cout << "\n=================================" << std::endl;
    std::cout << "       GERENCIADOR DE JOGOS       " << std::endl;
    std::cout << "=================================" << std::endl;
    std::cout << "1. Adicionar Novo Jogo" << std::endl;
    std::cout << "2. Excluir Jogo (ID)" << std::endl;
    std::cout << "3. Buscar Jogo" << std::endl;
    std::cout << "4. Editar Informacoes do Jogo" << std::endl;
    std::cout << "5. Processar Fila de Jogos" << std::endl;
    std::cout << "6. Abrir Arquivo de Jogos" << std::endl;
    std::cout << "7. Abrir Lista de Jogos no Navegador" << std::endl;
    std::cout << "8. Gerar Relatorio" << std::endl;
    std::cout << "9. Sair" << std::endl;
    std::cout << "=================================" << std::endl;
    std::cout << "Escolha uma opcao (1-9): ";

    int opcao;
    std::cin >> opcao;
    std::cin.ignore(); // Limpar buffer
    return opcao;
}

// Funcao para exibir o submenu de busca
int exibirSubmenuBusca()
{
    std::cout << "\n===== Menu de Busca =====" << std::endl;
    std::cout << "1. Buscar por Nome" << std::endl;
    std::cout << "2. Buscar por ID (Busca Linear)" << std::endl;
    std::cout << "3. Buscar por ID (Busca Binaria)" << std::endl;

    std::cout << "4. Voltar ao Menu Principal" << std::endl;
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
int main()
{
    initializeIdManager(); // Inicializa o gerenciador de IDs
    int opcao;
    std::vector<Jogo> jogos; // Vetor para armazenar os jogos
    Jogo jogo;
    FilaDeProcessamento fila; // Instância da Fila de Processamento

    while (true)
    {
        opcao = exibirMenu();

        switch (opcao)
        {
        case 1:
        {
            // Adicionar novo jogo
            jogo.id = getNextId();
            if (jogo.id == -1)
            {
                std::cerr << "Erro: Nao foi possivel obter o proximo ID. O jogo nao sera adicionado." << std::endl;
                break;
            }

            std::cout << "Nome do Jogo: ";
            std::getline(std::cin, jogo.nome);

            std::cout << "Genero do Jogo: ";
            std::getline(std::cin, jogo.genero);

            std::cout << "Plataforma (PC, Console, etc.): ";
            std::getline(std::cin, jogo.plataforma);

            std::cout << "Ano de Lancamento: ";
            std::getline(std::cin, jogo.anoLancamento);

            std::cout << "Desenvolvedor: ";
            std::getline(std::cin, jogo.desenvolvedor);

            jogos.push_back(jogo);
            fila.adicionarJogo(jogo);

            gravarJogo(jogo.id, jogo.nome, jogo.genero, jogo.plataforma, jogo.anoLancamento, jogo.desenvolvedor);
            std::cout << "\nSucesso! O jogo '" << jogo.nome << "' foi adicionado com ID: " << jogo.id << ".\n";
            break;
        }
        case 2:
        {
            // Excluir jogo
            int idExcluir;
            std::cout << "\nDigite o ID do jogo que deseja excluir: ";
            std::cin >> idExcluir;
            excluirJogo(idExcluir);
            break;
        }
        case 3:
        {
            // Submenu de busca
            int opcaoBusca = exibirSubmenuBusca();
            switch (opcaoBusca)
            {
            case 1:
            {
                // Buscar por nome
                std::cout << "\nDigite o nome do jogo que deseja buscar: ";
                std::cin.ignore();
                std::getline(std::cin, jogo.nome);
                buscarJogoPorNome(jogo.nome);
                break;
            }
            case 2:
            {
                // Buscar por ID
                int idBuscar;
                std::cout << "\nDigite o ID do jogo que deseja buscar: ";
                std::cin >> idBuscar;
                buscarJogoPorIDLinear(idBuscar);
                break;
            }
            case 3:
            {
                // Buscar por ID (Busca Binária)
                int idBuscar;
                std::cout << "\nDigite o ID do jogo que deseja buscar (Busca Binaria): ";
                std::cin >> idBuscar;
                buscarJogoPorIDBinario(idBuscar);
                break;
            }
            case 4:
                std::cout << "Voltando ao menu principal...\n";
                break;
            default:
                std::cerr << "Opcao invalida. Voltando ao menu principal...\n";
            }
            break;
        }
        case 4:
        {
            // Editar informacoes do jogo
            int idAtualizar;
            std::cout << "Digite o ID do jogo que deseja atualizar: ";
            std::cin >> idAtualizar;
            if (atualizarJogo(idAtualizar))
            {
                std::cout << "Jogo atualizado com sucesso!" << std::endl;
            }
            else
            {
                std::cout << "Nao foi possivel atualizar o jogo." << std::endl;
            }
            break;
        }
        case 5:
            // Processar fila de jogos
            std::cout << "Processando fila de jogos...\n";
            fila.processarFila();
            break;
        case 6:
            // Abrir arquivo de jogos
            system("start output/jogos.txt");
            std::cout << "Abrindo arquivo de jogos...\n";
            break;
        case 7:
        {
            // Abrir lista de jogos no navegador
            char resposta;
            std::cout << "\nDeseja abrir a lista de jogos no navegador? (S/s para Sim, N/n para Nao): ";
            std::cin >> resposta;
            std::cin.ignore(); // Limpar buffer

            if (resposta == 's' || resposta == 'S')
            {
                system("start http://127.0.0.1:5500/output/index.html");
                std::cout << "Abrindo lista de jogos no navegador...\n";
            }
            else if (resposta == 'n' || resposta == 'N')
            {
                std::cout << "Operacao cancelada.\n";
            }
            else
            {
                std::cerr << "Opcao invalida. Operacao cancelada.\n";
            }
            break;
        }
        case 8:
            // Gerar relatorio
            gerarRelatorio();
            break;
        case 9:
            // Sair do programa
            std::cout << "Saindo do programa. Ate logo!\n";
            return 0;
        default:
            std::cerr << "Opcao invalida. Por favor, tente novamente.\n"
                      << std::endl;
        }
    }

    return 0;
}