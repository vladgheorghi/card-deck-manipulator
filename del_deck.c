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
#include "exit.h"
#include "shuffle_deck.h"

// function that deletes a deck from the deck list
error del_deck(dllist *deck_list, int index)
{
	if (index >= deck_list -> size || index < 0)
		return DECK_INDEX_OUT_OF_BOUNDS;

	node *parc_decks = deck_list -> head;

	// deletes first deck in the list
	if (index == 0) {
		deck_list -> head = deck_list -> head -> next;

		if (deck_list -> size > 1)
			deck_list -> head -> prev = NULL;

		free_list((dllist *)parc_decks -> card_data);
		free(parc_decks);

		deck_list -> size--;

		return VALID;
	}

	for (int i = 0; i < index; i++)
		parc_decks = parc_decks -> next;

	// deletes last deck in the list
	if (index == deck_list -> size - 1) {
		parc_decks -> prev -> next = NULL;

		free_list((dllist *)parc_decks -> card_data);
		free(parc_decks);

		deck_list -> size--;
	// deletes a deck between 2 other decks in the list
	} else {
		parc_decks -> prev -> next = parc_decks -> next;
		parc_decks -> next -> prev = parc_decks -> prev;

		free_list((dllist *)parc_decks -> card_data);
		free(parc_decks);

		deck_list -> size--;
	}

	return VALID;
}

// function for deleting a card from a deck
error del_card(dllist *deck_list, int index, int card_index)
{
	if (index >= deck_list -> size || index < 0)
		return DECK_INDEX_OUT_OF_BOUNDS;

	// goes to the deck at index position
	node *parc_decks = get_node(deck_list, index);

	dllist *deck = (dllist *)parc_decks -> card_data;

	if (card_index >= deck -> size || card_index < 0)
		return CARD_INDEX_OUT_OF_BOUNDS;

	node *parc = deck -> head;

	// deletes the first card in a deck
	if (card_index == 0) {
		deck -> head = deck -> head -> next;

		free(parc -> card_data);
		free(parc);

		deck -> size--;
	}

	// if a deck ran out of cards it is deleted
	if (deck -> size == 0)
		del_deck(deck_list, index);

	if (card_index == 0)
		return VALID;

	for (int i = 0; i < card_index; i++)
		parc = parc -> next;

	// deletes the last card in a deck
	if (card_index == deck -> size - 1) {
		parc -> prev -> next = NULL;

		free(parc -> card_data);
		free(parc);

		deck -> size--;
	// deletes a card between 2 other cards in the deck
	} else {
		parc -> prev -> next = parc -> next;
		parc -> next -> prev = parc -> prev;

		free(parc -> card_data);
		free(parc);

		deck -> size--;
	}

	return VALID;
}
