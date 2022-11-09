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
#include "add_deck.h"
#include "del_deck.h"

// function for reversing the cards in a given deck
error reverse_deck(dllist *deck_list, int index)
{
	if (index >= deck_list -> size || index < 0)
		return DECK_INDEX_OUT_OF_BOUNDS;

	// initializing the reversed deck
	dllist *deck_reversed = malloc(sizeof(dllist));
	deck_reversed -> size = 0;
	deck_reversed -> data_size = sizeof(data);
	deck_reversed -> head = NULL;

	// goes through the deck list for the given deck
	node *parc_decks = get_node(deck_list, index);

	dllist *deck = (dllist *)parc_decks -> card_data;

	node *parc = get_node(deck, deck -> size - 1);

	// adds cards to the reversed deck from the given deck,
	// starting from the end of it
	while (parc != deck -> head) {
		add_node(deck_reversed, deck_reversed -> size, parc -> card_data, 0);
		parc = parc -> prev;
	}
	add_node(deck_reversed, deck_reversed -> size, parc -> card_data, 0);

	// deletes the given deck
	del_deck(deck_list, index);

	// adds the reversed deck to the deck list
	add_node(deck_list, index, deck_reversed, 1);

	return VALID;
}
