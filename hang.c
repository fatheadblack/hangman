#include<stdio.h>
#include<string.h>
#include<stdbool.h>

int play(char* wo, char* sol, char* use, int liv, int* uc)
{

 char guess;
 bool success = false;
 printf("\nEnter your next guess : ");
 scanf(" %c", &guess);
	
 for(int i =0; i<strlen(wo); i++)
 {
	if(wo[i] == guess)
	{
		sol[i] = wo[i];
		success = true;	
	}
 }

 if (success == false)
 {
  liv--;
  use[*uc] = guess;
  *uc += 1;
 }

 return liv;

}


void show(char* sol, int liv, char* use)
{
	printf("%s\n", sol);
	printf("lives remaining %i\n", liv);
	printf("Letters already used : ");
	for(int i =0; i<=strlen(use); i++)
	 {
		printf("%c",use[i]);
	 }
	printf("\n");
}



int main()
{

 int lives = 6;
 
 bool gameover = false;

 char word[20];
 char used[10];
 int usedcounter = 0;

 for(int i=0; i<20; i++)
{
  word[i] = ' ';
}


 printf("Enter word to guess : ");
 scanf("%s",word);
 
 int N = strlen(word);

 char solved[N];


 for(int i = 0; i<N; i++)
   {
	solved[i] = '*';
        used[i] = ' ';
   }

 show(solved, lives, used);
 
 int result = -2;
 while(gameover == false)
   {

     lives = play(word,solved,used,lives,&usedcounter);

     show(solved,lives, used);

     result =  (strcmp(word,solved));
     if (result == 0)
        { printf("Congratulations, You guessed correctly\n");
		gameover = true;
        }	
     if (lives == 0)
	{ printf("Sorry, you failed to guess correctly\n");
	  printf("The correct word was %s\n", word);
		gameover = true;
	}	

   }

 return 0;

}
