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
