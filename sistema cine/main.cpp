#include <iostream>  //lo basico
#include "windows.h" //libria de window
#include <string>    //Getline

using namespace std;

#define limp system("cls")
#define pausa system("pause")

//--------------------------------------------------------sala--------------------------------------------------------//

int Cantidad_sala = 0;

class Sala
{
private:
    string name;
    int cantidad_as;
    int asientos[100];
    int cantidad_oc;

public:
    string numsala;

    void create_sala(string _name, string _num_sala, int cant)
    {
        name = _name;
        numsala = _num_sala;
        cantidad_as = cant;
    }

    void mostrarStat(){
        cout<<numsala<<"  "<<name<<"  "<<cantidad_as<<"   "<<cantidad_oc<<"\n";
    }
};

Sala salas[100];

//------------------------------------------------------clientes------------------------------------------------------//

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

//-----------------------------------------------------hud-----------------------------------------------------//

void Menu_all(int menu)
{
    limp;
    switch (menu)
    {
    case 0:
        cout << "Bienvenido al sistema de cine\n1)administrar sala de cine\n2)administrar clientes\n3)comprar ticket\n4)Ver compras\n5)Salir\nSelecione: ";
        break;
    case 1:
        cout << "1)Adicionar sala\n2)Editar sala\n3)Eliminar sala\n4)Ver lista\n5)Salir\nselecione: ";
        break;
    case 2:
        cout << "1)Adicionar cliente\n2)Editar cliente\n3)Eliminar cliente\n4)Ver lista\n5)Salir\nselecione: ";
        break;
    default:
        break;
    }
}

//---------------------------------------------------sistema cine---------------------------------------------------//

int BuscarSala(string num)
{
    for (int x = 0; x < Cantidad_sala; x++)
    {
        if (num == salas[x].numsala)
        {
            return x;
        }
    }

    return -1;
}