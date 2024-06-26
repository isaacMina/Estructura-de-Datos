#include <iostream>
#include <cstdlib>
using namespace std;

struct Empresa {
    int RNT;
    string nombre;
    int ano;
    int mes;
    int dia;
    Empresa* izq;
    Empresa* der;

    Empresa(int codigoRNT, string nombreEmpresa, int anio, int mesEmpresa, int diaEmpresa) {
        RNT = codigoRNT;
        nombre = nombreEmpresa;
        ano = anio;
        mes = mesEmpresa;
        dia = diaEmpresa;
        izq = nullptr;
        der = nullptr;
    }
};

Empresa *raiz, *raiz2, *aux, *aux2;

void insertarEmpresa(Empresa* &raiz, int codigoRNT, string nombre, int ano, int mes, int dia) {
    if (raiz == nullptr) {
        raiz = (Empresa *)malloc(sizeof(Empresa));
        raiz->RNT = codigoRNT;
        raiz->nombre = nombre;
        raiz->ano = ano;
        raiz->mes = mes;
        raiz->dia = dia;
        raiz->izq = nullptr;
        raiz->der = nullptr;
        return;
    }

    aux = raiz;
    while (aux != nullptr) {
        aux2 = aux;
        if (codigoRNT < aux->RNT) {
            aux = aux->izq;
        } else {
            aux = aux->der;
        }
    }

    if (codigoRNT < aux2->RNT) {
        aux2->izq = (Empresa *)malloc(sizeof(Empresa));
        aux2->izq->RNT = codigoRNT;
        aux2->izq->nombre = nombre;
        aux2->izq->ano = ano;
        aux2->izq->mes = mes;
        aux2->izq->dia = dia;
        aux2->izq->izq = nullptr;
        aux2->izq->der = nullptr;
    } else {
        aux2->der = (Empresa *)malloc(sizeof(Empresa));
        aux2->der->RNT = codigoRNT;
        aux2->der->nombre = nombre;
        aux2->der->ano = ano;
        aux2->der->mes = mes;
        aux2->der->dia = dia;
        aux2->der->izq = nullptr;
        aux2->der->der = nullptr;
    }
}

void eliminarNodo(Empresa* &raiz, int codigoRNT) {
    if (raiz == nullptr) {
        return;
    }

    if (codigoRNT < raiz->RNT) {
        eliminarNodo(raiz->izq, codigoRNT);
    } else if (codigoRNT > raiz->RNT) {
        eliminarNodo(raiz->der, codigoRNT);
    } else {
        if (raiz->izq == nullptr) {
            Empresa* temp = raiz;
            raiz = raiz->der;
            free(temp);
        } else if (raiz->der == nullptr) {
            Empresa* temp = raiz;
            raiz = raiz->izq;
            free(temp);
        } else {
            Empresa* temp = raiz->der;
            while (temp->izq != nullptr) {
                temp = temp->izq;
            }
            raiz->RNT = temp->RNT;
            raiz->nombre = temp->nombre;
            raiz->ano = temp->ano;
            raiz->mes = temp->mes;
            raiz->dia = temp->dia;
            eliminarNodo(raiz->der, temp->RNT);
        }
    }
}

void eliminarNodoEspejo(Empresa* &raiz, int codigoRNT) {
    if (raiz == nullptr) {
        return;
    }

    if (codigoRNT < raiz->RNT) {
        eliminarNodoEspejo(raiz->izq, codigoRNT);
    } else if (codigoRNT > raiz->RNT) {
        eliminarNodoEspejo(raiz->der, codigoRNT);
    } else {
        if (raiz->izq == nullptr) {
            Empresa* temp = raiz;
            raiz = raiz->der;
            free(temp);
        } else if (raiz->der == nullptr) {
            Empresa* temp = raiz;
            raiz = raiz->izq;
            free(temp);
        } else {
            Empresa* temp = raiz->der;
            while (temp->izq != nullptr) {
                temp = temp->izq;
            }
            raiz->RNT = temp->RNT;
            raiz->nombre = temp->nombre;
            raiz->ano = temp->ano;
            raiz->mes = temp->mes;
            raiz->dia = temp->dia;
            eliminarNodoEspejo(raiz->der, temp->RNT);
        }
    }
}

void preorden(Empresa* raiz) {
    if (raiz == nullptr) return;
    cout << "RNT: " << raiz->RNT << ", Nombre: " << raiz->nombre << ", Fecha Vencimiento: " << raiz->ano << "-" << raiz->mes << "-" << raiz->dia << endl;
    preorden(raiz->izq);
    preorden(raiz->der);
}

void inorden(Empresa* raiz) {
    if (raiz == nullptr) return;
    inorden(raiz->izq);
    cout << "RNT: " << raiz->RNT << ", Nombre: " << raiz->nombre << ", Fecha Vencimiento: " << raiz->ano << "-" << raiz->mes << "-" << raiz->dia << endl;
    inorden(raiz->der);
}

void postorden(Empresa* raiz) {
    if (raiz == nullptr) return;
    postorden(raiz->izq);
    postorden(raiz->der);
    cout << "RNT: " << raiz->RNT << ", Nombre: " << raiz->nombre << ", Fecha Vencimiento: " << raiz->ano << "-" << raiz->mes << "-" << raiz->dia << endl;
}

int menu() {
    int opcion;
    cout << "\nMenu:" << endl;
    cout << "1. Insertar empresa" << endl;
    cout << "2. Eliminar empresa" << endl;
    cout << "3. Eliminar empresa espejo" << endl;
    cout << "4. Mostrar en preorden" << endl;
    cout << "5. Mostrar en inorden" << endl;
    cout << "6. Mostrar en postorden" << endl;
    cout << "7. Salir" << endl;
    cout << "Ingrese una opcion: ";
    cin >> opcion;
    return opcion;
}

int main() {
    raiz = nullptr;

    int opcion, codigoRNT;
    string nombre;
    int ano, mes, dia;

    do {
        opcion = menu();

        switch (opcion) {
            case 1:
                cout << "Ingrese el codigo RNT de la empresa: ";
                cin >> codigoRNT;
                cout << "Ingrese el nombre de la empresa: ";
                cin.ignore();
                getline(cin, nombre);
                cout << "Ingrese el año de vencimiento del RNT: ";
                cin >> ano;
                cout << "Ingrese el mes de vencimiento del RNT: ";
                cin >> mes;
                cout << "Ingrese el dia de vencimiento del RNT: ";
                cin >> dia;

                insertarEmpresa(raiz, codigoRNT, nombre, ano, mes, dia);
                break;

            case 2:
                cout << "Ingrese el codigo RNT de la empresa a eliminar: ";
                cin >> codigoRNT;
                eliminarNodo(raiz, codigoRNT);
                break;

            case 3:
                cout << "Ingrese el codigo RNT de la empresa espejo a eliminar: ";
                cin >> codigoRNT;
                eliminarNodoEspejo(raiz2, codigoRNT);
                break;

            case 4:
                cout << "Recorrido en Preorden:" << endl;
                preorden(raiz);
                break;

            case 5:
                cout << "Recorrido en Inorden:" << endl;
                inorden(raiz);
                break;

            case 6:
                cout << "Recorrido en Postorden:" << endl;
                postorden(raiz);
                break;

            case 7:
                cout << "Saliendo..." << endl;
                break;

            default:
                cout << "Opcion invalida. Por favor ingrese una opcion valida." << endl;
                break;
        }

    } while (opcion != 7);

    return 0;
}
