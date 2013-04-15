#include "src/Headers/estado.h"
/*
* Inicializa un estado.
* In: coordenadas del estado y padre del estado.
*/
Estado::Estado(int x, int y, Estado *padre)
{
    this->x=x;
    this->y=y;
    h=f=g=0;
    this->padre=padre;
}

/*
* Asigna el valor de la heuristicade un estado.
* In: heuristica.
*/
void Estado::setH(int h)
{
    f=h+g;
    this->h=h;
}

/*
* Asigna el valor de paso G de un estado.
* In: valor de paso g.
*/
void Estado::setG(int g)
{
    f=h+g;
    this->g=g;
}


/*
* Obtiene coordenada en X de un estado.
*/
int Estado::getX()
{
    return this->x;
}

/*
* Obtiene coordenada en Y de un estado.
*/
int Estado::getY()
{
    return this->y;
}

/*
* Obtiene la heuritica de un estado.
*/
int Estado::getH()
{
    return this->h;
}

/*
* Obtiene el valor de paso de un estado.
*/
int Estado::getG()
{
    return this->g;
}

/*
* Obtiene el valor de f como suma de h+g de un estado.
*/
int Estado::getF()
{
    return this->f;
}


