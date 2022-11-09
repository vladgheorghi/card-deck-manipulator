/**
 * Copyright 2022 Gheorghiu Doru-Vlad
 * Facultatea de Automatica si Calculatoare, UPB
 * Year 1, Semester 2
 * Data Structures: Homework 1
 * Double-Linked List Manipulation (Theme: Now you see me)
 **/

#ifndef MERGE_DECKS_H_
#define MERGE_DECKS_H_

#include "errors.h"
#include "dll_implement.h"

// function for merging 2 given decks
error merge_decks(dllist *deck_list, int index1, int index2);

#endif  // MERGE_DECKS_H_
