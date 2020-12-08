#include <stdio.h>
#include <stdlib.h>
#include "simulation.h"

int main(void) {
  printf ("Simulação Epidemiológica (SIR)\n");

  Parameters parameters;
  Constants constants;
  Results results;
  Aux aux;

  readFile(&parameters, &results);
  printf("Iniciando simulação...\n");
  calculateConstants(&constants, &parameters, &aux);
  startSimulation(&aux, &parameters, &constants, &results);
  printf("Dados gerados com sucesso!\n");

  return 0;
}
