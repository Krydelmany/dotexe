/**
 * @brief Função para buscar um jogo com base no nome.
 *
 * Esta função abre um arquivo contendo uma lista de jogos e procura por um jogo cujo nome
 * corresponda (case-insensitive) ao nome fornecido. Se o jogo for encontrado, ele será exibido
 * no console. Caso contrário, uma mensagem de erro será exibida.
 *
 * @param nomeJogo O nome do jogo que deseja buscar.
 */
#include "FilaDeProcessamento.h"
#include "buscar_jogo.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <chrono>

// Função para carregar jogos do arquivo e ordená-los por ID
std::vector<Jogo> carregarJogosOrdenados()
{
    std::ifstream arquivo("output/jogos.txt");
    std::vector<Jogo> jogos;
    std::string linha;
    Jogo jogo;

    if (!arquivo.is_open())
    {
        std::cerr << "Erro ao abrir o arquivo de jogos." << std::endl;
        return jogos;
    }
    while (std::getline(arquivo, linha))
    {
        if (linha.find("ID: ") == 0)
        {
            std::stringstream ss(linha);
            std::string temp;
            ss >> temp >> jogo.id; // Extrai o ID

            std::getline(arquivo, linha);
            jogo.nome = linha;
            std::getline(arquivo, linha);
            jogo.genero = linha;
            std::getline(arquivo, linha);
            jogo.plataforma = linha;
            std::getline(arquivo, linha);
            jogo.anoLancamento = linha;
            std::getline(arquivo, linha);
            jogo.desenvolvedor = linha;

            jogos.push_back(jogo);
        }
    }
    // Ordena os jogos pelo ID
    std::sort(jogos.begin(), jogos.end(), [](const Jogo &a, const Jogo &b)
              { return a.id < b.id; });

    return jogos;
}

/**
 * @brief Função para buscar um jogo pelo nome.
 *
 * Esta função realiza uma busca linear no arquivo de jogos para encontrar
 * jogos que contenham o nome especificado. A busca linear percorre todas as linhas
 * do arquivo e verifica se o nome do jogo está presente em cada linha.
 *
 * @param nome O nome do jogo que deseja buscar.
 */
void buscarJogoPorNome(const std::string &nomeJogo)
{
    std::ifstream arquivo("output/jogos.txt"); // Arquivo com a lista de jogos
    std::string linha;
    bool jogoEncontrado = false;

    if (!arquivo.is_open())
    {
        std::cerr << "Erro ao abrir o arquivo!" << std::endl;
        return;
    }

    // Lê o arquivo linha por linha
    while (std::getline(arquivo, linha))
    {
        // Converte para letras minúsculas para garantir uma busca case-insensitive
        std::string linhaLower = linha;
        std::string nomeJogoLower = nomeJogo;

        std::transform(linhaLower.begin(), linhaLower.end(), linhaLower.begin(), ::tolower);
        std::transform(nomeJogoLower.begin(), nomeJogoLower.end(), nomeJogoLower.begin(), ::tolower);

        // Verifica se o nome do jogo está contido na linha
        if (linhaLower.find(nomeJogoLower) != std::string::npos)
        {
            std::cout << "Jogo encontrado: " << linha << std::endl;
            jogoEncontrado = true;
        }
    }

    if (!jogoEncontrado)
    {
        std::cerr << "Jogo com nome '" << nomeJogo << "' nao encontrado!" << std::endl;
    }

    arquivo.close();
}

/**
 * @brief Função para buscar um jogo pelo ID utilizando busca binária.
 *
 * Esta função carrega os jogos de um arquivo, os ordena por ID e realiza uma
 * busca binária para encontrar o jogo correspondente ao ID fornecido.
 *
 * @param id O ID do jogo que deseja buscar.
 */
void buscarJogoPorIDBinario(int id)
{
    // Medir o tempo de execução
    auto start = std::chrono::high_resolution_clock::now();

    // Carrega e ordena os jogos
    std::vector<Jogo> jogos = carregarJogosOrdenados();

    // Verificar se há jogos disponíveis
    if (jogos.empty())
    {
        std::cerr << "Nenhum jogo encontrado no arquivo." << std::endl;
        return;
    }

    int esquerda = 0;
    int direita = jogos.size() - 1;
    bool encontrado = false;

    // Loop de busca binária
    while (esquerda <= direita)
    {
        int meio = esquerda + (direita - esquerda) / 2;

        // Verificar se o jogo do meio é o que estamos procurando
        if (jogos[meio].id == id)
        {
            // Jogo encontrado, exibir os detalhes
            std::cout << "\nJogo encontrado: " << std::endl;
            std::cout << "ID: " << jogos[meio].id << std::endl;
            std::cout << "Nome: " << jogos[meio].nome << std::endl;
            std::cout << "Genero: " << jogos[meio].genero << std::endl;
            std::cout << "Plataforma: " << jogos[meio].plataforma << std::endl;
            std::cout << "Ano de Lançamento: " << jogos[meio].anoLancamento << std::endl;
            std::cout << "Desenvolvedor: " << jogos[meio].desenvolvedor << std::endl;
            encontrado = true;
            break;
        }

        // Se o ID do meio for menor que o ID procurado, mover para a direita
        if (jogos[meio].id < id)
        {
            esquerda = meio + 1;
        }
        else
        {
            // Se o ID do meio for maior, mover para a esquerda
            direita = meio - 1;
        }
    }

    // Se o jogo não foi encontrado
    if (!encontrado)
    {
        std::cout << "Jogo com o ID '" << id << "' nao encontrado." << std::endl;
    }

    // Medir o tempo de execução
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    std::cout << "Tempo de execucao da busca binaria: " << duration.count() << " segundos." << std::endl;
}

/**
 * @brief Função para buscar um jogo pelo ID.
 *
 * Esta função realiza uma busca linear no arquivo de jogos para encontrar
 * o jogo com o ID especificado. A busca linear percorre todas as linhas
 * do arquivo até encontrar o ID desejado ou até chegar ao final do arquivo.
 *
 * @param id O ID do jogo que deseja buscar.
 */
void buscarJogoPorIDLinear(int id)
{
    auto start = std::chrono::high_resolution_clock::now();

    std::ifstream arquivo("output/jogos.txt");
    if (!arquivo.is_open())
    {
        std::cerr << "Erro ao abrir o arquivo de jogos." << std::endl;
        return;
    }

    std::string linha;
    bool encontrado = false;
    std::string idStr = "ID: " + std::to_string(id);

    while (std::getline(arquivo, linha))
    {
        // Verifica se a linha começa exatamente com o ID procurado
        if (linha.find(idStr) == 0)
        {
            std::cout << "\nJogo encontrado: " << std::endl;
            std::cout << linha << std::endl;

            // Exibir as próximas linhas (informações do jogo) até encontrar uma linha que comece com "ID: " ou o final do arquivo
            while (std::getline(arquivo, linha))
            {
                if (linha.find("ID: ") == 0)
                {
                    break;
                }
                std::cout << linha << std::endl;
            }

            encontrado = true;
            break;
        }
    }

    if (!encontrado)
    {
        std::cout << "Jogo com o ID '" << id << "' nao encontrado." << std::endl;
    }

    arquivo.close();

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    std::cout << "Tempo de execucao da busca linear: " << duration.count() << " segundos." << std::endl;
}