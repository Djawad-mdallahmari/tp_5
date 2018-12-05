#include "cards.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

t_card * create_deck(){
	t_card *current = NULL;
	t_card *previous = NULL;

	for (int i = 0; i < MAX_VAL; i++)
	{
		for (int j = 0; j < MAX_COLOR; j++)
		{
			current = (t_card*) malloc(sizeof(t_card));
			current->value = i;
			current->color = j;

			if(i==0 && j==0){
				current->next = NULL;
			}else{
				current->next = previous;
			}
			previous = current;
		}
	}

	return current;
}


int valueInArray(int val, int arr[], int size){
    int i;
    int res = 0;
    for (i=0; i < size; i++) {
        if (arr[i] == val){
            res = 1;
        }
    }
    return res;
}


void dispatch_2p(t_card* deck,t_card **hand_p1, t_card **hand_p2){
	int usedIndex[32]={};
	usedIndex[32]='\0';
	srand(time(NULL));
	int myrandom;
	t_card* headDeck = deck;
	
	t_card* previous = NULL;
	//Une seule liste (hand_p1)
	// tant qu on a pas distribue 32 cartes
	int distributedCardCpt = 0;
	while(distributedCardCpt < 32){
		deck = headDeck; //reprend le debut de la deck à chaque fois
		// choix du random (index dans le deck)
		do{
		 	myrandom = rand() % 33;
		}while(valueInArray(myrandom, usedIndex, 32)==1); //pas encore utilise
		// ajout de l index dans usedIndex
		usedIndex[distributedCardCpt] = myrandom;
		// selection dune carte au hasard
		for (int i = 0; i < myrandom; i++)
		{
			deck = deck->next;
		}
		// changement du head pointer de la liste
		hand_p1 = &deck;
		// MAJ du next qui pointe maintenant vers lancien
		(*hand_p1)->next = previous;
		// MAJ previous
		previous = (*hand_p1);

		//MAJ compteur carte distribue
		distributedCardCpt++;
	}
}

void display_hand(t_card *head){
	t_card *ptr = NULL;
	ptr = head;

	char *value="";
	char *color=""; 
	while(ptr != NULL){
//PIC, COEUR, CARREAU, TREFLE , MAX_COLOR 
		switch(ptr->value){
			case SEPT: value = "SEPT";break;
			case HUIT: value = "HUIT";break;
			case NEUF: value = "NEUF";break;
			case DIX: value = "DIX";break;
			case VALET: value = "VALET";break;
			case REINE: value = "REINE";break;
			case ROI: value = "ROI";break;
			case AS: value = "AS";break;
			case MAX_VAL: value = NULL;
		}

		switch(ptr->color){
			case PIC: color = "PIC";break;
			case COEUR: color = "COEUR";break;
			case CARREAU: color = "CARREAU";break;
			case TREFLE: color = "TREFLE";break;
			case MAX_COLOR: value = NULL;
		}

		printf("%s ", value);
		printf("%s\n", color);
		ptr = ptr->next;
	}
}
