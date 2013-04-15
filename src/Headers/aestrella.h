#ifndef AESTRELLA_H
#define AESTRELLA_H
#include "src/Headers/estado.h"
#include "src/Headers/escenario.h"
#include <vector>
#include <iostream>
#include <math.h>
#include <cstdlib>
#include <set>
#include <time.h>
#include <sys/time.h>
#include <stdio.h>

using namespace std;

/*
* Compara si dos objetos o estado son iguales.
*/
struct Cmp {
    bool operator()( Estado *s1, Estado *s2 ) const {
        if(s1->getF()<=s2->getF()){
            if(s1->getX()!=s2->getX() || s1->getY()!=s2->getY())
                return true;
            else
                return false;
        }else{
            return false;
        }

    }
};

class AEstrella{

private:
    vector <Estado*> listaAbierta;
    vector <Estado*> listaCerrada;
    Estado      *robot;
    Escenario   *mapa;
    Estado *salida;
    void agregarSucesores(Estado *estadoPadre);
    bool comprobarListaCerrada(Estado *estado);
    set <Estado*,Cmp> listaAbierta2;
    set <Estado*,Cmp> listaCerrada2;

public:
    AEstrella(Escenario *mapa);
    AEstrella();
    bool calcularCamino();
    virtual int heuristica(int x, int y);
    void segmentarCamino();
    int numeroDeNodosGenerados(){ return listaAbierta2.size()+listaCerrada2.size(); }
    int numeroDeNodosVisitados(){ return listaCerrada2.size();}

};

#endif 
