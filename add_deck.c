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

#include "dll_implement.h"
#include "add_deck.h"
#include "errors.h"
#include "exit.h"
#include "shuffle_deck.h"
#include "commands.h"

// function for adding a new deck to the deck list
error add_deck(dllist *deck_list, int cards)
{
	if (cards == 0)
		return INVALID_COMMAND;

	// creates new deck
	dllist *new_deck = make_deck(cards);

	// adds the new deck to the list
	add_node(deck_list, deck_list -> size, new_deck, 1);

	return VALID;
}

// function for creating a deck with a given number of cards
// returns the newly created deck
dllist *make_deck(int cards)
{
	// initializing the new deck
	dllist *new_deck = malloc(sizeof(dllist));
	if (!new_deck) {
		fprintf(stderr, "Failed to malloc: new_deck\n");
		exit(-1);
	}

	new_deck -> head = NULL;
	new_deck -> size = 0;
	new_deck -> data_size = sizeof(data);

	data card_data;
	char input[MAXCOMMLEN];

	// reads card data and verifies if it is valid then adds it to the new deck
	// if a card is invalid it is required to give a new card as input
	for (int i = 0; i < cards; i++) {
		fgets(input, MAXCOMMLEN, stdin);
		sscanf(input, "%d%s", &card_data.card_value, card_data.card_symbol);

		if (verify_value(card_data.card_value) == 1 &&
			verify_symbol(card_data.card_symbol) == 1) {
			add_node(new_deck, new_deck -> size, &card_data, 0);
		} else {
			printf("The provided card is not a valid one.\n");
			i--;
		}
	}

	return new_deck;
}

// function for verifying if a card's value is between marginal values
int verify_value(int card_value)
{
	if (card_value < MINCARDVALUE || card_value > MAXCARDVALUE)
		return 0;

	return 1;
}

// function for verifying if a card's symbol is one of the available ones
int verify_symbol(char *card_symbol)
{
	if (strcmp("HEART", card_symbol) == 0)
		return 1;

	if (strcmp("SPADE", card_symbol) == 0)
		return 1;

	if (strcmp("DIAMOND", card_symbol) == 0)
		return 1;

	if (strcmp("CLUB", card_symbol) == 0)
		return 1;

	return 0;
}

// generic function for adding a node to a list
// if is_deck_list = 0, then it adds a card to a deck
// if is_deck_list = 1, then it adds a deck to the deck_list
void add_node(dllist *list, int pos, void *card_data, int is_deck_list)
{
	if (list == NULL) {
		fprintf(stderr, "List uninitialized.\n");
		return;
	}

	// initializes the new node and stores card_data in it
	node *new_node = malloc(sizeof(node));
	if (!new_node) {
		fprintf(stderr, "Failed to malloc: new_node\n");
		exit(-1);
	}

	if (is_deck_list == 1) {
		new_node -> card_data = card_data;
	} else {
		new_node -> card_data = malloc(list -> data_size);
		if (!new_node -> card_data) {
			fprintf(stderr, "Failed to malloc: new_node -> card_data\n");
			exit(-1);
		}

		memcpy(new_node -> card_data, card_data, list -> data_size);
	}

	if (pos > list -> size)
		pos = list -> size;

	// adds the node to the given list by the given position (pos)

	// if the list is empty, the node is added as the first
	if (list -> size == 0) {
		list -> head = new_node;
		new_node -> next = NULL;
		new_node -> prev = NULL;
		list -> size++;

		return;
	}

	// goes through nodes for the given position
	node *parc = list -> head;

	for (int i = 0; i < pos - 1; i++)
		parc = parc -> next;

	// if pos is last position
	if (pos == list -> size) {
		new_node -> next = NULL;
		new_node -> prev = parc;
		parc -> next = new_node;
		list -> size++;
	// if pos is first position
	} else if (pos == 0) {
		new_node -> next = parc;
		new_node -> prev = NULL;
		parc -> prev = new_node;
		list -> head = new_node;
		list -> size++;
	// if pos is between 2 existing nodes
	} else {
		new_node -> next = parc -> next;
		new_node -> prev = parc;
		parc -> next -> prev = new_node;
		parc -> next = new_node;
		list -> size++;
	}
}

// function for adding a number of cards to a deck
error add_cards(dllist *deck_list, int index, int card_number)
{
	if (index >= deck_list -> size || index < 0)
		return DECK_INDEX_OUT_OF_BOUNDS;

	data card_data;
	char input[MAXCOMMLEN];

	// goes to the deck at index position
	node *parc_decks = get_node(deck_list, index);

	dllist *deck = (dllist *)parc_decks -> card_data;

	// reads card data and verifies if it is valid then adds it to the new deck
	// if a card is invalid it is required to give a new card as input
	for (int i = 0; i < card_number; i++) {
		fgets(input, MAXCOMMLEN, stdin);

		if (strchr("123456789", input[0]) == NULL) {
			printf("The provided card is not a valid one.\n");
			i--;
			continue;
		}

		sscanf(input, "%d%s", &card_data.card_value, card_data.card_symbol);

		if (verify_value(card_data.card_value) == 1 &&
			verify_symbol(card_data.card_symbol) == 1) {
			add_node(deck, deck -> size, &card_data, 0);
		} else {
			printf("The provided card is not a valid one.\n");
			i--;
		}
	}

	return VALID;
}
