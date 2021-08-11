/**
 * @file Equipe.cpp
 *
 * @author Vanderson Santos <vanderson.santos@usp.br>
 *
 * @date 10/2019
 *
 * @copyright MIT License - Copyright (c) 2021 Vanderson Santos
 */

#include "Equipe.h"

Equipe::Equipe(string nome) {
    this->nome = nome;
}

Equipe::~Equipe() {
    cout <<"Equipe "<<this->getNome()<< " Destruido" << endl;
}

string Equipe::getNome() {
    return this->nome;
}

void Equipe::imprimir() {
    cout<<"Equipe "<<this->getNome()<<endl;
}
