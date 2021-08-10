#ifndef COMPETICAOMULTIMODALIDADES_H
#define COMPETICAOMULTIMODALIDADES_H

#include "Equipe.h"
#include "Modalidade.h"
#include "Tabela.h"
#include "TabelaComOrdem .h"
#include "TabelaComPontos.h"
#include "Competicao.h"
#include "CompeticaoSimples.h"
#include "CompeticaoMultimodalidades.h"

#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;

class CompeticaoMultimodalidades:public Competicao
{
    public:
        CompeticaoMultimodalidades(string nome, Equipe** equipes, int quantidade);
        virtual ~CompeticaoMultimodalidades();

        Tabela* getTabela();
        void imprimir();

        void adicionar(Modalidade* m);
        list<Modalidade*>* getModalidades();
        static void setPontuacao(vector<int>* pontos);
        static int getPontoPorPosicao(int posicao);
        TabelaComPontos* gett1();


    protected:
        list<Modalidade*>* Modalidades;
        TabelaComPontos* t1;
        Tabela* tabelaNecessaria;
    private:
        static vector<int>* PontoPosicao;
};

#endif // COMPETICAOMULTIMODALIDADES_H
