/**
 * Copyright 2022 Gheorghiu Doru-Vlad
 * Facultatea de Automatica si Calculatoare, UPB
 * Year 1, Semester 2
 * Data Structures: Homework 1
 * Double-Linked List Manipulation (Theme: Now you see me)
 **/

#ifndef ADD_DECK_H_
#define ADD_DECK_H_

#include "errors.h"
#include "dll_implement.h"

// generic function for adding a node to a list
// if is_deck_list = 0, then it adds a card to a deck
// if is_deck_list = 1, then it adds a deck to the deck_list
void add_node(dllist *list, int pos, void *card_data, int is_deck_list);

// function for verifying if a card's symbol is one of the available ones
int verify_symbol(char *card_symbol);

// function for verifying if a card's value is between marginal values
int verify_value(int card_value);

// function for creating a deck with a given number of cards
// returns the newly created deck
dllist *make_deck(int cards);

// function for adding a new deck to the deck list
error add_deck(dllist *deck_list, int cards);

// function for adding a number of cards to a deck
error add_cards(dllist *deck, int index, int card_number);

#endif  // ADD_DECK_H_
