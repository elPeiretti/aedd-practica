#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

void imprimirCategoriaYRecomendacion(double imc) {
	
	if (imc >= 30) {
		cout<<"Categoria: Obesidad"<<endl;
		cout<<"Consultar a un medico para un plan de perdida de peso."<<endl;
	}
	else if (imc >= 25){ //[25, 30)
		cout<<"Categoria: Sobrepeso"<<endl;
		cout<<"Sugerir un programa de ejercicio y una dieta balanceada."<<endl;
	}
	else if (imc >= 18.5) { // [18.5, 25)
		cout<<"Categoria: Peso normal"<<endl;
		cout<<"Mantener un estilo de vida saludable."<<endl;
	}
	else{ // menor que 18.5
		cout<<"Categoria: Bajo peso"<<endl;
		cout<<"Consultar a un nutricionista para aumentar el peso."<<endl;
	}
	
	cout << endl;
}

int main(int argc, char *argv[]) {

	double peso, altura, promedio=0;
	int cantPersonas = 0;
	
	cin>>peso;
	cout<<fixed<<setprecision(2);
	
	while(peso!=-1) {
		cin>>altura;
		
		double imc = peso/(altura*altura);
		cout<<"El IMC es: "<< imc << endl;
		
		imprimirCategoriaYRecomendacion(imc);
		
		promedio += peso;
		cantPersonas++;
		
		cin>>peso;
	}
	
	if (cantPersonas > 0)
		promedio = promedio / cantPersonas;
	cout<<"Promedio de Peso: "<< promedio << endl;
	
	return 0;
}

