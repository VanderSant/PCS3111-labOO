#ifndef TABELA_H
#define TABELA_H
#include "Modalidade.h"

class Tabela {
    private:
        Equipe** participantes[quantidade];
        int pontuacao[quantidade] = {0};
        int quantidade;

    public:
        Tabela(Equipe** participantes, int quantidade);
        ~Tabela();
        void pontuar(Equipe* participante, int pontos);

        int getPontos(Equipe* participante);

        int getPosicao(Equipe* participante);

        void imprimir();
};

#endif  // TABELA_H
