#ifndef COMPETICAO_H
#define COMPETICAO_H

#include "Equipe.h"
#include "TabelaComOrdem .h"
#include "Modalidade.h"

#include <iostream>
#include <string>

using namespace std;

class Competicao
{
    public:
        Competicao(string nome, Equipe** equipes, int quantidade);
        virtual ~Competicao();

        virtual string getNome();
        virtual Equipe** getEquipes();
        virtual int getQuantidadeDeEquipes();
        virtual Tabela* getTabela()=0;
        virtual void imprimir()=0;

    protected:
        string nome;
        Equipe** equipes;
        int quantidade;
};

#endif // COMPETICAO_H
