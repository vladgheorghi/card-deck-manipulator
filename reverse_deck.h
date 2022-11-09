/**
 * Copyright 2022 Gheorghiu Doru-Vlad
 * Facultatea de Automatica si Calculatoare, UPB
 * Year 1, Semester 2
 * Data Structures: Homework 1
 * Double-Linked List Manipulation (Theme: Now you see me)
 **/

#ifndef REVERSE_DECK_H_
#define REVERSE_DECK_H_

#include "errors.h"
#include "dll_implement.h"

// function for reversing the cards in a given deck
error reverse_deck(dllist *deck_list, int index);

#endif  // REVERSE_DECK_H_
