#include <iostream>  //lo basico
#include "windows.h" //libria de window
#include <string>    //Getline

using namespace std;

#define limp system("cls")
#define pausa system("pause")

// Bus

int Cantidad_bus = 0;

class Bus
{
private:
    string name;
    int cantidad_as;
    int asientos[100];
    int cantidad_oc;

public:
    string placa;

    void create_bus(string _name, string _placa, int cant)
    {
        name = _name;
        placa = _placa;
        cantidad_as = cant;
    }

    void mostrarStat(){
        cout<<placa<<"  "<<name<<"  "<<cantidad_as<<"   "<<cantidad_oc<<"\n";
    }
};

Bus buses[100];

// Cliente

int cantidad_cliente = 0;

class Cliente
{
private:
    string name;
    string lastname;
    int dni;
    int asoc = -1;

public:
    void create_cliente(string _name, string _lastname, int _dni)
    {
        name = _name;
        lastname = _lastname;
        dni = _dni;
    }
};

Cliente clientes[100];

// HUD

void Menu_all(int menu)
{
    limp;
    switch (menu)
    {
    case 0:
        cout << "Bienvenido al sistema de bus\n1)administrar Buses\n2)administrar clientes\n3)comprar ticket\n4)Ver compras\n5)Salir\nSelecione: ";
        break;
    case 1:
        cout << "1)Adicionar bus\n2)Editar bus\n3)Eliminar Bus\n4)Ver lista\n5)Salir\nselecione: ";
        break;
    case 2:
        cout << "1)Adicionar cliente\n2)Editar cliente\n3)Eliminar cliente\n4)Ver lista\n5)Salir\nselecione: ";
        break;
    default:
        break;
    }
}

int BuscarBus(string num)
{
    for (int x = 0; x < Cantidad_bus; x++)
    {
        if (num == buses[x].placa)
        {
            return x;
        }
    }

    return -1;
}

void mostrarBus()
{
    limp;
    for(int x = 0; x < Cantidad_bus; x++){
        cout<<x+1<<")";buses[x].mostrarStat();
    }
    cout<<"\nTotal: "<<Cantidad_bus<<"\n";
    pausa;
}

void FunctionBus(int op)
{
    cin.ignore(); // el mas importante
    string placa, name;
    int encon, asiento;

    mostrarBus();

    limp;
    switch (op)
    {
    case 1:
        cout << "Ingrese numero de placa: ";
        do
        {
            getline(cin, placa);
            encon = BuscarBus(placa);
        } while (placa == "" || encon != -1);
        limp;
        do
        {
            cout << "Ingrese el nombre del bus: ";
            getline(cin, name);
        } while (name == "");
        limp;
        do
        {
            cout << "Ingrese la cantidad de asiento: ";
            cin >> asiento;
        } while (asiento < 1);

        buses[Cantidad_bus].create_bus(name, placa, asiento);
        Cantidad_bus++;

        break;

    default:
        break;
    }
}

// MAIN

int main()
{
    // system("color 0A");
    int option = 0, option2;

    while (option != 5)
    {
        Menu_all(0);

        cin >> option;

        Menu_all(option);

        switch (option)
        {
        case 1:
            cin >> option2;
            FunctionBus(option2);
            break;
        }
    }

    return 1;
}