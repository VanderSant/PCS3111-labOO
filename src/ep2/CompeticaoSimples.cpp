#include "Competicao.h"
#include "CompeticaoSimples.h"
#include "Equipe.h"
#include "Tabela.h"
#include "TabelaComOrdem .h"
#include "Modalidade.h"

#include <stdexcept>
#include <iostream>
#include <string>

using namespace std;

CompeticaoSimples::CompeticaoSimples(string nome, Equipe** equipes, int quantidade, Modalidade* m) :
    Competicao(nome, equipes, quantidade) {
    this->m = m;

    // Tabela= new TabelaComOrdem(equipes,quantidade);
    // talvez precise;
}

CompeticaoSimples::~CompeticaoSimples() {
    cout<<"Competicao Simples "<<this->getNome()<<" Destruida"<<endl;
}

Tabela* CompeticaoSimples::getTabela() {
    return m->getTabela();
}

void CompeticaoSimples::imprimir() {
    cout<<"COMPETICAO: "<<nome<<endl;
    m->imprimir();
}

Modalidade* CompeticaoSimples::getModalidade() {
    return m;
}
