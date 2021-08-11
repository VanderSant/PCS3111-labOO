/**
 * @file Equipe.h
 *
 * @author Vanderson Santos <vanderson.santos@usp.br>
 *
 * @date 12/2019
 *
 * @copyright MIT License - Copyright (c) 2021 Vanderson Santos
 */

#ifndef EQUIPE_H
#define EQUIPE_H

#include <iostream>
#include <string>

using namespace std;

class Equipe {
    public:
        Equipe(string nome);
        virtual ~Equipe();
        virtual string getNome();

        virtual void imprimir();

    protected:
        string nome;
};

#endif  // EQUIPE_H
