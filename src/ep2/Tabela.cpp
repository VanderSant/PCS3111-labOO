/**
 * @file Tabela.cpp
 *
 * @author Vanderson Santos <vanderson.santos@usp.br>
 *
 * @date 12/2019
 *
 * @copyright MIT License - Copyright (c) 2021 Vanderson Santos
 */

#include "Tabela.h"
#include "Equipe.h"

#include <stdexcept>
#include <iostream>
#include <string>

using namespace std;

Tabela::Tabela(Equipe** participantes, int quantidade) {
    if (quantidade < 2) {
        throw new invalid_argument("quantidade menor que 2(modalidadeCPP)");
    }

    this->participantes = participantes;
    this->quantidade = quantidade;
}

Tabela::~Tabela() {
    cout<<"Tabela Destruida"<<endl;
}

int Tabela::getQuantidadeDeEquipes() {
    return quantidade;
}
