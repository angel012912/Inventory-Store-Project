/*
Author: Jose Angel Garcia Gomez
Date: 30/11/2020
Description: This file is the definition of the class Dueno.
*/

#ifndef DUENO_C
#define DUENO_C

#include <iostream>
#include "inventario.h"
#include "cliente.h"
#include "producto.h"
#include <string>
using namespace std;

class Dueno{
    string nombre_dueno, correo_dueno;
    int telefono_dueno, id_dueno, prestamo;
    float prestamo_cantidad, pagar_cantidad, ganancia;
    Inventario inv;
    public:
    
    Dueno(){
        prestamo_cantidad = 0;
        pagar_cantidad = 0;
        id_dueno = 0;
    }
    Dueno(string nombre_dueno,string correo_dueno,int telefono_dueno,int id_dueno, int prestamo, float prestamo_cantidad, float pagar_cantidad,float ganancia, Inventario inv){
        this-> nombre_dueno = nombre_dueno;
        this-> correo_dueno = correo_dueno;
        this-> telefono_dueno = telefono_dueno;
        this->id_dueno = id_dueno;
        this->prestamo = prestamo;
        this->prestamo_cantidad = prestamo_cantidad;
        this->pagar_cantidad = pagar_cantidad;
        this->ganancia = ganancia;
        this->inv = inv;
    }
    string getNombre_dueno(){return nombre_dueno;}
    string getCorreo_dueno(){return correo_dueno;}
    int getTelefono_dueno(){return telefono_dueno;}
    int getId_dueno(){return id_dueno;}
    int getPrestamo(){return prestamo;}
    float getPrestamo_cantidad(){return prestamo_cantidad;}
    float getPagar_cantidad(){return pagar_cantidad;}
    float getGanancia(){return ganancia;}
    Inventario getInv(){return inv;}

    void setNombre_dueno(string nombre_dueno){this->nombre_dueno = nombre_dueno;}
    void setCorreo_dueno(string correo_dueno){this-> correo_dueno = correo_dueno;}
    void setTelefono_dueno(int telefono_dueno){this->telefono_dueno = telefono_dueno;}
    void setId_dueno(int id_dueno){this->id_dueno = id_dueno;}
    void setPrestamo(int prestamo){this->prestamo = prestamo;}
    void setPrestamo_cantidad(float prestamo_cantidad){this-> prestamo_cantidad = prestamo_cantidad;}
    void setPagara_cantidad(float pagar_cantidad){this->pagar_cantidad = pagar_cantidad;}
    void setGanancia(float ganancia){this->ganancia=ganancia;}
    void setInv(Inventario inv){this->inv=inv;}

void registrar_datos_dueno(){
            id_dueno++;
            string nombre;
            int telefono;
            string correo;
            cin.ignore(32767,'\n');
            cout<<endl;            
            cout<<"Sea usted bienvenid@"<<endl;
            cout << "Ingrese su nombre: ", getline(cin, nombre);
            cout << "Ingresa su correo: ",  getline(cin, correo);
            cout << "Ingresa su telefono: "; cin>>telefono; 
            cout<<endl;
            setId_dueno(id_dueno);
            setCorreo_dueno(correo);
            setTelefono_dueno(telefono);
            setNombre_dueno(nombre);
}
string print_info_dueno(){
        return "Dueno: \n\tID: "+to_string(id_dueno)+"\n\tNombre: "+nombre_dueno+"\n\tCorreo: "+correo_dueno+"\n\tTelefono: "+to_string(telefono_dueno)+"\n";

    }
int registrar_prestamo(){
    cout<<"¿Ha usted pedido un prestamo? (si = 1, no = 0) "; cin>>prestamo;
    switch(prestamo){
    case 1:
        cout<<"¿Cuánto dinero pidió prestado? "; cin>>prestamo_cantidad;
        return prestamo_cantidad;
        break;
    case 0:
        cout<<"Hasta luego."<<endl;
        return prestamo_cantidad;
        break;
    default:
        cout<<"La opcion ingresada no es valida."<<endl;
        return prestamo_cantidad;
        break;
    }
  }
void registrar_pago_prestamo(){
    int pagar;
    cout<<"\n¿Ha pagado alguna de sus deudas? (si=1, no=0) ";cin>>pagar;
    switch(pagar){
        case  1:
            cout<<"¿Cuánto dinero ha pagado de sus deudas? ";cin>>pagar_cantidad;
            break;
        case 0:
            break;
        default:
            cout<<"La opcion ingresada no es valida."<<endl;
        break;
    }
}
void mostrar_deuda(){
    if (prestamo_cantidad == 0){
        cout<<"\nLa deuda ya se pago\n"<<endl;
    }
    else{
        prestamo_cantidad = prestamo_cantidad - pagar_cantidad;
        cout<<"\nLa deuda es de: $" + to_string(prestamo_cantidad)+"\n"<<endl;
    }
}
};//Clase dueño
#endif