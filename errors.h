/**
 * Copyright 2022 Gheorghiu Doru-Vlad
 * Facultatea de Automatica si Calculatoare, UPB
 * Year 1, Semester 2
 * Data Structures: Homework 1
 * Double-Linked List Manipulation (Theme: Now you see me)
 **/

#ifndef ERRORS_H_
#define ERRORS_H_

// storing each error in an enum
// each command function returns an element from this enum
// if a function has no errors, it returns VALID
typedef enum errors {
	DECK_INDEX_OUT_OF_BOUNDS,
	CARD_INDEX_OUT_OF_BOUNDS,
	INVALID_CARD,
	INVALID_COMMAND,
	VALID
} error;

#endif  // ERRORS_H_
