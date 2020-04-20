#include <math.h>
#include <iostream>
#include <iomanip>
using namespace std;

//Abaixo, alguns templates usados para testes
long double myFunction(long double x){
    //Grau2
    long double result = (pow(x,2) + 2*x + 1);
    
    //Grau 5
    //long double result = (pow(x,5)+2*pow(x,4)+3*x+1);

    //Grau 7
    //long double result = (pow(x,7) + 9*pow(x,6) + 7*pow(x,5) + 2*pow(x,4) +3*x + 1);

    return result;
}

long double Laguerre_2_Pontos(){
    long double x1 = 0.5857864376;
    long double x2 = 3.41421362;

    long double w1 = 0.8535533906;
    long double w2 = 0.1464466094;

    long double primeira = myFunction(x1)*w1;
    long double segunda = myFunction(x2)*w2;

    return (primeira+segunda);
}

long double Laguerre_3_Pontos(){
    long double x1 = 0.4157745568;
    long double x2 = 2.2942803603;
    long double x3 = 6.2899450829;

    long double w1 = 0.7110930099;
    long double w2 = 0.2785177336;
    long double w3 = 0.0103892565;

    long double primeira = myFunction(x1)*w1;
    long double segunda = myFunction(x2)*w2;
    long double terceira = myFunction(x3)*w3;

    return (primeira+segunda+terceira);    
}


//Função apenas usada para automação do cálculo dos pesos
long double Laguerre_5_grau(long double x){
    long double result = (-pow(x,5) + 25*pow(x,4) -200*pow(x,3) + 600*pow(x,2) - 600*x + 120)/120.00;

    return result;
}

//Função usada apenas para automação do cálculo dos pesos
long double getW(long double x){
    long double result = (x)/(25*pow(Laguerre_5_grau(x),2));

    return result;
}

long double Laguerre_4_Pontos(){
    long double x1 = 0.32254769;
    long double x2 = 1.7457611;
    long double x3 = 4.5366203;
    long double x4 = 9.3950709;

    long double w1 = 0.6031540979;
    long double w2 = 0.3574186946;
    long double w3 = 0.0388879083;
    long double w4 = 0.0005392947;

    long double primeira = myFunction(x1)*w1;
    long double segunda = myFunction(x2)*w2;
    long double terceira = myFunction(x3)*w3;
    long double quarta = myFunction(x4)*w4;

    return (primeira + segunda + terceira + quarta);
}

int main(){
    int pontos;
    long double result;

    cout << fixed << setprecision(8);
    
    cout << "Você está usando o método de Gauss-Laguerre!" << "\n";
    cout << "Observações: " << "\n";
    cout << "1) Os limites são de 0 a +infinito" << "\n";
    cout << "2) Insira no método 'myFuncion' o F(x) que deseja integrar" << "\n";
    cout << "3) Note que a parte e^(-x) não deve ser incluída" << "\n" << "\n";


    while(pontos !=0){
        cout << "Insira o número de pontos que deseja usar (2,3 ou 4), ou 0 para sair: ";
        cin >> pontos;


        if(pontos == 2){
            result = Laguerre_2_Pontos();
            cout << "O valor da integral é: " << result << "\n" << "\n";
        }
        else if(pontos == 3){
            result = Laguerre_3_Pontos();
            cout << "O valor da integral é: " << result << "\n" << "\n";
        }
        else if(pontos == 4){
            result = Laguerre_4_Pontos();
            cout << "O valor da integral é: " << result << "\n" << "\n";
        }
        else{
            cout << "Opção inválida! Tente novamente" << "\n" << "\n";
        }
    }

    return 0;
}