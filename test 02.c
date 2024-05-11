// 12S23001 -Kegoel
// 12S23033 - Oloan Nainggolan

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./libs/dorm.h"
#include "./libs/student.h"
#include "./libs/gender.h"

int main(int _argc, char **_argv)
{
  char in[75];
  int jumlah= 0;
  int size = 0;
  struct dorm_t *dorm = malloc(size * sizeof(struct dorm_t));
  int jlh = 0;
  int sizee = 0;
  struct student_t *sttd = malloc(sizee * sizeof(struct student_t));
  char *token;

  while (1)
  {
    fgets(in, sizeof in, stdin);
    while (1)
    {
      if (in[strlen(in) - 1] == '\n' || in[strlen(in) - 1]== '\r')
      {
        in[strlen(in) - 1] = '\0';
      }
      else
      {
        break;
      }
    }

    token = strtok(in, "#");
    if (strcmp(token, "---") == 0)
    {
      break;
    }
    else if (strcmp(token, "dorm-add") == 0)
    {
      size++;
      dorm = realloc(dorm, size * sizeof(struct dorm_t));
      dorm[jumlah] = create_dorm(in);
      jumlah++;
    }
    else if (strcmp(token, "dorm-print-all") == 0)
    {
      for (int m = 0; m < jumlah; m++)
      {
        print_dorm(dorm[m]);
      }
    }
    else if (strcmp(token, "dorm-print-all-detail") == 0)
    {
      for (int m = 0; m < jumlah; m++)
      {
        print_dorm_detail(dorm[m]);
      }
    }
    else if (strcmp(token, "student-add") == 0)
    {
      sizee++;
      sttd = realloc(sttd, sizee * sizeof(struct student_t));
      sttd[jlh] = create_student(in);
      jlh++;
    }
    else if (strcmp(token, "student-print-all") == 0)
    {
      for (int m = 0; m < jlh; m++)
      {
        print_student(sttd[m]);
      }
    }
    else if (strcmp(token, "student-print-all-detail") == 0)
    {
      for (int m = 0; m < jlh; m++)
      {
        print_student_detail(sttd[m]);
      }
    }
    else if (strcmp(token, "assign-student") == 0)
    {
      char *nim = strtok(NULL, "#");
      char *asrama = strtok(NULL, "#");
      assign_student(dorm, sttd, nim, asrama, jlh, jumlah, pre_student, pre_dorm);
    }
    else if (strcmp(token, "move-student") == 0)
    {
      char *nim = strtok(NULL, "#");
      char *asrama = strtok(NULL, "#");
      move_student(dorm, sttd, nim, asrama, jlh, jumlah, pre_student, pre_dorm);
    }
    else if (strcmp(token, "dorm-empty") == 0)
    {
      char *asrama = strtok(NULL, "#");
      dorm_empty(asrama, jlh, jumlah, sttd, dorm, pre_dorm);
    }
  }
  free(sttd);
  free(dorm);

  return 0;
}

