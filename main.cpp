#include "gravar-jogo.h"
#include "excluir-jogo.h"
#include "buscar-jogo.h"
#include "logo.cpp"

int main() {
    setlocale(LC_ALL, "pt_BR.UTF-8");

    int opcao;
    int id = 1;  // Contador de jogos, você pode carregar isso de um arquivo para persistência.
    std::string nomeJogo, generoJogo, plataforma, anoLancamento, desenvolvedor;

    ExibirLogo();

    while (true) {
        // Menu de opções
        std::cout << "\n===== Gerenciador de Jogos =====" << std::endl;
        std::cout << "1. Adicionar Jogo" << std::endl;
        std::cout << "2. Excluir Jogo por ID" << std::endl;
        std::cout << "3. Buscar Jogo por Nome" << std::endl;
        std::cout << "4. Sair" << std::endl;
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
                // Sair do programa
                std::cout << "Saindo..." << std::endl;
                return 0;

            default:
                std::cout << "Opcao invalida. Tente novamente." << std::endl;
        }
    }

    return 0;
}
