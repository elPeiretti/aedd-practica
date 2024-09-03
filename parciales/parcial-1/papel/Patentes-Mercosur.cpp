#include <bits/stdc++.h>

using namespace std;

// A G 8 3 6 U D
// D J A U 8 2 6
// Los numeros que me dan siempre estan entre 0 y 9,
// por lo tanto los numeros tambien entran en un char

// Voy a leer todo como char
// Opcion 1:
//~ char a,b,c,d,e,f,g;
// Opcion 2:
char c1,c2,c3,c4,c5,c6,c7; // estos son los caracteres de entrada con cada numero representado la pos en que se ingresa 
// yo me inclinaria por esta
// saber la posicion del caracter
// me va a resultar util y comodo

bool esLetra(char c){
	return c >= 'A' and c<='Z';
}
bool esDigito(char c){
	return c >= '0' and c<='9';
}

bool patenteArgentinaAuto(){ 
	return esLetra(c1) and
		   esLetra(c2) and
		   esDigito(c3) and
		   esDigito(c4) and
		   esDigito(c5) and
		   esLetra(c6) and
		   esLetra(c7);
}

bool patenteArgentinaMoto(){ 
	return esLetra(c1) and
		   esDigito(c2) and
		   esDigito(c3) and
		   esDigito(c4) and
		   esLetra(c5) and
		   esLetra(c6) and
		   esLetra(c7);
}

bool patenteBrasil(){ 
	return esLetra(c1) and
		   esLetra(c2) and
		   esLetra(c3) and
		   esDigito(c4) and
		   esLetra(c5) and
		   esDigito(c6) and
		   esDigito(c7);
}

bool patenteBolivia(){ 
	return esLetra(c1) and
		   esLetra(c2) and
		   esDigito(c3) and
		   esDigito(c4) and
		   esDigito(c5) and
		   esDigito(c6) and
		   esDigito(c7);
}

bool patenteParaguayAuto(){ 
	return esLetra(c1) and
		   esLetra(c2) and
		   esLetra(c3) and
		   esLetra(c4) and
		   esDigito(c5) and
		   esDigito(c6) and
		   esDigito(c7);
}

bool patenteParaguayMoto(){ 
	return esDigito(c1) and
		   esDigito(c2) and
		   esDigito(c3) and
		   esLetra(c4) and
		   esLetra(c5) and
		   esLetra(c6) and
		   esLetra(c7);
}

bool patenteUruguay(){ 
	return esLetra(c1) and
		   esLetra(c2) and
		   esLetra(c3) and
		   esDigito(c4) and
		   esDigito(c5) and
		   esDigito(c6) and
		   esDigito(c7);
}


int convertirAEntero(char a, char b){ // 6 4 = 60 + 4
	return (a - '0') * 10 + (b - '0');
}

bool esMultiploDe7(int num){
	return num % 7 == 0;
}

bool esVehiculoOficial(){
	int num = convertirAEntero(c6,c7);
	return esMultiploDe7(num); // chequeo si el numero es multiplo de 7
}

bool esVehiculoDiplomatico(){
	return c1 == 'V' and c2 == 'D';
}

bool esVehiculoDeColeccion(){ // por transitividad si A = B y A = C -> B = C
	return c1 == c2 and c1 == c3 and c4 == c5 and c4 == c6 and c4 == c7; 
}

int main() {

	cin>>c1>>c2>>c3>>c4>>c5>>c6>>c7; // leo la entrada
	
	if(patenteArgentinaAuto()){
		cout<<"La patente es Argetina y pertence a un auto"<<endl;
	}
	else if(patenteArgentinaMoto()){
		cout<<"La patente es argetina y pertence a una moto"<<endl;
	}
	else if(patenteBrasil()){
		cout<<"La patente es brasilera";
		// Chequeo si es vehiculo oficial
		if(esVehiculoOficial()) cout<<" y correspode a un vehiculo oficial";
		cout<<endl;
	}
	else if(patenteBolivia()){
		cout<<"La patente es boliviana"<<endl;
		if(esVehiculoDiplomatico()) cout<<" y correspode a un vehiculo diplomatico";
		cout<<endl;
	}
	else if(patenteParaguayAuto()){
		cout<<"La patente es paraguaya y pertence a un auto"<<endl;
	}
	else if(patenteParaguayMoto()){
		cout<<"La patente es paraguaya y pertence a una moto"<<endl;
	}
	else{
		cout<<"La patente es uruguaya"<<endl;
		if(esVehiculoDeColeccion()) cout<<" y correspode a un vehiculo de colecion";
		cout<<endl;
	}

	
	return 0;
}
