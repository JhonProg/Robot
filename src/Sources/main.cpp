#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <vector>
#include "src/Headers/estado.h"
#include "src/Headers/escenario.h"
#include "src/Headers/aestrella.h"
#include "src/Headers/grey.h"
#include <windows.h>


using namespace std;


int n=10;
int m = 10;
int numeroObstaculos = 20;
Escenario *mapa = new Escenario(n,m,numeroObstaculos);

void resolverAEstrella();
void resolverGreedy();
void resolverAmbosMetodos();
void resolverAmbosMetodos();
void modificarEscesario();
void generarEscenario();
void salir();
void menu();

double performancecounter_diff(LARGE_INTEGER *a, LARGE_INTEGER *b)
{
  LARGE_INTEGER freq;
  QueryPerformanceFrequency(&freq);
  return (double)(a->QuadPart - b->QuadPart) / (double)freq.QuadPart;
}



/*
* Resuelve el problema mediante el algoritmo A*.
*/
void resolverAEstrella(){
    cout<<"-------------------------------- METODO DE A * -----------------------------\n\n\n";
    mapa->imprimirEscenarioGragico();
    AEstrella todo(mapa);
    cout<<endl;
    if(!todo.calcularCamino()){
        mapa->imprimirEscenarioGragico();
        cout<<endl<<endl;
        mapa->imprimirEscenario();
        cout<<endl<<endl<<"---------------------------------------"<<endl;
        cout<<"¡¡¡No hay ningun CAMINO posible!!!"<<endl;
        cout<<"---------------------------------------"<<endl<<endl<<endl;
    }else{
        mapa->imprimirEscenarioGragico();
        cout<<endl;
        mapa->imprimirEscenario();
        cout<<endl;
    }
    cout<<"Numero de nodos generados: "<<todo.numeroDeNodosGenerados()<<endl<<"Numero de nodos visitiados: "<<
          todo.numeroDeNodosVisitados()<<endl;
    //cout<<"Contador tiempo: "<<todo.contadorTiempo<<" Unidades "<<endl;
}

/*
* Resuelve el problema mediante el algoritmo voraz o greedy.
*/
void resolverGreedy(){
     cout<<"--------------------------- METODO DE GREEDY --------------------------------\n\n\n";
    mapa->imprimirEscenarioGragico();
    Grey *grey=new Grey(mapa);
    cout<<endl<<endl;
    if(!grey->calcularCamino()){
        mapa->imprimirEscenarioGragico();
        cout<<endl<<endl;
        mapa->imprimirEscenario();
        cout<<endl<<endl<<"---------------------------------------"<<endl;
        cout<<"¡¡¡No hay ningun CAMINO posible!!!"<<endl;
        cout<<"---------------------------------------"<<endl<<endl<<endl;
    }else{
        mapa->imprimirEscenarioGragico();
        cout<<endl;
        mapa->imprimirEscenario();
        cout<<endl;
    }
    cout<<"Numero de nodos generados: "<<grey->numeroDeNodosGenerados()<<endl<<"Numero de nodos visitiados: "<<
          grey->numeroDeNodosVisitados()<<endl;
    //cout<<"Contador tiempo: "<<grey->contadorTiempo<<" Unidades "<<endl<<endl;
}

/*
* Resuelve el problema mediante los algoritmos A* y Greedy
*/
void resolverAmbosMetodos(){
    Escenario *mapa=new Escenario(n,m,numeroObstaculos);
    mapa->imprimirEscenarioGragico();
    AEstrella todo(mapa);
    cout<<endl;    
    if(!todo.calcularCamino()){       
        mapa->imprimirEscenarioGragico();
        cout<<endl<<endl;
        mapa->imprimirEscenario();
        cout<<endl<<endl<<"---------------------------------------"<<endl;
        cout<<"¡¡¡No hay ningun CAMINO posible!!!"<<endl;
        cout<<"---------------------------------------"<<endl<<endl<<endl;
    }else{
        mapa->imprimirEscenarioGragico();
        cout<<endl;
        mapa->imprimirEscenario();
        cout<<endl;
    }
    cout<<"Numero de nodos generados: "<<todo.numeroDeNodosGenerados()<<endl<<"Numero de nodos visitiados: "<<
          todo.numeroDeNodosVisitados()<<endl;

    //cout<<"Contador tiempo: "<<todo.contadorTiempo<<" Unidades "<<endl;


    cout<<"------------------------------------------------------------------------"<<endl<<endl<<endl;

    mapa=new Escenario(n,m,numeroObstaculos);
    mapa->imprimirEscenarioGragico();
    Grey *grey=new Grey(mapa);
    cout<<endl<<endl;

    if(!grey->calcularCamino()){        
        mapa->imprimirEscenarioGragico();
        cout<<endl<<endl;
        mapa->imprimirEscenario();
        cout<<endl<<endl<<"---------------------------------------"<<endl;
        cout<<"¡¡¡No hay ningun CAMINO posible!!!"<<endl;
        cout<<"---------------------------------------"<<endl<<endl<<endl;
    }else{
        mapa->imprimirEscenarioGragico();
        cout<<endl;
        mapa->imprimirEscenario();
        cout<<endl;
    }
    cout<<"Numero de nodos generados: "<<grey->numeroDeNodosGenerados()<<endl<<"Numero de nodos visitiados: "<<
          grey->numeroDeNodosVisitados()<<endl;
    //cout<<"Contador tiempo: "<<grey->contadorTiempo<<" Unidades "<<endl<<endl;
}

/*
* Modifica el escenario del robot con parametros dados por el usuario.
*/
void modificarEscesario(){
     cout<<"Ingrese numero de filas:";
     cin>>n;
     cout<<"Ingrese numero de columnas:";
     cin>>m;
     cout<<"Ingrese numero de obstaculos:";
     cin>>numeroObstaculos;
     mapa=new Escenario(n,m,numeroObstaculos);
     cout<<"\n\n\n\n";
     system("pause");
     system("cls");
}

/*
* Genera un escenario aleatoriamente.
*/
void generarEscenario(){
     mapa->reGenerarEscenario();
}

/*
* Cierra la aplicacion.
*/
void salir(){
     exit(0);     
}


/*
* Muestra las opciones dentro del programa e interactua con el usuario.
*/
void menu(){
     system("COLOR 17");
     int opcion;
     LARGE_INTEGER t_ini, t_fin;
     double secs;
     cout<<"\n\n\n";
     do{
        cout<<"\n\n\n";
        cout<<"||---------------------------------------------------------------------------||\n";
        cout<<"||---------------------------------------------------------------------------||\n";
        cout<<"||             Universidad Distrital Francisco Jose de caldas                ||\n";
        cout<<"||                  Inteligencia artificial (A* - Greedy)                    ||\n";
        cout<<"||---------------------------------------------------------------------------||\n";  
        cout<<"||                                 MENU                                      ||\n";
        cout<<"||---------------------------------------------------------------------------||\n";
        cout<<"||                                                                           ||\n";
        cout<<"||\t\t\t[1]  Resolver por A*.                                ||\n";
        cout<<"||\t\t\t[2]  Resolver por Greedy.                            ||\n";
        cout<<"||\t\t\t[3]  Resolver por ambos.                             ||\n";
        cout<<"||\t\t\t[4]  Modificar escenario.                            ||\n";
        cout<<"||\t\t\t[5]  Autor(es).                                      ||\n";
        cout<<"||\t\t\t[0]  SALIR.                                          ||\n";
        cout<<"||                                                                           ||\n";
        cout<<"||---------------------------------------------------------------------------||\n";
        cout<<"||---------------------------------------------------------------------------||\n";
        cout<<"\tDigite una opcion:";
        cin>>opcion;
        switch(opcion){
               case 1:                   
                    system("cls");
                    QueryPerformanceCounter(&t_ini);
                    resolverAEstrella();
                    QueryPerformanceCounter(&t_fin);
                    secs = performancecounter_diff(&t_fin, &t_ini);
                    generarEscenario();
                    printf("Tiempo: %.16g segundos ", secs );
                    cout<<"\n\n\n\n";
                    system("pause");
                    system("cls");
                    break;
               case 2:
                    system("cls");
                    QueryPerformanceCounter(&t_ini);
                    resolverGreedy();
                    QueryPerformanceCounter(&t_fin);
                    secs = performancecounter_diff(&t_fin, &t_ini);
                    generarEscenario();
                    printf("Tiempo: %.16g segundos ", secs );
                    cout<<"\n\n\n\n";
                    system("pause");
                    system("cls");
                    break;
                    
               case 3:
                    system("cls");
                    resolverAmbosMetodos();
                    generarEscenario();
                    cout<<"\n\n\n\n";
                    system("pause");
                    system("cls");
                    break;
                    
               case 4:
                    system("cls");
                    modificarEscesario();
                    system("cls");
                    break;
                        
               case 5:
                    system("cls");
                    cout<<"||---------------------------------------------------------------------------||\n";
                    cout<<"||            Universidad Distrital Francisco jose de Caldas                 ||\n";
                    cout<<"||                Tecnologia en sistematizacion de datos                     ||\n";
                    cout<<"||                                                                           ||\n";
                    cout<<"|| Este programa fue desarrollado por :                                      ||\n";
                    cout<<"||                                                                           ||\n";
                    cout<<"||   Camilo Antonio Ramirez Morales                                          ||\n";
                    cout<<"||   camilortte@hotmail.com, on twitter @camilortte                          ||\n";
                    cout<<"||   20111078094                                                             ||\n";
                    cout<<"||                                                                           ||\n";
                    cout<<"||   Jhon Fredy Puentes Nuñez                                                ||\n";
                    cout<<"||   jhonpuentes93@hotmail.com, on twitter @jhon_fredy                       ||\n";
                    cout<<"||   20111078092                                                             ||\n";
                    cout<<"||                                                                           ||\n";
                    cout<<"||---------------------------------------------------------------------------||\n";
                    system("pause");
                    break;
                    
               case 0:
                    salir();
                    break;
                    
               default:
                      system("cls");
                      cout<<"ERROR : Opcion No valida..";
                      system("cls");
                      break;
        }
     }while(opcion!=0);
}



int main(){
    menu();
    return 0;
}



