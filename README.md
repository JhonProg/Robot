##¿Como funciona?

Se usó el algoritmo de búsqueda heurística A*; Se explicará brevemente.

1. Tomar el nodo inicial y asignarlo a nodoAuxiliar.
2. Realizar mientras la lista abierta no este vacía o mientras no se llegue a el objetivo.
  1. Enviar nodoAuxiliar a la lista cerrada.
  2. Descomponer sus nodos adyacentes. Para cada nodo adyacente enviarlo a la lista abierta si y sólo si no se encuentra en esta misma y tampoco en la lista cerrada.
  3. Almacenar en nodoAuxiliar ladirecciónn del padre.
  4. Asignar a nodoAuxiliar el menor de la lista abierta.
3. Medición del tiempo: (solo funcionó llamando una funcion, es decir el metodo que se reliza por los dos metodos no funciona)
  ```c++
      #include <stdio.h>
      #include <windows.h>
      
      /* retorna "a - b" en segundos */
      double performancecounter_diff(LARGE_INTEGER *a, LARGE_INTEGER *b)
      {
        LARGE_INTEGER freq;
        QueryPerformanceFrequency(&freq);
        return (double)(a->QuadPart - b->QuadPart) / (double)freq.QuadPart;
      }
      
      int main(int argc, char *argv[])
      {
        LARGE_INTEGER t_ini, t_fin;
        double secs;
      
        QueryPerformanceCounter(&t_ini);
        /* ...hacer algo... */
        QueryPerformanceCounter(&t_fin);
      
        secs = performancecounter_diff(&t_fin, &t_ini);
        printf("%.16g milliseconds\n", secs * 1000.0);
        return 0;
      }
  ```



##Autores:
Somos estudiantes de la universidad Distrital Francisco José de Caldas. El proyecto fue un trabajo para la materia de inteligencia artificial.

Copyright (C) 2013-today:
* Camilo Ramírez camilortte@hotmail.com, [@camilortte](https://twitter.com/camilortte) on Twitter.
* Jhon Puentes jhonpuentes93@hotmail.com
