#include <math.h>
#include <iostream>
#include <iomanip>
using namespace std;

long double getXAlpha(long double inicio, long double fim, long double alpha){
    
    long double result = ((inicio + fim)/2) + ((fim - inicio)/2)*alpha;

    return result;
}

long double IntegratedLagrange1(long double alpha){
    // Derivada de: 5/6(x²-x(3/5)^(1/2))
    long double result = (pow(alpha,2)*(10*alpha - pow(3,1.5)*pow(5,0.5)))/36;

    return result;
}

long double IntegratedLagrange2(long double alpha){
    //Derivada de: -5/3(x²- 3/5)
    long double result = alpha - (5*pow(alpha,3))/9;

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

long double calculateLegendreThirdDegree(long double inicio, long double fim){
    long double alpha1 = - 0.7745966692;
    long double alpha2 = 0;
    long double alpha3 = 0.7745966692;

    long double xAlpha1 = getXAlpha(inicio, fim, alpha1);
    long double xAlpha2 = getXAlpha(inicio, fim, alpha2);
    long double xAlpha3 = getXAlpha(inicio, fim, alpha3);

    long double fXAlpha1 = myFunction(xAlpha1);
    long double fXAlpha2 = myFunction(xAlpha2);
    long double fXAlpha3 = myFunction(xAlpha3);
    
    long double w1 = getW1();
    long double w2 = getW2();
    //L1 = L3
    long double w3 = w1;

    long double primeiro = fXAlpha1*w1;
    long double segundo = fXAlpha2*w2;
    long double terceiro = fXAlpha3*w3;
    
    long double result = ((fim - inicio)/2)*(primeiro+segundo+terceiro);

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
    
    long double result = calculateLegendreThirdDegree(inicio, fim);
    
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
            acumuladorIntegral = acumuladorIntegral + calculateLegendreThirdDegree(inicio+(subIntervalo*loopCounter), inicio+(subIntervalo*(loopCounter+1)));
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