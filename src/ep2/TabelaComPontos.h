/**
 * @file TabelaComPontos.h
 *
 * @author Vanderson Santos <vanderson.santos@usp.br>
 *
 * @date 12/2019
 *
 * @copyright MIT License - Copyright (c) 2021 Vanderson Santos
 */

#ifndef TABELACOMPONTOS_H
#define TABELACOMPONTOS_H
#include "Tabela.h"
#include "Equipe.h"

#include <iostream>
#include <string>

using namespace std;

class TabelaComPontos :
    public Tabela {
    public:
        TabelaComPontos(Equipe** participantes, int quantidade);
        virtual ~TabelaComPontos();

// fun��es herdadas da classe abstrata:
        Equipe** getEquipesEmOrdem();

        int getPosicao(Equipe* participante);

        void imprimir();

// fun��es da tabela com ordem:
        int getPontos(Equipe* participante);

        void pontuar(Equipe* participante, int pontos);

    protected:
        bool ResultadoSetado;
        int* PontuacaoParticipantes;
        Equipe** ordem;
};

#endif  // TABELACOMPONTOS_H
