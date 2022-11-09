/**
 * Copyright 2022 Gheorghiu Doru-Vlad
 * Facultatea de Automatica si Calculatoare, UPB
 * Year 1, Semester 2
 * Data Structures: Homework 1
 * Double-Linked List Manipulation (Theme: Now you see me)
 **/

#ifndef SHOW_H_
#define SHOW_H_

#include "errors.h"
#include "dll_implement.h"

// function for outputing a given deck
error show_deck(dllist *deck_list, int index);

// function for outputing all decks from the deck list
error show_all(dllist *deck_list);

#endif  // SHOW_H_
