#include "CompeticaoMultimodalidades.h"
#include "TabelaComPontos.h"
#include "Competicao.h"
#include "CompeticaoSimples.h"
#include "Equipe.h"
#include "Tabela.h"
#include "TabelaComOrdem .h"
#include "Modalidade.h"

#pragma once
#include <algorithm>

#include <stdexcept>
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

vector<int>* CompeticaoMultimodalidades::PontoPosicao = new vector<int>({ 13, 10, 8, 7, 5, 4, 3, 2, 1 });

CompeticaoMultimodalidades::CompeticaoMultimodalidades(string nome, Equipe** equipes, int quantidade) :
    Competicao(nome, equipes, quantidade) {
    Modalidades = new list<Modalidade*>();

    /// cout<<"TAMANHO:"<<CompeticaoMultimodalidades::PontoPosicao->size()<<endl;
    // t1=new TabelaComPontos(equipes,quantidade);
}

CompeticaoMultimodalidades::~CompeticaoMultimodalidades() {
    cout<<"Competicao Multimodalidades "<<nome<<" Destruida"<<endl;

    while (!Modalidades->empty()) {
        Modalidade* mo = Modalidades->front();
        Modalidades->pop_front();
        delete mo;
    }
}

Tabela* CompeticaoMultimodalidades::getTabela() {
    delete t1;
    t1 = new TabelaComPontos(equipes, quantidade);

    list<Modalidade*>::iterator i = Modalidades->begin();
    Equipe** Equipes1;
    TabelaComOrdem* Tabela1;

    while (i != Modalidades->end()) {
        Tabela1 = (*i)->getTabela();

        if ((*i)->temResultado() == 1) {
            Equipes1 = (*i)->getEquipes();

            for (int j = 0; j < quantidade; j++) {
                t1->pontuar(equipes[j], getPontoPorPosicao(Tabela1->getPosicao(equipes[j])));
            }  // CompeticaoMultimodalidades::PontoPosicao->at(Tabela1->getPosicao(Equipes1[j]))
        }

        i++;
    }

    return t1;
}

void CompeticaoMultimodalidades::imprimir() {
    tabelaNecessaria = getTabela();
    cout<<"COMPETICAO MULTIMODALIDADE: "<<this->nome<<endl;
    t1->imprimir();
}

void CompeticaoMultimodalidades::adicionar(Modalidade* m) {
    list<Modalidade*>::iterator i = find(Modalidades->begin(), Modalidades->end(), m);

    if (i != Modalidades->end()) {
        throw new invalid_argument("modalidade ja adicionada(erro adicionar competicao multimodalidades)");
    }

    Modalidades->push_back(m);
}

list<Modalidade*>* CompeticaoMultimodalidades::getModalidades() {
    return Modalidades;
}

void CompeticaoMultimodalidades::setPontuacao(vector<int>* pontos) {
    if (pontos->size() < 3) {
        throw new invalid_argument(
                  "o vector com menos de 3 elementos(erro na sepontuacao da comperticao multimodalidades)");
    } else {
        while (!CompeticaoMultimodalidades::PontoPosicao->empty()) {
            CompeticaoMultimodalidades::PontoPosicao->pop_back();
        }

        for (unsigned int i = 0; i < pontos->size(); i++) {
            CompeticaoMultimodalidades::PontoPosicao->push_back(pontos->at(i));
        }
    }
}

int CompeticaoMultimodalidades::getPontoPorPosicao(int posicao) {
    if (CompeticaoMultimodalidades::PontoPosicao->size() > posicao-1) {
        return CompeticaoMultimodalidades::PontoPosicao->at(posicao-1);
    } else {
        return 0;
    }
}

TabelaComPontos* CompeticaoMultimodalidades::gett1() {
    return t1;
}
