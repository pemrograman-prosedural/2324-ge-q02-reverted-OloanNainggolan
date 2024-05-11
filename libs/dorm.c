#include "dorm.h"
#include <stdio.h>
#include <string.h>

struct dorm_t create_dorm(char *_name, unsigned short _kapasitas, enum gender_t _gender){
    struct dorm_t dot;
    strcpy(dot.name, _name);
    dot.kapasitas = _kapasitas;
    dot.gender = _gender;
    dot.residents_number = 0;
    return dot;
}

void print_dorm(struct dorm_t *_dorm, int count){
    for (int j = 0; j < count; j++)
    {
        if (_dorm[j].gender == GENDER_MALE){
            printf("%s|%d|male\n", _dorm[j].name, _dorm[j].kapasitas);
        } else if(_dorm[j].gender == GENDER_FEMALE){
            printf("%s|%d|female\n", _dorm[j].name, _dorm[j].kapasitas);
        }
    }   
}
void print_dormitori(struct dorm_t *_dorm, int count){
    for (int j = 0; j < count; j++)
    {
        if (_dorm[j].gender == GENDER_MALE){
            printf("%s|%d|male|%d\n", _dorm[j].name, _dorm[j].kapasitas, _dorm[j].residents_number);
        } else if(_dorm[j].gender == GENDER_FEMALE){
            printf("%s|%d|female|%d\n", _dorm[j].name, _dorm[j].kapasitas, _dorm[j].residents_number);
        }
    }   
}