/**
 * Copyright 2022 Gheorghiu Doru-Vlad
 * Facultatea de Automatica si Calculatoare, UPB
 * Year 1, Semester 2
 * Data Structures: Homework 1
 * Double-Linked List Manipulation (Theme: Now you see me)
 **/

#ifndef COMMANDS_H_
#define COMMANDS_H_

#include "errors.h"

#define MAXCOMMLEN 50  // macro for maximum length of command input

// each command is stored in a enum so it can be used in switch case
typedef enum commands {
	ADD_DECK,
	DEL_DECK,
	DEL_CARD,
	ADD_CARDS,
	DECK_NUMBER,
	DECK_LEN,
	SHUFFLE_DECK,
	MERGE_DECKS,
	SPLIT_DECK,
	REVERSE_DECK,
	SHOW_DECK,
	SHOW_ALL,
	SORT_DECK,
	EXIT,
	EMPTY,
	INVALID
} command;

// function for verifying if a string is a number
int is_number(char *input);

// function for counting the number of parameters
int count_parameters(char *comm_str);

// function for storing each parameter
char **assign_parameters(char *comm_str, int n);

// function for changing input lines with commands and parameters
// returns a command and stores parameters inside param
command assign_command(char *comm_str, char ***param, int *n);

// function that checks for errors and outputs a proper message
void verify_status(error status, command comm, int param1, int param2);

#endif  // COMMANDS_H_
