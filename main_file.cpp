#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<windows.h>
#include<conio.h>

void disp(char *display ,int len);

int main(){
	system("color 3");
	
	//For displaying rules:
	printf("\t\t\t\t\t**--**Hangman**--**\n");
	printf("\t\t\t\t*****Rules for playing Hangman Game*****\n");
	printf("\t\t\t\t1.Guess the letter of the word.\n\t\t\t\t2.Enter the letter by using keyboard.\n\t\t\t\t3.Don't enter the same letter again.\n\t\t\t\t4.You have only 6 chances if you made a mistake\n");
	
	
	//File system
	FILE *fptr ;
	fptr =fopen("text.txt","a");

	char name_player[50];
	char print[100] = "Enter your name \a:";

	// Displaying it 
	for(int i = 0 ; print[i] !='\0' ;i++){
		Sleep(90);
		printf("%c",print[i]);
	}
	fgets(name_player,25,stdin);
	fprintf(fptr,"\t\t\t\tPlayer's Name :%s",name_player);
	fclose(fptr);


	//For random words; // dictionary
	char name[10][20] ={
	"rat","mouse","aeiou","happy","sad","apple","laptop","keyboard","bottel","book"};
	
	
	srand(time(NULL));
	int r = rand()%10;
	
	//length of the random string;
	int len = strlen(name[r]);
	
	// //test 
	// printf("\t\t\t\t%s\n",name[r]);
	// printf("\t\t\t\t%d\n",len);
	
	
	//initalization
	int chance = 0 ;
	int flag = 0 ;
	int l = 0 ;
	char display[15];
	char ch;
	
	// displaying ---... on consol
	disp(display,len);
	printf("\n");
	printf(" ________\n         |\n|\n|\n|\n|\n|\n|\n|\n");
	
	
	//file in append mode 
	FILE *ptr ;
	ptr = fopen("text.txt","a");
	fprintf(ptr , "\t\t\t\tThe random word from my dictionary is :%s\n",name[r]);

	//	main code 
	fprintf(ptr,"\t\t\t\tThe guess letters are:\n\t\t\t\tRight letter:\t\t\t\t\tWrong letter:\n\t\t\tAttempts:\n");
	while(chance < 6){
		int c = 0 ;
		printf("\t\t\t\tEnter the guess word:");
		fflush(stdin);
		scanf("%c",&ch);
		
		// in case of right word 
		for(int i = 0 ; i<len ;i++){
			
			if( ch == name[r][i]){
				display[i] = ch;
				l++;
				c++;
				//For right word in file 
				fprintf(ptr , "\t\t\t\t%c\n",ch);
			}
		}
		if(c>0){
			//Displaying
			printf("\t\t\t\t%s\n",display);
			//displaying hand man
			if(flag == 0){
				printf(" ________\n         |\n|\n|\n|\n|\n|\n|\n|\n");
			}
			if(flag == 1){
				printf(" ________\n         |\n        (\n|\n|\n|\n|\n|\n|\n|\n");
			}
			if(flag == 2){
				printf(" ________\n         |\n        ( )\n|\n|\n|\n|\n|\n|\n");
			}
			if(flag == 3){
				printf(" ________\n         |\n        ( )\n         |\n|\n|\n|\n|\n|\n|\n|\n");
			}
			if(flag == 4){
				printf(" ________\n         |\n        ( )\n        \\|\n|\n|\n|\n|\n|\n|\n");
			}
			if(flag == 5){
				printf(" ________\n         |\n        ( )\n        \\|/\n|\n|\n|\n|\n|\n|\n");
			}
			if(flag == 6){
				printf(" ________\n         |\n        ( )\n        \\|/\n        / \\\n|\n|\n|\n|\n|\n");		
			}
	}
				
	
		// in case of wrong word 
		if(c == 0){


			//file system
			fprintf(ptr,"\t\t\t\t\t\t\t\t\t\t\t\t\t%c\n",ch);
			
			
			chance++;
			printf("\t\t\t\tYou have %d chance left\n:",6-chance);
			flag++;
			printf("\t\t\t\t%s\n",display);
			
		if(flag == 1){
			printf(" ________\n         |\n        (\n|\n|\n|\n|\n|\n|\n|\n");
		}
		if(flag == 2){
			printf(" ________\n         |\n        ( )\n|\n|\n|\n|\n|\n|\n");
		}
		if(flag == 3){
			printf(" ________\n         |\n        ( )\n         |\n|\n|\n|\n|\n|\n|\n|\n");
		}
		if(flag == 4){
			printf(" ________\n         |\n        ( )\n        \\|\n|\n|\n|\n|\n|\n|\n");
		}
		if(flag == 5){
			printf(" ________\n         |\n        ( )\n        \\|/\n|\n|\n|\n|\n|\n|\n");
		}
		if(flag == 6){
			printf(" ________\n         |\n        ( )\n        \\|/\n        / \\\n|\n|\n|\n|\n|\n");
		}
		}
		
	
		printf("\n");
		if( len == l){
			break;
		}
		
	}
	if( len == l){
		printf("**************************");
		printf("you won the game");	
		printf("**************************\n");
	}else{
		printf("**************************");
		printf("Please try again\nYou hanged ");
		printf("**************************\n");
	}
	
	fclose(ptr);


	return 0;
}

void disp(char *display , int len){
	int i;
	for(i = 0 ; i<len ; i++){
		display[i] = '-';
	}
	display[i] = '\0';
	printf("\t\t\t\t%s\n",display);
}
