#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

struct RegistroTemperatura {
    char fecha[11]; 
    float manana;
    float tarde;
    float noche;
    RegistroTemperatura* sig;
};

RegistroTemperatura* cab = nullptr;
RegistroTemperatura* aux = nullptr;
RegistroTemperatura* aux2 = nullptr;

void agregarRegistro() {
    aux = new RegistroTemperatura;
    printf("Ingrese la fecha (dd/mm/yyyy): ");
    cin >> aux->fecha;
    printf("Ingrese la temperatura de la manana: ");
    cin >> aux->manana;
    printf("Ingrese la temperatura de la tarde: ");
    cin >> aux->tarde;
    printf("Ingrese la temperatura de la noche: ");
    cin >> aux->noche;
    aux->sig = nullptr;
    if (!cab) {
        cab = aux;
    } else {
        aux2 = cab;
        while (aux2->sig != nullptr)
            aux2 = aux2->sig;
        aux2->sig = aux;
    }
}

void mostrarRegistros() {
    printf("Registros de temperatura:\n");
    for (aux = cab; aux != nullptr; aux = aux->sig) {
        printf("Fecha: %s, Manana: %.2f%cC, Tarde: %.2f%cC, Noche: %.2f%cC\n", aux->fecha, aux->manana, char(248), aux->tarde, char(248), aux->noche, char(248));
    }
}

void promedioTemperaturaDia() {
    unordered_map<string, vector<float>> promedios;
    for (aux = cab; aux != nullptr; aux = aux->sig) {
        float promedioDia = (aux->manana + aux->tarde + aux->noche) / 3.0;
        promedios[aux->fecha].push_back(promedioDia);
    }

    printf("Promedio de temperatura por dia:\n");
    for (auto& it : promedios) {
        float total = 0;
        for (float temp : it.second) {
            total += temp;
        }
        float promedio = total / it.second.size();
        printf("Fecha: %s, Promedio: %.2f%cC\n", it.first.c_str(), promedio, char(248));
    }
}

float promedioTemperaturaTodosRegistros() {
    float total = 0;
    int count = 0;
    for (aux = cab; aux != nullptr; aux = aux->sig) {
        total += aux->manana + aux->tarde + aux->noche;
        count += 3; 
    }
    return total / count;
}

int main() {
    int opc = 0;
    int dias = 0;
    do {
        printf("               Registros de Temperaturas             ");
        printf(" ");
        printf("\n1. Agregar registro\n2. Mostrar registros\n3. Promedio de temperatura del dia por fecha\n4. Promedio de temperatura de todos los registros\n5. Salir\n");
        printf("Selecione la opcion que desea ejecutar: ");
        cin >> opc;

        switch (opc) {
            case 1:
                printf("Ingrese la cantidad de dias que desea registrar: ");
                cin >> dias;
                for (int i = 0; i < dias; i++) {
                    agregarRegistro();
                }
                break;
            case 2:
                mostrarRegistros();
                break;
            case 3:
                promedioTemperaturaDia();
                break;
            case 4: {
                float promedio = promedioTemperaturaTodosRegistros();
                printf("El promedio de temperatura de todos los registros es: %.2f%cC\n", promedio, char(248));
                break;
            }
            case 5:
                printf("Saliendo del programa.\n");
                break;
            default:
                printf("Opcion invalida. Intente de nuevo.\n");
                break;
        }
    } while (opc != 5);

    return 0;
}