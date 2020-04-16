#include <math.h>
#include <iostream>
#include <iomanip>
using namespace std;



long double IntegratedLagrange1(long double alpha, long double alpha1, long double alpha2, long double alpha3, long double alpha4){
    /*
    (x³ - x²d - x²c + xcd - bx² + xbd + xbc -bcd) / ( a³ - a²d -a²c + acd --a²b + abd +abc - bcd )
    long double dividendo = ( pow(alpha,3) - (pow(alpha,2)*alpha4) - (pow(alpha,2)*alpha3)
                            + (alpha*alpha3*alpha4) - (alpha2*pow(alpha,2)) + (alpha*alpha2*alpha4)
                            + (alpha*alpha2*alpha3) - (alpha2*alpha3*alpha4));
    
    long double divisor = ( pow(alpha1,3) - (pow(alpha1,2)*alpha4) - (pow(alpha1,2)*alpha3)
                          + (alpha1*alpha3*alpha4) - (pow(alpha1,2)*alpha2) + (alpha1*alpha2*alpha4)
                          + (alpha1*alpha2*alpha3) - (alpha2*alpha3*alpha4) );

    long double result = (dividendo / divisor);
    */

    long double dividendo = - alpha * (3*pow(alpha,3) - 4*(alpha4*alpha3*alpha2)*pow(alpha,2)
                            + 6*((alpha3*alpha4) + (alpha2*alpha4) +(alpha2*alpha3))*alpha
                            - 12*(alpha2*alpha3*alpha4));
    
    long double divisor = 12* (alpha4*((alpha2-alpha1)*(alpha3-alpha1))
                          - ((alpha1*alpha3)*(alpha2-alpha1)) - (alpha2*pow(alpha1,2))
                          -pow(alpha3,2));

    long double result = (dividendo/divisor);
    return result;
}

long double IntegratedLagrange2(long double alpha, long double alpha1, long double alpha2, long double alpha3, long double alpha4){
    /*
    alpha = x
    alpha1 = a; alpha2 = b; alpha3 = c; alpha4 = d
    (x³- x²d - x²c +xcd - x²a +xad+xac-acd)/(b³- b²d - b²c + bcd - ab² + abd + abc - acd)

    long double dividendo = ( pow(alpha,3) - (pow(alpha,2)*alpha4) - (pow(alpha,2)*alpha3)
                            + (alpha*alpha3*alpha4) - (pow(alpha,2)*alpha1) + (alpha*alpha1*alpha4)
                            + (alpha*alpha1*alpha3) - (alpha*alpha3*alpha4));

    long double divisor = ( pow(alpha2,3) - (pow(alpha2,2)*alpha4) - (pow(alpha2,2)*alpha3)
                          + (alpha2*alpha3*alpha4) - (alpha1*pow(alpha2,2)) + (alpha1*alpha2*alpha4)
                          + (alpha1*alpha2*alpha3) - (alpha1*alpha3*alpha4));

    long double result = (dividendo/divisor);
    */

    long double dividendo = alpha*(3*(pow(alpha,3)) - 4*(alpha4+alpha3+alpha1)*pow(alpha,2)
                            + 6*((alpha3*alpha4) + (alpha1*alpha4) + (alpha1*alpha3))*alpha
                            - 12*(alpha1*alpha3*alpha4));
    
    long double divisor = 12*((alpha2-alpha1)*(alpha3-alpha2)*(alpha4-alpha2));

    long double result = (dividendo/divisor);

    return result;
}

long double getW1(long double alpha1, long double alpha2, long double alpha3, long double alpha4){
    //(1) - (-1)

    long double valorFim = IntegratedLagrange1(1, alpha1, alpha2, alpha3, alpha4);

    long double valorInicio = IntegratedLagrange1(-1, alpha1, alpha2, alpha3, alpha4);

    long double result = valorFim - valorInicio;
    
    return result;
}

long double getW2(long double alpha1, long double alpha2, long double alpha3, long double alpha4){
    
    long double valorFim = IntegratedLagrange2(1, alpha1, alpha2, alpha3, alpha4);

    long double valorInicio = IntegratedLagrange2(-1, alpha1, alpha2, alpha3, alpha4);

    long double result = valorFim - valorInicio;

    return result;    
}

long double myFunction(long double x){
    long double equation = (sin(2*x) + (4*pow(x,2)) + 3*x);
    long double finalResult = pow(equation,2);
    return finalResult;
}

long double getXAlpha(long double inicio, long double fim, long double alpha){
    long double result = ((inicio + fim) / 2) + ((inicio-fim)/2)*alpha;

    return result;
}

long double calculateLegendreGrau4(long double inicio, long double fim){
    long double alpha1 = 0.861136116;
    long double alpha2 = -0.861136116;
    long double alpha3 = 0.3399810436;
    long double alpha4 = -0.3399810436;

    long double xAlpha1 = getXAlpha(inicio, fim, alpha1);
    long double xAlpha2 = getXAlpha(inicio, fim, alpha2);
    long double xAlpha3 = getXAlpha(inicio, fim, alpha3);
    long double xAlpha4 = getXAlpha(inicio, fim, alpha4);

    long double primeiro = myFunction(alpha1)*getW1(xAlpha1, xAlpha2, xAlpha3, xAlpha4);
    long double segundo = myFunction(alpha2)*getW2(xAlpha1, xAlpha2, xAlpha3, xAlpha4);
    
    long double terceiro = myFunction(alpha3)*getW2(xAlpha1, xAlpha2, xAlpha3, xAlpha4);
    long double quarto = myFunction(alpha4)*getW1(xAlpha1, xAlpha2, xAlpha3, xAlpha4);
    
    long double result = ((fim-inicio)/2)*(primeiro+segundo+terceiro+quarto);
    
   return result;
}

int main(int argc, char** argv){
    
    long double inicio = 0;
    long double fim = 1;


    long double result = calculateLegendreGrau4(inicio, fim);

    cout << fixed << setprecision(8);
    cout << result;

    return 0;
}