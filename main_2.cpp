#include <iostream>
using namespace std;

struct sopa
{
  string tema_juego;
  char sopa_letras[25][25];
  string palabras_buscar[100];
};

struct respuesta
{

  string palabra;
  string orientacion;
  int fila_1, columna_1;
  int fila_2, columna_2;
};

struct jugador
{
  int id;
  string nombre;
  int edad;
  char genero;
  respuesta palabras_encontradas[25];
  int puntaje;
};

void imprimir_titulo()
{
  cout << "SOPA DE LETRAS" << endl;
}

string convertir_minusculas(string palabra)
{
  string c = "";
  for (int i = 0; i < palabra.size(); i++)
    c += tolower(palabra[i]);
  return c;
}

int presentar_menu_juego()
{
  int opcion_menu;
  cout << "MENU SOPA DE LETRAS" << endl;
  cout << endl;
  cout << "Digite el numero de la opción que desea hacer" << endl;
  cout << endl;
  cout << "[1] Mostrar jugadores en orden de edad " << endl;
  cout << "[2] Descubrir palabras" << endl;
  cout << "[3] Mostrar sopa de letras" << endl;
  cout << "[4] Mostrar respuestas" << endl;
  cout << "[5] Asignar puntaje a jugadores" << endl;
  cout << "[6] Presentar clasificación de los jugadores" << endl;
  cout << "[0] Salir del Juego" << endl;
  cout << endl;
  cin >> opcion_menu;
  return opcion_menu;
}

respuesta buscar_palabra(string palabra_buscar, int fils, int cols, sopa soup)
{

  int tamanio = palabra_buscar.size();
  respuesta r;
  r.fila_1 = -1;
  r.fila_2 = -1;
  r.columna_1 = -1;
  r.columna_2 = -1;

  int encontrado = 0;

  for (int i = 0; i < cols; i++)
  {

    string str = "";
    for (int j = 0; j < fils; j++)
    {
      char c = soup.sopa_letras[j][i];
      str = str + c;
    }

    int pos_encontrada = str.find(palabra_buscar);

    if (pos_encontrada != -1)
    {
      r.fila_1 = pos_encontrada;
      r.columna_1 = i;
      r.fila_2 = (pos_encontrada + tamanio) - 1;
      r.columna_2 = i;
      r.orientacion = "Vertical";

      return r;
    }
  }

  for (int i = 0; i < fils; i++)
  {

    string str = "";
    for (int j = 0; j < cols; j++)
    {
      char c = soup.sopa_letras[i][j];
      str = str + c;
    }

    int pos_encontrada = str.find(palabra_buscar);

    if (pos_encontrada != -1)
    {
      r.fila_1 = i;
      r.columna_1 = pos_encontrada;
      r.fila_2 = i;
      r.columna_2 = (pos_encontrada + tamanio) - 1;
      r.orientacion = "Horizontal";

      return r;
    }
  }

  for (int i = fils - 1; i >= 0; i--)
  {

    string str = "";
    int j;
    int k = 0;
    for (j = i; j < fils; j++)
    {

      if (k >= cols)
        break;
      char c = soup.sopa_letras[j][k];
      str = str + c;
      k++;
    }

    int pos_encontrada = str.find(palabra_buscar);

    if (pos_encontrada != -1)
    {

      r.fila_1 = i + pos_encontrada;
      r.columna_1 = pos_encontrada;
      r.fila_2 = (r.fila_1 + tamanio) - 1;
      r.columna_2 = (r.columna_1 + tamanio) - 1;
      r.orientacion = "Diagonal derecha";

      return r;
    }
  }

  for (int i = 1; i < cols && encontrado == 0; i++)
  {

    string str = "";
    int j;
    int k = i;
    for (int j = 0; j < fils; j++)
    {

      if (k >= cols)
        break;
      char c = soup.sopa_letras[j][k];
      str = str + c;
      k++;
    }

    int pos_encontrada = str.find(palabra_buscar);

    if (pos_encontrada != -1)
    {
      r.fila_1 = pos_encontrada;
      r.columna_1 = i + pos_encontrada;
      r.fila_2 = (r.fila_1 + tamanio) - 1;
      r.columna_2 = (r.columna_1 + tamanio) - 1;
      r.orientacion = "Diagonal derecha";

      return r;
    }
  }

  for (int i = fils - 1; i >= 0; i--)
  {

    string str = "";
    int j;
    int k = cols - 1;
    for (j = i; j < fils; j++)
    {

      if (k < 0 && encontrado != 0)
        break;

      char c = soup.sopa_letras[j][k];
      str = str + c;
      k--;
    }

    int pos_encontrada = str.find(palabra_buscar);

    if (pos_encontrada != -1)
    {
      r.fila_1 = i + pos_encontrada;
      r.columna_1 = ((cols - 1) - pos_encontrada);
      r.fila_2 = (r.fila_1 + tamanio) - 1;
      r.columna_2 = (r.columna_1 - tamanio) + 1;
      r.orientacion = "Diagonal izquierda";

      return r;
    }
  }

  for (int i = cols - 2; i >= 0; i--)
  {

    string str = "";
    int j;
    int k = i;
    for (j = 0; j < fils; j++)
    {

      if (k < 0 && encontrado != 0)
        break;

      char c = soup.sopa_letras[j][k];
      str = str + c;
      k--;
    }

    int pos_encontrada = str.find(palabra_buscar);

    if (pos_encontrada != -1)
    {
      r.fila_1 = pos_encontrada;
      r.columna_1 = i - pos_encontrada;
      r.fila_2 = (r.fila_1 + tamanio) - 1;
      r.columna_2 = (r.columna_1 - tamanio) + 1;
      r.orientacion = "Diagonal izquierda";

      return r;
    }
  }
  return r;
}

void ordenar_jugadores(int numjug, jugador jugs[25], string valor_ordenamiento)
{

  for (int i = 0; i < numjug; i++)
  {
    for (int j = i + 1; j < numjug; j++)
    {

      if (valor_ordenamiento == "puntaje")
      {
        if (jugs[j].puntaje > jugs[i].puntaje)
        {
         
          swap(jugs[i], jugs[j]);
        }
      }
      else
      {
        if (jugs[j].edad < jugs[i].edad)
        {
          swap(jugs[i], jugs[j]);
        }
      }
    }
  }
}

void imprimir_sopa(sopa soup, int fils, int cols)
{

  for (int i = 0; i < fils; i++)
  {
    for (int j = 0; j < 40; j++)
      cout << " ";
    for (int j = 0; j < cols; j++)
    {
      cout << soup.sopa_letras[i][j] << " ";
    }
    cout << endl;
  }
}

int asignar_puntajes(respuesta respuesta_jugador[25], respuesta mi_respuesta[25], int numpals)
{

  int total = 0;

  for (int i = 0; i < numpals; i++)
  {

    int puntaje_palabra = 0;


    if (respuesta_jugador[i].fila_1 == mi_respuesta[i].fila_1 && respuesta_jugador[i].fila_2 == mi_respuesta[i].fila_2 && respuesta_jugador[i].columna_1 == mi_respuesta[i].columna_1 && respuesta_jugador[i].columna_2 == mi_respuesta[i].columna_2)
    {

      puntaje_palabra += 5;
    }

    if (respuesta_jugador[i].fila_1 == mi_respuesta[i].fila_1 && respuesta_jugador[i].columna_1 == mi_respuesta[i].columna_1)
    {

      puntaje_palabra += 2;
    }

    if (respuesta_jugador[i].fila_2 == mi_respuesta[i].fila_2 && respuesta_jugador[i].columna_2 == mi_respuesta[i].columna_2)
    {

      puntaje_palabra += 2;
    }

    if (convertir_minusculas(respuesta_jugador[i].orientacion) == convertir_minusculas(mi_respuesta[i].orientacion))
    {
      puntaje_palabra += 3;
    }

    total += puntaje_palabra;
  }

  return total;
}

void imprimir_respuesta_correcta(respuesta respuesta_palabra)
{
  cout << respuesta_palabra.palabra << ": " << endl;
  cout << " Orientación: " << respuesta_palabra.orientacion << endl;

  cout << " Posición inicial: [" << respuesta_palabra.fila_1 << "," << respuesta_palabra.columna_1 << "]" << endl;

  cout << " Posición final: [" << respuesta_palabra.fila_2 << "," << respuesta_palabra.columna_2 << "]" << endl;

  cout << endl;
}

int main()
{

  const int MAX_FILS = 25;
  const int MAX_COLS = 25;

  const int fils = 16;
  const int cols = 15;
  const int numpals = 10;
  const int numjug = 5;

  sopa soup = {
      "CLIMA",
      {{'F', 'L', 'A', 'B', 'O', 'L', 'G', 'F', 'G', 'T', 'Y', 'U', 'O', 'Z', 'A'},
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
       {'A', 'G', 'U', 'A', 'S', 'E', 'V', 'I', 'D', 'E', 'N', 'C', 'I', 'A', 'S'}},
      {"AGUA", "CIENCIA", "EVIDENCIAS", "CALENTAMIENTO", "CLIMA", "ATMOSFERA", "GLACIAR", "TCKA", "SDGUE", "NMIE"}};

  jugador jugs[numjug] = {

      {200, "Lula", 12, 'F', {{"AGUA", "Horizontal", 14, 0, 15, 2}, {"CIENCIA", "Vertical", 7, 4, 12, 4}, {"EVIDENCIAS", "Horizontal", 15, 5, 15, 15}, {"CALENTAMIENTO", "Vertical", 1, 0, 13, 0}, {"CLIMA", "Diagonal Izquierda", 10, 8, 14, 4}, {"", "", -1, -1, -1, -1}, {"", "", -1, -1, -1, -1}, {"", "", -1, -1, -1, -1}, {"", "", -1, -1, -1, -1}, {"", "", -1, -1, -1, -1}}, 0},

      {400, "Mary", 13, 'F', {{"AGUA", "Horizontal", 15, 0, 15, 3}, {"CIENCIA", "Vertical", 7, 4, 12, 4}, {"EVIDENCIAS", "Horizontal", 15, 5, 15, 15}, {"CALENTAMIENTO", "Vertical", 1, 0, 13, 0}, {"", "", -1, -1, -1, -1}, {"", "", -1, -1, -1, -1}, {"", "", -1, -1, -1, -1}, {"", "", -1, -1, -1, -1}, {"", "", -1, -1, -1, -1}, {"", "", -1, -1, -1, -1}}, 0},

      {600, "Tomy", 11, 'M', {{"AGUA", "Horizontal", 15, 0, 15, 3}, {"CIENCIA", "Vertical", 7, 4, 12, 4}, {"EVIDENCIAS", "Horizontal", 15, 5, 15, 15}, {"CALENTAMIENTO", "Vertical", 1, 0, 13, 0}, {"CLIMA", "Diagonal Izquierda", 10, 8, 14, 4}, {"ATMOSFERA", "Vertical", 0, 2, 8, 2}, {"GLACIAR", "Vertical", 4, 12, 10, 12}, {"", "", -1, -1, -1, -1}, {"", "", -1, -1, -1, -1}, {"", "", -1, -1, -1, -1}}, 0},

      {800, "Peter", 12, 'M', {{"", "", -1, -1, -1, -1}, {"CIENCIA", "Vertical", 7, 4, 12, 4}, {"EVIDENCIAS", "Horizontal", 15, 5, 15, 15}, {"CALENTAMIENTO", "Vertical", 1, 0, 13, 0}, {"", "", -1, -1, -1, -1}, {"", "", -1, -1, -1, -1}, {"", "", -1, -1, -1, -1}, {"", "", -1, -1, -1, -1}, {"", "", -1, -1, -1, -1}, {"", "", -1, -1, -1, -1}}, 0},

      {1000, "Luna", 13, 'M', {{"AGUA", "Horizontal", 1, 0, 15, 1}, {"CIENCIA", "Vertical", 7, 4, 12, 4}, {"EVIDENCIAS", "Horizontal", 15, 5, 15, 15}, {"CALENTAMIENTO", "Vertical", 1, 0, 13, 0}, {"CLIMA", "Diagonal Izquierda", 10, 8, 14, 4}, {"ATMOSFERA", "Vertical", 0, 2, 8, 1}, {"GLACIAR", "Vertical", 3, 12, 10, 10}, {"", "", -1, -1, -1, -1}, {"", "", -1, -1, -1, -1}, {"", "", -1, -1, -1, -1}}, 0}};

  respuesta mi_respuesta[numpals];

  bool puntaje_generado = false;

  for (int i = 0; i < numpals; i++)
  {

    string palabra_buscar = soup.palabras_buscar[i];

    respuesta palabra_encontrada = buscar_palabra(palabra_buscar, fils, cols, soup);
    palabra_encontrada.palabra = palabra_buscar;

    mi_respuesta[i] = palabra_encontrada;
  }

  imprimir_titulo();

  while (true)
  {
    int opcion = presentar_menu_juego();

    if (opcion != 0) imprimir_titulo();

    if (opcion == 0)
    {

      cout << "Saliendo del juego..." << endl;
      break;
    }
    else if (opcion == 1)
    {

      ordenar_jugadores(numjug, jugs, "edad");

      cout << "Jugadores (ordenados por edad):" << endl
           << endl;

      for (int i = 0; i < numjug; i++)
      {
        cout << " Jugador " << jugs[i].id << ": " << endl;
        cout << "  Nombre: " << jugs[i].nombre << endl;

        cout << "  Edad: " << jugs[i].edad << endl;
        cout << "  Género: " << jugs[i].genero << endl;
        cout << "  Puntaje: " << (jugs[i].puntaje) << endl
             << endl;
      }
    }

    else if (opcion == 2)
    {
      cout << endl
           << "Generando respuesta...." << endl;
    }
    else if (opcion == 3)
    {
      imprimir_sopa(soup, fils, cols);
    }
    else if (opcion == 4)
    {
      cout << "Tema del juego: " << soup.tema_juego << endl
           << endl;

      for (int i = 0; i < numpals; i++)
      {
        string palabra = soup.palabras_buscar[i];
        imprimir_respuesta_correcta(mi_respuesta[i]);
      }
    }
    else if (opcion == 5)
    { 

      cout << "Asignando puntajes a los jugadores..." << endl;

      if (!puntaje_generado)
      {

        int total_puntaje_jugador;
        for (int i = 0; i < numjug; i++)
        {

          int total_puntaje_jugador = asignar_puntajes(jugs[i].palabras_encontradas, mi_respuesta, numpals);

          jugs[i].puntaje = (total_puntaje_jugador);
        }
        puntaje_generado = true;
      }
    }
    else
    {

      if (!puntaje_generado)
      {
        int total_puntaje_jugador;
        for (int i = 0; i < numjug; i++)
        {

          int total_puntaje_jugador = asignar_puntajes(jugs[i].palabras_encontradas, mi_respuesta, numpals);

          jugs[i].puntaje = (total_puntaje_jugador); 
        }

        puntaje_generado = true;
      }

      cout << "CLASIFICACIÓN DE LOS JUGADORES: " << endl
           << endl;

      ordenar_jugadores(numjug, jugs, "puntaje");

      for (int i = 0; i < numjug; i++)
      {
        cout << " Jugador " << jugs[i].id << ": " << endl;
        cout << "  Nombre: " << jugs[i].nombre << endl;

        cout << "  Edad: " << jugs[i].edad << endl;
        cout << "  Género: " << jugs[i].genero << endl;
        cout << "  Puntaje: " << (jugs[i].puntaje) << endl
             << endl;
      }
    }
  }

  return 0;
}