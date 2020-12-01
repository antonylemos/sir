#include <stdio.h>

/**
 * Calcula o período de tempo em que a simulação executará.
 * @param days representa tempo de simulação em dias.
 * @param hours representa as horas que serão utilizadas durante o dia.
 * @return período de tempo em horas em que a simulação executará.
*/
int getPeriod(int days, int hours) {
  return days * hours;
}

int main(void) {
  FILE *file;
  file = fopen("data.txt", "r");

  if (file == NULL) {
    printf("Houve um problema ao abrir o arquivo!\n");
    
    return 0;
  }
  
  double S = 0, I = 0, R = 0, h = 0, N_b = 0, T_b = 0, S_bi = 0, I_bi = 0, m_k = 0, n_k = 0, T_k = 0;
  int simulation_period = 0;

  fscanf(file, "%lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %i", &S, &I, &R, &h, &N_b, &T_b, &S_bi, &I_bi, &m_k, &n_k, &T_k, &simulation_period);

  fclose(file);

  simulation_period = getPeriod(simulation_period, 24);

  double b = N_b / (T_b * S_bi * I_bi);
  double k = m_k / (n_k * T_k);

  double S_aux = S;
  double I_aux = I;
  double R_aux = R;
  double time = 0;

  FILE *csv_file = fopen("results.csv", "w+");

  if (csv_file == NULL) {
    printf("Houve um problema ao criar o arquivo!\n");
    
    return 0;
  }

  fprintf(csv_file, "%lf, %lf, %lf, %lf\n", S, I, R, time);

  while (time < simulation_period) {
    S = S_aux - h * b * S_aux * I_aux;
    I = I_aux + h * (b * S_aux * I_aux - k * I_aux);
    R = R_aux + h * k * I_aux;
    time = time + h;

    fprintf(csv_file, "%lf, %lf, %lf, %lf\n", S, I, R, time);

    S_aux = S;
    I_aux = I;
    R_aux = R;
  }

  fclose(csv_file);

  return 0;
}
