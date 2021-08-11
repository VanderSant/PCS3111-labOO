/**
 * @file CompeticaoSimples.h
 *
 * @author Vanderson Santos <vanderson.santos@usp.br>
 *
 * @date 12/2019
 *
 * @copyright MIT License - Copyright (c) 2021 Vanderson Santos
 */

#ifndef COMPETICAOSIMPLES_H
#define COMPETICAOSIMPLES_H

#include "Equipe.h"
#include "Tabela.h"
#include "TabelaComOrdem .h"
#include "Competicao.h"
#include "Modalidade.h"

#include <iostream>
#include <string>

using namespace std;

class CompeticaoSimples :
    public Competicao {
    public:
        CompeticaoSimples(string nome, Equipe** equipes, int quantidade, Modalidade* m);
        virtual ~CompeticaoSimples();

        Tabela* getTabela();

        void imprimir();

        Modalidade* getModalidade();

    protected:
        Modalidade* m;
};

#endif  // COMPETICAOSIMPLES_H
