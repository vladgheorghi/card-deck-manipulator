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
#include "show.h"
#include "shuffle_deck.h"

// function for outputing a given deck
error show_deck(dllist *deck_list, int index)
{
	if (index >= deck_list -> size || index < 0)
		return DECK_INDEX_OUT_OF_BOUNDS;

	printf("Deck %d:\n", index);

	node *parc_decks = get_node(deck_list, index);

	node *parc = ((dllist *)parc_decks -> card_data) -> head;

	for (int i = 0; i < ((dllist *)parc_decks -> card_data) -> size; i++) {
		printf("\t%d", ((data *) parc -> card_data) -> card_value);
		printf(" %s\n", ((data *) parc -> card_data) -> card_symbol);

		parc = parc -> next;
	}

	return VALID;
}

// function for outputing all decks from the deck list
error show_all(dllist *deck_list)
{
	for (int i = 0; i < deck_list -> size; i++)
		show_deck(deck_list, i);

	return VALID;
}
