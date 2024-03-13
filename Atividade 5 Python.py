class Funcionario:
    def __init__(self):
        self.Nome = ""
        self.Departamento = 0
        self.HorasMes = 0
        self.HoraExtra = 0
        self.HorasAdicionais = 0
        self.SalarioBase = 0
        self.Insalubridade = 0
        self.Bonificacao = 0
        self.SalarioBruto = 0
        self.INSS = 0
        self.ImpostoDeRenda = 0
        self.PlanoDeSaude = 20
        self.SalarioLiquido = 0

def calcular_salario_base(funcionario):
    if funcionario.Departamento == 1:
        funcionario.SalarioBase = funcionario.HorasMes * 22
    else:
        funcionario.SalarioBase = funcionario.HorasMes * 12

def calcular_hora_extra(funcionario):
    if funcionario.HorasMes > 40:
        funcionario.HorasAdicionais = funcionario.HorasMes - 40
        if funcionario.Departamento == 1:
            funcionario.HoraExtra = 22 * 2 * funcionario.HorasAdicionais
        elif funcionario.Departamento == 2:
            funcionario.HoraExtra = 12 * 2 * funcionario.HorasAdicionais

def calcular_insalubridade(funcionario):
    if funcionario.Departamento == 2:
        funcionario.Insalubridade = funcionario.SalarioBase + (funcionario.SalarioBase * 0.15)

def calcular_bonificacao(funcionario):
    if funcionario.Departamento == 1:
        if funcionario.HorasMes >= 40:
            funcionario.Bonificacao = funcionario.SalarioBase * 0.1
        elif funcionario.HorasMes > 30:
            funcionario.Bonificacao = funcionario.SalarioBase * 0.05
        elif funcionario.HorasMes > 20:
            funcionario.Bonificacao = funcionario.SalarioBase * 0.03

def calcular_salario_bruto(funcionario):
    funcionario.SalarioBruto = (funcionario.SalarioBase + funcionario.HoraExtra + funcionario.Insalubridade
                                + funcionario.Bonificacao)
    funcionario.INSS = funcionario.SalarioBruto * 0.07

def calcular_imposto_de_renda(funcionario):
    funcionario.ImpostoDeRenda = funcionario.SalarioBruto * 0.12

def calcular_salario_liquido(funcionario):
    funcionario.SalarioLiquido = (funcionario.SalarioBruto - funcionario.INSS - funcionario.ImpostoDeRenda
                                  - funcionario.PlanoDeSaude)

def converter_departamento(funcionario):
    if funcionario.Departamento == 1:
        return "Departamento Administrativo"
    elif funcionario.Departamento == 2:
        return "Departamento de Producao"
    else:
        return "Departamento Invalido!!"

def main():
    funcionarios = [Funcionario() for _ in range(5)]
    print("\t\t\t\t\t CALCULO SALARIO FUNCIONARIO-CSS \n\n\n\n")

    for i in range(5):
        funcionarios[i].Nome = input("Qual o nome do funcionario {}:".format(i+1))
        while True:
            funcionarios[i].Departamento = int(input("Qual o numero do departamento (1 = Administrativo / 2 = Producao) de "
                                             "{}: ".format(funcionarios[i].Nome)))
            if funcionarios[i].Departamento != 1 and funcionarios[i].Departamento != 2:
                print("Numero de Departamento não é valido")
            else:
                break
        funcionarios[i].HorasMes = float(input("Informe o numero de horas trabalhadas no mes de {}: ".format(funcionarios[i].Nome)))

        calcular_salario_base(funcionarios[i])
        calcular_hora_extra(funcionarios[i])
        calcular_insalubridade(funcionarios[i])
        calcular_bonificacao(funcionarios[i])
        calcular_salario_bruto(funcionarios[i])
        calcular_imposto_de_renda(funcionarios[i])
        calcular_salario_liquido(funcionarios[i])

    for i in range(5):
        print("\t\t\t\t\tFolha de Pagamento -", funcionarios[i].Nome)
        print("Nome:", funcionarios[i].Nome)
        print("Departamento:", funcionarios[i].Departamento, "-", converter_departamento(funcionarios[i]))
        print("Horas Trabalhadas:", funcionarios[i].HorasMes)
        print("Salario Base:", funcionarios[i].SalarioBase)
        print("Valor a pagar Hora Extra:", funcionarios[i].HoraExtra)
        print("Horas adicionais:", funcionarios[i].HorasAdicionais)
        print("Insalubridade:", funcionarios[i].Insalubridade)
        print("Bonificacao:", funcionarios[i].Bonificacao)
        print("Salario Bruto:", funcionarios[i].SalarioBruto)
        print("INSS:", funcionarios[i].INSS)
        print("Imposto de Renda:", funcionarios[i].ImpostoDeRenda)
        print("Valor Plano de Saude:", funcionarios[i].PlanoDeSaude)
        print("Salario Liquido:", funcionarios[i].SalarioLiquido)

if __name__ == "__main__":
    main()
