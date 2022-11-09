/**
 * Copyright 2022 Gheorghiu Doru-Vlad
 * Facultatea de Automatica si Calculatoare, UPB
 * Year 1, Semester 2
 * Data Structures: Homework 1
 * Double-Linked List Manipulation (Theme: Now you see me)
 **/

#ifndef DLL_IMPLEMENT_H_
#define DLL_IMPLEMENT_H_

#define MAXSYMLEN 8  // macro for maximum symbol length

#define MAXCARDVALUE 14  // macro for maximum card value

#define MINCARDVALUE 1  // macro for minimum card value

// struct for storing card data
typedef struct deck_data {
	int card_value;
	char card_symbol[MAXSYMLEN];
} data;

// generic struct for a node in a double-linked list
typedef struct node {
	struct node *next;
	struct node *prev;
	void *card_data;
} node;

// generic struct for a double-linked list
typedef struct double_linked_list {
	node *head;
	int size;
	int data_size;
} dllist;

#endif  // DLL_IMPLEMENT_H_
