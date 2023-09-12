#include<iostream>
#include<locale>

int main(){

    int value1, value2, result;
    char op;

    std::cout.width(20);
    std::cout << "<<< Calculadora >>>\n\n" << std::endl;

    std::cout << "Digite o primeiro valor: ";
    std::cin >> value1;

    std::cout << "Digite o segundo valor: ";
    std::cin >> value2;

    std::cout << "\n***Digite o operador***\n\n"
    "> Adicao: +\n> Subtracao: -\n> Multiplicacao: *\n> Divisao: /\n"
    "> AND bitwise: &\n> OR bitwise: |\n> XOR bitwise: ^\n" << std::endl;
    
    std::cout << "\nDigite: ";
    std::cin >> op;

    switch(op){
        case '+':
            result = value1 + value2;
            break;
        case '-':
            result = value1 - value2;
            break;
        case '*':
            result = value1 * value2;
            break;
        case '/':
            if(value1 == 0 || value2 == 0){
                std::cout << "Operacao invalida! Impossivel dividir por 0.\n";
                system("pause");
                return 0;
                break;
            }
            std::cout << "\nResultado: " << (float)value1 / value2 << std:: endl;
            system("pause");
            break;
        case '&':
            result = value1 & value2;
            break;
        case '|':
            result = value1 | value2;
            break;
        case '^':
            result = value1 ^ value2;
            break;
        default:
            std::cout << "Operação inválida, tente novamente";
            return 0;
            break;
    }

    std::cout << "\nResultado: " << result << std:: endl;

    system("pause");

    return 0;
}