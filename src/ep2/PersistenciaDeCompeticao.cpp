#include "PersistenciaDeCompeticao.h"

#include "CompeticaoMultimodalidades.h"
#include "TabelaComPontos.h"
#include "Competicao.h"
#include "CompeticaoSimples.h"
#include "Equipe.h"
#include "Tabela.h"
#include "TabelaComOrdem .h"
#include "Modalidade.h"

#pragma once
#include <algorithm>
#include <fstream>

#include <stdexcept>
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>

PersistenciaDeCompeticao::PersistenciaDeCompeticao()
{

}

PersistenciaDeCompeticao::~PersistenciaDeCompeticao()
{
    cout<<"PersistenciaDeCompeticao Destruida"<<endl;
}


Competicao* PersistenciaDeCompeticao::carregar(string arquivo){
    int QuantidadeDeEquipes;
    string nomeEquipe;
    string NomeCompeticao;
    int verificador;
    int QuantidadeDeModalidade;
    string NomeModalidade;
    int SegundoVerificador;
    int QuantidadeDeParticipantesDaModalidade;
    string trash;
    string NomeParaOrdem;

    ifstream persistencia;
    persistencia.open(arquivo);

    if (!persistencia.is_open()) {
		persistencia.close();
		throw new invalid_argument("Arquivo cagado ou inesistente");
	}
    if(persistencia.fail()){
        persistencia.close();
        throw new invalid_argument("arquivo nao encontrado(erro carrefar persistencia de competicao)");
    }

    persistencia>> QuantidadeDeEquipes;
    equipesCompeticao= new Equipe*[QuantidadeDeEquipes];
    for(int a=0;a<QuantidadeDeEquipes;a++){
        persistencia>>nomeEquipe;
        equipesCompeticao[a]=new Equipe(nomeEquipe);}

    persistencia>>NomeCompeticao;
    persistencia>>verificador;
    if(verificador==1){
       CompeticaoMultimodalidades* CompMult=new CompeticaoMultimodalidades(NomeCompeticao,equipesCompeticao,QuantidadeDeEquipes);
       persistencia>>QuantidadeDeModalidade;
       modalidadesCompeticao= new Modalidade*[QuantidadeDeModalidade];
       for(int i=0;i<QuantidadeDeModalidade;i++){
            persistencia>>NomeModalidade;
            modalidadesCompeticao[i]= new Modalidade(NomeModalidade,equipesCompeticao,QuantidadeDeEquipes);
            persistencia>>SegundoVerificador;
            persistencia>>QuantidadeDeParticipantesDaModalidade;
            if(SegundoVerificador==1){
                ordemCM=new Equipe*[QuantidadeDeParticipantesDaModalidade];
                for(int k=0;k<QuantidadeDeParticipantesDaModalidade;k++){
                persistencia>>NomeParaOrdem;
                ordemCM[k]= new Equipe(NomeParaOrdem);}
                modalidadesCompeticao[i]->setResultado(ordemCM);
                modalidadesCompeticao[i]->getTabela()->setResultado(ordemCM);
                ///modalidadesCompeticao[i]->imprimir();
                CompMult->adicionar(modalidadesCompeticao[i]);
            }
            ///
            if(SegundoVerificador==0){
                CompMult->adicionar(modalidadesCompeticao[i]);
                for(int j=0;j<QuantidadeDeParticipantesDaModalidade;j++){
                    persistencia>>trash;}
            }

       }
       return CompMult;
    }
    //
    if(verificador==0){
        persistencia>>NomeModalidade;
        persistencia>> SegundoVerificador;
        persistencia>> QuantidadeDeParticipantesDaModalidade;
        modalidadeCS= new Modalidade(NomeModalidade,equipesCompeticao,QuantidadeDeParticipantesDaModalidade);
        if(SegundoVerificador==1){
            ordemCS=new Equipe*[QuantidadeDeParticipantesDaModalidade];
            for(int i=0;i<QuantidadeDeParticipantesDaModalidade;i++){
                persistencia>> NomeParaOrdem;
                ordemCS[i]= new Equipe(NomeParaOrdem);}
            modalidadeCS->setResultado(ordemCS);
        }
        //
        else{
            for(int i=0;i<QuantidadeDeParticipantesDaModalidade;i++){
                persistencia>>trash;}
        }
        CompeticaoSimples* CompSimp= new CompeticaoSimples(NomeCompeticao,equipesCompeticao,QuantidadeDeEquipes,modalidadeCS);
        return CompSimp;
    }
    persistencia.close();
    throw new invalid_argument("se fudeu gostoso(erro no carregar, possivelmente nos vericadores)");
}

void PersistenciaDeCompeticao::salvar(string arquivo, Competicao* c){
    ofstream persitencia;
    if(persitencia.fail()){
        persitencia.close();
        throw new invalid_argument("nao foi possivel salvar(erro salva da persistenciaDeCompeticao");
    }

    persitencia.open(arquivo,ios_base::app);
    CompeticaoSimples* TesteCompSim= dynamic_cast<CompeticaoSimples*>(c);
    if(TesteCompSim != NULL){
        equipesCS= c->getEquipes();
        modalidadeCS=TesteCompSim->getModalidade();
        persitencia<<c->getQuantidadeDeEquipes()<<endl;
        for(int i=0;i<c->getQuantidadeDeEquipes();i++){
            persitencia<<equipesCS[i]->getNome()<<endl;
        }
        persitencia<<c->getNome()<<"\n"<<0<<endl;
        persitencia<<modalidadeCS->getNome()<<"\n"<<modalidadeCS->temResultado()<<endl;
        persitencia<<modalidadeCS->getQuantidadeDeEquipes()<<endl;
        if(modalidadeCS->temResultado()==true){
            ordemCS=modalidadeCS->getOrdem();
            for(int i=0;i<modalidadeCS->getQuantidadeDeEquipes();i++){
            persitencia<<ordemCS[i]->getNome()<<endl;
        }}
        if(modalidadeCS->temResultado()==false){
            for(int i=0;i<modalidadeCS->getQuantidadeDeEquipes();i++){
            persitencia<<equipesCS[i]->getNome()<<endl;
        }}
        }

        else{
            CompeticaoMultimodalidades* TesteCompMult=dynamic_cast<CompeticaoMultimodalidades*>(c);
            if(TesteCompMult != NULL){
                persitencia<<c->getQuantidadeDeEquipes()<<endl;
                equipesCM=c->getEquipes();
                for(int i=0;i<c->getQuantidadeDeEquipes();i++){
                    persitencia<<equipesCM[i]->getNome()<<endl;}

                modalidadesCM=TesteCompMult->getModalidades();
                persitencia<<c->getNome()<<"\n"<<1<<"\n"<<modalidadesCM->size()<<endl;
                list<Modalidade*>::iterator it=modalidadesCM->begin();
                for(int i=0;i<modalidadesCM->size();i++){
                    persitencia<<(*it)->getNome()<<endl;
                    persitencia<<(*it)->temResultado()<<endl;
                    persitencia<<(*it)->getQuantidadeDeEquipes()<<endl;
                    if((*it)->temResultado()==true){
                        ordemCM=(*it)->getOrdem();
                        for(int i=0;i<(*it)->getQuantidadeDeEquipes();i++){
                            persitencia<<ordemCM[i]->getNome()<<endl;}}

                    if((*it)->temResultado()==false){
                        for(int i=0;i<c->getQuantidadeDeEquipes();i++){
                        persitencia<<equipesCM[i]->getNome()<<endl;}}
                    it++;
                }
            }
        }
        persitencia.close();


}
