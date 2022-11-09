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

#include "commands.h"
#include "dll_implement.h"
#include "exit.h"

// function for freeing all allocated data when exiting the program
void exit_function(dllist *deck_list)
{
	node *parc_decks = deck_list -> head;
	while(deck_list -> head) {
		deck_list -> head = deck_list -> head -> next;

		free_list((dllist *)parc_decks -> card_data);
		free(parc_decks);

		parc_decks = deck_list -> head;
	}

	free(deck_list);
}

// function for freeing the data of a given list
void free_list(dllist *list)
{
	node *parc = list -> head;
	while (list -> head) {
		list -> head = list -> head -> next;

		free(parc -> card_data);
		free(parc);

		parc = list -> head;
	}

	free(list);
}
