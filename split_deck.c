/**
 * Copyright 2022 Gheorghiu Doru-Vlad
 * Facultatea de Automatica si Calculatoare, UPB
 * Year 1, Semester 2
 * Data Structures: Homework 1
 * Double-Linked List Manipulation (Theme: Now you see me)
 **/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "errors.h"
#include "dll_implement.h"
#include "shuffle_deck.h"
#include "del_deck.h"
#include "add_deck.h"

// function that splits a given deck into 2 decks at a given index
error split_deck(dllist *deck_list, int index, int split_index)
{
	if (index >= deck_list -> size || index < 0)
		return DECK_INDEX_OUT_OF_BOUNDS;

	// goes through the deck list for the given deck
	node *parc_decks = get_node(deck_list, index);

	dllist *deck = (dllist *)parc_decks -> card_data;

	if (split_index >= deck -> size || split_index < 0)
		return CARD_INDEX_OUT_OF_BOUNDS;

	if (split_index == 0)
		return VALID;

	// initializing the right side of the deck
	dllist *right = malloc(sizeof(dllist));
	right -> size = 0;
	right -> data_size = sizeof(data);
	right -> head = NULL;

	// initializing the left side of the deck
	dllist *left = malloc(sizeof(dllist));
	left -> size = 0;
	left -> data_size = sizeof(data);
	left -> head = NULL;

	// adds the left side nodes from the given deck to the left deck
	node *parc = deck -> head;
	for (int i = 0; i < split_index; i++) {
		add_node(left, left -> size, parc -> card_data, 0);
		parc = parc -> next;
	}

	// adds the right side nodes from the given deck to the right deck
	for (int i = split_index; i < deck -> size; i++) {
		add_node(right, right -> size, parc -> card_data, 0);
		parc = parc -> next;
	}

	// deletes the given deck
	del_deck(deck_list, index);

	// adds the 2 splited decks to the deck list
	add_node(deck_list, index, left, 1);

	add_node(deck_list, index + 1, right, 1);

	return VALID;
}
