#ifndef BUSCAS_VARIADAS_H
#define BUSCAS_VARIADAS_H

#include "../main.h"
#include "../cabecalhos/FilaDeProcessamento.h"

void ordenarJogosPorID(std::vector<Jogo>& jogos);
int buscarJogoPorIDBinario(const std::vector<Jogo>& jogos, int id);

#endif