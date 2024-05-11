#ifndef DORM_H
#define DORM_H

#include "gender.h"

struct dorm_t
{
  char name[50];
  unsigned short kapasitas;
  enum gender_t gender;
  unsigned short residents_number;
};

struct dorm_t create_dorm(char *_name, unsigned short _capacity, enum gender_t _gender);
void print_dorm(struct dorm_t *_dorm, int count);
void print_dormitori(struct dorm_t *_dorm, int count);
#endif
