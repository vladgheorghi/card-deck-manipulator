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
#include "sort_deck.h"

// function for sorting a given deck by its value and symbol
error sort_deck(dllist *deck_list, int index)
{
	if (index >= deck_list -> size || index < 0)
		return DECK_INDEX_OUT_OF_BOUNDS;

	// goes through the deck list for the given deck
	node *parc_decks = get_node(deck_list, index);

	dllist *deck = (dllist *)parc_decks -> card_data;

	if (deck -> size == 1)
		return VALID;

	// initializing the sorted deck
	dllist *deck_sorted = malloc(sizeof(dllist));
	if (!deck_sorted) {
		fprintf(stderr, "Failed malloc: deck_sorted\n");
		exit(-1);
	}
	deck_sorted -> size = 0;
	deck_sorted -> head = NULL;
	deck_sorted -> data_size = sizeof(data);

	node *parc = deck -> head;
	node *mini = parc;
	parc = parc -> next;
	int del_index = 0;
	int size = deck -> size;

	while (size != deck_sorted -> size) {
		// searches for the lesser card
		for (int i = 1; i < deck -> size; i++) {
			if (((data *)parc -> card_data) -> card_value <
				((data *)mini -> card_data) -> card_value) {
					mini = parc;
					del_index = i;
			} else if (((data *)parc -> card_data) -> card_value ==
					   ((data *)mini -> card_data) -> card_value) {
				if (symbol_int(((data *)parc -> card_data) -> card_symbol)
					< symbol_int(((data *)mini -> card_data) -> card_symbol)) {
					mini = parc;
					del_index = i;
				}
			}

			parc = parc -> next;
		}

		// adds the found lesser card to the last position of the sorted deck
		add_node(deck_sorted, deck_sorted -> size, mini -> card_data, 0);

		// deletes the lesser card from the given deck
		del_card(deck_list, index, del_index);

		// repeats the process until no cards are left in the given
		if (size != deck_sorted -> size) {
			parc = deck -> head;
			mini = parc;
			parc = parc -> next;
			del_index = 0;
		}
		// the given deck is deleted afterwards
	}

	// adds the sorted deck to the list
	add_node(deck_list, index, deck_sorted, 1);

	return VALID;
}

// function for assigning a number to a symbol so that they can be compared
int symbol_int(char *symbol)
{
	if (strcmp("HEART", symbol) == 0)
		return 1;
	if (strcmp("SPADE", symbol) == 0)
		return 2;
	if (strcmp("DIAMOND", symbol) == 0)
		return 3;
	return 4;
}
