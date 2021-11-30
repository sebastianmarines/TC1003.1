#include <iostream>
#include <iomanip>
#include "Persona.hpp"
#include "Tienda.hpp"
#include "Producto.hpp"

using namespace std;

int menu();

int main()
{
    vector<Persona> listaDePersonas;
    vector<Tienda> listaDeTiendas;
    while (true)
    {
        switch (menu())
        {
        case 1:
        {

            string nombre;
            string apellido;
            cout << "Ingrese el nombre: ";
            cin >> nombre;
            cout << "Ingrese el apellido: ";
            cin >> apellido;
            Persona persona(nombre, apellido);
            cout << persona.getNombre() << " " << persona.getApellido() << endl;
            listaDePersonas.push_back(persona);
            break;
        }
        case 2:
        {
            string nombre;
            cout << "Ingrese el nombre de la tienda: ";
            cin >> nombre;
            Tienda tienda(nombre);
            listaDeTiendas.push_back(tienda);
            break;
        }
        case 3:
        {
            string nombre;
            int precio;
            string nombreTienda;
            cout << "Ingrese el nombre de la tienda: ";
            cin >> nombreTienda;
            int posicion = -1;
            for (size_t i = 0; i < listaDeTiendas.size(); i++)
            {
                if (listaDeTiendas[i].getNombre() == nombreTienda)
                {
                    posicion = i;
                    break;
                }
            }
            if (posicion == -1)
            {
                cout << "No se encontro la tienda" << endl;
                break;
            }
            cout << "Ingrese el nombre del producto: ";
            cin >> nombre;
            cout << "Ingrese el precio del producto: ";
            cin >> precio;
            cout << "Ingrese el numero de productos: ";
            int numeroDeProductos;
            cin >> numeroDeProductos;
            Producto producto(nombre, precio);
            for (int j = 0; j < numeroDeProductos; j++)
            {
                listaDeTiendas[posicion].agregarProducto(producto);
            }
            cout << "Productos agregados exitosamente" << endl;
            break;
        }
        case 4:
        {
            cout << "TODO" << endl;
            break;
        }
        case 5:
        {
            string nombre;
            cout << "Ingrese el nombre de la tienda: ";
            cin >> nombre;
            bool encontrado = false;
            for (size_t i = 0; i < listaDeTiendas.size(); i++)
            {
                if (listaDeTiendas[i].getNombre() == nombre)
                {
                    listaDeTiendas[i].mostrarProductos();
                    encontrado = true;
                    break;
                }
                if (!encontrado)
                {
                    cout << "No se encontro la tienda" << endl;
                }
            }
            break;
        }
        default:
            return 0;
        }
    }
}

int menu()
{
    string separator = string(13, '-');
    cout << setw(13) << "MENU" << endl;
    cout << string(26, '=') << endl;
    cout << setw(10) << "1. Agregar persona" << endl;
    cout << setw(10) << "2. Agregar tienda" << endl;
    cout << setw(10) << "3. Agregar producto" << endl;
    cout << setw(10) << "4. Comprar producto" << endl;
    cout << setw(10) << "5. Mostrar productos" << endl;
    cout << setw(10) << "6. Mostrar productos por nombre" << endl;
    cout << setw(10) << "7. Mostrar productos por precio" << endl;
    cout << setw(10) << "8. Mostrar tiendas" << endl;
    cout << left << setw(10) << "9. Salir" << right << endl;
    cout << endl;

    int opcion;
    cout << "Ingrese una opcion: ";
    cin >> opcion;

    if (opcion > 9 || opcion < 1)
    {
        cout << "Opcion invalida" << endl;
        return menu();
    }
    return opcion;
}