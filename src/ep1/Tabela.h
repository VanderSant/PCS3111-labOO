/**
 * @file Tabela.h
 *
 * @author Vanderson Santos <vanderson.santos@usp.br>
 *
 * @date 10/2019
 *
 * @copyright MIT License - Copyright (c) 2021 Vanderson Santos
 */

#ifndef TABELA_H
#define TABELA_H
#include "Modalidade.h"

class Tabela {
    private:
        Equipe** participantes[quantidade];
        int pontuacao[quantidade] = {0};
        int quantidade;

    public:
        Tabela(Equipe** participantes, int quantidade);
        ~Tabela();
        void pontuar(Equipe* participante, int pontos);

        int getPontos(Equipe* participante);

        int getPosicao(Equipe* participante);

        void imprimir();
};

#endif  // TABELA_H
