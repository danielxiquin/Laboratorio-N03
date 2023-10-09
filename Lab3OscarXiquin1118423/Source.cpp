#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <math.h>
#include <stdio.h>


using namespace std;


int fibonachi(int numero) {
	if (numero == 0) {
		return 0;
	}
	if (numero == 1) {
		return 1;
	}
	return fibonachi(numero - 1) + fibonachi(numero - 2);
}

int factorial(int numero) {

	
	if (numero == 1 || numero == 0) {
		return 1;
	}

	return numero * factorial(numero - 1); 
}

int binary(int numero) {

	if (numero == 0) {
		return 0; 
	}

	int digit = numero % 2;
	return digit + 10 * binary(numero / 2);
}




int main() {

	int eleccion1;
	cout << "MENU DE ELECCIÓN" << endl;
	cout << "1. Calculo de fibonachi" << endl;
	cout << "2. Calculo de factorial" << endl;
	cout << "3. Conversion de numero" << endl;
	cout << "4. Salir" << endl;

	cin >> eleccion1;

	if (eleccion1 < 1 || eleccion1 >4) {
		cout << "\033[2J\033[1;1H";

		cout << "El numero seleccionado no es una opción a elegir" << endl;



	}

	if (eleccion1 == 1) {
		cout << "\033[2J\033[1;1H";

		int num;
		cout << "Ingrese el numero para el calculo de fibonachi" << endl;
		cin >> num;
		cout << "El calculo fibonachi del numero es: " << fibonachi(num) << endl;

		
	}
	if (eleccion1 == 2) {
		cout << "\033[2J\033[1;1H";

		int num2;
		cout << "Ingrese el numero para el calculo de factorial" << endl;
		cin >> num2;
		cout << "El calculo del factorial de !" << num2 << " es: " << factorial(num2) << endl;

	}
	if (eleccion1 == 3) {

		cout << "\033[2J\033[1;1H";

		int eleccion;

		cout << "MENU DE ELECCIÓN" << endl;
		cout << "1. Numero a binario" << endl;
		cout << "2. Archivo a binario" << endl;
		cin >> eleccion;

		if (eleccion < 1 || eleccion >2) {
			cout << "\033[2J\033[1;1H";

			cout << "El numero seleccionado no es una opción a elegir" << endl;

		}

		if (eleccion == 1) {
			cout << "\033[2J\033[1;1H";

			int numero1;
			cout << "Ingrese el numero a convertir" << endl;
			cin >> numero1;
			cout << "El numero en binario es: " << binary(numero1) << endl;

		}

		if (eleccion == 2) {
			cout << "\033[2J\033[1;1H";

			ifstream archivo;

			archivo.open("archivos.csv", ios::in);

			if (archivo.fail()) {
				cout << "Error al abrir el archivo." << endl;
			}
			vector<string> convernumeros;
			vector<string> numerosiniciales;

			string numero;

			while (getline(archivo, numero, ';')) {

				numerosiniciales.push_back(numero);

				string nums = to_string(binary(stoi(numero)));

				convernumeros.push_back(nums);

			}

			archivo.close();

			cout << "Los numeros inciales del archivo son: " << endl;
			for (const string& inicial : numerosiniciales) {
				cout << inicial << ", ";
			}
			cout << endl;
			cout << "La conversion de lo numeros a binario son: " << endl;
			for (const string& binario : convernumeros) {
				cout << binario << ", ";
			}


			cout << endl;
		}
	}


	
	






	






}