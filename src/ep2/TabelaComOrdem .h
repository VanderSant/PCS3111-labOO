#ifndef TABELACOMORDEM _H
#define TABELACOMORDEM _H

#include "Tabela.h"
#include "Equipe.h"

#include <iostream>
#include <string>

using namespace std;

class TabelaComOrdem: public Tabela {
    public:
        TabelaComOrdem (Equipe** participantes, int quantidade);
        virtual ~TabelaComOrdem();

        // fun��es herdadas da classe abstrata:
        Equipe** getEquipesEmOrdem();
        int getPosicao (Equipe* participante);
        void imprimir();

        //fun��es da tabela com ordem:
        void setResultado(Equipe** ordem);

    protected:
        bool ResultadoSetado;
        Equipe** ordem;

};

#endif // TABELACOMORDEM _H














