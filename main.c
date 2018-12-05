#include "cards.h"
#include <stdlib.h>
#include <stdio.h>

int main() {

    t_card *deck = create_deck();
    t_card *p1 = NULL;
    t_card *p2 = NULL;

    // p2 = (t_card*) malloc(sizeof(t_card));

    dispatch_2p(deck, &p1, &p2);

    display_hand(deck);
    // display_hand(p2);

    return 0;
}

