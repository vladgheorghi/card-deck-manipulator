/**
 * Copyright 2022 Gheorghiu Doru-Vlad
 * Facultatea de Automatica si Calculatoare, UPB
 * Year 1, Semester 2
 * Data Structures: Homework 1
 * Double-Linked List Manipulation (Theme: Now you see me)
 **/

#ifndef DEL_DECK_H_
#define DEL_DECK_H_

#include "errors.h"
#include "dll_implement.h"

// function that deletes a deck from the deck list
error del_deck(dllist *deck_list, int index);

// function for deleting a card from a deck
error del_card(dllist *deck_list, int index, int card_index);

#endif  // DEL_DECK_H_
