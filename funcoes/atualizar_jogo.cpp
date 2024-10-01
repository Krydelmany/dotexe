#include "atualizar_jogo.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

/**
 * @brief Função para atualizar as informações de um jogo pelo ID.
 *
 * Esta função permite modificar as informações de um jogo específico
 * identificado pelo seu ID. O usuário pode escolher qual campo deseja
 * atualizar (nome, gênero, plataforma, ano de lançamento ou desenvolvedor).
 *
 * @param id O ID do jogo a ser atualizado.
 * @return bool Retorna true se a atualização for bem-sucedida, false caso contrário.
 */
bool atualizarJogo(int id)
{
    std::ifstream arquivoEntrada("output/jogos.txt");
    if (!arquivoEntrada.is_open())
    {
        std::cerr << "Erro ao abrir o arquivo de jogos." << std::endl;
        return false;
    }

    std::vector<std::string> linhas;
    std::string linha;
    bool jogoEncontrado = false;
    size_t linhaJogo = 0;

    // Lê todo o arquivo para a memória
    while (std::getline(arquivoEntrada, linha))
    {
        linhas.push_back(linha);
        if (!jogoEncontrado && linha.find("ID: " + std::to_string(id) + ";") == 0)
        {
            jogoEncontrado = true;
            linhaJogo = linhas.size() - 1;
        }
    }
    arquivoEntrada.close();

    if (!jogoEncontrado)
    {
        std::cout << "Jogo com o ID " << id << " nao encontrado." << std::endl;
        return false;
    }

    // Exibe as informações atuais do jogo
    std::cout << "Informacoes atuais do jogo:" << std::endl;
    std::cout << linhas[linhaJogo] << std::endl;

    // Menu de opções para atualização
    std::cout << "\nQual informação voce deseja atualizar?" << std::endl;
    std::cout << "1. Nome" << std::endl;
    std::cout << "2. Genero" << std::endl;
    std::cout << "3. Plataforma" << std::endl;
    std::cout << "4. Ano de Lançamento" << std::endl;
    std::cout << "5. Desenvolvedor" << std::endl;
    std::cout << "Escolha uma opcao (1-5): ";

    int opcao;
    std::cin >> opcao;
    std::cin.ignore(); // Limpa o buffer do teclado

    std::string novoValor;
    std::cout << "Digite o novo valor: ";
    std::getline(std::cin, novoValor);

    // Divide a linha do jogo em partes
    std::vector<std::string> partes;
    std::istringstream iss(linhas[linhaJogo]);
    std::string parte;
    while (std::getline(iss, parte, ';'))
    {
        partes.push_back(parte);
    }

    // Atualiza a parte escolhida
    switch (opcao)
    {
    case 1:
        partes[1] = " Nome: " + novoValor;
        break;
    case 2:
        partes[2] = " Genero: " + novoValor;
        break;
    case 3:
        partes[3] = " Plataforma: " + novoValor;
        break;
    case 4:
        partes[4] = " Ano: " + novoValor;
        break;
    case 5:
        partes[5] = " Desenvolvedor: " + novoValor;
        break;
    default:
        std::cout << "Opcao invalida." << std::endl;
        return false;
    }

    // Reconstrói a linha atualizada
    linhas[linhaJogo] = "";
    for (size_t i = 0; i < partes.size(); ++i)
    {
        linhas[linhaJogo] += partes[i];
        if (i < partes.size() - 1)
            linhas[linhaJogo] += ";";
    }

    // Escreve as informações atualizadas de volta no arquivo
    std::ofstream arquivoSaida("output/jogos.txt");
    if (!arquivoSaida.is_open())
    {
        std::cerr << "Erro ao abrir o arquivo para escrita." << std::endl;
        return false;
    }

    for (const auto &l : linhas)
    {
        arquivoSaida << l << std::endl;
    }
    arquivoSaida.close();

    std::cout << "Jogo atualizado com sucesso!" << std::endl;
    return true;
}