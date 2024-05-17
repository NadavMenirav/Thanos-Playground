/**********************
 * Nadav Menirav
 * 330845678
 * ex_2
 **********************/

#include <stdio.h>
#include <math.h>

//Functions 
int mainMenu();
int firstQuest();
int secondQuest();
int thirdQuest();
int fourthQuest();
int fifthQuest();
void printError(int minNumberRequired);
int isPrime(int num);
int scanDouble();

int main() {
	//While player hasn't quit
	int isPlayerDone = 0;
	while (!isPlayerDone) {
		isPlayerDone = mainMenu();
	}
	return 0;
}

int mainMenu() {
	//Main menu of the game
	printf("Welcome to Thanos's playground.\n");
	printf("Choose your adventure:\n");
	printf("1. Revealing the Hidden Code\n");
	printf("2. Thanos' numeric mayhem\n");
	printf("3. Thanos' Maze System\n");
	printf("4. The Sorcery of Thanos\n");
	printf("5. Quit the quest\n\n");

	int	questChoice = 0;
	double questChoiceDouble = 0, remainder = 0;
	scanf("%lf", &questChoiceDouble);

	questChoice = (int)questChoiceDouble;
	remainder = questChoiceDouble - questChoice;

	//Gets valid value for questChoice
	if (questChoice < 1 || questChoice > 5 || remainder != 0.0) {
		printf("Thanos is mad! You are playing his game and this is not an option. Choose again, wisely.\n\n");
		return 0;
	}

	//Playing the quests
	if (questChoice == 1)
		return firstQuest();
	if (questChoice == 2)
		return secondQuest();
	if (questChoice == 3)
		return thirdQuest();
	if (questChoice == 4)
		return fourthQuest();
	if (questChoice == 5)
		return fifthQuest();
	return 0;

}

int firstQuest() {
	//The function scans an integer and prints FizzBuzz values till the scanned integer

	const int minValueOfNum = 2;
	int num = scanDouble(), i = 0;
	//scanf("%d", &num);

	//Scanned an invalid number
	if (num < minValueOfNum) {
		printError(minValueOfNum-1);
		return 0;
	}

	for (i = 1;i <= num;i++) {
		if (i % 3 == 0)
			printf("Fizz");

		if (i % 5 == 0)
			printf("Buzz");

		if (i % 3 && i % 5)
			printf("%d", i);
		printf("\n");
	}
	printf("\n");
	return 0;
}

int secondQuest() {
	//The function scans an integer "num" and prints the first "num" numbers in Fibonacci Sequence

	//printf("\nEnter a number: ");
	const int minValueOfScannedNum = 1;
	int num = scanDouble(), i = 0;
	unsigned long long int twoNumBack = 0, oneNumBack = 1, currentNum = 0;
	//scanf("%d", &num);

	//Invalid input
	if (num < minValueOfScannedNum) {
		printError(minValueOfScannedNum-1);
		return 0;
	}

	//Prints the first number in Fibonacci, 0
	printf("%llu", twoNumBack);

	//Prints the second one if requested
	if (num > minValueOfScannedNum)
		printf(" %llu", oneNumBack);

	//Starts with 3 because 1 and 2 are done already
	for (i = 3;i <= num;i++) {
		currentNum = twoNumBack + oneNumBack;
		printf(" %llu", currentNum);
		twoNumBack = oneNumBack;
		oneNumBack = currentNum;
	}
	printf("\n\n");
	return 0;
}

int thirdQuest() {
	//The function scans an integer and prints the sum of all the prime numbers which are smaller or equal to the number
	
	const int minValueOfNum = 2;
	int i = 0, num = scanDouble();
	unsigned long long int sumPrime = 0;
	//printf("\nEnter a number: ");
	//scanf("%d", &num);

	if (num < minValueOfNum) {
		printError(minValueOfNum - 1);
		return 0;
	}

	//Loop sums the prime numbers smaller or equal to scanned num
	for (i = minValueOfNum;i <= num;i++) {
		if (isPrime(i))
			sumPrime += i;
	}
	printf("%llu\n\n", sumPrime);
	return 0;
}

int fourthQuest() {
	//The function scans an integer and prints if it is perfect or not.

	const int minValueOfNum = 1;
	int i = 0, num = scanDouble(), sumOfDevisors = 0;

	//printf("\nEnter a number: ");
	//scanf("%d", &num);	

	//Perfect numbers are positive integers
	if (num < minValueOfNum) {
		printError(minValueOfNum - 1);
		return 0;
	}

	//Runs until num/2 because a positive number cannot be divided by a number bigger than his half
	for (i = 1;i <= num / 2;i++) {
		if (num % i == 0)
			sumOfDevisors += i;
	}
	if (sumOfDevisors == num) { //Perferct
		printf("Perfect!\n\n");
		return 0;
	}
	//Not perfect
	printf("Not Perfect!\n\n");
	return 0;
}

int fifthQuest(){
	printf("Congratulations! You finished the quest and managed to defeat Thanos\n");
	return 1;
}

int isPrime(int num) {
	//The funtion gets an integer and returns 1 if it's prime and 0 if it isn't
	if (num <= 1)
		return 0;
	if (num == 2)
		return 1;
	int i;
	for (i = 2; i <= pow(num, 0.5);i++) {
		if (num % i == 0)
			return 0;
	}
	return 1;
}

void printError(int minNumberRequired) {
	//The function prints the reason why the scanned integer is invalid
	printf("Foolish mortal!");
	printf(" You cannot solve Thanos's quest with an input that isn't a number bigger than %d\n\n", minNumberRequired);
}		

int scanDouble() {
	//The function Scans a number and returns it (if its an integer) and if its a double it returns -1
	double num = 0, remainder = 0;
	printf("Enter a number: ");
	scanf("%lf", &num);
	remainder = num - (int)num;

	if (remainder != 0.0) //If the input wasn't an integer. Output format for this kind of input was not given
		return -1;
	return (int)num;
}