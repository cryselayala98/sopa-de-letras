//version del proyecto sin utilizar variables en el main
#include <bits/stdc++.h>
#include "functions.h"

using namespace std;


int main() {

  const int MAX_FILS = 1000;
  const int MAX_COLS = 1000;

  const int fils = 16;
  const int cols = 15;
  const int numpals = 10;
  const int numjug = 5;

  //permitir caracteres especiales
  setlocale(LC_ALL,"");

  /* 
    Estructura que contiene la información de la sopa de letras
  */
  struct sopa
  {
    string tema_juego;
    char sopa_letras [MAX_FILS][MAX_COLS];
    string palabras_buscar[numpals];
  };

  /*
    Estructura que contiene la respuesta de una palabra encontrada por un jugador
  */
  struct respuesta
  {

    string palabra;
    string orientacion;

    //posicion inicial
    int fila_1, columna_1;

    //posicion final
    int fila_2, columna_2;
  };

  /*
    Estructura que contiene la información del jugador y las palabras que el encontró
  */
  struct jugador
  {
    int id;
    string nombre;
    int edad;
    char genero;

    // Array de las respuestas con las palabras que ha encontrado
    respuesta palabras_encontradas[numpals];

    int puntaje;
  };

  /*Instancias de las estructuras que el profesor va a proporcionar*/

  sopa soup = {
              "CLIMA",
              {
                  {'F', 'L', 'A', 'B', 'O', 'L', 'G', 'F', 'G', 'T', 'Y', 'U', 'O', 'Z', 'A'},
                  {'C', 'Z', 'T', 'N', 'O', 'I', 'C', 'A', 'T', 'P', 'A', 'D', 'A', 'F', 'R'},
                  {'A', 'W', 'M', 'V', 'Y', 'R', 'I', 'C', 'R', 'S', 'S', 'A', 'L', 'V', 'U'},
                  {'L', 'I', 'O', 'T', 'H', 'X', 'O', 'G', 'E', 'I', 'H', 'D', 'R', 'B', 'T'},
                  {'E', 'G', 'S', 'N', 'R', 'D', 'R', 'N', 'W', 'R', 'P', 'I', 'G', 'T', 'A'},
                  {'N', 'W', 'F', 'P', 'O', 'E', 'O', 'D', 'H', 'A', 'A', 'S', 'L', 'U', 'R'},
                  {'T', 'N', 'E', 'D', 'S', 'I', 'S', 'V', 'B', 'U', 'T', 'R', 'A', 'K', 'E'},
                  {'A', 'C', 'R', 'H', 'C', 'A', 'C', 'X', 'D', 'L', 'X', 'E', 'C', 'H', 'P'},
                  {'M', 'L', 'A', 'C', 'I', 'E', 'n', 'A', 'X', 'A', 'J', 'V', 'I', 'F', 'M'},
                  {'I', 'I', 'A', 'D', 'E', 'I', 'S', 'J', 'G', 'B', 'V', 'I', 'A', 'D', 'E'},
                  {'E', 'N', 'W', 'F', 'N', 'O', 'F', 'T', 'C', 'I', 'X', 'D', 'R', 'T', 'T'},
                  {'N', 'O', 'C', 'C', 'C', 'U', 'P', 'L', 'M', 'L', 'T', 'O', 'R', 'I', 'Q'},
                  {'T', 'C', 'M', 'D', 'I', 'W', 'I', 'F', 'W', 'G', 'R', 'I', 'Y', 'G', 'L'},
                  {'O', 'C', 'I', 'T', 'A', 'M', 'I', 'L', 'C', 'O', 'I', 'B', 'M', 'A', 'C'},
                  {'G', 'L', 'K', 'P', 'A', 'O', 'X', 'I', 'G', 'E', 'N', 'I', 'T', 'O', 'Q'},
                  {'A', 'G', 'U', 'A', 'S', 'E', 'V', 'I', 'D', 'E', 'N', 'C', 'I', 'A', 'S'}
              },
                {"AGUA", "CIENCIA", "EVIDENCIAS", "CALENTAMIENTO", "CLIMA", "ATMOSFERA", "GLACIAR", "TCKA", "SDGUE", "NMIE"}
              };

  jugador jugs[numjug] = {

      {
        200, "Lula", 12, 'F', 
        {
          {"AGUA", "Horizontal", 14, 0, 15, 2}, 
          {"CIENCIA", "Vertical", 7, 4, 12, 4}, 
          {"EVIDENCIAS", "Horizontal", 15, 5, 15, 15},
          {"CALENTAMIENTO", "Vertical", 1, 0, 13, 0}, 
          {"CLIMA", "Diagonal Izquierda", 10, 8, 14, 4}, 
          {"", "", -1, -1, -1, -1}, 
          {"", "", -1, -1, -1, -1},
          {"", "", -1, -1, -1, -1},
          {"", "", -1, -1, -1, -1},
          {"", "", -1, -1, -1, -1}
        }, 
        0
      },

      {
        400, "Mary", 13, 'F', 
        {
          {"AGUA", "Horizontal", 15, 0, 15, 3}, 
          {"CIENCIA", "Vertical", 7, 4, 12, 4}, 
          {"EVIDENCIAS", "Horizontal", 15, 5, 15, 15}, 
          {"CALENTAMIENTO", "Vertical", 1, 0, 13, 0}, 
          {"", "", -1, -1, -1, -1}, 
          {"", "", -1, -1, -1, -1}, 
          {"", "", -1, -1, -1, -1},
          {"", "", -1, -1, -1, -1},
          {"", "", -1, -1, -1, -1},
          {"", "", -1, -1, -1, -1}
        }, 
        0
      },
      
      {
        600, "Tomy", 11, 'M', 
        {
          {"AGUA", "Horizontal", 15, 0, 15, 3}, 
          {"CIENCIA", "Vertical", 7, 4, 12, 4}, 
          {"EVIDENCIAS", "Horizontal", 15, 5, 15, 15}, 
          {"CALENTAMIENTO", "Vertical", 1, 0, 13, 0}, 
          {"CLIMA", "Diagonal Izquierda", 10, 8, 14, 4}, 
          {"ATMOSFERA", "Vertical", 0, 2, 8, 2}, 
          {"GLACIAR", "Vertical", 4, 12, 10, 12},
          {"", "", -1, -1, -1, -1},
          {"", "", -1, -1, -1, -1},
          {"", "", -1, -1, -1, -1}
        }, 
        0
      },

      {
        800, "Peter", 12, 'M', 
        {
          {"", "", -1, -1, -1, -1}, 
          {"CIENCIA", "Vertical", 7, 4, 12, 4}, 
          {"EVIDENCIAS", "Horizontal", 15, 5, 15, 15}, 
          {"CALENTAMIENTO", "Vertical", 1, 0, 13, 0}, 
          {"", "", -1, -1, -1, -1}, 
          {"", "", -1, -1, -1, -1}, 
          {"", "", -1, -1, -1, -1},
          {"", "", -1, -1, -1, -1},
          {"", "", -1, -1, -1, -1},
          {"", "", -1, -1, -1, -1}
        }, 
        0
      },

      {
        1000, "Luna", 13, 'M', 
        {
          {"AGUA", "Horizontal", 1, 0, 15, 1}, 
          {"CIENCIA", "Vertical", 7, 4, 12, 4}, 
          {"EVIDENCIAS", "Horizontal", 15, 5, 15, 15}, 
          {"CALENTAMIENTO", "Vertical", 1, 0, 13, 0}, 
          {"CLIMA", "Diagonal Izquierda", 10, 8, 14, 4}, 
          {"ATMOSFERA", "Vertical", 0, 2, 8, 1}, 
          {"GLACIAR", "Vertical", 3, 12, 10, 10},
          {"", "", -1, -1, -1, -1},
          {"", "", -1, -1, -1, -1},
          {"", "", -1, -1, -1, -1}
        }, 
        0
      }
    };

    //contiene las respuestas correctas para luego comparar con las respuestas de los jugadores
    //las columnas contienen las coordenadas inicial y final y un índice que guarda la orientación (1 a 4)
    int mi_respuesta[numpals][5];

    //lista de jugadores, palabras, y por cada palabra se encuentran ->(las coordenadas inicial y final, puntaje asociado a esa palabra y orientacion)
    int respuestas_jugadores[numjug][numpals][6];

    //lista de los datos de los jugadores. Las filas corresponden a los jugadores, esto servirá para ordenar los valores y acceder a los demás datos del struct de jugadores usando el id auxiliar
    //columnas -> id auxiliar - id jugador - edad - puntaje
    int valores_jugadores[numjug][4];

    //matriz que indica los índices marcados donde están las palabras encontradas
    int sopa_letras_rta[MAX_FILS][MAX_COLS]= {};

    //inicializar todos los datos en 0, no estpan coloreados
    for(int i = 0; i < fils; i++){
      for(int j = 0; j < cols; j++){
        sopa_letras_rta[i][j] = 0;
      }
    }

    //esto indica cuando la opción 5 haya sido seleccionada
    bool puntaje_generado = false;
    
    //generando la respuesta del juego para después comparar con las respuestas de los jugadores
    
    for(int i = 0; i < numpals; i++){
      string palabra_buscar = soup.palabras_buscar[i];

      //contiene las coordenadas de la palabra, si la encontró y un valor (0 a 4) que indica si ha encontrado la palabra en el sentido a buscar
      int posicion_palabra_encontrada[5];


      posicion_palabra_encontrada[4] = 0; // 0 no se ha encontrado orientacion, 1 vertical, 2 horizontal, 3 diagonal derecha, 4 diagonal izquierda

      buscar_sentido_vertical(palabra_buscar, fils, cols, posicion_palabra_encontrada, soup.sopa_letras);

      if(posicion_palabra_encontrada[4] == 0){
        
        buscar_sentido_horizontal(palabra_buscar, fils, cols, posicion_palabra_encontrada, soup.sopa_letras);

        if(posicion_palabra_encontrada[4] == 0){

          buscar_sentido_diagonal(palabra_buscar, fils, cols, posicion_palabra_encontrada, soup.sopa_letras);
        }
      }

      mi_respuesta[i][0] = posicion_palabra_encontrada[0]; //fila 1
      mi_respuesta[i][1] = posicion_palabra_encontrada[1]; //columna 1
      mi_respuesta[i][2] = posicion_palabra_encontrada[2]; //fila 2
      mi_respuesta[i][3] = posicion_palabra_encontrada[3]; //columna 2
      mi_respuesta[i][4] = posicion_palabra_encontrada[4]; //orientacion (1 vertical, 2 horizontal, 3 diagonal derecha, 4 diagonal izquierda)

      //generando numero aleatorio que servirá para luego imprimir la palabra de un colorcito (rango 40 al 46), en la matriz coloreada de la sopa de letras
      int numero_random = (rand() % (46 + 1 - 40)) + 40;

      //sirve para luego mostrar la sopa de letras coloreada cuando se escoja la opción 3
      colorear(sopa_letras_rta, mi_respuesta[i], numero_random);

    }

    // reasignando los valores de jugs al array de respuestas jugadores
    //revisar los datos de los jugadores y revisar el arreglo de mi_respuesta para asignar puntajes
    for(int i = 0; i<numjug; i++){
      for(int j = 0; j<numpals; j++){
        respuestas_jugadores[i][j][0] = jugs[i].palabras_encontradas[j].fila_1;
        respuestas_jugadores[i][j][1] = jugs[i].palabras_encontradas[j].columna_1;
        respuestas_jugadores[i][j][2] = jugs[i].palabras_encontradas[j].fila_2;
        respuestas_jugadores[i][j][3] = jugs[i].palabras_encontradas[j].columna_2;

        //asignando puntaje inicial 
        respuestas_jugadores[i][j][4] = 0;

        string orientacion = jugs[i].palabras_encontradas[j].orientacion;

        int v_orientacion = 0;
      //  cout << convertir_minusculas(orientacion)<<"nnn"<<endl;
        if(convertir_minusculas(orientacion) == "vertical"){
          v_orientacion = 1;
        } 

        else if(convertir_minusculas(orientacion) == "horizontal"){
          v_orientacion = 2;
        }

        else if(convertir_minusculas(orientacion) == "diagonal derecha"){
          v_orientacion = 3;
        }

        else if(convertir_minusculas(orientacion) == "diagonal izquierda"){
          v_orientacion = 4;
        }

        respuestas_jugadores[i][j][5] = v_orientacion;
      }
    }

    //pasando la info de los jugadores a un array
    for(int i = 0; i < numjug; i++){

      valores_jugadores[i][0] = i; // id auxiliar
      valores_jugadores[i][1] = jugs[i].id;
      valores_jugadores[i][2] = jugs[i].edad;
      valores_jugadores[i][3] = jugs[i].puntaje;
    }

   limpiar_pantalla();
   imprimir_titulo();
   
   while(true){
     int opcion = presentar_menu_juego();
     
     limpiar_pantalla();
     if(opcion!=0) imprimir_titulo();

     if(opcion == 0){

      cout<<"Saliendo del juego..."<<endl;
      generar_espera();
      break;

     }
     else if(opcion == 1){
    
      ordenar_jugadores(numjug, valores_jugadores, "edad");  

      cout << "Jugadores (ordenados por edad):" << endl << endl;    

      for(int i = 0; i < numjug; i++){
        cout << " Jugador " << valores_jugadores[i][1] << ": " << endl;

        int id_auxiliar = valores_jugadores[i][0];
        cout << "  Nombre: " << jugs[id_auxiliar].nombre << endl;

        cout << "  Edad: " << valores_jugadores[i][2] << endl;
        cout << "  Género: " << jugs[id_auxiliar].genero << endl;
        cout << "  Puntaje: " <<  (valores_jugadores[i][3] * -1)  << endl << endl;

      }

     }
     
     else if(opcion == 2){

       //generar las respuestas correctas del juego, ya se hizo anteriormente para no repetir esta funcionalidad varias veces

       cout << endl << "Generando respuesta...."<< endl;
       generar_espera();

     }
     else if(opcion == 3){

       //mostrar la matriz de la sopa de letras
       string mostrando_respuesta = "2";
       
       while(mostrando_respuesta != "0" && mostrando_respuesta != "1"){
         cout << "¿Desea ver la sopa de letras solucionada? 1 para si y 0 para no" <<endl;
         cin >> mostrando_respuesta;
       }

       cout<<endl;

        //c_str(); convertir a array de char
        //atoi-> convertir a entero
        int r = atoi(mostrando_respuesta.c_str());

       imprimir_sopa(soup.sopa_letras, sopa_letras_rta, r, fils, cols);

     }
     else if(opcion == 4){ //mostrar  respuesta correcta, respuesta generada por el programa

      cout << "Tema del juego: " << soup.tema_juego << endl << endl;

      //usar el arreglo mi_respuesta
      for(int i = 0; i<numpals; i++){
        string palabra = soup.palabras_buscar[i];
        imprimir_respuesta_correcta(palabra, mi_respuesta[i]);
      }

     }
     else if(opcion == 5){ //asignar puntaje a jugadores
      
       cout<<"Asignando puntajes a los jugadores..."<<endl;

       //para generar el puntaje 1 sola vez y no repetir operaciones
       if(!puntaje_generado){
        //actualizar el puntaje de la matriz respuestas_jugadores usando el array de mi_respuesta
        int total_puntaje_jugador;
        for(int i = 0; i< numjug; i++){

          // se accede por la id auxiliar, en caso de que los jugadores hayan sido ordenados anteriormente (se haya escogido la opcion 1 o 6)
          int id_auxiliar = valores_jugadores[i][0];

          total_puntaje_jugador =  asignar_puntajes(respuestas_jugadores[id_auxiliar], mi_respuesta, numpals);

          jugs[id_auxiliar].puntaje = valores_jugadores[i][3] = (total_puntaje_jugador * -1); //guardarlo como negativo para ordenarlos de mayor a menor
 
        }

        puntaje_generado = true;
       }

       generar_espera();
       
    }else{ // presentar clasificación de los jugadores, ordenados por puntaje
      
      //revisar si el puntaje aún no ha sido generado
      if(!puntaje_generado){
        //actualizar el puntaje de la matriz respuestas_jugadores usando el array de mi_respuesta

        int total_puntaje_jugador;
        for(int i = 0; i< numjug; i++){

          // se accede por la id auxiliar, en caso de que los jugadores hayan sido ordenados anteriormente (se haya escogido la opcion 1 o 6)
          int id_auxiliar = valores_jugadores[i][0];

          cout<<"jugador "<< jugs[id_auxiliar].nombre<<": "<<endl;

          total_puntaje_jugador =  asignar_puntajes(respuestas_jugadores[id_auxiliar], mi_respuesta, numpals);

          jugs[id_auxiliar].puntaje = valores_jugadores[i][3] = (total_puntaje_jugador * -1 ); //guardarlo como negativo para ordenarlos de mayor a menor
 
        }
       puntaje_generado = true;
       }

       cout << "CLASIFICACIÓN DE LOS JUGADORES: " << endl << endl;

       ordenar_jugadores(numjug, valores_jugadores, "puntaje");

       string opcion = "2";
       while(opcion != "0" && opcion != "1"){
         cout << "¿Desea ver los resultados para cada palabra? presione 1 para [si] y 0 para [no]" << endl;
         cin >> opcion;
       }

      
       for(int i = 0; i < numjug; i++){
          cout << " Jugador " << valores_jugadores[i][1] << ": " << endl;

          int id_auxiliar = valores_jugadores[i][0];
          cout << "  Nombre: " << jugs[id_auxiliar].nombre << endl;

          cout << "  Edad: " << valores_jugadores[i][2] << endl;
          cout << "  Género: " << jugs[id_auxiliar].genero << endl;

          
          cout << "  Puntaje: " << (jugs[id_auxiliar].puntaje * -1) << endl << endl;

          //para el caso que se quieran ver los detalles del puntaje para cada palabra
          if(opcion == "1"){
            //imprimir el puntaje asignado para cada palabra encontrada por el jugador i
            cout << "  Puntaje asociado para cada palabra: " << endl;
            for(int j = 0; j < numpals; j++){
              cout << "   " << soup.palabras_buscar[j] << ": " << endl;

              cout << "    Orientación dada por el jugador: " << jugs[id_auxiliar].palabras_encontradas[j].orientacion << endl;

              cout << "    Posición inicial: [" << jugs[id_auxiliar].palabras_encontradas[j].fila_1 << "," << jugs[id_auxiliar].palabras_encontradas[j].columna_1 << "]"<< endl;

              cout << "    Posición final: [" << jugs[id_auxiliar].palabras_encontradas[j].fila_2 << "," << jugs[id_auxiliar].palabras_encontradas[j].columna_2 << "]"<< endl;

              int puntaje_palabra = respuestas_jugadores[id_auxiliar][j][4];
              imprimir_puntaje_palabra(puntaje_palabra, mi_respuesta[j], jugs[id_auxiliar].palabras_encontradas[j].orientacion);

              cout << "    TOTAL: " << acumular_puntaje_palabra(puntaje_palabra)<<endl; 
              
            }

        } 

        cout << endl << endl;

        }
    }


   }
  

  return 0;
}