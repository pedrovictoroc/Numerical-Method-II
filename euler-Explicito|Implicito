#include <math.h>
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

long double exactFormula(long double y){
  double euler = 2.71828182845904523536;
  long double response = 2*pow(euler,(2.0/3.0)*y);
  return response;
}

long double myFormula(long double y){
  return ((2.0/3.0) * y);
}

void explicitEuler(long double timeLimit, long double timeStep ,long double initialValueY, long double initialValueStep){
  vector< long double >responses = { initialValueY };
  int responseIndexer = 0;
  long double steper = initialValueStep;

  while (steper <= timeLimit){
    long double newResponse = responses[responseIndexer] + timeStep*myFormula(responses[responseIndexer]);

    responses.push_back(newResponse);
    responseIndexer++;

    long double exactResponse = exactFormula(steper);
    long double relativeError = ( exactResponse - responses[responseIndexer]) / exactResponse;

    steper = steper + timeStep;

    cout << "Resposta aproximada: " << newResponse << "\n";
    cout << "Resposta exata: " << exactResponse << "\n";
    cout << "Erro relativo: " << relativeError << "\n";
    cout << "---------------------------------------" << "\n";
  }
  return ;
}

void implicitEuler(long double timeLimit, long double timeStep ,long double initialValueY, long double initialValueStep){
  vector< long double >responses = { initialValueY };
  int responseIndexer = 0;
  long double steper = initialValueStep;

  while( steper <= timeLimit ) {

    //formula no formato: y1 = y0 + deltaT*( CONSTANTE * y1 + RESTO )
    //abaixo deve ser escrito no formato: y1 = (y0 + deltaT * RESTO) / (1 - deltaT * CONSTANTE)
    long double newResponse = ( responses[responseIndexer] + timeStep*0 )/(1 - timeStep * (2.0/3.0));

    responses.push_back(newResponse);
    responseIndexer++;

    long double exactResponse = exactFormula(steper);
    long double relativeError = ( exactResponse - responses[responseIndexer]) / exactResponse;

    steper = steper + timeStep;

    cout << "Resposta aproximada: " << newResponse << "\n";
    cout << "Resposta exata: " << exactResponse << "\n";
    cout << "Erro relativo: " << relativeError << "\n";
    cout << "---------------------------------------" << "\n";
  }

}

int main(){
    implicitEuler(10, 0.5, 2,0.5);

    return 0;
}
