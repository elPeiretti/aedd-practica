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
// char c1,c2,c3,c4,c5,c6,c7; estos son los caracteres de entrada con cada numero representado la pos en que se ingresa 
// yo me inclinaria por esta
// saber la posicion del caracter
// me va a resultar util y comodo

bool esLetra(char c){
	return c >= 'A' and c<='Z';
}
bool esDigito(char c){
	return c >= '0' and c<='9';
}

bool patenteArgentinaAuto(char c1, char c2, char c3, char c4, char c5, char c6, char c7){ 
	return esLetra(c1) and
		   esLetra(c2) and
		   esDigito(c3) and
		   esDigito(c4) and
		   esDigito(c5) and
		   esLetra(c6) and
		   esLetra(c7);
}

bool patenteArgentinaMoto(char c1, char c2, char c3, char c4, char c5, char c6, char c7){ 
	return esLetra(c1) and
		   esDigito(c2) and
		   esDigito(c3) and
		   esDigito(c4) and
		   esLetra(c5) and
		   esLetra(c6) and
		   esLetra(c7);
}

bool patenteBrasil(char c1, char c2, char c3, char c4, char c5, char c6, char c7){ 
	return esLetra(c1) and
		   esLetra(c2) and
		   esLetra(c3) and
		   esDigito(c4) and
		   esLetra(c5) and
		   esDigito(c6) and
		   esDigito(c7);
}

bool patenteBolivia(char c1, char c2, char c3, char c4, char c5, char c6, char c7){ 
	return esLetra(c1) and
		   esLetra(c2) and
		   esDigito(c3) and
		   esDigito(c4) and
		   esDigito(c5) and
		   esDigito(c6) and
		   esDigito(c7);
}

bool patenteParaguayAuto(char c1, char c2, char c3, char c4, char c5, char c6, char c7){ 
	return esLetra(c1) and
		   esLetra(c2) and
		   esLetra(c3) and
		   esLetra(c4) and
		   esDigito(c5) and
		   esDigito(c6) and
		   esDigito(c7);
}

bool patenteParaguayMoto(char c1, char c2, char c3, char c4, char c5, char c6, char c7){ 
	return esDigito(c1) and
		   esDigito(c2) and
		   esDigito(c3) and
		   esLetra(c4) and
		   esLetra(c5) and
		   esLetra(c6) and
		   esLetra(c7);
}

bool patenteUruguay(char c1, char c2, char c3, char c4, char c5, char c6, char c7){ 
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

bool esVehiculoOficial(char c6, char c7){
	int num = convertirAEntero(c6,c7);
	return esMultiploDe7(num); // chequeo si el numero es multiplo de 7
}

bool esVehiculoDiplomatico(char c1, char c2){
	return c1 == 'V' and c2 == 'D';
}

bool esVehiculoDeColeccion(char c1, char c2, char c3, char c4, char c5, char c6, char c7){ // por transitividad si A = B y A = C -> B = C
	return c1 == c2 and c1 == c3 and c4 == c5 and c4 == c6 and c4 == c7; 
}

int main() {

	char c1,c2,c3,c4,c5,c6,c7;
	cin>>c1>>c2>>c3>>c4>>c5>>c6>>c7; // leo la entrada
	
	if(patenteArgentinaAuto(c1,c2,c3,c4,c5,c6,c7)){
		cout<<"La patente es Argetina y pertence a un auto"<<endl;
	}
	else if(patenteArgentinaMoto(c1,c2,c3,c4,c5,c6,c7)){
		cout<<"La patente es argetina y pertence a una moto"<<endl;
	}
	else if(patenteBrasil(c1,c2,c3,c4,c5,c6,c7)){
		cout<<"La patente es brasilera";
		// Chequeo si es vehiculo oficial
		if(esVehiculoOficial(c6,c7)) cout<<" y correspode a un vehiculo oficial";
		cout<<endl;
	}
	else if(patenteBolivia(c1,c2,c3,c4,c5,c6,c7)){
		cout<<"La patente es boliviana"<<endl;
		if(esVehiculoDiplomatico(c1,c2)) cout<<" y correspode a un vehiculo diplomatico";
		cout<<endl;
	}
	else if(patenteParaguayAuto(c1,c2,c3,c4,c5,c6,c7)){
		cout<<"La patente es paraguaya y pertence a un auto"<<endl;
	}
	else if(patenteParaguayMoto(c1,c2,c3,c4,c5,c6,c7)){
		cout<<"La patente es paraguaya y pertence a una moto"<<endl;
	}
	else if(patenteUruguay(c1,c2,c3,c4,c5,c6,c7)){
		cout<<"La patente es uruguaya"<<endl;
		if(esVehiculoDeColeccion(c1,c2,c3,c4,c5,c6,c7)) cout<<" y correspode a un vehiculo de colecion";
		cout<<endl;
	}
	else {
		cout<<"Datos invalidos"<<endl;
	}

	
	return 0;
}
