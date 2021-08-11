/**
 * @file Tabela.h
 *
 * @author Vanderson Santos <vanderson.santos@usp.br>
 *
 * @date 12/2019
 *
 * @copyright MIT License - Copyright (c) 2021 Vanderson Santos
 */

#ifndef TABELA_H
#define TABELA_H
#include "Equipe.h"

#include <iostream>
#include <string>

using namespace std;

class Tabela {
    public:
        Tabela(Equipe** participantes, int quantidade);
        virtual ~Tabela();

        virtual int getPosicao(Equipe* participante) = 0;

        virtual Equipe** getEquipesEmOrdem() = 0;

        virtual int getQuantidadeDeEquipes();

        virtual void imprimir() = 0;

    protected:
        Equipe** participantes;
        int quantidade;
};

#endif  // TABELA_H
