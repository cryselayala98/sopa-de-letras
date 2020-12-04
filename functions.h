#include <bits/stdc++.h>

using namespace std;

/*
  Funciones del juego
*/

void limpiar_pantalla(){
  system("clear");
}

void imprimir_titulo(){

  //sacado de https://ascii.today/
    string a = " .d88888b                                      dP             dP            dP                              ";
    string b = " 88.    \"\'                                     88             88            88                              ";
    string c = " `Y88888b. .d8888b. 88d888b. .d8888b.    .d888b88 .d8888b.    88 .d8888b. d8888P 88d888b. .d8888b. .d8888b. ";
    string d ="       `8b 88'  `88 88'  `88 88'  `88    88'  `88 88ooood8    88 88ooood8   88   88'  `88 88'  `88 Y8ooooo. ";
    string e = " d8'   .8P 88.  .88 88.  .88 88.  .88    88.  .88 88.  ...    88 88.  ...   88   88       88.  .88       88 ";
    string f ="  Y88888P  `88888P' 88Y888P' `88888P8    `88888P8 `88888P'    dP `88888P'   dP   dP       `88888P8 `88888P' ";
    string g ="                    88                                                                                      ";        
    string h= "                    dP                                                                                      ";
    string i = "                                                                                                            ";
    string j = "                                                                                                              ";

    cout<< endl;
    cout << "\e[0;" << 46 << "m"<< j << "\e[0;0m" << endl;

    cout << "\e[0;" << 46 << "m"<< " " << "\e[0;0m";
    cout << "\e[0;" << 41 << "m"<< i << "\e[0;0m";
    cout << "\e[0;" << 46 << "m"<< " " << "\e[0;0m" << endl;

    cout << "\e[0;" << 46 << "m"<< " " << "\e[0;0m";
    cout << "\e[0;" << 41 << "m"<< a << "\e[0;0m";
    cout << "\e[0;" << 46 << "m"<< " " << "\e[0;0m" << endl;

    cout << "\e[0;" << 46 << "m"<< " " << "\e[0;0m";
    cout << "\e[0;" << 41 << "m"<< b << "\e[0;0m";
    cout << "\e[0;" << 46 << "m"<< " " << "\e[0;0m" << endl;

    cout << "\e[0;" << 46 << "m"<< " " << "\e[0;0m";
    cout << "\e[0;" << 41 << "m"<< c << "\e[0;0m";
    cout << "\e[0;" << 46 << "m"<< " " << "\e[0;0m" << endl;

    cout << "\e[0;" << 46 << "m"<< " " << "\e[0;0m";
    cout << "\e[0;" << 41 << "m"<< d << "\e[0;0m";
    cout << "\e[0;" << 46 << "m"<< " " << "\e[0;0m" << endl;

    cout << "\e[0;" << 46 << "m"<< " " << "\e[0;0m";
    cout << "\e[0;" << 41 << "m"<< e << "\e[0;0m";
    cout << "\e[0;" << 46 << "m"<< " " << "\e[0;0m" << endl;

    cout << "\e[0;" << 46 << "m"<< " " << "\e[0;0m";
    cout << "\e[0;" << 41 << "m"<< f << "\e[0;0m";
    cout << "\e[0;" << 46 << "m"<< " " << "\e[0;0m" << endl;

    cout << "\e[0;" << 46 << "m"<< " " << "\e[0;0m";
    cout << "\e[0;" << 41 << "m"<< g << "\e[0;0m";
    cout << "\e[0;" << 46 << "m"<< " " << "\e[0;0m" << endl;

    cout << "\e[0;" << 46 << "m"<< " " << "\e[0;0m";
    cout << "\e[0;" << 41 << "m"<< h << "\e[0;0m";
    cout << "\e[0;" << 46 << "m"<< " " << "\e[0;0m" << endl;

    cout << "\e[0;" << 46 << "m"<< " " << "\e[0;0m";
    cout << "\e[0;" << 41 << "m"<< i << "\e[0;0m";
    cout << "\e[0;" << 46 << "m"<< " " << "\e[0;0m" << endl;

    cout << "\e[0;" << 46 << "m"<< j << "\e[0;0m" << endl;  
}

//Mostrar el menú en la consola
int presentar_menu_juego(){

  //valor que el usuario escribe para saber que opción desea ejecutar
  int opcion_menu;

    cout << "\e[0;" << 1 << "m"<< "                                            MENU SOPA DE LETRAS" << "\e[0;0m"<< endl;

    cout<< "                    *                                               *"<<endl;

    cout << "\e[0;" << 1 << "m"<< "                                *Digite el numero de la opción que desea hacer*" << "\e[0;0m"<< endl;

    cout << "" << endl;

    cout << "\e[0;" << 41 << "m"<< "[1]" << "\e[0;0m";
    cout << " Mostrar jugadores en orden de edad "<< endl;

    cout << "\e[0;" << 41 << "m"<< "[2]" << "\e[0;0m";
    cout << " Descubrir palabras" << endl;

    cout << "\e[0;" << 41 << "m"<< "[3]" << "\e[0;0m";
    cout << " Mostrar sopa de letras" << endl;

    cout << "\e[0;" << 41 << "m"<< "[4]" << "\e[0;0m";
    cout << " Mostrar respuestas" << endl;

    cout << "\e[0;" << 41 << "m"<< "[5]" << "\e[0;0m";
    cout << " Asignar puntaje a jugadores" << endl;

    cout << "\e[0;" << 41 << "m"<< "[6]" << "\e[0;0m";
    cout << " Presentar clasificación de los jugadores" << endl;

    cout << "\e[0;" << 46 << "m"<< "[0]" << "\e[0;0m";
    cout << " Salir del Juego" << endl;

    cout << endl;

    cin >> opcion_menu;

    return opcion_menu;

}

//Buscar una palabra en sentido vertical, de arriba a abajo
void buscar_sentido_vertical(string palabra_buscar, int fils, int cols, int *posicion_palabra_encontrada, char (*sopa_de_letras)[1000]){

  int tamanio = palabra_buscar.size();

  int fila_1 = -1;
  int columna_1 = -1;
  int fila_2 = -1; 
  int columna_2 = -1;
  int encontrado = 0;


  //de arriba hacia abajo
  for(int i = 0; i < cols; i++){

    //formar una cadena con la columna
    string str = "";
    for(int j = 0; j < fils; j++){
      char c = sopa_de_letras[j][i];
      str = str + c;
    }

    //buscando coincidencias
    //el metodo find permite buscar coincidencias de un string dentro de otro string, retorna un entero con la posición inicial de la primera aparición del string, si la palabra no es encontrada, retorna -1
    int pos_encontrada = str.find(palabra_buscar);

    if(pos_encontrada != -1){
      //coordenadas en caso de que la palabra haya sido encontrada
      fila_1 = pos_encontrada;
      columna_1 = i;
      fila_2 = (pos_encontrada + tamanio) - 1; 
      columna_2 = i;
      encontrado = 1; //vertical

      break;
    }

  }

  if(encontrado != 0){
    posicion_palabra_encontrada[0] = fila_1;
    posicion_palabra_encontrada[1] = columna_1;
    posicion_palabra_encontrada[2] = fila_2;
    posicion_palabra_encontrada[3] = columna_2;

    posicion_palabra_encontrada[4] = encontrado;

    return;
  }
}

//Buscar una palabra en sentido horizontal, de izquierda a derecha
void buscar_sentido_horizontal(string palabra_buscar, int fils, int cols, int *posicion_palabra_encontrada, char (*sopa_de_letras)[1000]){

  int tamanio = palabra_buscar.size();

  int fila_1 = -1;
  int columna_1 = -1;
  int fila_2 = -1; 
  int columna_2 = -1;
  int encontrado = 0;


  //de arriba hacia abajo
  for(int i = 0; i < fils; i++){

    //formar una cadena con la columna
    string str = "";
    for(int j = 0; j < cols; j++){
      char c = sopa_de_letras[i][j];
      str = str + c;
    }

    //buscando coincidencias
    //el metodo find permite buscar coincidencias de un string dentro de otro string, retorna un entero con la posición inicial de la primera aparición del string, si la palabra no es encontrada, retorna -1
    int pos_encontrada = str.find(palabra_buscar);

    if(pos_encontrada != -1){
      //coordenadas en caso de que la palabra haya sido encontrada
      fila_1 = i;
      columna_1 = pos_encontrada;
      fila_2 = i; 
      columna_2 = (pos_encontrada + tamanio) - 1;
      encontrado = 2; //horizontal

      break;
    }

  }

  if(encontrado != 0){
    posicion_palabra_encontrada[0] = fila_1;
    posicion_palabra_encontrada[1] = columna_1;
    posicion_palabra_encontrada[2] = fila_2;
    posicion_palabra_encontrada[3] = columna_2;

    posicion_palabra_encontrada[4] = encontrado;

    return;
  }  
  
}

//Buscar una palabra en sentido diagonal, hacia la derecha y hacia la izquierda, ambas de arriba a abajo
void buscar_sentido_diagonal(string palabra_buscar, int fils, int cols, int *posicion_palabra_encontrada, char (*sopa_de_letras)[1000]){

  
  int tamanio = palabra_buscar.size();

  int fila_1 = -1;
  int columna_1 = -1;
  int fila_2 = -1; 
  int columna_2 = -1;
  int encontrado = 0;


  //Diagonal izquierda a derecha
  //Diagonales que empiezan por la columna 0
  for(int i = fils - 1; i >= 0 ; i--){

    //formar una cadena con la columna
    string str = "";
    //j recorre fila y k columna
    int j; int k = 0;
    for(j = i; j < fils; j++){
      
      if(k >= cols) break;
      char c = sopa_de_letras[j][k];
      str = str + c;
      k++;
    }

    //buscando coincidencias
    int pos_encontrada = str.find(palabra_buscar);

    if(pos_encontrada != -1){
      //coordenadas en caso de que la palabra haya sido encontrada
      fila_1 = i + pos_encontrada;
      columna_1 = pos_encontrada;
      fila_2 = (fila_1 + tamanio) -1; 
      columna_2 = (columna_1 + tamanio) -1;
      encontrado = 3; //diagonal derecha

      break;
    }

  }

  //Diagonales que empiezan por la fila 0
  for(int i = 1; i < cols && encontrado == 0; i++){

    //formar una cadena con la columna
    string str = "";
    //j recorre fila y k columna
    int j; int k = i;
    for(int j = 0; j < fils; j++){
      
      if(k >= cols) break;
      char c = sopa_de_letras[j][k];
      str = str + c;
      k++;

    }

    //buscando coincidencias
    int pos_encontrada = str.find(palabra_buscar);

    if(pos_encontrada != -1){
      //coordenadas en caso de que la palabra haya sido encontrada
      fila_1 = pos_encontrada;
      columna_1 = i + pos_encontrada;
      fila_2 = (fila_1 + tamanio) -1;
      columna_2 = (columna_1 + tamanio) -1; 
      encontrado = 3; //diagonal derecha

      break;
    }

  }


  //Diagonal derecha a izquierda
  //Diagonales que empiezan por la columna cols-1 (la columna final)
  for(int i = fils - 1; i >= 0 ; i--){

    //formar una cadena con la columna
    string str = "";
    //j recorre fila y k columna
    int j; int k = cols-1;
    for(j = i; j < fils; j++){

      if(k < 0 && encontrado != 0) break;

      char c = sopa_de_letras[j][k];
      str = str + c;
       k--;

    }

    //buscando coincidencias
    int pos_encontrada = str.find(palabra_buscar);

    if(pos_encontrada != -1){
      //coordenadas en caso de que la palabra haya sido encontrada
      fila_1 = i + pos_encontrada;
      columna_1 = ((cols-1) - pos_encontrada);
      fila_2 = (fila_1 + tamanio) -1; 
      columna_2 = (columna_1 - tamanio) +1;
      encontrado = 4; //diagonal izquierda

      break;
    }

  }

  //Diagonales que empiezan por la fila fils-2 (la penultima fila)
  for(int i = cols - 2; i >= 0 ; i--){

    //formar una cadena con la columna
    string str = "";
    //j recorre fila y k columna
    int j; int k = i;
    for(j = 0; j < fils; j++){

      if(k < 0 && encontrado != 0) break;

      char c = sopa_de_letras[j][k];
      str = str + c;
      k--;

    }

    //buscando coincidencias
    int pos_encontrada = str.find(palabra_buscar);

    if(pos_encontrada != -1){
      //coordenadas en caso de que la palabra haya sido encontrada
      fila_1 = pos_encontrada;
      columna_1 = i - pos_encontrada; 
      fila_2 = (fila_1 + tamanio) -1; 
      columna_2 = (columna_1 - tamanio)+1;
      encontrado = 4; //diagonal izquierda

      break;
    }

  }

  if(encontrado != 0){
    posicion_palabra_encontrada[0] = fila_1;
    posicion_palabra_encontrada[1] = columna_1;
    posicion_palabra_encontrada[2] = fila_2;
    posicion_palabra_encontrada[3] = columna_2;

    posicion_palabra_encontrada[4] = encontrado;

    return;
  }  
  
}

//Ordenando los jugadores por un valor de ordenamiento (por la edad o el puntaje)
void ordenar_jugadores(int numjug, int (*valores_jugadores)[4], string valor_ordenamiento){
  
  for(int i = 0; i < numjug; i++){
    for(int j = i+1; j < numjug; j++){

      int v = 2; //2 para edad, 3 para puntaje
      if(valor_ordenamiento == "puntaje") v = 3;

      if(valores_jugadores[j][v] < valores_jugadores[i][v]){

        // intercambiar las variables de i y de j
        int id_auxiliar = valores_jugadores[i][0];
        int id = valores_jugadores[i][1];
        int edad_min = valores_jugadores[i][2]; 
        int puntaje = valores_jugadores[i][3];

        valores_jugadores[i][0] = valores_jugadores[j][0];
        valores_jugadores[i][1] = valores_jugadores[j][1];
        valores_jugadores[i][2] = valores_jugadores[j][2];
        valores_jugadores[i][3] = valores_jugadores[j][3];

        valores_jugadores[j][0] = id_auxiliar;
        valores_jugadores[j][1] = id;
        valores_jugadores[j][2] = edad_min;
        valores_jugadores[j][3] = puntaje;
      }
    }
  }
}

//generar espera de 3 segundos
void generar_espera(){
  for(int i = 0; i<500000000; i++){

  }
}

//coloreando la matriz de sopa de letras para imprimirla coloreada
void colorear(int (*sopa_letras_rta)[1000], int *respuesta, int color){

  int fila_inicial = respuesta[0], fila_final = respuesta[2], columna_inicial = respuesta[1], columna_final = respuesta[3];

  if(respuesta[4] == 1){ //sentido vertical

    //la columna siempre será igual, lo que cambia es la fila

    for(int i = fila_inicial; i <= fila_final; i++){
      sopa_letras_rta[i][columna_inicial] = color; // colorear
    }

  }else if(respuesta[4] == 2){ //sentido horizontal

    //la fila siempre será igual, lo que cambia es la columna

    for(int i = columna_inicial; i <= columna_final; i++){
      sopa_letras_rta[fila_inicial][i] = color;  //colorear
    }

  }else if(respuesta[4] == 3){ //sentido diagonal de izquierda a derecha

    int i; int j = columna_inicial;
    for(i = fila_inicial; i <= fila_final; i++){
      sopa_letras_rta[i][j] = color; //colorear
      j++;
    }

  }else{ // sentido diagonal de derecha a izquierda

    int i; int j = columna_inicial;
    for(i = fila_inicial; i <= fila_final; i++){
      sopa_letras_rta[i][j] = color; //colorear
      j--;
    }

  }
}


//imprimir la sopa de letras, si la opción vale 1 imprimirá las palabras encontradas
void imprimir_sopa(char (*sopa_letras_caracteres)[1000], int (*sopa_letras_coloreada)[1000], int opcion, int fils, int cols){

  for(int i = 0; i < fils; i++){

    for(int j = 0; j < 40; j++)cout<< " ";
    for(int j = 0; j < cols; j++){
      if(opcion == 1){
        int color = sopa_letras_coloreada[i][j]; 

        cout << "\e[0;" << color << "m"<< (sopa_letras_caracteres[i][j]) << "\e[0;0m" << " ";
      }else{
        cout<< sopa_letras_caracteres[i][j] << " ";
      }
      
    }
    cout<<endl;
  }

}

/*
puntaje_palabra es un número de 5 dígitos, donde el primer dígito a la izquierda se ignora, y los 4 dígitos pueden ser 0 o 1, cumpliendo ciertas condiciones de acuerdo a la palabra que encontró el jugador y la respuesta correcta:

1 0 0 0 0
  1 1 1 1 

// de izquerda a derecha -> 
// total +=                 +5, +2, +2, +3
// puntaje_palabra       1   1   1   1   1

+5 -> la palabra coincide con la respuesta correcta del juego
+2 -> coincide la posición inicial
+2 -> coincide la posición final
+3 -> coincide la orientación

Esta función extrae esos números y suma el total(si el dígito es 1) para generar el acumulado de puntos para una palabra
Se van a extraer los dígitos de derecha a izquerda usando el operador módulo (%)
1  0  0  0  0
          <-- 
*/
int acumular_puntaje_palabra(int puntaje_palabra){

  int total = 0;

  //extraer ultimo digito de puntaje palabra, por medio del residuo de la división (operador módulo %)
  int c = puntaje_palabra % 10;
  if(c == 1) total += 3; // coincide la orientación
  puntaje_palabra /= 10;

  c = puntaje_palabra % 10;
  if(c == 1) total += 2; // coincide la posición final
  puntaje_palabra /= 10;

  c = puntaje_palabra % 10;
  if(c == 1) total += 2; // coincide la posición inicial
  puntaje_palabra /= 10;

  c = puntaje_palabra % 10;
  if(c == 1) total += 5; // coincide toda la palabra

  return total;
}

//Teniendo la lista con la respuesta correcta del juego, se asignan los puntajes a los jugadores de acuerdo a los datos que ellos tienen para cada palabra encontrada
int asignar_puntajes(int (*respuesta_jugador)[6], int (*mi_respuesta)[5], int numpals){
  
  int total = 0;

  //recorrer cada palabra para comparar la respuesta correcta de las posiciones donde se encuentra la palabra con la de cada jugador
  for(int i = 0; i < numpals; i++){

    //puntaje_alabra almacena las condiciones que cumplen de acuerdo a las condiciones establecidas en el juego. revisar acumular_puntaje_palabra()
    int puntaje_palabra = 10000;

    //si coincide toda la palabra, +5
    //si la posicion inicial y final del jugador es igual a la posición inicial y final de la respuesta correcta
    if(respuesta_jugador[i][0] == mi_respuesta[i][0] && respuesta_jugador[i][1] == mi_respuesta[i][1] && respuesta_jugador[i][2] == mi_respuesta[i][2] && respuesta_jugador[i][3] == mi_respuesta[i][3]){

      puntaje_palabra +=1000;
    }

    //si coincide posición inicial, +2
    // si la posición inicial del jugador es igual a la posición inicial de la respuesta correcta
    if(respuesta_jugador[i][0] == mi_respuesta[i][0] && respuesta_jugador[i][1] == mi_respuesta[i][1]){

      puntaje_palabra +=100;
    }

    //si coincide posición final, +2
    // si la posición final del jugador es igual a la posición final de la respuesta correcta
    if(respuesta_jugador[i][2] == mi_respuesta[i][2] && respuesta_jugador[i][3] == mi_respuesta[i][3]){

      puntaje_palabra +=10;
    }

    //si coincide orientación, +3
    //respuesta_jugador[i][5] almacena la orientación de una palabra encontrada por un jugador
    //mi_respuesta[i][4] almacena la orientación correcta en la que se ha encontrado una palabra en la sopa de letras
    if(respuesta_jugador[i][5] == mi_respuesta[i][4]){

      puntaje_palabra +=1;
    }

    //guardando el puntaje final

    //desmenuzar puntaje_palabra para agregarlo a total
    
    total += acumular_puntaje_palabra(puntaje_palabra);
    respuesta_jugador[i][4] = puntaje_palabra;

  }

  return total;
}

//imprimir la respuesta correcta de posiciones y la orientación donde fué encontrada una palabra
//parametros -> string, arreglo de la respuesta, con las posiciones inicial y final, y la orientación
void imprimir_respuesta_correcta(string palabra, int *respuesta_palabra){
  cout << palabra << ": "<<endl;
  cout << " Orientación: ";

  switch (respuesta_palabra[4]){
  case 1:
    cout << "Vertical" << endl;
    break;
  case 2:
    cout << "Horizontal" << endl;
    break;
  case 3:
    cout << "Diagonal derecha" << endl;
    break; 
  default: //case 4
    cout << "Diagonal izquerda" << endl;
    break;
  }

  cout << " Posición inicial: [" << respuesta_palabra[0] << "," << respuesta_palabra[1] << "]" << endl;

  cout << " Posición final: [" << respuesta_palabra[2] << "," << respuesta_palabra[3] << "]" << endl;

  cout << endl;
}

//imprimir los puntos que fueron acumulados a una palabra encontrada por un jugador, dependiendo de que si las orientaciones, la posición inicial y final de la palabra coinciden
void imprimir_puntaje_palabra( int puntaje_palabra, int *respuesta_correcta, string orientacion){
  
  //revisar comentarios de acumular_puntaje_palabra();
  //extraer ultimo digito de puntaje palabra, por medio del residuo de la división
  int c = puntaje_palabra % 10;

  if(c == 1) cout << "    Coincide la orientación: " << orientacion << ", +3" << endl;
  puntaje_palabra /=10;

  c = puntaje_palabra % 10;

  if(c == 1) cout << "    Coincide la posición final: [" << respuesta_correcta[2] << "," << respuesta_correcta[3]<< "] , +2" << endl;
  puntaje_palabra /=10;

  c = puntaje_palabra % 10;

  if(c == 1) cout << "    Coincide la posición inicial: [" << respuesta_correcta[0] << "," << respuesta_correcta[1]<< "] , +2" << endl;
  puntaje_palabra /=10;

  c = puntaje_palabra % 10;

  if(c == 1) cout << "    Coincide toda la palabra, +5" << endl;
}

//convertir una palabra a minusculas
string convertir_minusculas(string palabra){
  string c= "";
  for(int i = 0; i<palabra.size(); i++) c+= tolower(palabra[i]);

  return c;
}
