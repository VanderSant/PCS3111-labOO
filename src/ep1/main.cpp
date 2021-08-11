#include "Equipe.h"
#include "Modalidade.h"

int main() {
    Equipe* e[10];
    e[0] = new Equipe("FFLCH");
    e[1] = new Equipe("POLI");
    e[2] = new Equipe("FEA");
    e[3] = new Equipe("IAG");
    e[4] = new Equipe("IF");
    e[5] = new Equipe("IME");

    for (int i = 0; i < 6; i++) {
        e[i]->imprimir();
    }

    return 0;
}
