#include <iostream>
#include <string>
#include <conio.h>

//Fila estatica

using namespace std;

const int TAM=5;

class empleado{
private:
	int ClaveEmpleado;
	string nombre;
	string domicilio;
	float sueldo;
	string reporta;
	public:
//metos costructores
	empleado(){
		ClaveEmpleado=0;
		nombre=" ";
		domicilio=" ";
		sueldo=0;
		reporta=" ";
	}
	empleado(int clave, string nom, string dom, float suel, string report){
    ClaveEmpleado=clave;
	 nombre=nom;
	 domicilio=dom;
	 sueldo=suel;
	 reporta=report;
	}
	friend ostream& operator<<(ostream& o, empleado& e){
	    o<<"Codigo: "<<e.ClaveEmpleado<<endl;
	    o<<"Nombre: "<<e.nombre<<endl;
	    o<<"Domicilio: "<<e.domicilio<<endl;
	    o<<"Sueldo: "<<e.sueldo<<endl;
	    o<<"Reporta: "<<e.reporta<<endl;
	}
	friend istream& operator>>(istream& in, empleado& e){
	    cout<<"Dame el codigo: ";
	    in>>e.ClaveEmpleado;
	    cout<<"Dame el nombre: ";
	    in>>e.nombre;
	    cout<<"Dame el domicilio: ";
	    in>>e.domicilio;
	    cout<<"Dame el sueldo: ";
	    in>>e.sueldo;
	    cout<<"Dame a quien reporta: ";
	    in>>e.reporta;
	    return in;
	}

	int insertarclave(int clave){
	    ClaveEmpleado=clave;
	}
	bool operator==(empleado& p){
	    return(ClaveEmpleado==p.ClaveEmpleado);
	}
};

class Lista{
private:
    empleado datos[TAM];
    int ult;
public:
    Lista():ult(-1){}

    bool vacia()const{
        if(ult==-1){
            return true;
        }
        else{
            return false;
        }
    }
    bool llena()const{
        if(ult==TAM-1)
            return true;
        return false;
    }

    int ultimo()const{
        return ult;
    }

    int agrega(empleado elem){
        int i=ult+1;
        if(llena()){
            cout<<"Erros al insertar :(";
        }
        else{
            datos[i]=elem;
            ult++;
        }
    }

    int buscar(empleado elem){
        for(int i=0;i<=ult;i++){
            if(elem==datos[i]){
                cout<<"------------------"<<endl;
                cout<<datos[i];
            }
            else{
                cout<<"------------------"<<endl;
                cout<<"No hay resultados :(";
            }
        }
    }

    bool elimina(int pos){
        if(vacia() || pos<0 || pos>ult){
            cout<<"\n error de eliminacion";
            return true;
        }
        int i=pos;
        while(i<ult){
            datos[i]=datos[i+1];
            i++;
        }
        ult--;
        return false;
    }

    int inserta(empleado elem, int pos){
        if(llena()|| pos<0 || pos>ult+1){
            cout<<"\n Error de insercion";
            return 0;
        }
        int i=ult+1;
        while(i>pos){
            datos[i]=datos[i-1];
            i--;
        }
        datos[pos]=elem;
        ult++;
        return 1;
    }

    int muestra(){
        if(vacia()){
            cout<<"La lista esta vacia :("<<endl;
            cout<<"-------------------------"<<endl;
        }
        else{
            for(int i=0;i<=ult;i++){
                cout<<datos[i]<<endl;
                cout<<"-----------------"<<endl;
            }
        }
    }

//Sobre Carga
    friend ostream& operator<<(ostream& o, Lista& L){
        int i=0;
        cout<<"\n";
        while(i<=L.ultimo()){
            o<<L.datos[i];
            i++;
        }
        return o;
    }
    bool operator ==(Lista& L){
        for(int i=0;i<=ult;i++){
            if(datos[i]==L.datos[i]);
        }
    }
};

int main()
{
    empleado empleadito;
    Lista listita;
    int opcion, pos, clave;

    do {
        cout << "---Menu---" << endl;
        cout << "1. Agrega." << endl;
        cout << "2. Buscar" << endl;
        cout << "3. Elimina" << endl;
        cout << "4. Inserta" << endl;
        cout << "5. Muestra" << endl;
        cout << "6. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        system("cls");

        switch (opcion) {
            case 1:
                cout<<"---Agregar---"<<endl;
                cin>>empleadito;
                listita.agrega(empleadito);
                cout<<"-----------------"<<endl;
                cout<<"Se agrego correctamente :)";
                system("cls");
                break;

            case 2:
                cout<<"---Buscar---"<<endl;
                if(listita.vacia()){
                    cout<<"La lista esta vacia :(";
                }
                else{
                    cout<<"Dame la clave: ";
                    cin>>clave;
                    empleadito.insertarclave(clave);
                    listita.buscar(empleadito);
                }
                getch();
                system("cls");
                break;

            case 3:
                cout<<"---Eliminar---"<<endl;
                cout<<"Dame la posicion del empleado a eliminar: ";
                cin>>pos;
                pos=pos-1;
                listita.elimina(pos);
                cout<<"-----------------"<<endl;
                cout<<"Se elimino correctamente :)";
                system("cls");
                break;

            case 4:
                cout<<"---Insertar---"<<endl;
                cout<<"¿En que posicion desea insertar?";
                cin>>pos;
                pos=pos-1;
                cin>>empleadito;
                listita.inserta(empleadito,pos);
                cout<<"-----------------"<<endl;
                cout<<"Se inserto correctamente :)";
                system("cls");
                break;

            case 5:
                cout<<"---Muestra---"<<endl;
                listita.muestra();
                cout<<"Enter para continuar.";
                getch();
                system("cls");
                break;

            case 6:
                cout << "Adios c:" << endl;
                break;

            default:
                cout << "Opción no válida. Por favor, seleccione una opción válida." << endl;
                break;
        }
    } while (opcion != 6);

    return 0;
}
