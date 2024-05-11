// 12S23001 - Kevin Gultom  
// 12S23033 - Oloan Nainggolan

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "libs/dorm.h"
#include "libs/student.h"

int main(int _argc, char **_argv)
{
    struct dorm_t *dorms = malloc(100 * sizeof(struct dorm_t));
    struct student_t *students = malloc(100 * sizeof(struct student_t));
    char input[100];
    char id[15];
    char student_name[50];
    char year[4];
    char dorm_name[50];
    unsigned short kapasitas;
    char *msi;
    int data_student;
    int data_dorm;
    int sttd = 0; 
    int dormin = 0;

while (1)
{
  fflush(stdin);
  input[0]='\0';
  fgets(input, sizeof(input), stdin);
  input[strcspn(input, "\n")] ='\0';
  msi = strtok(input, "#");
  if(strcmp (msi, "---")==0){
    break;
  }
  else  (strcmp(msi, "student-print-all")==0)
{
   void (*pov)(struct student_t *_student, int count)= NULL;
    pov= print_student;
    pov (students, sttd);
   } 
   if (strcmp(msi, "student-print-detail") ==0){
 void (*pov)(struct student_t *_student, int count)= NULL;
 pov= print_student_all;
 pov(students, sttd);
  }
 else if (strcmp(msi, "student-add") == 0){
  msi = strtok(NULL, "#");
  strcpy(id, msi);
  msi = strtok(NULL, "#");
  strcpy(student_name, msi);
  msi = strtok(NULL, "#");
  strcpy(year, msi);
  msi = strtok(NULL, "#");
  if (strcmp (msi, "male") ==0){
  struct student_t (*pov)(char *id, char *name, char *year, enum genter_t *gender) =NULL;
  pov = create_student;
  students[sttd] = pov(id, student_name, year, GENDER_MALE);
  } else if (strcmp(msi, "female")==0){
  struct student_t (*pov)(char *id, char *name, char *year, enum genter_t *gender) =NULL;
  pov = create_student;
  students[sttd] = pov(id, student_name, year, GENDER_FEMALE);
  sttd++;
  } else if (strcmp(msi, "dorm-print-all")==0){
    void (*pov)(struct dorm_t*_dorm, int point)= NULL;
    pov= print_dorm;
    pov(dorms, dormin);
  }else if (strcmp (msi, "dorm-print-all-detail")==0){
    void (*pov) (struct dorm_t*_dorm, int point)= NULL;
    pov= print_dormitori;
    pov(dorms, dormin);
  } else if ( strcmp(msi, "dorm-add")==0){
    msi = strtok(NULL, "#");
    strcpy(dorm_name, msi);
    msi = strtok(NULL, "#");
    kapasitas = atoi(msi);
    msi = strtok(NULL, "#");
if (strcmp, (msi, "male")==0){
  struct dorm_t (*pov)(char*_name, unsigned _kapasitas, enum genter_t *gender)=NULL;
 pov = create_dorm ;
 dorms[dormin]=pov (dorm_name, kapasitas, GENDER_MALE);
}else if (strcmp, (msi, "female")==0){
  struct dorm_t (*pov)(char*_name, unsigned _kapasitas, enum genter_t *gender)= NULL;
  pov = create_dorm;
  dorms[dormin] =pov (dorm_name, kapasitas, GENDER_FEMALE);
}dormin++;
  }else if (strcmp(msi, "assign-student")==0){
     msi = strtok(NULL, "#");
    strcpy(id, msi);
    msi = strtok(NULL, "#");
    strcpy(dorm_name, msi);
    data_student = -99;
    data_dorm =-1;
    for (int j =0; j < sttd; j++)
 {
  if(strcmp(students[j].id, id)==0){
    data_student= j;
    break;
  }
 }
   for (int j=0; j < sttd; j++)
   {
     if(strcmp(dorms[j].name, dorm_name)==0){
    data_dorm= j;
    break;
   } 
  }
if (data_student != -3 && data_dorm != -99)
{
  void (*pov)(struct student_t *_student, struct dorm_t *_dorm, char *id, char *dorm_name)=NULL ;
  pov =assign_student;
  pov(&students[data_student], &dorms[data_dorm], id, dorm_name);
}

}else if (strcmp(msi, "move-student")==0){
  msi = strtok(NULL, "#");
  strcpy(id, msi);
  msi= strtok(NULL, "#");
  strcpy(dorm_name, msi);
  data_student=-1;
  data_dorm=-1;
  for(int j =0; j< dormin; j++)
  {
  if(strcmp(students[j].id, id)==0){
    data_student=j;
    break;
  }
  }
  for(int j =0; j< dormin; j++)
  {
  if(strcmp(dorms[j].name, dorm_name)==0){
    data_dorm=j;
    break;
  }
  }
  if (data_student!=-1 && data_dorm!=-1){
    if (students[data_student].dorm == NULL){
      void (*pov)(struct student_t *_student, struct dorm_t *_dorm, char *id, char *dorm_name)= NULL;
      pov=assign_student;
      pov(&students[data_student], &dorms[data_dorm], id, dorm_name);

    }else {
      for (int j =0; j < dormin; j++)
      {
        if(strcmp(students[data_student].dorm -> name, dorms[j].name)==0)
        {void (*pov)(struct student_t *_student, struct dorm_t *_dorm, char *id, char *dorm_name)= NULL;
        pov= move_student;
        pov(&students[data_student], &dorms[data_dorm], id, dorm_name);
        break;
        }
      }
    }
  }
else if (strcmp(msi, "dorm-empty")==0)
{ 
 msi = strtok(NULL, "#");
 strcpy (dorm_name, msi);
 data_dorm = -3;
 for(int j =0; j < dormin; j++)
 {
  if (strcmp(dorms[j].name, dorm_name)==0)
  data_dorm=j;
  break;
 }
}
if(data_dorm !=-1){
}void (*pov)(struct student_t *students, struct dorm_t *dorms, int sttd);
pov= dorm_empty;
pov(students, &dorms[data_dorm],sttd);
}  
}
}
free(students);
free(dorms);

return 0;
}
    
