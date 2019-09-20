/************************************************************
* Name: Abdirisak Arr                                       *
* Date: 19/09/2019                                          *
* Description: Poker.c modification whereby cards are stored*
*              in a 5*2 array, removing the need for        *
*              num_in_rank, num_in_suit, and card_exists    *
*              arrays.                                      *
*************************************************************/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_CARDS 5
#define RANK_AND_SUIT 2
#define RANK 0
#define SUIT 1

/* external variables */
int cards[NUM_CARDS] [RANK_AND_SUIT];
bool straight, flush, four, three;
int pairs; /* can be 0, 1, or 2 */

/* prototypes */
void read_cards(void);
void analyze_hand(void);
void print_result(void);

/************************************************************
* main: Calls read_cards, analyze_hand, and print_result    *
*       repeatedly.                                         *
*************************************************************/

int main(void)
{
	for (;;)
	{
		read_cards();
		analyze_hand();
		print_result();
	}
}

/************************************************************
* read_cards: Reads the cards into the external variable    *
*             num_cards; checks for bad cards and duplicate *
*             cards.                                        *
*************************************************************/

void read_cards(void)
{
	char ch, rank_ch, suit_ch;
	bool bad_card;
	bool repeat = false;
	int cards_read = 0;
	int rank, suit;
	int back_cards; /* used to navigate external array, cards */
	
	while (cards_read < NUM_CARDS)
	{
		bad_card = false;
		
		printf("Enter a card: ");
		
		rank_ch = getchar();
		switch (rank_ch)
		{
			case '0':
				exit(EXIT_SUCCESS);
			case '2':
				rank = 0;
				break;
			case '3':
				rank = 1;
				break;
			case '4':
				rank = 2;
				break;
			case '5':
				rank = 3;
				break;
			case '6':
				rank = 4;
				break;
			case '7':
				rank = 5;
				break;
			case '8':
				rank = 6;
				break;
			case '9':
				rank = 7;
				break;
			case 't': case 'T':
				rank = 8;
				break;
			case 'j': case 'J':
				rank = 9;
				break;
			case 'q': case 'Q':
				rank = 10;
				break;
			case 'k': case 'K':
				rank = 11;
				break;
			case 'a': case 'A':
				rank = 12;
				break;
			default:
				bad_card = true;
		}
		
		suit_ch = getchar();
		switch (suit_ch)
		{
			case 'c': case 'C':
				suit = 0;
				break;
			case 'd': case 'D':
				suit = 1;
				break;
			case 'h': case 'H':
				suit = 2;
				break;
			case 's': case 'S':
				suit = 3;
				break;
			default:
				bad_card = true;
		}
		
		while ((ch = getchar()) != '\n')
		{
			if (ch != ' ')
			{
				bad_card = true;
			}
		}
		
		/* checks for repeats/duplicates */
		if (cards_read > 0)
		{
			for (back_cards = 0; back_cards < cards_read; back_cards++)
			{
				if (cards[back_cards] [RANK] == rank && cards[back_cards] [SUIT] == suit && bad_card != true)
				{
					repeat = true;
				}
			}
		}
		
		if (bad_card)
		{
			printf("Bad card; ignored.\n");
		}
		else if (repeat)
		{
			printf("Duplicate card; ignored.\n");
			repeat = false;
		}
		else
		{
			cards[cards_read] [RANK] = rank;
			cards[cards_read] [SUIT] = suit;
			cards_read++;
		}
	}
}

/************************************************************
* analyze_hand: Determines whether the hand contains a      *
*               straight, a flush, four-of-a-kind, and/or   *
*               three-of-a-kind; determines the number      *
*               of pairs; stores the results into the       *
*               external variables straight, flush, four,   *
*               three and pairs.                            *
*************************************************************/

void analyze_hand(void)
{
	int matches = 0;
	int same_suit = 1;
	int card, card2, rank_sum = 0;
	straight = false;
	flush = false;
	four = false;
	three = false;
	pairs = 0;
	
	/* checks for flush */
	for (card = 1; card < NUM_CARDS; card++)
	{
		if (cards[0] [SUIT] == cards[card] [SUIT])
		{
			same_suit++;
		}
	}
	if (same_suit == 5)
	{
		flush = true;
	}
	
	/* checks for straight */
	for (card = 0; card < NUM_CARDS; card++)
	{
		rank_sum += cards[card] [RANK];
	}
	if (rank_sum % 5 == 0)
	{
		straight = true;
	}
	
	/* checks for 4-of-a-kind, and 3-of-a-kind, and pairs*/
	card = 0;
	while (card < NUM_CARDS - 1)
	{
		card2 = card + 1;
		while (card2 < NUM_CARDS)
		{
			if (cards[card] [RANK] == cards[card2] [RANK])
			{
				matches++;
			}
			card2++;
		}
		card++;
	}
	if (matches == 6)
	{
		four = true;
	}
	else if (matches == 3)
	{
		three = true;
	}
	else if (matches == 2)
	{
		pairs = matches;
	}
	else if (matches == 1)
	{
		pairs = matches;
	}
}

/************************************************************
* print_result: Prints the classification of the hand, based*
*               on the values of the external variables     *
*               straight, flush, four, three, and pairs     *
*************************************************************/

void print_result(void)
{
	if (straight && flush)
	{
		printf("Straight flush");
	}
	else if (four)
	{
		printf("Four of a kind");
	}
	else if (three && pairs == 1)
	{
		printf("Full house");
	}
	else if (flush)
	{
		printf("Flush");
	}
	else if (straight)
	{
		printf("Straight");
	}
	else if (three)
	{
		printf("Three of a kind");
	}
	else if (pairs == 2)
	{
		printf("Two pairs");
	}
	else if (pairs == 1)
	{
		printf("Pair");
	}
	else
	{
		printf("High card");
	}
	
	printf("\n\n");
}

