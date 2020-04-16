#include <math.h>
#include <iostream>
#include <iomanip>
using namespace std;

long double getXAlpha(long double inicio, long double fim, long double alpha){
    
    long double result = ((inicio + fim)/2) + ((fim - inicio)/2)*alpha;

    return result;
}

long double IntegratedLagrange1(long double alpha){
    long double result = - (alpha * (alpha*pow(3,(1/2)) -2)) /4;

    return result;
}

long double IntegratedLagrange2(long double alpha){
    long double result = (alpha*(alpha*pow(3,(1/2)) + 2))/4;

    return result;
}

long double getW1(){
    long double inicial = IntegratedLagrange1(-1);
    long double final = IntegratedLagrange1(1);
    
    return (final - inicial);
}

long double getW2(){
    long double inicial = IntegratedLagrange2(-1);
    long double final = IntegratedLagrange2(1);
    
    return (final - inicial);
}

long double myFunction(long double x){

    long double equation = (sin(2*x) + (4*pow(x,2)) + 3*x);
    long double finalResult = pow(equation,2);
    
    return finalResult;
}

long double calculateLegendreSecondeDegree(long double inicio, long double fim){
    long double alpha1 = - 0.5773502692;
    long double alpha2 = 0.5773502692;

    long double xAlpha1 = getXAlpha(inicio, fim, alpha1);
    
    long double xAlpha2 = getXAlpha(inicio, fim, alpha2);

    long double fXAlpha1 = myFunction(xAlpha1);
    long double fXAlpha2 = myFunction(xAlpha2);
    
    long double w1 = getW1();
    long double w2 = getW2();

    long double primeiro = fXAlpha1*w1;
    long double segundo = fXAlpha2*w2;

    long double result = ((fim - inicio)/2)*(primeiro+segundo);

    return result;
}

int main(){
    
    long double inicio;
    long double fim;


    cout << "Por padrão esse algoritmo usa a função benchmark das aulas!" << "\n";
    cout << "Caso deseja outra função, altere o método 'MyFuction'!" << "\n";
    cout << "Informe o limite inferior" << "\n"; 
    cin >> inicio;
    cout << "Informe o limite superior" << "\n"; 
    cin >> fim;
    
    long double result = calculateLegendreSecondeDegree(inicio, fim);

    long double erro = 1;    
    int n = 1;
    long double intervalo = fim - inicio;
    long double integralAnterior = result;

    int contadorVoltas = 0;
    
    while(erro > 0.000001){
        
        n = 2*n;
        contadorVoltas = contadorVoltas + 1;

        long double acumuladorIntervalo = 0;
        long double subIntervalo = intervalo / n;
        long double acumuladorIntegral = 0;
        int loopCounter = 0;
            
        while(acumuladorIntervalo < intervalo){
            acumuladorIntervalo = acumuladorIntervalo + subIntervalo;
            acumuladorIntegral = acumuladorIntegral + calculateLegendreSecondeDegree(inicio+(subIntervalo*loopCounter), inicio+(subIntervalo*(loopCounter+1)));
            loopCounter = loopCounter + 1;
        }

        erro = abs(acumuladorIntegral - integralAnterior);

        cout << fixed << setprecision(8);
        cout << "Volta: " << contadorVoltas << "| Integral: " << acumuladorIntegral << "| Erro: " << erro << "\n";

        if(erro > 0.000001){
            integralAnterior = acumuladorIntegral;
        }
    }

    cout << "Aproximação alcançada com sucesso!" << "\n";

    return 0;
}