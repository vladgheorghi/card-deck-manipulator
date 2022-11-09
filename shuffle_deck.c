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

// function for shuffling a given deck
error shuffle_deck(dllist *deck_list, int index)
{
	if (deck_list -> size <= index || index < 0)
		return DECK_INDEX_OUT_OF_BOUNDS;

	// goes through the deck list for the given deck
	node *parc_decks = get_node(deck_list, index);

	dllist *deck = (dllist *)parc_decks -> card_data;

	if (deck -> size == 1)
		return VALID;

	node *half = get_node(deck, deck -> size / 2 - 1);
	node *last = get_node(deck, deck -> size - 1);
	node *half_next = get_node(deck, deck -> size / 2);

	// operations for switching the halves of the deck
	half -> next = NULL;
	last -> next = deck -> head;
	deck -> head -> prev = last;
	half_next -> prev = NULL;
	deck -> head = half_next;

	return VALID;
}

// function that returns the nth node of a given list
node *get_node(dllist *deck, int n)
{
	if (n >= deck -> size)
		return NULL;

	node *parc = deck -> head;

	for (int i = 0; i < n; i++)
		parc = parc -> next;

	return parc;
}
