#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

string nameEmpresa = "Katio";

struct Producto
{

    int id;
    float precio;
    int vecesVendido = 0; // para que no suceda un bug
    string nombre;
    int cantidad;
};

Producto productos[100];
int cantidad_productos = 0;

void menu();
void subMenu(char op);
void introKatio(int pre);
void mostrarProductos();
void agregarProductos();
void eliminarProductos();
void venderProductos();
void Rakin();

int buscarProductos(string name, int id);

int main()
{

    introKatio(1);
    menu();

    return 0;
}

void menu()
{

    char op, op2;

    do
    {

        cout << "1. Administrar Productos\n2. Vender Producto\n3. Salir\nIngrese una opcion: ";

        cin >> op;

        system("cls");

        switch (op)
        {
        case '1':
        {
            do
            {
                cout << "1.Ver Productos\n2.Agregar Productos\n3.Editar Producto\n4.Eliminar Producto\n5.Ver Rakin del mas vendido\n6.Retroceder\nIngrese una opcion: ";
                cin >> op2;
                subMenu(op2);
            } while (op2 != '6');
        }
        break;

        case '2':
        {
            venderProductos();
        }
        break;

        default:
            cout << "\nIngrese una opcion Valida";
            getch();
            break;
        }

        system("cls");

    } while (op != '3');
}

void subMenu(char op)
{
    system("cls");
    switch (op)
    {
    case '1':
        mostrarProductos();
        break;
    case '2':
        agregarProductos();
        break;
    case '3':
        cout << "@App_s1s";
        break;
    case '4':
        eliminarProductos();
        break;
    case '5':
        Rakin();
        break;
    }
    system("cls");
}

void mostrarProductos()
{

    cout << "ID  |   Nombre  |   Precio  |   Cantidad    |   Ventas  |" << endl;

    for (int x = 0; x < cantidad_productos; x++)
    {

        cout << productos[x].id << " " << productos[x].nombre << " " << productos[x].precio << " " << productos[x].cantidad << " " << productos[x].vecesVendido << endl;
    }

    cout << "\n\nProductos Totales: " << cantidad_productos << "\n";

    getch();
}

void agregarProductos()
{
    float precio;
    int cantidad;
    string name;

    cin.ignore();

    do
    {
        system("cls");
        cout << "Ingrese Nombre del producto: ";
        getline(cin, name);

        int buscar = buscarProductos(name, -1);

        if (buscar != -1)
        {
            cout << "\nEl Producto " << name << " Ya existe\n";
            system("pause");
        }
        else
        {
            break;
        }

    } while (true);

    do
    {
        system("cls");
        cout << "Ingrese el precio del producto: ";
        cin >> precio;

        if (precio < 0)
        {
            cout << "Precio invalido\n";
            system("pause");
            cin.clear();
            cin.ignore();
        }
        else
        {
            break;
        }

    } while (true);

    do
    {
        system("cls");
        cout << "Ingrese la cantidad del producto: ";
        cin >> cantidad;

        if (cantidad < 0)
        {
            cout << "Cantidad invalida\n";
            system("pause");
            cin.clear();
            cin.ignore();
        }
        else
        {
            break;
        }

    } while (true);

    productos[cantidad_productos].id = cantidad_productos;
    productos[cantidad_productos].nombre = name;
    productos[cantidad_productos].precio = precio;
    productos[cantidad_productos].cantidad = cantidad;
    cantidad_productos++;

    system("cls");
    cout << "El Producto se creo con exito\n";
    system("pause");
}

void eliminarProductos()
{
    string name;
    int buscar;

    cin.ignore();

    do
    {
        system("cls");
        cout << "Ingrese el nombre del producto: ";
        getline(cin, name);

        buscar = buscarProductos(name, -1);

        if (buscar != -1)
        {
            break;
        }
        else
        {
            system("cls");
            mostrarProductos();

            cout << "\nEl producto no existe";
        }
    } while (true);

    for (int x = buscar; x < cantidad_productos; x++)
    {
        productos[x] = productos[x + 1];
    }

    cantidad_productos--;

    cout << "El producto fue eliminado";
    getch();
}

void venderProductos()
{
    int id = -1, buscar, cantidad;
    string name = "";
    char typeBusqueda;

    do
    {
        system("cls");
        cout << "Ingrese el tipo de busqueda: \n1. nombre\n2. id\ningrese la selecion: ";
        cin >> typeBusqueda;
        if (typeBusqueda == '1' || typeBusqueda == '2')
        {
            break;
        }
        else
        {
            cout << "Ingrese una opcion valida";
        }
    } while (true);

    cin.ignore();

    do
    {
        system("pause");
        if (typeBusqueda == '1')
        {
            mostrarProductos();
            cout << "\nIngrese el nombre del producto: ";
            getline(cin, name);
            buscar = buscarProductos(name, -1);
        }
        else
        {
            mostrarProductos();
            cout << "\nIngrese el id del producto: ";
            cin >> id;
            buscar = buscarProductos("", id);
        }

        if (buscar == -1)
        {
            cout << "\nEl producto no existe..\n";
            system("pause");
        }
        else
        {
            break;
        }
    } while (true);

    if (productos[buscar].cantidad >= 1)
    {
        do
        {
            system("cls");
            cout << "Ingrese la cantidad a vender: ";
            cin >> cantidad;

            if (cantidad > productos[buscar].cantidad)
            {
                cout << "No hay suficiente cantidad para vender";
            }
            else
            {
                break;
            }
        } while (true);

        productos[buscar].cantidad -= cantidad;
        productos[buscar].vecesVendido += cantidad;

        cout << "Total a pagar: " << (productos[buscar].precio * cantidad) << "\n";
        system("pause");
    }
    else
    {
        cout << "\nNO hay suficiente cantidad\n";
        system("pause");
    }
}

void Rakin()
{
    Producto productosCopia[100];
    for (int i = 0; i < cantidad_productos; ++i)
    {
        productosCopia[i] = productos[i];
    }

    for (int i = 0; i < cantidad_productos - 1; i++)
    {
        int max_idx = i;
        for (int j = i + 1; j < cantidad_productos; j++)
        {
            if (productosCopia[j].vecesVendido > productosCopia[max_idx].vecesVendido)
            {
                max_idx = j;
            }
        }
        if (max_idx != i)
        {
            Producto temp = productosCopia[i];
            productosCopia[i] = productosCopia[max_idx];
            productosCopia[max_idx] = temp;
        }
    }
    system("cls");
    cout << "Los mas vendidos:\n";
    for (int i = 0; i < cantidad_productos; ++i)
    {
        cout << productosCopia[i].id << " " << productosCopia[i].nombre << " " << productosCopia[i].precio << " " << productosCopia[i].cantidad << " " << productosCopia[i].vecesVendido << endl;
    }
    cout << endl;
    system("pause");
}

int buscarProductos(string name, int id)
{

    for (int x = 0; x < cantidad_productos; x++)
    {
        if (name == productos[x].nombre || id == productos[x].id)
            return x;
    }

    return -1;
}

void introKatio(int pre)
{
    system("cls");
    system("color 04");
    cout << "Bienvenido a sistema de " << nameEmpresa;

    getch();
    system("cls");
    system("color 0f");

    if (pre == 1)
    {

        // Generar base data preterminado

        productos[0].id = 0;
        productos[0].nombre = "Laptop Intel i9 14gen";
        productos[0].cantidad = 5;
        productos[0].precio = 1500;

        // Producto 2: Teclado mecánico RGB
        productos[1].id = 1;
        productos[1].nombre = "Teclado mecanico RGB";
        productos[1].cantidad = 20;
        productos[1].precio = 100;

        // Producto 3: Monitor 27 pulgadas IPS
        productos[2].id = 2;
        productos[2].nombre = "Monitor 27 pulgadas IPS";
        productos[2].cantidad = 8;
        productos[2].precio = 300;

        // Producto 4: Audífonos inalámbricos Bluetooth
        productos[3].id = 3;
        productos[3].nombre = "Audifonos inalambricos Bluetooth";
        productos[3].cantidad = 15;
        productos[3].precio = 50;

        // Producto 5: Mouse óptico gamer
        productos[4].id = 4;
        productos[4].nombre = "Mouse optico gamer";
        productos[4].cantidad = 12;
        productos[4].precio = 30;

        // Producto 6: Disco duro SSD 1TB
        productos[5].id = 5;
        productos[5].nombre = "Disco duro SSD 1TB";
        productos[5].cantidad = 25;
        productos[5].precio = 120;

        // Producto 7: Tarjeta gráfica Nvidia RTX 3080
        productos[6].id = 6;
        productos[6].nombre = "Tarjeta grafica Nvidia RTX 3080";
        productos[6].cantidad = 10;
        productos[6].precio = 800;

        // Producto 8: Memoria RAM DDR4 16GB
        productos[7].id = 7;
        productos[7].nombre = "Memoria RAM DDR4 16GB";
        productos[7].cantidad = 30;
        productos[7].precio = 80;

        // Producto 9: Cargador portátil USB-C
        productos[8].id = 8;
        productos[8].nombre = "Cargador portatil USB-C";
        productos[8].cantidad = 18;
        productos[8].precio = 25;

        // Producto 10: Webcam HD 1080p
        productos[9].id = 9;
        productos[9].nombre = "Webcam HD 1080p";
        productos[9].cantidad = 7;
        productos[9].precio = 40;

        cantidad_productos = 10;
    }
}

//@app_s1s