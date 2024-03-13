#include <iostream>
#include <string>
using namespace std;

typedef struct{
    string Nome;
    int Departamento = 0;
    float HorasMes = 0;
    float HoraExtra = 0;
    float HorasAdicionais = 0;
    float SalarioBase = 0;
    float Insalubridade = 0;
    float Bonificacao= 0;
    float SalarioBruto = 0;
    float INSS = 0;
    float ImpostoDeRenda = 0;
    int PlanoDeSaude = 20;
    float SalarioLiquido;
} funcionario;





void calcularSalarioBase(funcionario &vFuncionarios){
    if(vFuncionarios.Departamento == 1){
        vFuncionarios.SalarioBase = vFuncionarios.HorasMes * 22;
    }else {
        vFuncionarios.SalarioBase = vFuncionarios.HorasMes * 12;
    }
}




void calcularHoraExtra(funcionario &vFuncionarios){
    if(vFuncionarios.HorasMes > 40){
        vFuncionarios.HorasAdicionais = vFuncionarios.HorasMes - 40;
     if(vFuncionarios.Departamento == 1)
        vFuncionarios.HoraExtra = 22 * 2 * vFuncionarios.HorasAdicionais;
     else if(vFuncionarios.Departamento == 2)
         vFuncionarios.HoraExtra = 12 * 2 * vFuncionarios.HorasAdicionais;
    }
}




void calcularInsalubridade(funcionario &vFuncionarios){
        if(vFuncionarios.Departamento == 2){
        vFuncionarios.Insalubridade = vFuncionarios.SalarioBase + (vFuncionarios.SalarioBase * 0.15);
    }
}




void calcularBonificacao(funcionario &vFuncionarios){
    if(vFuncionarios.Departamento == 1){
        if(vFuncionarios.HorasMes >= 40){
            vFuncionarios.Bonificacao = vFuncionarios.SalarioBase * 0.1;
        } else if(vFuncionarios.HorasMes > 30){
            vFuncionarios.Bonificacao = vFuncionarios.SalarioBase * 0.05;
        } else if(vFuncionarios.HorasMes > 20){
            vFuncionarios.Bonificacao = vFuncionarios.SalarioBase * 0.03;
        }
    }
}




void calcularSalarioBruto(funcionario &vFuncionarios){
    vFuncionarios.SalarioBruto = vFuncionarios.SalarioBase + vFuncionarios.HoraExtra + vFuncionarios.Insalubridade + vFuncionarios.Bonificacao;
    vFuncionarios.INSS = vFuncionarios.SalarioBruto * 0.07;
}




void calcularImpostoDeRenda(funcionario &vFuncionarios){
    vFuncionarios.ImpostoDeRenda = vFuncionarios.SalarioBruto * 0.12;
}




void calcularSalarioLiquido(funcionario &vFuncionarios){
    vFuncionarios.SalarioLiquido = vFuncionarios.SalarioBruto - vFuncionarios.INSS - vFuncionarios.ImpostoDeRenda - vFuncionarios.PlanoDeSaude;
}




string converterDepartamento(funcionario &vFuncionarios){
    switch (vFuncionarios.Departamento) {
        case 1 : return "Departamento Administrativo";
        case 2 : return "Departamento de Producao";
        default: return "Departamento Invalido!!";
    }
}

int main() {
    funcionario vFuncionarios[5];
    cout << "\t\t\t\t\t CALCULO SALARIO FUNCIONARIO-CSS \n\n\n\n";



    for(int i = 0; i < 5; i++){
        cout << "Qual o nome do funcionario "<< i+1 <<": " << endl;
        getline(cin, vFuncionarios[i].Nome);

        do {
            cout << "Qual o numero do departamento (1 = Administrativo / 2 = Producao) de " << vFuncionarios[i].Nome << ": " << endl;
            cin >> vFuncionarios[i].Departamento;

            if (vFuncionarios[i].Departamento != 1 && vFuncionarios[i].Departamento != 2){
                cout << "Numero de Departamento não é valido" << endl;
            }

        } while (vFuncionarios[i].Departamento != 1 && vFuncionarios[i].Departamento != 2);

        cout << "informe o numero de horas trabalhadas no mes de " << vFuncionarios[i].Nome << ": " << endl;
        cin >> vFuncionarios[i].HorasMes;

        calcularSalarioBase(vFuncionarios[i]);
        calcularHoraExtra(vFuncionarios[i]);
        calcularInsalubridade(vFuncionarios[i]);
        calcularBonificacao(vFuncionarios[i]);
        calcularSalarioBruto(vFuncionarios[i]);
        calcularImpostoDeRenda(vFuncionarios[i]);
        calcularSalarioLiquido(vFuncionarios[i]);
        cin.ignore();
    }



    for (int i = 0; i < 5; i++){


        cout << "\t\t\t\t\tFolha de Pagamento - " << vFuncionarios[i].Nome << endl;
        cout << "Nome: " << vFuncionarios[i].Nome << endl;
        cout << "Departamento: " << vFuncionarios[i].Departamento << "-" << converterDepartamento(vFuncionarios[i]) << endl;
        cout << "Horas Trabalhadas: " << vFuncionarios[i].HorasMes << endl;
        cout << "Salario Base: " << vFuncionarios[i].SalarioBase << endl;
        cout << "Valor a pagar Hora Extra: " << vFuncionarios[i].HoraExtra << endl;
        cout << "Horas adicionais: " << vFuncionarios[i].HorasAdicionais << endl;
        cout << "Insalubridade: " <<vFuncionarios[i].Insalubridade << endl;
        cout << "Bonificacao: " << vFuncionarios[i].Bonificacao << endl;
        cout << "Salario Bruto: " << vFuncionarios[i].SalarioBruto << endl;
        cout << "INSS : " << vFuncionarios[i].INSS << endl;
        cout << "Imposto de Renda: " << vFuncionarios[i].ImpostoDeRenda << endl;
        cout << "Valor Plano de Saude :" << vFuncionarios[i].PlanoDeSaude << endl;
        cout << "Salario Liquido: " << vFuncionarios[i].SalarioLiquido << endl;


    }
}
