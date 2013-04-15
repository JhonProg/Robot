#include "src/Headers/escenario.h"
#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

/*
* Construye un escenario con parametros especificos.
* In: numero de filas,columnas y obstaculos.
*/
Escenario::Escenario(int n, int m,int numeroObstaculos){
                         
    srand(time(NULL));
    this->n=n;
    this->m=m;
    this->numeroObstaculos=numeroObstaculos;
    escenario=new int*[n];
    for(int i=0;i<n;i++){
        escenario[i]=new int[m];        
    }   
    reGenerarEscenario();
    
}

/*
* Genera aleatoriamente la posicion de: 
* robot, rio, obstaculos, salida y el puente.
* dentro del escenario. 
*/
void Escenario::reGenerarEscenario()
{
    for(int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            escenario[i][j]=0;
        }
    }
    
    robotX=rand() % (n);
    robotY=rand() % (3);


    escenario[robotX][robotY]=1;

    salidaX=rand() % (n);
    salidaY=m-1;
    escenario[salidaX][m-1]=5;

    int rioy=4+rand() % (m-2-4);
    while(rioy==robotY || rioy==m-1){
        rioy=0+rand() % (m);
    }

    int puentex=0+rand() % (n);


    for(int i=0;i<n;i++){
        if(i==puentex){
            escenario[i][rioy]=3;
        }else{
            escenario[i][rioy]=4;
        }
    }

    int obstaculox= 0;
    int obstaculoy= 0;

    for(int i=0;i<numeroObstaculos;i++){
        obstaculox= rand() % (n) ;
        obstaculoy= rand() % (m) ;
        while(obstaculoy==robotY || obstaculoy==rioy || escenario[obstaculox][obstaculoy]==2 ||
              escenario[obstaculox][obstaculoy+1]==3 || escenario[obstaculox][obstaculoy-1]==3 ||
              escenario[obstaculox][obstaculoy]==5 ){
            obstaculox= rand() % (n) ;
            obstaculoy= rand() % (m) ;
        }
        escenario[obstaculox][obstaculoy]=2;
    }
}

/*
* Imprime el escenario.
*/
void Escenario::imprimirEscenario()
{
    for(int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            cout<<escenario[i][j]<<" ";
        }
        cout<<endl;
    }
}


/*
* Imprime el escenario de forma grafica.
*/
void Escenario::imprimirEscenarioGragico()
{
    for(int i=0;i<n;i++){
            cout<<"\t\t\t";
            for(int j=0;j<m;j++){
                switch (escenario[i][j]) {
                case 0:
                    cout<<" _ ";
                    break;
                case 1:
                    cout<<" R ";
                    break;
                case 2:
                    cout<<" * ";
                    break;
                case 4:
                    cout<<" * ";
                    break;
                case 3:
                    cout<<" _ ";
                    break;
                case 5:
                    cout<<" S ";
                    break;
                case 7:
                    cout<<" R ";
                    break;
                }
            }
            cout<<endl;
        }
}


/*
* Mueve el root a un posicion especifica.
* In: siguiente posicion del robot (x,y)
*/
void Escenario::moverRobot(int x, int y)
{
    escenario[robotX][robotY]=0;
    if(x>=0 && x<n && y>=0 && y<m){
        escenario[x][y]=1;
        robotX=x;
        robotY=y;
    }
}

/*
* Devuelve el contenido de una posicion especifica.
* In: coordenadas x,y
* Out: contenido en x,y
*/
int Escenario::getItem(int x, int y)
{
    if(movimientoIsValid(x,y))
        return escenario[x][y];
    else
        return -1;
}


/*
* Modifica el tamanho del escenario, los obstaculos y regenera uno nuevo.
* In: caracteristicas dl nuevo escenario.
*/
void Escenario::setEscenario(int n, int m,int numeroObstaculos)
{
    delete escenario;
    this->n=n;
    this->m=m;
    this->numeroObstaculos=numeroObstaculos;
    escenario=new int*[n];
    for(int i=0;i<n;i++){
        escenario[i]=new int[m];
    }
    reGenerarEscenario();
}


/*
* Verifica que i,j sea una posicion valida para moverse.
* In: coordenadas i,j.
* Out: valido con valor de verdadero si es posible moverse a i,j
*      valido con valor de falso si no se puede mover a i,j
*/
bool Escenario::movimientoIsValid(int i, int j)
{
    bool valido=false;
    if(i<0 || i>=n || j<0 || j>=m){
        valido=false;
    }else{
        if(escenario[i][j]!=2 && escenario[i][j]!=4){
            valido=true;
        }else{
            valido=false;
        }
    }
    return valido;
}

/*
* Asigna un valor especifico en una coordenadaa especifica.
* In: coordenada x,y y valor para el contnido de x,y
*/
void Escenario::setItem(int x, int y, int valor)
{
    this->escenario[x][y]=valor;
}

/*
* Asigna una nueva matriz al escenario.
* In: escenario con obstaculos, rio, puente.
      posiciones en x,y del robot y de la salida.
*/
void Escenario::setMatrizEscenario(int **escenario,int robotX,int robotY,int salidaX,int salidaY)
{
    this->escenario=escenario;
    this->robotX=robotX;
    this->robotY=robotY;

    this->salidaX=salidaX;
    this->salidaY=salidaY;
}



