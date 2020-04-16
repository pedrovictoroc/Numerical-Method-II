#include <math.h>
#include <iostream>
#include <iomanip>
using namespace std;

long double getXAlpha(long double inicio, long double fim, long double alpha){
    
    long double result = ((inicio + fim)/2.0) + ((fim - inicio)/2.0)*alpha;

    return result;
}

long double IntegratedLagrange1(long double alpha){
    // Foi derivado de: (x³+0.8611363116x²+0.11558711x-0.9953626)/1.07808865
    // Aproximado para: (x³+0.8611x²+0.1155x-0.0995)/1.0781 
    long double result = ((1000*alpha*(15000*pow(alpha,3) + 17222*pow(alpha,2) + 3465*alpha - 5970))/64685319.0);

    return result;
}

long double IntegratedLagrange2(long double alpha){
    //Foi derivado de: (x³ - 0.339981x²- 0.741557x + 0,2521)/0.425634
    long double result = ((alpha *(500000*pow(alpha,3) - 226654*pow(alpha,2) - 741557*alpha + 504200))/851268.0);

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

long double calculateLegendreFourthDegree(long double inicio, long double fim){
    long double alpha1 = 0.8611363116;
    long double alpha2 = -0.8611363116;
    long double alpha3 = 0.3399810436;
    long double alpha4 = -0.3399810436;

    long double xAlpha1 = getXAlpha(inicio, fim, alpha1);
    long double xAlpha2 = getXAlpha(inicio, fim, alpha2);
    long double xAlpha3 = getXAlpha(inicio, fim, alpha3);
    long double xAlpha4 = getXAlpha(inicio, fim, alpha4);

    long double fXAlpha1 = myFunction(xAlpha1);
    long double fXAlpha2 = myFunction(xAlpha2);
    long double fXAlpha3 = myFunction(xAlpha3);
    long double fXAlpha4 = myFunction(xAlpha4);

    //Note que W1=W4 e W2=W3
    //long double w1 = getW1();
    //long double w2 = getW2();

    long double w1 = 0.3478548451 ;
    long double w2 = 0.6521451548;

    long double primeiro = fXAlpha1*w1;
    long double segundo = fXAlpha2*w2;
    long double terceiro = fXAlpha3*w2;
    long double quarto = fXAlpha4*w1;

    long double result = ((fim - inicio)/2.0)*(primeiro+segundo+terceiro+quarto);

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

    
    long double result = calculateLegendreFourthDegree(inicio, fim);

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
            acumuladorIntegral = acumuladorIntegral + calculateLegendreFourthDegree(inicio+(subIntervalo*loopCounter), inicio+(subIntervalo*(loopCounter+1)));
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