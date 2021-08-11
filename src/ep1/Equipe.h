/**
 * @file Equipe.h
 *
 * @author Vanderson Santos <vanderson.santos@usp.br>
 *
 * @date 10/2019
 *
 * @copyright MIT License - Copyright (c) 2021 Vanderson Santos
 */

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
