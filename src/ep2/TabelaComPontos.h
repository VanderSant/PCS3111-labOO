#ifndef TABELACOMPONTOS_H
#define TABELACOMPONTOS_H
#include "Tabela.h"
#include "Equipe.h"

#include <iostream>
#include <string>

using namespace std;

class TabelaComPontos: public Tabela
{
    public:
        TabelaComPontos (Equipe** participantes, int quantidade);
        virtual ~TabelaComPontos();

// funções herdadas da classe abstrata:
        Equipe** getEquipesEmOrdem();
        int getPosicao (Equipe* participante);
        void imprimir();

//funções da tabela com ordem:
        int getPontos (Equipe* participante);
        void pontuar (Equipe* participante, int pontos);

    protected:
        bool ResultadoSetado;
        int* PontuacaoParticipantes;
        Equipe** ordem;

};

#endif // TABELACOMPONTOS_H
