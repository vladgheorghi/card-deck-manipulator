/**
 * Copyright 2022 Gheorghiu Doru-Vlad
 * Facultatea de Automatica si Calculatoare, UPB
 * Year 1, Semester 2
 * Data Structures: Homework 1
 * Double-Linked List Manipulation (Theme: Now you see me)
 **/

#ifndef EXIT_H_
#define EXIT_H_

#include "dll_implement.h"

// function for freeing the data of a given list
void free_list(dllist *list);

// function for freeing all allocated data when exiting the program
void exit_function(dllist *deck_list);

#endif  // EXIT_H_
