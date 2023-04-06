/*
Author: Jose Angel Garcia Gomez
Date: 30/11/2020
Description: This program is an application that simulates a software for a clothes store.
The user can add products to the inventory, add clients, register the purchases of a client,
see the information of a client, calculate the reward that the client will acquire (wallet $),
see the inventory, enter the data of the provider, see the data of the provider,
make a purchase to the provider, enter the data of the owner, see the data of the owner,
register a loan, register that he already paid a loan, see the debt he has. 
*/

#include <iostream>
#include <string>
#include "inventario.h"
#include "dueno.h"
using namespace std;

int main( ){
    int res {};
    Inventario inv;
    Dueno d1; // Esto es parte de la implementacion de la programacion individual de Erika
    while(res != 15){
        cout<<"\n~~Ingresa un numero de acuerdo a la opcion que quieras elegir.~~\n"<<endl;
        cout<<"\t1. Agregar productos al inventario. \n";
        cout<<"\t2. Dar de alta a un cliente. \n";
        cout<<"\t3. Registrar las compras de un cliente. \n";
        cout<<"\t4. Ver informacion del cliente. \n";
        cout<<"\t5. Calcular la recompensa que va a adquir el cliente (monedero $). \n";
        cout<<"\t6. Ver inventario. \n";
        cout<<"\t7. Ingresar datos del proveedor. \n";// Esto es parte de la implementacion de la programacion individual de Angel
        cout<<"\t8. Ver datos del proveedor. \n";// Esto es parte de la implementacion de la programacion individual de Angel
        cout<<"\t9. Hacer pedido al proveedor. \n";// Esto es parte de la implementacion de la programacion individual de Angel
        cout<<"\t10. Registrar datos del dueno. \n";// Esto es parte de la implementacion de la programacion individual de Erika
        cout<<"\t11. Ver datos del dueno. \n";// Esto es parte de la implementacion de la programacion individual de Erika
        cout<<"\t12. Registrar un prestamo. \n";// Esto es parte de la implementacion de la programacion individual de Erika
        cout<<"\t13. Registrar que ya pago un prestamo. \n";// Esto es parte de la implementacion de la programacion individual de Erika
        cout<<"\t14. Ver la deuda que tiene. \n";// Esto es parte de la implementacion de la programacion individual de Erika
        cout<<"\t15. Salir. \n";
        cout<<"Opcion: "; cin>>res;

        switch (res)
        {
        case 1:
            cout<<endl;
            cout<<inv.agregar_producto()<<endl;
            break;
        case 2:
            cout<<endl;
            cout<<inv.agregar_Clientes()<<endl;
            break;
        case 3:
            if (inv.getProductos().size()==0 || inv.getClientes().size() == 0 || /* Esto es parte de la implementacion de la programacion individual de Angel -> */inv.getProveedor().getId_proveedor() == 0){
                cout<<"No hay productos o clientes o proveedor dados de alta."<<endl;
                break;
            }
            else{
               inv.borrar_producto();
            }
            cout<<endl;
            break;
        case 4: 
            if (inv.getClientes().size()==0){
                cout<<"No hay clientes dados de alta."<<endl;
                break;

            }   
            else{
                inv.mostrar_atributos_cliente();
            }
            break;
        case 5:
            if (inv.getClientes().size()==0 ){  
                cout<<"No se han ingresado clientes."<<endl;
                break;            
            }
            else{
               for (int i = 0; i<inv.getClientes().size(); i++){
                    if (inv.getClientes()[i].getCompras() >= 5){
                        inv.recompensa_tipo_cliente();
                        break;
                    }
                    else{
                        cout<<"No hay suficientes compras para calcular una recompensa."<<endl;
                        break;
                    }
                } 
            }
            break;
        case 6:
            if(inv.getProductos().size()==0){
                cout<<"El inventario está vacío."<<endl;
                break;
            }
            else{
                inv.mostrar_atributos_producto();
                cout<<inv.mostrar_disponible()<<endl;
                break;
            }
            break;
        case 7:// Esto es parte de la implementacion de la programacion individual de Angel
            inv.agregar_datos_proveedor();
            break;
        case 8:// Esto es parte de la implementacion de la programacion individual de Angel
            if (inv.getProveedor().getId_proveedor() == 0){
                cout << "\nNo hay proveer que mostrar, favor de ingresar antes un proveedor. \n" << endl;
                break;
            }
            else{
                inv.mostrar_atributos_proveedor();
                break;
            }
            break;
        case 9:// Esto es parte de la implementacion de la programacion individual de Angel
            inv.hacer_pedido();
            break;
        case 10: // Esto es parte de la implementacion de la programacion individual de Erika
             d1.registrar_datos_dueno();//Parte individual hecha por Erika
             break;
        case 11:
            if (d1.getId_dueno() == 0){
                cout << "\nNo hay ningun dueno registrado, favor de ingresar antes un dueno. \n" << endl;
                break;
            }    
            else{
                cout<<d1.print_info_dueno()<<endl;//Parte individual hecha por Erika     
            cout<<endl;
            break;
            } 
        case 12:
            d1.registrar_prestamo();//Parte individual hecha por Erika
            cout<<endl;
            break;
        case 13:
            if(d1.getPrestamo_cantidad()==0){
                cout<<"\nNo ha pedido ningun prestamo.\n"<<endl;
                break;
            }
            else{
            d1.registrar_pago_prestamo();//Parte individual hecha por Erika
            cout<<endl;
            break;                
            }
        case 14://Parte individual hecha por Erika
            if(d1.getPrestamo_cantidad()==0){
                cout<<"\nNo ha pedido ningun prestamo.\n"<<endl;
                cout<<endl;
                break;
            } 
            else{
                d1.mostrar_deuda();
                cout<<endl;
                break; 
            } 
        }//switch
    }//while
};//main