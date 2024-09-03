#include <iostream>
using namespace std;

int sumaDigitosCuadrados(int num) {
	int suma = 0;
	
	while(num>0) {
		int digito = num%10;
		suma += digito*digito;
		num/=10;
	}
	
	return suma;
}

bool esFeliz(int num) {
	
	int resultado = sumaDigitosCuadrados(num);
	while(resultado > 9) {
		resultado = sumaDigitosCuadrados(resultado);
	}
	
	return resultado == 1 || resultado == 7;
}

int main(int argc, char *argv[]) {
	
	int x,y; cin>>x>>y;
	
	bool hayFelices=false;
	for(int i=x; i<=y; i++){
		if (esFeliz(i)) {
			cout<<i<<endl;
			hayFelices = true;
		}
	}
	
	if (!hayFelices)
		cout<<"Sin numeros"<<endl;
	
	return 0;
}
