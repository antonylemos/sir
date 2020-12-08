#include <stdio.h>
#include <stdlib.h>
#include "simulation.h"

int readFile(Parameters *parameters, Results *results) {
  FILE *file = fopen("data.txt", "r");

  if (file == NULL) {
    printf("Houve um problema ao abrir o arquivo!\n");
    
    return 0;
  }

  fscanf(
    file, "%lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %i",
    &parameters->S,
    &parameters->I,
    &parameters->R,
    &parameters->h,
    &parameters->N_b,
    &parameters->T_b,
    &parameters->S_bi,
    &parameters->I_bi,
    &parameters->m_k,
    &parameters->n_k,
    &parameters->T_k,
    &parameters->simulation_period
  );
  
  parameters->simulation_period = parameters->simulation_period * 24;

  fclose(file);
}

void calculateConstants(Constants *constants, Parameters *parameters, Aux *aux) {
  constants->b = parameters->N_b / (parameters->T_b * parameters->S_bi * parameters->I_bi);
  constants->k = parameters->m_k / (parameters->n_k * parameters->T_k);
}

void calculateSimulationData(
  Aux *aux,
  Parameters *parameters,
  Constants *constants,
  Results *results,
  int time_interval,
  int time_extra,
  int index
) {
  if (index != 0 && parameters->simulation_period > time_interval) {
    if (index == 1) {
      aux->b = parameters->N_b / ((parameters->T_b + time_extra) * parameters->S_bi * parameters->I_bi);
    } else {
      aux->k = parameters->m_k / (parameters->n_k * (parameters->T_k + time_extra));
    }
  }

  aux->S = results->S;
  aux->I = results->I;
  aux->R = results->R;

  results->S = aux->S - parameters->h * aux->b * aux->S * aux->I;
  results->I = aux->I + parameters->h * (aux->b * aux->S * aux->I - aux->k * aux->I);
  results->R = aux->R + parameters->h * aux->k * aux->I;
  results->M = results->R * 2 / 100;
  results->time = results->time + parameters->h;
}

int startSimulation(Aux *aux, Parameters *parameters, Constants *constants, Results *results) {
  for (int i = 0; i < 3; i++) {
    FILE *file;

    aux->b = constants->b;
    aux->k = constants->k;
    results->S = parameters->S;
    results->I = parameters->I;
    results->R = parameters->R;
    results->time = 0;

    int time_interval = 0, time_extra = 0;

    switch (i) {
      case 0:
        file = fopen("out/results_0.csv", "w+");
        break;

      case 1:
        file = fopen("out/results_1.csv", "w+");
        time_interval = 72;
        time_extra = 12;
        break;

      case 2:
        file = fopen("out/results_2.csv", "w+");
        time_interval = 72;
        time_extra = 12;
        break;

      default:
        break;
    }

    if (file == NULL) {
      printf("Houve um problema ao criar o arquivo!\n");
      
      return 0;
    }

    int size = parameters->simulation_period / parameters->h;
    int count = 0;

    Results *results_vector = calloc(size, sizeof(Results));

    fprintf(file, "%lf, %lf, %lf, 0, %lf\n", parameters->S, parameters->I, parameters->R, results->time);

    while (results->time < parameters->simulation_period) {
      calculateSimulationData(aux ,parameters, constants, results, time_interval, time_extra, i);

      results_vector[count] = *results;

      count++;
    }

    for (int i = 0; i < size; i++) {
      fprintf(file, "%lf, %lf, %lf, %lf, %lf\n",
        results_vector[i].S,
        results_vector[i].I,
        results_vector[i].R,
        results_vector[i].M,
        results_vector[i].time
      );
    }

    free(results_vector);

    fclose(file);
  }
}
