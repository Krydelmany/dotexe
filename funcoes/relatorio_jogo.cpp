#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <set>

// Estrutura para armazenar os dados do jogo
struct Jogo
{
    int id;
    std::string nome;
    std::string genero;
    std::string plataforma;
    std::string anoLancamento;
    std::string desenvolvedor;
};

/**
 * @brief Carrega os jogos do arquivo para um vetor.
 *
 * Esta função lê os dados dos jogos a partir de um arquivo de texto e os armazena em um vetor.
 * Cada linha do arquivo deve conter os dados de um jogo no formato:
 * "ID: <id>; Nome: <nome>; Genero: <genero>; Plataforma: <plataforma>; Ano: <ano>; Desenvolvedor: <desenvolvedor>;"
 *
 * @return Um vetor contendo os jogos carregados do arquivo.
 */
std::vector<Jogo> carregarJogos()
{
    std::vector<Jogo> jogos;
    std::ifstream arquivo("output/jogos.txt");
    if (!arquivo.is_open())
    {
        std::cerr << "Erro ao abrir o arquivo de jogos." << std::endl;
        return jogos;
    }

    std::string linha;
    while (std::getline(arquivo, linha))
    {
        Jogo jogo;
        std::stringstream ss(linha);
        std::string idStr;

        // Remover rótulos e espaços em branco
        if (!std::getline(ss, idStr, ':') || !std::getline(ss, idStr, ';') ||
            !std::getline(ss, jogo.nome, ':') || !std::getline(ss, jogo.nome, ';') ||
            !std::getline(ss, jogo.genero, ':') || !std::getline(ss, jogo.genero, ';') ||
            !std::getline(ss, jogo.plataforma, ':') || !std::getline(ss, jogo.plataforma, ';') ||
            !std::getline(ss, jogo.anoLancamento, ':') || !std::getline(ss, jogo.anoLancamento, ';') ||
            !std::getline(ss, jogo.desenvolvedor, ':') || !std::getline(ss, jogo.desenvolvedor, ';'))
        {
            std::cerr << "Erro ao ler os dados do jogo: " << linha << std::endl;
            continue;
        }

        try
        {
            jogo.id = std::stoi(idStr);
        }
        catch (const std::invalid_argument &e)
        {
            std::cerr << "Erro de conversao ao ler os dados do jogo: " << linha << std::endl;
            continue;
        }

        jogos.push_back(jogo);
    }

    arquivo.close();
    return jogos;
}

/**
 * @brief Gera um relatório de todos os jogos.
 *
 * Esta função carrega os jogos a partir do arquivo, agrupa-os por desenvolvedora, gênero,
 * plataforma e ano de lançamento, e escreve essas informações em um arquivo de relatório.
 */
void gerarRelatorio()
{
    std::vector<Jogo> jogos = carregarJogos();
    std::ofstream relatorio("output/relatorio.txt");
    if (!relatorio.is_open())
    {
        std::cerr << "Erro ao abrir o arquivo de relatorio." << std::endl;
        return;
    }

    // Quantidade de jogos cadastrados
    relatorio << "Quantidade de Jogos Cadastrados: " << jogos.size() << "\n\n";

    // Jogos agrupados por desenvolvedora
    std::map<std::string, std::set<std::string>> jogosPorDesenvolvedora;
    for (const auto &jogo : jogos)
    {
        jogosPorDesenvolvedora[jogo.desenvolvedor].insert(jogo.nome);
    }
    relatorio << "Jogos Agrupados por Desenvolvedora:\n";
    for (const auto &[desenvolvedor, jogos] : jogosPorDesenvolvedora)
    {
        relatorio << "Desenvolvedora: " << desenvolvedor << "\n";
        for (const auto &nome : jogos)
        {
            relatorio << "  - " << nome << "\n";
        }
        relatorio << "\n";
    }

    // Jogos agrupados por gênero
    std::map<std::string, std::set<std::string>> jogosPorGenero;
    for (const auto &jogo : jogos)
    {
        jogosPorGenero[jogo.genero].insert(jogo.nome);
    }
    relatorio << "Jogos Agrupados por Genero:\n";
    for (const auto &[genero, jogos] : jogosPorGenero)
    {
        relatorio << "Genero: " << genero << "\n";
        for (const auto &nome : jogos)
        {
            relatorio << "  - " << nome << "\n";
        }
        relatorio << "\n";
    }

    // Jogos agrupados por plataforma
    std::map<std::string, std::set<std::string>> jogosPorPlataforma;
    for (const auto &jogo : jogos)
    {
        jogosPorPlataforma[jogo.plataforma].insert(jogo.nome);
    }
    relatorio << "Jogos Agrupados por Plataforma:\n";
    for (const auto &[plataforma, jogos] : jogosPorPlataforma)
    {
        relatorio << "Plataforma: " << plataforma << "\n";
        for (const auto &nome : jogos)
        {
            relatorio << "  - " << nome << "\n";
        }
        relatorio << "\n";
    }

    // Jogos agrupados por ano de lançamento
    std::map<std::string, std::set<std::string>> jogosPorAno;
    for (const auto &jogo : jogos)
    {
        jogosPorAno[jogo.anoLancamento].insert(jogo.nome);
    }
    relatorio << "Jogos Agrupados por Ano de Lançamento:\n";
    for (const auto &[ano, jogos] : jogosPorAno)
    {
        relatorio << "Ano: " << ano << "\n";
        for (const auto &nome : jogos)
        {
            relatorio << "  - " << nome << "\n";
        }
        relatorio << "\n";
    }

    relatorio.close();
    std::cout << "Relatorio gerado com sucesso em 'output/relatorio.txt'." << std::endl;
}