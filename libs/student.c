#include "student.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct student_t create_student(char *_id, char *_name, char *_year,enum gender_t _gender){
    struct student_t mix;
    strcpy(mix.id, _id);
    strcpy(mix.name, _name);
    strcpy(mix.year, _year);
    mix.gender = _gender;
    mix.dorm = malloc (sizeof(struct dorm_t));
    mix.dorm = NULL;
    return mix;
}
void print_student(struct student_t *_student, int point){
    for (int j = 0; j < point; j++)
    {
        if (_student[j].gender == GENDER_MALE)
        {
          printf("%s|%s|%s|male\n", _student[j].id, _student[j].name, _student[j].year);
        } else if (_student[j].gender == GENDER_FEMALE)
        {
          printf("%s|%s|%s|female\n", _student[j].id, _student[j].name, _student[j].year);
        }
    }
}
void print_student_all(struct student_t *_student, int point){
    for (int j = 0; j < point; j++)
    {
        if (_student[j].dorm == NULL)
        {
            if (_student[j].gender==GENDER_MALE)
            {
                printf("%s|%s|%s|male|unassigned\n", _student[j].id, _student[j].name, _student[j].year);
            } else if (_student[j].gender == GENDER_FEMALE)
            {
                printf("%s|%s|%s|female|unassigned\n", _student[j].id, _student[j].name, _student[j].year);
            }
        } else {
            if (_student[j].gender == GENDER_MALE)
            {
                printf("%s|%s|%s|male|%s\n", _student[j].id, _student[j].name, _student[j].year, _student[j].dorm->name);
            } else if (_student[j].gender == GENDER_FEMALE)
            {
                printf("%s|%s|%s|female|%s\n", _student[j].id, _student[j].name, _student[j].year, _student[j].dorm->name);
            }
        }
    }
}
void assign_student(struct student_t *_student,struct dorm_t *_dorm, char *id, char *dorm_name){
    if (_dorm->residents_number < _dorm-> kapasitas){
        if (_student->gender == _dorm->gender){
            _student->dorm = _dorm;
            _dorm->residents_number++;
        }
    }
}
void move_student(struct student_t *_student, struct dorm_t *_dorm, struct dorm_t *_dormnt, char *id, char *dorm_name){
    if (_dorm->residents_number< _dorm->kapasitas){
        if (_student->gender == _dorm->gender){
            _student->dorm = _dorm;
            _dorm->residents_number++;
            _dormnt->residents_number--;
        }
    }
}
void dorm_empty(struct student_t *students, struct dorm_t *dorms, int sttd){
    for (int j = 0; j < sttd; j++){
        if (students[j].dorm == NULL)
        {
          continue;
        } else if(strcmp(students[j].dorm->name, dorms->name)==0)
        {
          students[j].dorm = NULL;
        }
    }
    dorms->residents_number = 0;
}