/**
 * Copyright 2022 Gheorghiu Doru-Vlad
 * Facultatea de Automatica si Calculatoare, UPB
 * Year 1, Semester 2
 * Data Structures: Homework 1
 * Double-Linked List Manipulation (Theme: Now you see me)
 **/

#ifndef SPLIT_DECK_H_
#define SPLIT_DECK_H_

#include "errors.h"
#include "dll_implement.h"

// function that splits a given deck into 2 decks at a given index
error split_deck(dllist *deck_list, int index, int split_index);

#endif  // SPLIT_DECK_H_
