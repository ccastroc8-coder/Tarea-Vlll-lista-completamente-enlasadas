#include <iostream>                        //Carlos Daniel Castro Caceres
using namespace std;           // 9941-24-10004

struct Nodo {
    int dato;
    Nodo* siguiente;
    Nodo* anterior;
};

void insertarInicio(Nodo*& head, Nodo*& tail, int valor) {
    Nodo* nuevo = new Nodo;
    nuevo->dato = valor;
    nuevo->siguiente = head;
    nuevo->anterior = NULL;

    if (head != NULL) {
        head->anterior = nuevo;
    } else {
        tail = nuevo;
    }

    head = nuevo;
}

void insertarFinal(Nodo*& head, Nodo*& tail, int valor) {
    Nodo* nuevo = new Nodo;
    nuevo->dato = valor;
    nuevo->siguiente = NULL;
    nuevo->anterior = tail;

    if (head == NULL) {
        head = tail = nuevo;
        return;
    }

    tail->siguiente = nuevo;
    tail = nuevo;
}

void mostrarAdelante(Nodo* head) {
    if (head == NULL) {
        cout << "Lista vacia\n";
        return;
    }

    cout << "\nLista hacia adelante: ";
    while (head != NULL) {
        cout << head->dato << " <-> ";
        head = head->siguiente;
    }
    cout << "NULL\n";
}

void mostrarAtras(Nodo* tail) {
    if (tail == NULL) {
        cout << "Lista vacia\n";
        return;
    }

    cout << "\nLista hacia atras: ";
    while (tail != NULL) {
        cout << tail->dato << " <-> ";
        tail = tail->anterior;
    }
    cout << "NULL\n";
}

bool buscar(Nodo* head, int valor) {
    while (head != NULL) {
        if (head->dato == valor)
            return true;
        head = head->siguiente;
    }
    return false;
}

void eliminar(Nodo*& head, Nodo*& tail, int valor) {
    if (head == NULL) {
        cout << "Lista vacia\n";
        return;
    }

    Nodo* actual = head;

    while (actual != NULL && actual->dato != valor) {
        actual = actual->siguiente;
    }

    if (actual == NULL) {
        cout << "Dato no encontrado\n";
        return;
    }

    if (head == tail) {
        delete actual;
        head = tail = NULL;
        cout << "Eliminado\n";
        return;
    }

    if (actual == head) {
        head = head->siguiente;
        head->anterior = NULL;
        delete actual;
        cout << "Eliminado\n";
        return;
    }

    if (actual == tail) {
        tail = tail->anterior;
        tail->siguiente = NULL;
        delete actual;
        cout << "Eliminado\n";
        return;
    }

    actual->anterior->siguiente = actual->siguiente;
    actual->siguiente->anterior = actual->anterior;

    delete actual;
    cout << "Eliminado\n";
}

int contarNodos(Nodo* head) {
    int contador = 0;
    while (head != NULL) {
        contador++;
        head = head->siguiente;
    }
    return contador;
}

void liberarLista(Nodo*& head, Nodo*& tail) {
    while (head != NULL) {
        Nodo* temp = head;
        head = head->siguiente;
        delete temp;
    }
    tail = NULL;
}

int main() {
    Nodo* head = NULL;
    Nodo* tail = NULL;
    int opcion, valor;

    do {
        cout << "\n===== MENU =====\n";
        cout << "1. Insertar al inicio\n";
        cout << "2. Insertar al final\n";
        cout << "3. Mostrar hacia adelante\n";
        cout << "4. Mostrar hacia atras\n";
        cout << "5. Buscar dato\n";
        cout << "6. Eliminar dato\n";
        cout << "7. Contar nodos\n";
        cout << "8. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch(opcion) {
            case 1:
                cout << "Ingrese valor: ";
                cin >> valor;
                insertarInicio(head, tail, valor);
                break;

            case 2:
                cout << "Ingrese valor: ";
                cin >> valor;
                insertarFinal(head, tail, valor);
                break;

            case 3:
                mostrarAdelante(head);
                break;

            case 4:
                mostrarAtras(tail);
                break;

            case 5:
                cout << "Ingrese valor: ";
                cin >> valor;
                if (buscar(head, valor))
                    cout << "SI existe\n";
                else
                    cout << "NO existe\n";
                break;

            case 6:
                cout << "Ingrese valor: ";
                cin >> valor;
                eliminar(head, tail, valor);
                break;

            case 7:
                cout << "Total: " << contarNodos(head) << endl;
                break;
        }

    } while (opcion != 8);

    liberarLista(head, tail);
    return 0;
}