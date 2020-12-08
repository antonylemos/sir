#include <stdio.h>
#ifndef SIMULATION_H
#define SIMULATION_H

typedef struct {
  double S;
  double I;
  double R;
  double h;
  double N_b;
  double T_b;
  double S_bi;
  double I_bi;
  double m_k;
  double n_k;
  double T_k;
  int simulation_period;
} Parameters;

typedef struct {
  double b;
  double k;
} Constants;

typedef struct {
  double S;
  double I;
  double R;
  double M;
  double time;
} Results;

typedef struct {
  double S;
  double I;
  double R;
  double b;
  double k;
} Aux;

int readFile(Parameters*, Results*);
void calculateConstants(Constants*, Parameters*, Aux*);
void calculateSimulationData(Aux*, Parameters*, Constants*, Results*, int, int, int);
int startSimulation(Aux*, Parameters*, Constants*, Results*);

#endif