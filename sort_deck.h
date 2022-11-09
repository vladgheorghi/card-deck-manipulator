/**
 * Copyright 2022 Gheorghiu Doru-Vlad
 * Facultatea de Automatica si Calculatoare, UPB
 * Year 1, Semester 2
 * Data Structures: Homework 1
 * Double-Linked List Manipulation (Theme: Now you see me)
 **/

#ifndef SORT_DECK_H_
#define SORT_DECK_H_

#include "errors.h"
#include "dll_implement.h"

// function for sorting a given deck by its value and symbol
error sort_deck(dllist *deck_list, int index);

// function for assigning a number to a symbol so that they can be compared
int symbol_int(char *symbol);

#endif  // SORT_DECK_H_
