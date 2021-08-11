#include "TabelaComOrdem .h"
#include "Equipe.h"

#ifndef MODALIDADE_H
#define MODALIDADE_H
#include <iostream>
#include <string>

using namespace std;

class Modalidade {
    public:
        Modalidade(string nome, Equipe** participantes, int quantidade);
        virtual ~Modalidade();
        virtual string getNome();

        virtual Equipe** getEquipes();

        virtual int getQuantidadeDeEquipes();

        virtual void setResultado(Equipe** ordem);

        virtual bool temResultado();

        virtual TabelaComOrdem* getTabela();

        virtual void imprimir();

        virtual Equipe** getOrdem();

    protected:
        string nome;
        int quantidade;
        bool ResultadoSetado;
        Equipe** participantes;
        Equipe** ordem;
        TabelaComOrdem* Tabela;
};

#endif  // MODALIDADE_H
