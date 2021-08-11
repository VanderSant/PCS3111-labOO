/**
 * @file TabelaComOrdem.cpp
 *
 * @author Vanderson Santos <vanderson.santos@usp.br>
 *
 * @date 12/2019
 *
 * @copyright MIT License - Copyright (c) 2021 Vanderson Santos
 */

#include "TabelaComOrdem .h"
#include "Equipe.h"

#include <stdexcept>
#include <iostream>
#include <string>

using namespace std;

TabelaComOrdem ::TabelaComOrdem(Equipe** participantes, int quantidade):
    Tabela(participantes,quantidade)
{
    ResultadoSetado=false;
}

TabelaComOrdem ::~TabelaComOrdem ()
{
    //cout<<"Tabela com ordem destruida"<<endl;

}

int TabelaComOrdem::getPosicao(Equipe* participante){
    int ver=false;
    for(int i=0;i<quantidade;i++){
        if(participantes[i]==participante){
            ver=true;
        }
    }
    if(ver==false){
        throw new invalid_argument("equipe nao e participante(familia tabela)");
    }

    if(ResultadoSetado==false){
        throw new logic_error("Resultado nao setado Tabela Com Ordem");
    }

    if(ResultadoSetado==true){
        for(int i=0;i<quantidade;i++){
            if(ordem[i]->getNome()==participante->getNome()){
                return i+1;
            }
        }
    }
    throw new logic_error("ha alguma coisa errada na ordem da Tabela com Ordem(eu acho)");

}

Equipe** TabelaComOrdem::getEquipesEmOrdem(){
   return ordem;
}

void TabelaComOrdem::imprimir(){
    if(ResultadoSetado==false){
        for(int i=0;i<quantidade;i++){
        cout<<participantes[i]->getNome()<<endl;
            }
    }

    else{
        for(int i=0;i<quantidade;i++){
            cout<<i+1<<"o "<< ordem[i]->getNome()<<endl;
        }
    }
}

void TabelaComOrdem::setResultado(Equipe** ordem){
    this->ordem=ordem;
    ResultadoSetado=true;
}





