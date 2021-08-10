#ifndef PERSISTENCIADECOMPETICAO_H
#define PERSISTENCIADECOMPETICAO_H

#include "CompeticaoMultimodalidades.h"
#include "TabelaComPontos.h"
#include "Competicao.h"
#include "CompeticaoSimples.h"
#include "Equipe.h"
#include "Tabela.h"
#include "TabelaComOrdem .h"
#include "Modalidade.h"

#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;


class PersistenciaDeCompeticao
{
    public:
        PersistenciaDeCompeticao();
        virtual ~PersistenciaDeCompeticao();

        Competicao* carregar(string arquivo);
        void salvar(string arquivo, Competicao* c);

    protected:
        Modalidade* modalidadeCS;
        Equipe** equipesCS;
        Equipe** ordemCS;
        Equipe** equipesCM;
        list<Modalidade*>* modalidadesCM;
        Equipe** ordemCM;
        Modalidade** modalidadesCompeticao;
        Equipe** equipesCompeticao;



};

#endif // PERSISTENCIADECOMPETICAO_H
