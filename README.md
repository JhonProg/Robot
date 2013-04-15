##¿Cómo funciona?

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

##Licencia
This program is free software; you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation; either version 3 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful,but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for more details.
Este proyecto se distribuye bajo la licencia GNU GPL v3. http://www.gnu.org/licenses/gpl-3.0.html


##Autores:
Somos estudiantes de la universidad Distrital Francisco José de Caldas. El proyecto fue un trabajo para la materia de inteligencia artificial.

Copyright (C) 2013-today:
* Camilo Ramírez camilortte@hotmail.com, [@camilortte](https://twitter.com/camilortte) on Twitter.
* Jhon Puentes jhonpuentes93@hotmail.com
