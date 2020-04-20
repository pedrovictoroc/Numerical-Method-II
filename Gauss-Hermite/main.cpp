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

long double Hermite_2_Pontos(){
    long double x1 = -0.7071067812;
    long double x2 = 0.7071067812;
    
    //W1=W2
    long double w1 = 0.8862269255;

    long double primeira = myFunction(x1)*w1;
    long double segunda = myFunction(x2)*w1;
    
    return (primeira+segunda);
}

long double Hermite_3_Pontos(){
    long double x1 = -1.224744871;
    long double x2 = 0;
    long double x3 = 1.224744871;

    //W1=W3
    long double w1 = 0.2954089752;
    long double w2 = 1.181635901;

    long double primeira = myFunction(x1)*w1;
    long double segunda = myFunction(x2)*w2;
    long double terceira = myFunction(x3)*w1;

    return (primeira+segunda+terceira);
}

long double Hermite_4_Pontos(){
    long double x1 = -1.650680124;
    long double x2 = -0.5246476233;
    long double x3 = 0.5246476233;
    long double x4 = 1.650680124;

    //W1=W4 && W2=W3
    long double w1 = 0.08131283537;
    long double w2 = 0.8049140899;

    long double primeira = myFunction(x1)*w1;
    long double segunda = myFunction(x2)*w2;
    long double terceira = myFunction(x3)*w2;
    long double quarta = myFunction(x4)*w1;

    return (primeira+segunda+terceira+quarta);
}

int main(){
int pontos;
    long double result;

    cout << fixed << setprecision(8);
    
    cout << "Você está usando o método de Gauss-Hermite!" << "\n";
    cout << "Observações: " << "\n";
    cout << "1) Os limites são de -infinito a +infinito" << "\n";
    cout << "2) Insira no método 'myFuncion' o F(x) que deseja integrar" << "\n";
    cout << "3) Note que a parte e^(-x^2) não deve ser incluída" << "\n" << "\n";


    while(pontos !=0){
        cout << "Insira o número de pontos que deseja usar (2,3 ou 4), ou 0 para sair: ";
        cin >> pontos;


        if(pontos == 2){
            result = Hermite_2_Pontos();
            cout << "O valor da integral é: " << result << "\n" << "\n";
        }
        else if(pontos == 3){
            result = Hermite_3_Pontos();
            cout << "O valor da integral é: " << result << "\n" << "\n";
        }
        else if(pontos == 4){
            result = Hermite_4_Pontos();
            cout << "O valor da integral é: " << result << "\n" << "\n";
        }
        else{
            cout << "Opção inválida! Tente novamente" << "\n" << "\n";
        }
    }
    
    return 0;
}