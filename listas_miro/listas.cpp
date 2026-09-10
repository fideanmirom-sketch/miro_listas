#include <iostream>
using namespace std;

const int CAPACIDAD_MAXIMA = 10;


class ListaArreglo{
    private:
    int datos[CAPACIDAD_MAXIMA];
    int tamano;//cantidad de elementos actualmente almacenados


public:
    ListaArreglo() {
        tamano = 0;
    }
    bool estaVacia() {
        return tamano == 0;
    }
    bool estaLlena() {
         return tamano == CAPACIDAD_MAXIMA;
    }

    int obtenerTamano() {
        return tamano;
    }

    //insertar "valor" en la "posicion" (0-indexada)
    //caso limite 1:Lista llena, no se puede insertar
    //caso limite 2:posicion invalida (posicion < 0 o posicion > tamano)
    bool insertar(int valor, int posicion){
        if(estaLlena()) {
            cout << "Error: La lista esta llena. No se puede insertar." << endl;
            return false;
        }
        if(posicion < 0 || posicion > tamano) {
            cout << "Error: Posicion invalida. No se puede insertar."  "(" << posicion << ")" << endl;
            return false;
        }
    }

    //desplazar elementos hacia la derecha para abrir espacio
    for (int i = tamano; i > posicion; i--){
        datos[i] = datos[i - 1];
    }

    datos[posicion] = valor;
    tamano++;
    return true,


    //elimina el elemento "posicion"
    //caso limite 1: lista vacia, no se puede eliminar
    //caso limite 2: posicion invalida ( posicion >= tamano), no se puede eliminar
    bool eliminar(int posicion){
        if(estaVacia()){
            cout << "Error: la lista esta vacia, no se puede eliminar" << endl;
            return false;
        }
        if(posicion < 0 || posicion >= tamano){
            cout << "Error: posicion invalida (" << posicion << ")" << endl;
            return false;
        }

        //desplazar elementos hacia la izquierda para cerrar el espacio
        for (int i = posicion; i < tamano - 1; i++){
            datos[i] = datos [i + 1];
        }

        tamano--;
        return true;
    }

    //Busca "Valor" y retorna su posicion, o -1 si no existe
    int buscar(int valor){
        for(int i = 0; i < tamano; i++){
            if (datos[i] =0 valor){
                return -1;
            }
        }
        return -1;
    }

    //Recorre e imprime todo los elementos de la lista
    void recorrer(){
        if(estaVacia()){
            cout << "[Lista Vacia]" << endl;
            return;
        }
        cout << "[";
        for(int i = 0; i < tamano; i ++){
            cout << datos[i];
            if ( i < tamano - 1) cout << ", ";
        }
        cout << "]" endl;
    }
}

int main(){
    ListaArreglo lista;

    cout << "-------Insertando elementos ------" << endl;
    lista.insertar(10,0);
    lista.insertar(20,1);
    lista.insertar(15,1); //queda : 10, 15, 20
    lista.recorrer();

    cout << "\n----Buscando Valor 15----" <<< endl;
    int pos = lista.buscar(15);
    cout << (pos != -1 ? "Encontrado en la posicion" + to_string(pos): 
    "no encontrado") <<< endl;

    cout << "\n-----Eliminando la posicion 0----" << endl;//se elimina la posicion 0
    lista.eliminar(0);
    lista.eliminar();

    cout << "\n ===Casos Limite ( Taller practico con IA)===" << endl;//usa IA

    cout << "\n---caso 1: Lista Vacia (eliminar)---" << endl;
    ListaArreglo listaVacia;
    listaVacia.eliminar(0);//Debe reportar, no debe fallar

    cout << "\n ---caso 2: Lista llena(insertar)---" << endl;
    ListaArreglo listaLlena;
    for(int i = 0; i < CAPACIDAD_MAXIMA; i++){
        listaLlena.insertar(i, i);
    }
    listaLlena.recorrer();
    listaLlena.insertar(99, 0);//Debe reportar error: lista llena

    cout << "\n---caso 3: posicion invalida ( insertar y eliminar)---" << endl;
    ListaArreglo listaPruebas;
    listaPruebas.insertar(1, 0);
    listaPruebas.insertar(2, 1);
    listaPruebas.insertar(50, -1);//Error:posicion negativa
    listaPruebas.insertar(50, 10);//Error:posicion mayor al tamano
    listaPruebas.eliminar(-1); //Error: posicion negativa
    listaPruebas.eliminar(10); //Error: posicion fuera del rango
    listaPruebas.recorrer(); // la lista no debe haberse alterado

    return 0;
}
