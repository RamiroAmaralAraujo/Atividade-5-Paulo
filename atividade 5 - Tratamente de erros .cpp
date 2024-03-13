#include <iostream>
using namespace std;

double divide(double a, double b) {
    if (b == 0) {
        throw "Divisão por zero não é permitida.";
    }
    return a / b;
}

int main() {
    double num1, num2;
    cout << "Digite o numerador: ";
    cin >> num1;
    cout << "Digite o denominador: ";
    cin >> num2;

    try {
        double resultado = divide(num1, num2);
        cout << "O resultado da divisão é: " << resultado << endl;
    }
    catch (const char* errorMessage) {
        cout << "Erro: " << errorMessage << endl;
    }
    finally {
        cout << "Programa finalizado." << endl;
    }

    return 0;
}
