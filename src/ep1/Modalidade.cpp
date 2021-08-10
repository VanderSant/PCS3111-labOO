#include "Modalidade.h"

Modalidade::Modalidade(string nome, Equipe** participantes, int quantidade)
{
  this->nome=nome;
  this->quantidade=quantidade;
  this->participantes=participantes;
}

Modalidade::~Modalidade()
{
    cout <<"Modalidade "<<this->getNome()<< " Destruido" << endl;
}

string Modalidade::getNome(){
  return this->nome;
}

Equipe** Modalidade::getEquipes(){
  return this->ordem;
}

int Modalidade::getQuantidadeDeEquipes(){
  return this->quantidade();
}

void Modalidade::setResultado(Equipe** ordem){
for(int i=0;i<this->getQuantidadeDeEquipes();i++){
  this->ordem[i]=ordem[i];
}
}

int Modalidade::getPosicao(Equipe* participante){
if (ordem==NULL){
    return -1;
    }

for(int i=0;i<quantidade;i++){
    if((participante->getNome())==(ordem[i])){
        return (i+1);
    }}
 return -1;
}

void Modalidade::imprimir(){
cout<<"Modalidade: "<<this->getNome()<<endl;
cout<<"Participantes:"<<endl;
for(int i=0;i<this->getQuantidadeDeEquipes();i++){
    cout<<ordem[i]->getNome()<<endl;}
}



