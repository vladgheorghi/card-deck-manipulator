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

// function for showing a deck's length
error deck_len(dllist *deck_list, int index)
{
	if (index >= deck_list -> size || index < 0)
		return DECK_INDEX_OUT_OF_BOUNDS;

	// goes to the deck at index position
	node *parc_decks = get_node(deck_list, index);

	dllist *deck = (dllist *)parc_decks -> card_data;

	printf("The length of deck %d is %d.\n", index, deck -> size);

	return VALID;
}
