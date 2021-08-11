/**
 * @file TabelaComPontos.cpp
 *
 * @author Vanderson Santos <vanderson.santos@usp.br>
 *
 * @date 12/2019
 *
 * @copyright MIT License - Copyright (c) 2021 Vanderson Santos
 */

#include "TabelaComPontos.h"
#include "Equipe.h"

#include <stdexcept>
#include <iostream>
#include <string>

using namespace std;

TabelaComPontos::TabelaComPontos(Equipe** participantes, int quantidade) :
    Tabela(participantes, quantidade) {
    ResultadoSetado = false;
    PontuacaoParticipantes = new int[quantidade];
    ordem = new Equipe*[quantidade];

    for (int i = 0; i < quantidade; i++) {
        PontuacaoParticipantes[i] = 0;
        ordem[i] = NULL;
    }
}

TabelaComPontos::~TabelaComPontos() {
    // cout<<"Tabela com Pontos "<<endl;
}

Equipe** TabelaComPontos::getEquipesEmOrdem() {
    return ordem;
}

int TabelaComPontos::getPosicao(Equipe* participante) {
    if (ResultadoSetado == false) {
        throw new logic_error("Resultado nao setado Tabela Com Pontos");
    }

    int ver = false;
    int posicao = 0;
    int classificacao = 1;

    for (int i = 0; i < quantidade; i++) {
        if (participantes[i] == participante) {
            ver = true;
            posicao = i;
        }
    }

    if (ver == false) {
        throw new invalid_argument("equipe nao e participante(familia tabela)");
    }

    if (ResultadoSetado == true) {
        for (int j = 0; j < quantidade; j++) {
            if (PontuacaoParticipantes[posicao] < PontuacaoParticipantes[j]) {
                classificacao++;
            }
        }

        return classificacao;
    }

    throw new logic_error("ha alguma coisa errada na ordem da Tabela com Pontos(eu acho)");
}

void TabelaComPontos::imprimir() {
    if (ResultadoSetado == false) {
        for (int i = 0; i < quantidade; i++) {
            cout<<participantes[i]->getNome()<<endl;
        }
    } else {
        for (int i = 0; i < quantidade; i++) {
            cout<<getPosicao(ordem[i])<<"o "<<ordem[i]->getNome()<<" ("<<getPontos(ordem[i])<<" pontos)"<<endl;
        }
    }
}

int TabelaComPontos::getPontos(Equipe* participante) {
    for (int i = 0; i < quantidade; i++) {
        if (participantes[i] == participante) {
            return PontuacaoParticipantes[i];
        }
    }

    throw new invalid_argument("participante nao existe(erro getpontos tabela com ponto)");
}

void TabelaComPontos::pontuar(Equipe* participante, int pontos) {
    bool ver = false;
    int posicao = 0;

    for (int i = 0; i < quantidade; i++) {
        if (participantes[i] == participante) {
            PontuacaoParticipantes[i] = PontuacaoParticipantes[i]+pontos;
            ver = true;
            ResultadoSetado = true;
        }
    }

    for (int i = 0; i < quantidade; i++) {
        ordem[i] = NULL;
    }

    for (int i = 0; i < quantidade; i++) {
        posicao = getPosicao(participantes[i])-1;

        while (ordem[posicao] != NULL) {
            posicao++;
        }

        ordem[posicao] = participantes[i];
    }

    if (ver == false) {
        throw new invalid_argument("participante nao existente(erro pontuar da tabela com pontos)");
    }
}
