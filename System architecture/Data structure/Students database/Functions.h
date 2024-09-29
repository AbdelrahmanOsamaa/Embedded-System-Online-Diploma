#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>

// the head
struct Sstudent* gpFirstStudent ;


struct Sdata
{
    int ID ;
    char name[40];
    float hight ;
};

struct Sstudent 
{
    struct Sdata student ;
    struct Sstudent* PNextStudent;
};

void fill_record(struct Sstudent* new_record);
void Add_student();
int Delete_student();
void view_all_students();
void Delete_all();
void node_index_info();
void length_of_list_iterative();
// int length_of_list_recursive(struct Sstudent* pNode);
void n_th_node_info(int n);
void middle_of_list();

#endif