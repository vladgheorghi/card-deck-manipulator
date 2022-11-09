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
#include "commands.h"
#include "add_deck.h"
#include "errors.h"
#include "exit.h"
#include "del_deck.h"
#include "deck_len.h"
#include "shuffle_deck.h"
#include "show.h"
#include "merge_decks.h"
#include "split_deck.h"
#include "reverse_deck.h"
#include "sort_deck.h"

#define MAXPARAM 2  // macro for maximum number of parameters

int main(void)
{
	dllist *deck_list = malloc(sizeof(dllist));  // list of decks
	deck_list -> head = NULL;
	deck_list -> data_size = sizeof(dllist);
	deck_list -> size = 0;
	if (!deck_list) {
		fprintf(stderr, "Failed to malloc: deck_list\n");
		exit(-1);
	}
	int param_int[MAXPARAM], n = 0;
	char *comm_str = malloc(MAXCOMMLEN * sizeof(char)), **param, *p;
	if (!comm_str) {
		fprintf(stderr, "Failed to malloc: comm_str\n");
		exit(-1);
	}
	command comm = EMPTY;  // commands are stored here
	error status = VALID;  // errors are stored here
	while (comm != EXIT) {
		for (int i = 0; i < MAXPARAM; i++)
			param_int[i] = -1;
		fgets(comm_str, BUFSIZ, stdin);  // reads each command line
		p = strchr(comm_str, '\n');
		if (p)  // changes \n with \0
			*p = '\0';
		comm = assign_command(comm_str, &param, &n);  // change line with param
		if (n < 4) {
			for (int i = 1; i < n; i++)
				param_int[i - 1] = atoi(param[i]);  // change strings with ints
		}
		switch (comm) {  // each command branch
			case ADD_DECK:
				status = add_deck(deck_list, param_int[0]);
				break;
			case DEL_DECK:
				status = del_deck(deck_list, param_int[0]);
				break;
			case DEL_CARD:
				status = del_card(deck_list, param_int[0], param_int[1]);
				break;
			case ADD_CARDS:
				status = add_cards(deck_list, param_int[0], param_int[1]);
				break;
			case DECK_NUMBER:
				printf("The number of decks is %d.\n", deck_list -> size);
				status = VALID;
				break;
			case DECK_LEN:
				status = deck_len(deck_list, param_int[0]);
				break;
			case SHUFFLE_DECK:
				status = shuffle_deck(deck_list, param_int[0]);
				break;
			case MERGE_DECKS:
				status = merge_decks(deck_list, param_int[0], param_int[1]);
				break;
			case SPLIT_DECK:
				status = split_deck(deck_list, param_int[0], param_int[1]);
				break;
			case REVERSE_DECK:
				status = reverse_deck(deck_list, param_int[0]);
				break;
			case SHOW_DECK:
				status = show_deck(deck_list, param_int[0]);
				break;
			case SHOW_ALL:
				status = show_all(deck_list);
				break;
			case SORT_DECK:
				status = sort_deck(deck_list, param_int[0]);
				break;
			case EXIT:
				exit_function(deck_list);
				break;
			case EMPTY:
				break;
			case INVALID:
				printf("Invalid command. Please try again.\n");
				break;
		}
		verify_status(status, comm, param_int[0], param_int[1]);  // verifies
		free(param);										// for any errors
	}
	free(comm_str);
	return 0;
}

// function for changing input lines with commands and parameters
// returns a command and stores parameters inside param
command assign_command(char *comm_str, char ***param, int *n)
{
	(*n) = count_parameters(comm_str);
	(*param) = assign_parameters(comm_str, (*n));
	if (strcmp((*param)[0], "ADD_DECK") == 0) {
		if ((*n) == 2)
			if (is_number((*param)[1]))
				return ADD_DECK;
		return INVALID;
	}
	if (strcmp((*param)[0], "DEL_DECK") == 0) {
		if ((*n) == 2)
			if (is_number((*param)[1]))
				return DEL_DECK;
		return INVALID;
	}
	if (strcmp((*param)[0], "DEL_CARD") == 0) {
		if ((*n) == 3)
			if (is_number((*param)[1]) && is_number((*param)[2]))
				return DEL_CARD;
		return INVALID;
	}
	if (strcmp((*param)[0], "ADD_CARDS") == 0) {
		if ((*n) == 3)
			if (is_number((*param)[1]) && is_number((*param)[2]))
				return ADD_CARDS;
		return INVALID;
	}
	if (strcmp((*param)[0], "DECK_NUMBER") == 0) {
		if ((*n) == 1)
			return DECK_NUMBER;
		return INVALID;
	}
	if (strcmp((*param)[0], "DECK_LEN") == 0) {
		if ((*n) == 2)
			if (is_number((*param)[1]))
				return DECK_LEN;
		return INVALID;
	}
	if (strcmp((*param)[0], "SHUFFLE_DECK") == 0) {
		if ((*n) == 2)
			if (is_number((*param)[1]))
				return SHUFFLE_DECK;
		return INVALID;
	}
	if (strcmp((*param)[0], "MERGE_DECKS") == 0) {
		if ((*n) == 3)
			if (is_number((*param)[1]) && is_number((*param)[2]))
				return MERGE_DECKS;
		return INVALID;
	}
	if (strcmp((*param)[0], "SPLIT_DECK") == 0) {
		if ((*n) == 3)
			if (is_number((*param)[1]) && is_number((*param)[2]))
				return SPLIT_DECK;
		return INVALID;
	}
	if (strcmp((*param)[0], "REVERSE_DECK") == 0) {
		if ((*n) == 2)
			if (is_number((*param)[1]))
				return REVERSE_DECK;
		return INVALID;
	}
	if (strcmp((*param)[0], "SHOW_DECK") == 0) {
		if ((*n) == 2)
			if (is_number((*param)[1]))
				return SHOW_DECK;
		return INVALID;
	}
	if (strcmp((*param)[0], "SHOW_ALL") == 0) {
		if ((*n) == 1)
			return SHOW_ALL;
		return INVALID;
	}
	if (strcmp((*param)[0], "SORT_DECK") == 0) {
		if ((*n) == 2)
			if (is_number((*param)[1]))
				return SORT_DECK;
		return INVALID;
	}
	if (strcmp((*param)[0], "EXIT") == 0) {
		if ((*n) == 1)
			return EXIT;
		return INVALID;
	}
	return INVALID;
}

// function for storing each parameter
char **assign_parameters(char *comm_str, int n)
{
	char **param = malloc(n * sizeof(char *));
	if (!param) {
		fprintf(stderr, "Failed to malloc: param\n");
		exit(-1);
	}

	char *token = strtok(comm_str, " ");

	int i = 0;

	while (token) {
		param[i] = token;
		token = strtok(NULL, " ");
		i++;
	}

	return param;
}

// function for counting the number of parameters
int count_parameters(char *comm_str)
{
	int i = 0, param = 1;

	while (comm_str[i]) {
		if (comm_str[i] == ' ')
			param++;
		i++;
	}

	return param;
}

// function for verifying if a string is a number
int is_number(char *input)
{
	int i = 0;

	if(input[0] == '-')
		i++;

	while (input[i]) {
		if (strchr("0123456789", input[i]) == NULL)
			return 0;
		i++;
	}

	return 1;
}

// function that checks for errors and outputs a proper message
void verify_status(error status, command comm, int param1, int param2)
{
	switch (comm) {
		case ADD_DECK:
			if (status == INVALID_COMMAND)
				printf("Invalid command. Please try again.\n");
			else if (status == VALID)
				printf("The deck was successfully created with %d cards.\n",
					   param1);
			break;
		case DEL_DECK:
			if (status == DECK_INDEX_OUT_OF_BOUNDS)
				printf("The provided index is out of bounds for the deck list.\n");
			else if (status == VALID)
				printf("The deck %d was successfully deleted.\n", param1);
			break;
		case DEL_CARD:
			if (status == DECK_INDEX_OUT_OF_BOUNDS)
				printf("The provided index is out of bounds for the deck list.\n");
			else if (status == CARD_INDEX_OUT_OF_BOUNDS)
				printf("The provided index is out of bounds for deck %d.\n",
				param1);
			else if (status == VALID)
				printf("The card was successfully deleted from deck %d.\n",
					   param1);
			break;
		case ADD_CARDS:
			if (status == DECK_INDEX_OUT_OF_BOUNDS)
				printf("The provided index is out of bounds for the deck list.\n");
			else if (status == VALID)
				printf("The cards were successfully added to deck %d.\n",
					   param1);
			break;
		case DECK_NUMBER:
			break;
		case DECK_LEN:
			if (status == DECK_INDEX_OUT_OF_BOUNDS)
				printf("The provided index is out of bounds for the deck list.\n");
			break;
		case SHUFFLE_DECK:
			if (status == DECK_INDEX_OUT_OF_BOUNDS)
				printf("The provided index is out of bounds for the deck list.\n");
			else if (status == VALID)
				printf("The deck %d was successfully shuffled.\n", param1);
			break;
		case MERGE_DECKS:
			if (status == DECK_INDEX_OUT_OF_BOUNDS)
				printf("The provided index is out of bounds for the deck list.\n");
			else if (status == VALID)
				printf("The deck %d and the deck %d were successfully merged.\n",
					   param1, param2);
			else if (status == INVALID_COMMAND)
				printf("Invalid command. Please try again.\n");
			break;
		case SPLIT_DECK:
			if (status == DECK_INDEX_OUT_OF_BOUNDS)
				printf("The provided index is out of bounds for the deck list.\n");
			else if (status == CARD_INDEX_OUT_OF_BOUNDS)
				printf("The provided index is out of bounds for deck %d.\n",
					   param1);
			else if (status == VALID)
				printf("The deck %d was successfully split by index %d.\n",
					   param1, param2);
			break;
		case REVERSE_DECK:
			if (status == DECK_INDEX_OUT_OF_BOUNDS)
				printf("The provided index is out of bounds for the deck list.\n");
			else if (status == VALID)
				printf("The deck %d was successfully reversed.\n", param1);
			break;
		case SHOW_DECK:
			if (status == DECK_INDEX_OUT_OF_BOUNDS)
				printf("The provided index is out of bounds for the deck list.\n");
			break;
		case SHOW_ALL:
			break;
		case SORT_DECK:
			if (status == DECK_INDEX_OUT_OF_BOUNDS)
				printf("The provided index is out of bounds for the deck list.\n");
			else if (status == VALID)
				printf("The deck %d was successfully sorted.\n", param1);
			break;
		case EXIT:
			break;
		case EMPTY:
			break;
		case INVALID:
			break;
	}
}
