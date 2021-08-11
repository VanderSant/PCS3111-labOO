#ifndef EQUIPE_H
#define EQUIPE_H

#include <iostream>
#include <string>

using namespace std;

class Equipe {
    private:
        string nome;

    public:
        Equipe(string nome);
        ~Equipe();
        string getNome();

        void imprimir();
};

#endif  // EQUIPE_H
