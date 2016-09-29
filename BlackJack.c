#include<Stdio.h>
#include<stdlib.h>
#include <ctype.h>
#include <string.h>

int main()
{


	printf("\t BlackJack\n");

	char select[5];
	const int bust = 22;
	const int blackjack = 21;
	const int HIGH = 11;
	const int LOW = 1;

	do
	{
		srand(time(0));

		int playerhand[7] = { 0,0,0,0,0,0,0 };
		int dealerhand[7] = { 0,0,0,0,0,0,0 };
		int playertotal = 0;
		int dealertotal = 0;
		int i = 0;
		int playercards = 3;
		int ACE = 0; 


		//player setup

		printf("Your hand is : ");

		for (i; i < 2; i++)
		{
			playerhand[i] = LOW + rand() % (14 - LOW);

			if (playerhand[i] == HIGH || playerhand[i] == LOW)
			{
				ACE++;
				printf(" A ");

				playerhand[i] = HIGH;
				
			}// end if 	
			else if (playerhand[i] == 12)
			{
				printf(" J ");
				playerhand[i] = 10;
			}
			else if (playerhand[i] == 13)
			{
				printf(" Q ");
				playerhand[i] = 10;
			}
			else if (playerhand[i] == 14)
			{
				printf(" K ");
				playerhand[i] = 10;
			}
			else
				printf(" %d ", playerhand[i]);

			if (i == 0)
				printf(",");
			
			playertotal += +playerhand[i];

		}// end for

		if (ACE == 2)
			playertotal = playertotal - 10;

		
		// Dealer setup

		printf("\nthe dealers card is ");

		dealerhand[0] = LOW + rand() % (14 - LOW);

		if (dealerhand[0] == HIGH || dealerhand[i] == LOW)
		{
			printf(" A ");
			dealerhand[i] = HIGH;
		}
		else if (dealerhand[0] == 12)
		{
			printf(" J ");
			dealerhand[0] = 10;
		}
		else if (dealerhand[0] == 13)
		{
			printf(" Q ");
			dealerhand[0] = 10;
		}
		else if (dealerhand[0] == 14)
		{
			printf(" K ");
			dealerhand[0] = 10;
		}
		else
			printf(" % d", dealerhand[0]);

		dealerhand[1] = LOW + rand() % (14 - LOW);
		if (dealerhand[1] == HIGH || dealerhand[1] == LOW)
		{
				dealerhand[1] = HIGH;
		}// end if
		else if (dealerhand[1] == 12)
			dealerhand[1] == 10;
		else if (dealerhand[1] == 13)
			dealerhand[1] == 10;
		else if (dealerhand[1] == 14)
			dealerhand[1] == 10;

		dealertotal = dealerhand[0] + dealerhand[1];

		printf(" \nthe dealers second card is face down");


		do
		{
			if (playertotal >= blackjack)
			{
				if (ACE > 0)
				{
					playertotal - 10;
					continue;
				}
			break;
		    }

			printf("\nhit or hold ? : ");
			scanf("%s", &select);

			for (int b = 0; b < 5; b++)
				select[b] = tolower(select[b]);

			if (strcmp(select, "hit") == 0)
			{
				playerhand[playercards] = LOW + rand() % (HIGH - LOW);
				
				if (playerhand[playercards] == HIGH || playerhand[playercards] == LOW)
				{
					ACE++;
					printf(" A ");

					if (playerhand[i] == LOW)
						playerhand[i] = HIGH;
				}
				else
					printf(" %d ", playerhand[playercards]);

				playertotal += +playerhand[playercards];


				playercards++;
			}// end if 
			if (strcmp(select, "hold") == 0 || playertotal >= blackjack)
			{
				if (ACE > 0 && playertotal > blackjack)
				{
					playertotal - 10;
					continue;
				}
				break;
			}
		}
		while (strcmp(select, "hit") == 0);


		printf("\ndealer turned card face up :  %d \n", dealerhand[1]);

		//playertotal += +playerhand[playercards];

		printf("your hand : %d\n", playertotal);

		printf("dealers hand : %d\n", dealertotal);

		if (playertotal > dealertotal && playertotal <= blackjack)
		{
			printf("Your win!! :)\n");
			if (playertotal == blackjack)
				printf("Black jack!!\n ");
		}
		else if (dealertotal == playertotal)
			printf("Tie\n");
		else
			printf("You Lose :(\n");

		printf("\nPlay agian (yes or no)\n");
		scanf("%s", &select);
		printf("\n");

		for (int b = 0; b < 5; b++)
			select[b] = tolower(select[b]);

	}
	while ((strcmp(select, "yes") == 0));


}// end main