#include "../include/query3.h"
#include "../include/interpreter.h"

void query3(Reservation *booking, char *hotel_id, int counter, int mode)
{

  clock_t start, end;
  double cpu_time_used;
  start = clock();

  double media_rating = 0;
  int *n_stars = calloc(100, sizeof(int));
  int soma = 0;

  soma = get_hotel_rating(booking, hotel_id, n_stars);

  media_rating = media((double)soma, (double)n_stars[0]);
  free(n_stars);

  char *output;
  output = malloc(sizeof(char) * 30);
  if (flag)
  {
    sprintf(output, "--- 1 ---\nrating: %.3f\n", media_rating);
  }
  else
    sprintf(output, "%.3f\n", media_rating);

  if (mode == 0)
  {
    printf("<Rating>\n");
    printf("%s", output);
  }
  else
    handle_outputs(counter, output);

  end = clock();
  cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
  if (mode == 1)
    printf("\n");
  if ((mode == 1) || (mode == 0) || (mode == 3))
    printf("Fim da Q3 - %f segundos (input nº %i)\n", cpu_time_used, counter);

  free(output);
}
