/**
 * @file Competicao.cpp
 *
 * @author Vanderson Santos <vanderson.santos@usp.br>
 *
 * @date 12/2019
 *
 * @copyright MIT License - Copyright (c) 2021 Vanderson Santos
 */

#include "Competicao.h"
#include "Equipe.h"
#include "TabelaComOrdem .h"

#include <stdexcept>
#include <iostream>
#include <string>

using namespace std;

Competicao::Competicao(string nome, Equipe** equipes, int quantidade) {
    if (quantidade < 2) {
        throw new invalid_argument("ha menos de duas equipes(erro construtor competicao)");
    }

    this->nome = nome;
    this->equipes = equipes;
    this->quantidade = quantidade;
}

Competicao::~Competicao() {
    cout<<"Competicao "<<this->getNome()<<" Destruida"<<endl;
}

string Competicao::getNome() {
    return nome;
}

Equipe** Competicao::getEquipes() {
    return equipes;
}

int Competicao::getQuantidadeDeEquipes() {
    return quantidade;
}
