/**
 * Copyright 2022 Gheorghiu Doru-Vlad
 * Facultatea de Automatica si Calculatoare, UPB
 * Year 1, Semester 2
 * Data Structures: Homework 1
 * Double-Linked List Manipulation (Theme: Now you see me)
 **/

#ifndef SHUFFLE_DECK_H_
#define SHUFFLE_DECK_H_

#include "errors.h"
#include "dll_implement.h"

// function for shuffling a given deck
error shuffle_deck(dllist *deck_list, int index);

// function that returns the nth node of a given list
node *get_node(dllist *deck, int n);

#endif  // SHUFFLE_DECK_H_
