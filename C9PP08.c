/* Name: Abdirisak Arr
 * Date: 13/09/2019
 * Description: Simulates a game of craps; played with two dice
 */
 
 #include <stdio.h>
 #include <stdlib.h>
 #include <stdbool.h>
 #include <ctype.h>
 #include <time.h>
 
 #define ROLL_LIMIT 100
 #define INITIAL 0
 
 int roll_dice(void);
 bool play_game(void);
 
 int main(void)
 {
 	int win_count = 0, loss_count = 0;
 	bool result;
 	char condition;
 	
 	srand((unsigned) time(NULL));
 	
 	printf("Game of Craps Simulation. (Key: y - yes, n - no)\n");
 	printf("------------------------------------------------\n");
 	
 	for (;;)
 	{
 		result = play_game();
 		
 		if (result)
 		{
 			printf("You win!\n");
 			win_count++;
		}
		else
		{
			printf("You lose!\n");
			loss_count++;
		}
		
		printf("\nPlay again: ");
		condition = getchar();
		getchar();
		
		if (tolower(condition) == 'n')
		{
			break;
		}
		printf("\n");
	}
	
	printf("\nWins: %d\tLosses: %d", win_count, loss_count);
 	
 	return 0;
 }
 
 int roll_dice(void)
 {
 	int dice1, dice2, sum;
 	
 	dice1 = (rand() % 6) + 1;
 	dice2 = (rand() % 6) + 1;
 	
 	sum = dice1 + dice2;
 	
 	return sum;
 }
 
 bool play_game(void)
 {
 	int roll[ROLL_LIMIT], roll_count;
	
	for (roll_count = INITIAL;; roll_count++)
	{
		roll[roll_count] = roll_dice();
		printf("You rolled: %d\n", roll[roll_count]);
		if (roll_count == INITIAL && (roll[roll_count] == 7 || roll[roll_count] == 11))
		{
			return true;
		}
		
		else if (roll_count == INITIAL && (roll[roll_count] == 2 || roll[roll_count] == 3 || roll[roll_count] == 12))
		{
			return false;
		}
		
		else if (roll_count > INITIAL && roll[roll_count] == roll[INITIAL])
		{
			return true;
		}
		
		else if (roll_count > INITIAL && roll[roll_count] == 7)
		{
			return false;
		}
		
		if (roll_count == INITIAL)
		{
			printf("Your point is %d\n", roll[roll_count]);
		}
	}
 }
