/**
 * @file main.cpp
 *
 * @author Vanderson Santos <vanderson.santos@usp.br>
 *
 * @date 12/2019
 *
 * @copyright MIT License - Copyright (c) 2021 Vanderson Santos
 */

#include "Equipe.h"
#include "Modalidade.h"
#include "Tabela.h"
#include "TabelaComOrdem .h"
#include "TabelaComPontos.h"
#include "Competicao.h"
#include "CompeticaoSimples.h"
#include "CompeticaoMultimodalidades.h"
#include "PersistenciaDeCompeticao.h"

#include <stdexcept>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() {
    try {
        PersistenciaDeCompeticao* PdC = new PersistenciaDeCompeticao();
        char DesejaCarregar;
        char DesejaSalvar;
        cout<<"Deseja carregar uma competicao(s/n)?(s ou n)"<<endl;
        cin >> DesejaCarregar;

        if (DesejaCarregar == 's') {
            string arquivo;
            Competicao* compet;
            cout<<"Digite o nome do arquivo:"<<endl;
            cin>>arquivo;
            compet = PdC->carregar(arquivo);

            if (dynamic_cast<CompeticaoSimples*>(compet) != NULL) {
                CompeticaoSimples* cs = dynamic_cast<CompeticaoSimples*>(compet);
                cs->imprimir();
            } else {
                CompeticaoMultimodalidades* cm = dynamic_cast<CompeticaoMultimodalidades*>(compet);
                cm->imprimir();
            }
        }

        ///
        if (DesejaCarregar == 'n') {
            int quantidade;
            string nomeEquipe;
            string nomeCompeticao;
            char TipoDeCompeticao;
            cout<<"Informe a quantidade de equipes:"<<endl;
            cin>>quantidade;
            Equipe** equipes = new Equipe*[quantidade];

            for (int i = 0; i < quantidade; i++) {
                cout<<"Informe o nome da equipe:"<<endl;
                cin>>nomeEquipe;
                equipes[i] = new Equipe(nomeEquipe);
            }

            cout<<"Informe o nome da competicao: "<<endl;
            cin>>nomeCompeticao;
            cout<<"Competicao simples (s) ou multimodalidades (m):(s/m)"<<endl;
            cin>>TipoDeCompeticao;

            if (TipoDeCompeticao == 's') {
                CompeticaoSimples* cs;
                string nomeModalidade;
                char ResultadoModalidade;
                cout<<"Informe o nome da modalidade:"<<endl;
                cin>>nomeModalidade;
                Modalidade* mod = new Modalidade(nomeModalidade, equipes, quantidade);
                cout<<"Tem resultado (s/n):"<<endl;
                cin>>ResultadoModalidade;

                if (ResultadoModalidade == 's') {
                    int posicao;
                    Equipe** ordem = new Equipe*[quantidade];

                    for (int j = 0; j < quantidade; j++) {
                        cout<<"Informe a posicao da equipe "<<equipes[j]->getNome()<<endl;
                        cin>>posicao;
                        posicao--;
                        ordem[posicao] = equipes[j];
                    }

                    mod->setResultado(ordem);
                }

                cs = new CompeticaoSimples(nomeCompeticao, equipes, quantidade, mod);
                char salvarCompeticao;
                cout<<"Deseja salvar a competicao (s/n)?"<<endl;
                cin>>salvarCompeticao;

                if (salvarCompeticao == 's') {
                    string arquivo;
                    cout<<"Digite o nome do arquivo:"<<endl;
                    cin>>arquivo;
                    PdC->salvar(arquivo, cs);
                }

                cs->imprimir();
            }

            //
            if (TipoDeCompeticao == 'm') {
                CompeticaoMultimodalidades* cm = new CompeticaoMultimodalidades(nomeCompeticao, equipes, quantidade);
                int quantidadeModalidade;
                string nomeModalidade;
                char temResultado;
                Modalidade* mod;
                cout<<"Informe a quantidade de modalidades: "<<endl;
                cin>>quantidadeModalidade;

                for (int j = 0; j < quantidadeModalidade; j++) {
                    cout<<"Informe o nome da modalidade "<<j+1<<":"<<endl;
                    cin>>nomeModalidade;
                    cout<<"Tem resultado (s/n):"<<endl;
                    cin>>temResultado;
                    mod = new Modalidade(nomeModalidade, equipes, quantidade);

                    if (temResultado == 's') {
                        int posicao;
                        Equipe** ordem = new Equipe*[quantidade];

                        for (int k = 0; k < quantidade; k++) {
                            cout<<"Informe a posicao da equipe "<<equipes[k]->getNome()<<endl;
                            cin>>posicao;
                            posicao--;
                            ordem[posicao] = equipes[k];
                        }

                        mod->setResultado(ordem);
                    }

                    cm->adicionar(mod);
                }

                cout<<"Deseja salvar a competicao (s/n)?"<<endl;
                cin>>DesejaSalvar;

                if (DesejaSalvar == 's') {
                    string arquivo;
                    cout<<"Digite o nome do arquivo:"<<endl;
                    cin>>arquivo;
                    PdC->salvar(arquivo, cm);
                }

                cm->imprimir();
            }
        }
    } catch (invalid_argument* e) {
        cout<<"erro: "<<e->what();
        delete e;
    }
    system("pause");
    return 0;
}
