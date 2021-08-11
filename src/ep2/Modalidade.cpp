#include "Modalidade.h"
#include "TabelaComOrdem .h"
#include "Equipe.h"

#include <stdexcept>
#include <iostream>
#include <string>

using namespace std;

Modalidade::Modalidade(string nome, Equipe** participantes, int quantidade) {
    if (quantidade < 2) {
        throw new invalid_argument("quantidade menor que 2(modalidadeCPP)");
    }

    this->nome = nome;
    this->participantes = participantes;
    this->quantidade = quantidade;
    ResultadoSetado = false;
    Tabela = new TabelaComOrdem(participantes, quantidade);
}

Modalidade::~Modalidade() {
    cout<<"Modalidade "<<this->getNome()<<" Destruida"<<endl;
    delete Tabela;
}

string Modalidade::getNome() {
    return nome;
}

Equipe** Modalidade::getEquipes() {
    return participantes;
}

int Modalidade::getQuantidadeDeEquipes() {
    return quantidade;
}

void Modalidade::setResultado(Equipe** ordem) {
    this->ordem = ordem;
    this->ResultadoSetado = true;
    Tabela->setResultado(ordem);

    // CONFERIR ESSA FUNÇÂO DEPOIS!!!!!!!!!!!!!!!!!!!
}

bool Modalidade::temResultado() {
    return ResultadoSetado;
}

TabelaComOrdem* Modalidade::getTabela() {
    return Tabela;
}

void Modalidade::imprimir() {
    cout<<"Modalidade: "<<this->getNome()<<endl;
    Tabela->imprimir();
}

Equipe** Modalidade::getOrdem() {
    return ordem;
}
