#include "src/Headers/aestrella.h"

using namespace std;

/*
* Inicializa el escenario, el estado del robot y tiempo.
* In: Un escenario.
*/
AEstrella::AEstrella(Escenario *mapa)
{
    robot=NULL;
    this->mapa=mapa;
}

/*
* Inicializa  el estado del robot y crea un escenario por defecto.
*/
AEstrella::AEstrella()
{
    robot=NULL;
    mapa=new Escenario(10,10,10);
}

/*
* Implementacion del algoritmo A* y greedy.
*/
bool AEstrella::calcularCamino(){
    int robotX=mapa->getRobotX();
    int robotY=mapa->getRobotY();
    robot=new Estado(robotX,robotY,NULL);
    robot->setH(heuristica(robotX,robotY));
    robot->setG(10);

    agregarSucesores(robot);

    listaCerrada2.insert(*listaAbierta2.begin());

    int sx=-1;
    int sy=-1;
    while((sx!=mapa->getSalidaX()|| sy!=mapa->getSalidaY()) && listaAbierta2.empty()!=true ){
        Estado *auxiliar=*listaAbierta2.begin();
        listaCerrada2.insert(auxiliar);
        listaAbierta2.erase(listaAbierta2.begin());
        agregarSucesores(auxiliar);
        sx=auxiliar->getX();
        sy=auxiliar->getY();
        salida=auxiliar;        
    }

    segmentarCamino();

    if(listaAbierta2.empty() && (sx!=mapa->getSalidaX()|| sy!=mapa->getSalidaY()) )
        return false;
    else
        return true;
}


/*
* Obtiene la heuristica en un punto con coordenadas x,y en el escenario
* mediante el metodo manhattan. H = 10*(abs(Xactual-Xdestino) + abs(Yactual-Ydestino))
* In: posicion (x,y)
* Out: valor heuristica.
*/
int AEstrella::heuristica(int x, int y)
{
    return 10*(abs(x-mapa->getSalidaX()) + abs(y-mapa->getSalidaY()));
}


/*
* Modifica el escenario para marcar el camino desde la salida 
* hasta el punto de partida. el camino se marca con el numero '7'
*/
void AEstrella::segmentarCamino()
{
    Estado *auxliar=salida;
    while(auxliar!=NULL){
        mapa->setItem(auxliar->getX(),auxliar->getY(),7);
        auxliar=auxliar->getPadre();
    }
}


/*
* Agrega a la lista abiertos los sucesores de un estado, siempre y cuando 
* no se encuentren en la lista cerrados y abiertos.
* In: Un estado.
*/
void AEstrella::agregarSucesores(Estado *estadoPadre){

    int estadoPadreX=estadoPadre->getX();
    int estadoPadreY=estadoPadre->getY();
    Estado *estado;
    for(int i=0;i<4;i++){
        switch (i){
        case 0:
            if(mapa->getItem(estadoPadreX-1,estadoPadreY)!=-1){
                estado=new Estado(estadoPadreX-1,estadoPadreY,estadoPadre);
                estado->setG(10);
                estado->setH(heuristica(estadoPadreX-1,estadoPadreY));
                listaAbierta.push_back(estado);
                if(!comprobarListaCerrada(estado))
                    listaAbierta2.insert(estado);
            }
            break;
        case 1:
            if(mapa->getItem(estadoPadreX,estadoPadreY+1)!=-1){
                estado=new Estado(estadoPadreX,estadoPadreY+1,estadoPadre);
                estado->setG(10);
                estado->setH(heuristica(estadoPadreX,estadoPadreY+1));
                listaAbierta.push_back(estado);
                if(!comprobarListaCerrada(estado))
                    /**/listaAbierta2.insert(estado);
            }
            break;
        case 2:
            if(mapa->getItem(estadoPadreX+1,estadoPadreY)!=-1){
                estado=new Estado(estadoPadreX+1,estadoPadreY,estadoPadre);
                estado->setG(10);
                estado->setH(heuristica(estadoPadreX+1,estadoPadreY));
                listaAbierta.push_back(estado);
                if(!comprobarListaCerrada(estado))
                    /**/listaAbierta2.insert(estado);
            }
            break;
        case 3:
            if(mapa->getItem(estadoPadreX,estadoPadreY-1)!=-1){
                estado=new Estado(estadoPadreX,estadoPadreY-1,estadoPadre);
                estado->setG(10);
                estado->setH(heuristica(estadoPadreX,estadoPadreY-1));
                listaAbierta.push_back(estado);
                if(!comprobarListaCerrada(estado))
                    /**/listaAbierta2.insert(estado);
            }
            break;
        }

    }
}


/*
* Comprueba si un estado esta en la lista cerrada.
* In : Un estado.
* Out: verdadero si esta en la lista.
*      falso si no esta en la lista.
*/
bool AEstrella::comprobarListaCerrada(Estado *estado)
{
    set<Estado*>::iterator it;
    for (it=listaCerrada2.begin(); it!=listaCerrada2.end(); ++it){
        if((*it)->getX()==estado->getX() && (*it)->getY()==estado->getY()){
            return true;
        }
    }
    return false;
}


