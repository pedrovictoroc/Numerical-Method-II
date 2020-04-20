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

//Implementado apenas para teste e comprovação de resultados
//não utilizado no código
long double getChebyshevRoots(int k, int n){
    long double result = cos(((2*k -1)/(2.0*n))*3.141592654);

    return result;
}

long double Chebyshev_2_Pontos(){
    long double x1 = -0.7071067812;
    long double x2 = 0.7071067812;

    //W1=W2
    long double w1 = 1.570796327;

    long double primeira = myFunction(x1)*w1;
    long double segunda = myFunction(x2)*w1;
    
    return (primeira+segunda);
}

long double Chebyshev_3_Pontos(){
    long double x1 = -0.8660254038;
    long double x2 = 0;
    long double x3 = 0.8660254038;

    //W1=W2=W3
    long double w1 = 1.047197551;

    long double primeira = myFunction(x1)*w1;
    long double segunda = myFunction(x2)*w1;
    long double terceira = myFunction(x3)*w1;
    
    return (primeira+segunda+terceira);
}

long double Chebyshev_4_Pontos(){
    long double x1 = -0.9238795325;
    long double x2 = -0.3826834324;
    long double x3 = 0.3826834324;
    long double x4 = 0.9238795325;

    //W1=W2=W3=W4
    long double w1 = 0.7853981634;

    long double primeira = myFunction(x1)*w1;
    long double segunda = myFunction(x2)*w1;
    long double terceira = myFunction(x3)*w1;
    long double quarta = myFunction(x4)*w1;

    return (primeira+segunda+terceira+quarta);
}

int main(){
    int pontos;
    long double result;

    cout << fixed << setprecision(8);
    
    cout << "Você está usando o método de Gauss-Chebyshev!" << "\n";
    cout << "Observações: " << "\n";
    cout << "1) Os limites são de -1 a 1" << "\n";
    cout << "2) Insira no método 'myFuncion' o F(x) que deseja integrar" << "\n";
    cout << "3) Note que a parte 1/(1-x^2)^(1/2) não deve ser incluída" << "\n" << "\n";


    while(pontos !=0){
        cout << "Insira o número de pontos que deseja usar (2,3 ou 4), ou 0 para sair: ";
        cin >> pontos;


        if(pontos == 2){
            result = Chebyshev_2_Pontos();
            cout << "O valor da integral é: " << result << "\n" << "\n";
        }
        else if(pontos == 3){
            result = Chebyshev_3_Pontos();
            cout << "O valor da integral é: " << result << "\n" << "\n";
        }
        else if(pontos == 4){
            result = Chebyshev_4_Pontos();
            cout << "O valor da integral é: " << result << "\n" << "\n";
        }
        else{
            cout << "Opção inválida! Tente novamente" << "\n" << "\n";
        }
    }

    return 0;
}