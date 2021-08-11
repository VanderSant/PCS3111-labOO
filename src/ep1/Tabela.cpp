/**
 * @file Tabela.cpp
 *
 * @author Vanderson Santos <vanderson.santos@usp.br>
 *
 * @date 10/2019
 *
 * @copyright MIT License - Copyright (c) 2021 Vanderson Santos
 */

#include "Tabela.h"

Tabela::Tabela(Equipe** participantes, int quantidade) {
    this->participantes = participantes;
    this->quantidade = quantidade;
}

Tabela::~Tabela() {
    cout << " Tabela destruido" << endl;
}

void Tabela::pontuar(Equipe* participante, int pontos) {
    for (int i = 0; i < quantidade; i++) {
        if ((participante->getNome()) == (participantes[i]->getNome())) {
            pontuacao[i] = pontuacao[i]+pontos;
        }
    }
}

int Tabela::getPontos(Equipe* participante) {
    for (int i = 0; i < quantidade; i++) {
        if ((participante->getNome()) == (participantes[i]->getNome())) {
            return pontuacao[i];
        }
    }

    return -1;
}

int Tabela::getPosicao(Equipe* participante) {
    int posicao = 1
                  int pontos = getPontos(participante);

    for (int i = 0; i < quantidade; i++) {
        if (pontos < pontuacao[i]) {
            posicao++;
        }
    }

    return posicao;
}

void Tabela::imprimir() {
    for (int i = 0; i < quantidade; i++) {
        cout<<participantes[i]->getNome()<<"-"<<pontuacao[i]<<"pontos ("<<getPosicao(participantes[i])<<")"<<endl;
    }
}
