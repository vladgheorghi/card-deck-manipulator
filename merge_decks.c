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
#include "add_deck.h"
#include "del_deck.h"
#include "merge_decks.h"
#include "shuffle_deck.h"

// function for merging 2 given decks
error merge_decks(dllist *deck_list, int index1, int index2)
{
	if (index1 == index2)
		return INVALID_COMMAND;

	if (index1 >= deck_list -> size || index2 >= deck_list -> size)
		return DECK_INDEX_OUT_OF_BOUNDS;

	if(index1 < 0 || index2 < 0)
		return DECK_INDEX_OUT_OF_BOUNDS;

	// initializing merged deck
	dllist *merged_deck = malloc(sizeof(dllist));
	if (!merged_deck) {
		fprintf(stderr, "Failed to malloc: merged_deck\n");
		exit(-1);
	}

	merged_deck -> size = 0;
	merged_deck -> data_size = sizeof(data);

	// goes through the deck list for the 2 decks
	node *parc1_deck = get_node(deck_list, index1);
	node *parc2_deck = get_node(deck_list, index2);

	node *parc1 = ((dllist *)parc1_deck -> card_data) -> head;
	node *parc2 = ((dllist *)parc2_deck -> card_data) -> head;

	// adds nodes to the merged deck from the 2 given decks repeatedly
	while (parc1 && parc2) {
		add_node(merged_deck, merged_deck -> size, parc1 -> card_data, 0);
		parc1 = parc1 -> next;

		add_node(merged_deck, merged_deck -> size, parc2 -> card_data, 0);
		parc2 = parc2 -> next;
	}

	// when a deck ran out of cards to be added, adds the rest of the cards
	// from the deck with more cards left
	while (parc1) {
		add_node(merged_deck, merged_deck -> size, parc1 -> card_data, 0);
		parc1 = parc1 -> next;
	}

	while (parc2) {
		add_node(merged_deck, merged_deck -> size, parc2 -> card_data, 0);
		parc2 = parc2 -> next;
	}

	// deletes the 2 given decks
	if (index1 > index2) {
		del_deck(deck_list, index1);
		del_deck(deck_list, index2);
	} else {
		del_deck(deck_list, index2);
		del_deck(deck_list, index1);
	}

	// adds the merged deck to the deck list
	add_node(deck_list, deck_list -> size, merged_deck, 1);

	return VALID;
}
