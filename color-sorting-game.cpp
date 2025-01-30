#include <iostream>
#include <ctime>
#include <stack>
#define MAX_SIZE 15
#define STACK_SIZE 5
using namespace std;
void displayInstructions()
{
	cout << "\t\t\t\t\t --------------------------------------------------------" <<
		endl;
	cout << "\t\t\t\t\t| Welcome to the Color Sorting Game |"
		<< endl;
	cout << "\t\t\t\t\t| |" << endl;
		cout << "\t\t\t\t\t --------------------------------------------------------" <<
		endl;
	cout << endl << endl << endl;
	cout << "\t\t\t*INSTRUCTIONS*" << endl;
	cout << endl;
	cout << "1) ---> You will see a list of colored elements (R, G, B)." << endl;
	cout << "2) ---> Your goal is to sort these elements into their respective color stacks." << endl;
		cout << "3) ---> The elements are represented in the list with (R, G, B)." << endl;
		cout << "4) ---> Enter the color letter to sort from the list into its corresponding stack." << endl;
		cout << "5) ---> For example, if 'R' is at the top, enter 'R' to sort it into the Red stack." << endl;
		cout << "6) ---> Keep sorting until all elements are in their correct stacks to win." << endl << endl;
		cout << "7) ---> In Level 2 (for >=30 points) and 3 (for >=55 points) a special power is unlocked known as PowerStack." << endl << endl;
		
		cout << "8) ---> It is an extra stack to store your color but to use it in level 2 your 15 point will be deducted and in level 3, 20 points." << endl
		<< endl;
	cout << "9) ---> Also in level 1 & 2 you have limited moves (16) so be carefull." << endl << endl;
		cout << endl;
	cout << "\t\t\t\t\t ------- GIVE IT A TRY; BEST OF LUCK :) --------"
		<< endl << endl << endl;
}
void displayList(const char elements[], int size, int topIndex)
{
	cout << "List of Elements to Sort: ";
	for (int i = 0; i < size; ++i)
	{
		if (i == topIndex)
		{
			cout << "(" << elements[i] << ") ";
			
		}
		else
		{
			cout << elements[i] << " ";
		}
	}
	cout << endl;
}
void displayStack(const char stack[], int top, const char* stackName)
{
	cout << stackName << " Stack: ";
	if (top == -1)
	{
		cout << "Empty";
	}
	else
		
	{
		for (int i = top; i >= 0; --i)
		{
			cout << stack[i] << " ";
		}
	}
	cout << endl;
}
char getColorToSort(const char elements[], int topIndex)
{
	return elements[topIndex];
}
bool isGameWon(const char redStack[], const char greenStack[], const
	char blueStack[], int chosenLevel)
{
	bool isRedSorted = true;
	
		bool isGreenSorted = true;
	bool isBlueSorted = true;
	// Check if the Red stack is sorted
	for (int i = 0; i < STACK_SIZE - 1; ++i)
	{
		if (redStack[i] != 'R' || redStack[i] > redStack[i + 1])
		{
			isRedSorted = false;
			break;
		}
	}
	// Check if the Green stack is sorted
	for (int i = 0; i < STACK_SIZE - 1; ++i)
	{
		if (greenStack[i] != 'G' || greenStack[i] > greenStack[i + 1])
			
		{
			isGreenSorted = false;
			break;
		}
	}
	// Check if the Blue stack is sorted
	for (int i = 0; i < STACK_SIZE - 1; ++i)
	{
		if (blueStack[i] != 'B' || blueStack[i] > blueStack[i + 1])
		{
			isBlueSorted = false;
			break;
		}
	}
	// Game is won if all three stacks are sorted
	
		if (chosenLevel == 2)
		{
			return isRedSorted && isGreenSorted && isBlueSorted;
		}
		else
		{
			return isRedSorted || isGreenSorted || isBlueSorted;
		}
}
bool isGameWon(const char Stack1[], const char Stack2[], const char
	Stack3[], const char Stack4[])
{
	bool isStack1Sorted = true;
	bool isStack2Sorted = true;
	bool isStack3Sorted = true;
	bool isStack4Sorted = true;
	
		// Check if Stack1 is sorted
		for (int i = 0; i < STACK_SIZE - 1; ++i)
		{
			if (Stack1[i] != ' ' && (Stack1[i] != Stack1[i + 1]))
			{
				isStack1Sorted = false;
				break;
			}
		}
	// Check if Stack2 is sorted
	for (int i = 0; i < STACK_SIZE - 1; ++i)
	{
		if (Stack2[i] != ' ' && (Stack2[i] != Stack2[i + 1]))
		{
			isStack2Sorted = false;
			break;
			
		}
	}
	// Check if Stack3 is sorted
	for (int i = 0; i < STACK_SIZE - 1; ++i)
	{
		if (Stack3[i] != ' ' && (Stack3[i] != Stack3[i + 1]))
		{
			isStack3Sorted = false;
			break;
		}
	}
	// Check if Stack4 is sorted
	for (int i = 0; i < STACK_SIZE - 1; ++i)
	{
		if (Stack4[i] != ' ' && (Stack4[i] != Stack4[i + 1]))
			
		{
			isStack4Sorted = false;
			break;
		}
	}
	// Game is won if all stacks are sorted
	return isStack1Sorted && isStack2Sorted && isStack3Sorted &&
		isStack4Sorted;
}
unsigned int generateRandomSeed()
{
	return static_cast<unsigned int>(time(nullptr));
}
int myRandom(unsigned int& seed, int min, int max)

{
	seed = seed * 1103515245 + 12345;
	return static_cast<int>((seed / 65536) % (max - min + 1)) + min;
}
void initializeElements(char elements[], unsigned int& seed, int
	chosenLevel)
{
	if (chosenLevel == 1)
	{
		for (int i = 0; i < MAX_SIZE; i++)
		{
			elements[i] = (i % 3 == 0) ? 'R' : ((i % 3 == 1) ? 'G' : 'B');
		}
	}
	else if (chosenLevel == 2)
	{
		
			for (int i = 0; i < MAX_SIZE; i++)
			{
				elements[i] = myRandom(seed, 0, 2) == 0 ? 'R' :
					(myRandom(seed, 0, 1) == 1 ? 'G' : 'B');
			}
	}
	else // Level 3 with 4 colors (R, G, B, Y) and 4 stacks (Stack1, Stack2, Stack3, Stack4)
		{
			for (int i = 0; i < MAX_SIZE; i++)
			{
				int randomColor = myRandom(seed, 0, 3);
				if (randomColor == 0)
				{
					elements[i] = 'R';
				}
				else if (randomColor == 1)
				{
					
						elements[i] = 'G';
				}
				else if (randomColor == 2)
				{
					elements[i] = 'B';
				}
				else
				{
					elements[i] = 'Y';
				}
			}
 }
}
void handleFullStack(char colorToSort, char powerStack[], int&
	powerTop, int& score, int chosenLevel)
{
	if (chosenLevel == 2)
	{
		
			cout << "\t\t\t\t\t" << colorToSort << " Stack Full! Using Power Stack." << endl;
			if (powerTop < STACK_SIZE - 1)
			{
				powerStack[++powerTop] = colorToSort;
				score = score - 15; // Deduct 15 points for using the power stack
			}
			else
			{
				cout << "\t\t\t\t\tPower Stack Full! Cannot use it now." << endl;
			}
	}
	else if (chosenLevel == 3)
	{
		cout << "\t\t\t\t\t" << colorToSort << " Stack Full! Using Power Stack." << endl;
			if (powerTop < STACK_SIZE - 1)
			{
				
					powerStack[++powerTop] = colorToSort;
				score = score - 20; // Deduct 20 points for using the power stack
			}
			else
			{
				cout << "\t\t\t\t\tPower Stack Full! Cannot use it now." << endl;
			}
	}
}
int main()
{
	int moves = 0; // Initialize move counter
	unsigned int seed = generateRandomSeed();
	char elements[MAX_SIZE];
	int topIndex = 0; // Top index of the element to sort
	
		int opt = 1;
	char redStack[STACK_SIZE], greenStack[STACK_SIZE],
		blueStack[STACK_SIZE], powerStack[MAX_SIZE];
	int redTop = -1, greenTop = -1, blueTop = -1, powerTop = -1;
	char Stack1[STACK_SIZE], Stack2[STACK_SIZE],
		Stack3[STACK_SIZE], Stack4[STACK_SIZE];
	int stack1Top = -1, stack2Top = -1, stack3Top = -1, stack4Top = -1;
	int score = 0;
	int chosenLevel;
	while (opt != 0)
	{
		displayInstructions();
		cout << "Choose the type of level to play:" << endl;
		cout << "1. Easy" << endl;
		cout << "2. Medium" << endl;
		
			cout << "3. Difficult" << endl;
		cout << "Enter your choice (1/2/3): ";
		cin >> chosenLevel;
		cout << endl;
		if (chosenLevel != 1 && chosenLevel != 2 && chosenLevel != 3)
		{
			cout << "\t\t\t-- INVALID CHOICE!!! Exiting the game... --" <<
				endl;
			cout << "\t\t\t\t -------------------------------------" << endl;
			cout << "\t\t\t\t| Total Points: " << score << " | " <<
				endl;
			cout << "\t\t\t\t -------------------------------------" << endl;
			return 1;
		}
		initializeElements(elements, seed, chosenLevel);
		
			char userChoice;
		while (topIndex < MAX_SIZE)
		{
			char colorToSort = getColorToSort(elements, topIndex);
			cout << "Sort the '" << colorToSort << "' from the list." << endl <<
				endl;
			displayList(elements, MAX_SIZE, topIndex);
			if (chosenLevel == 3)
			{
				cout << "Stack Options: " << endl;
				displayStack(Stack1, stack1Top, "Stack 1");
				displayStack(Stack2, stack2Top, "Stack 2");
				displayStack(Stack3, stack3Top, "Stack 3");
				displayStack(Stack4, stack4Top, "Stack 4");
				displayStack(powerStack, powerTop, "Power");
			}
			else
			{
				displayStack(redStack, redTop, "Red");
				displayStack(greenStack, greenTop, "Green");
				displayStack(blueStack, blueTop, "Blue");
				displayStack(powerStack, powerTop, "Power");
			}
			cout << endl;
			if (chosenLevel == 1 || chosenLevel == 2)
			{
				
					cout << "Enter your choice (R/G/B/P for Power) or 'Q' to quit: ";
				cin >> userChoice;
				if (userChoice == 'Q' || userChoice == 'q')
				{
					cout << "Exiting the game." << endl;
					cout << "\t\t\t\t -------------------------------------" << endl;
					cout << "\t\t\t\t| Total Points: " << score << " | "
						<< endl;
					cout << "\t\t\t\t -------------------------------------" << endl;
					break;
				}
				if (userChoice == 'R' || userChoice == 'G' || userChoice == 'B')
				{
					if (userChoice == colorToSort)
					{
						if (userChoice == 'R' && redTop < STACK_SIZE - 1)
						{
							
								redStack[++redTop] = 'R';
						}
						else if (userChoice == 'G' && greenTop < STACK_SIZE -
							1)
						{
							greenStack[++greenTop] = 'G';
						}
						else if (userChoice == 'B' && blueTop < STACK_SIZE - 1)
						{
							blueStack[++blueTop] = 'B';
						}
						else if (powerTop < STACK_SIZE - 1)
						{
							handleFullStack(userChoice, powerStack, powerTop,
								score, chosenLevel);
						}
						else
						{
							
								handleFullStack(userChoice, powerStack, powerTop,
									score, chosenLevel);
						}
						elements[topIndex++] = ' '; // Replace the sorted element with a placeholder
							score += 5; // Increment score for correct sorting
					}
					else
					{
						cout << endl;
						cout << "\t\t\t\t\tINVALID CHOICE!!!" << endl;
					}
				}
				else if (userChoice == 'P' || userChoice == 'p')
				{
					if (score >= 30 && powerTop < STACK_SIZE - 1)
						
					{
						powerStack[++powerTop] = colorToSort; // Allow putting the same color into the power stack
							score -= 15; // Deduct 15 points for using the power stack
						cout << "You used power stack special power." << endl;
					}
					else if (powerTop == STACK_SIZE - 1)
					{
						cout << "\t\t\t\t\tPower Stack Full! Cannot use it now." <<
							endl;
					}
					else
					{
						cout << "\t\t\t\t\tInsufficient points to use Power Stack." <<
							endl;
					}
				}
				else
					
				{
					cout << endl;
					cout << "\t\t\t\t\tINVALID CHOICE!!!" << endl;
				}
				moves++; // Increment move counter
				if (moves > MAX_SIZE + 1) {
					cout << "Out of moves! You've exceeded the maximum moves allowed." << endl;
						cout << "Game Over!" << endl;
					cout << "\t\t\t\t -------------------------------------" << endl;
					cout << "\t\t\t\t| Total Points: " << score << " | "
						<< endl;
					cout << "\t\t\t\t -------------------------------------" << endl;
					break;
				}
			}
			if (chosenLevel == 3)
				
			{
				int stackChoice;
				cout << "Enter stack choice (1/2/3/4) or '5' to quit and to use special power enter '6': ";
					cin >> stackChoice;
				if (stackChoice == 5)
				{
					cout << "Game Over!" << endl;
					cout << "\t\t\t\t -------------------------------------" << endl;
					cout << "\t\t\t\t| Total Points: " << score << " | "
						<< endl;
					cout << "\t\t\t\t -------------------------------------" << endl;
					break;
				}
				if (stackChoice >= 1 && stackChoice <= 4)
				{
					
						char userChoice = getColorToSort(elements, topIndex);
					switch (stackChoice)
					{
					case 1:
						if (userChoice == 'R' && stack1Top < STACK_SIZE - 1)
						{
							Stack1[++stack1Top] = 'R';
						}
						else if (userChoice == 'G' && stack1Top < STACK_SIZE -
							1)
						{
							Stack1[++stack1Top] = 'G';
						}
						else if (userChoice == 'B' && stack1Top < STACK_SIZE -
							1)
						{
							Stack1[++stack1Top] = 'B';
							
						}
						else if (userChoice == 'Y' && stack1Top < STACK_SIZE -
							1)
						{
							Stack1[++stack1Top] = 'Y';
						}
						else
						{
							handleFullStack(userChoice, powerStack, powerTop,
								score, chosenLevel);
						}
						break;
					case 2:
						if (userChoice == 'R' && stack2Top < STACK_SIZE - 1)
						{
							Stack2[++stack2Top] = 'R';
						}
						
						else if (userChoice == 'G' && stack2Top < STACK_SIZE -
							1)
						{
							Stack2[++stack2Top] = 'G';
						}
						else if (userChoice == 'B' && stack2Top < STACK_SIZE -
							1)
						{
							Stack2[++stack2Top] = 'B';
						}
						else if (userChoice == 'Y' && stack2Top < STACK_SIZE -
							1)
						{
							Stack2[++stack2Top] = 'Y';
						}
						else
						{
							
								handleFullStack(userChoice, powerStack, powerTop,
									score, chosenLevel);
						}
						break;
					case 3:
						if (userChoice == 'R' && stack3Top < STACK_SIZE - 1)
						{
							Stack3[++stack3Top] = 'R';
						}
						else if (userChoice == 'G' && stack3Top < STACK_SIZE -
							1)
						{
							Stack3[++stack3Top] = 'G';
						}
						else if (userChoice == 'B' && stack3Top < STACK_SIZE -
							1)
						{
							Stack3[++stack3Top] = 'B';
							
						}
						else if (userChoice == 'Y' && stack3Top < STACK_SIZE -
							1)
						{
							Stack3[++stack3Top] = 'Y';
						}
						else
						{
							handleFullStack(userChoice, powerStack, powerTop,
								score, chosenLevel);
						}
						break;
					case 4:
						if (userChoice == 'R' && stack4Top < STACK_SIZE - 1)
						{
							Stack4[++stack4Top] = 'R';
						}
						
						else if (userChoice == 'G' && stack4Top < STACK_SIZE -
							1)
						{
							Stack4[++stack4Top] = 'G';
						}
						else if (userChoice == 'B' && stack4Top < STACK_SIZE -
							1)
						{
							Stack4[++stack4Top] = 'B';
						}
						else if (userChoice == 'Y' && stack4Top < STACK_SIZE -
							1)
						{
							Stack4[++stack4Top] = 'Y';
						}
						else
						{
							
								handleFullStack(userChoice, powerStack, powerTop,
									score, chosenLevel);
						}
						break;
					default:
						cout << "Invalid choice or stack is full!" << endl;
						continue; // Continue loop without incrementing topIndex
					}
					elements[topIndex++] = ' '; // Mark the element as sorted
					score += 5; // Increment score for correct sorting
				}
				else if (stackChoice == 6)
				{
					if (score >= 55 && powerTop < STACK_SIZE - 1)
					{
						
							powerStack[++powerTop] = colorToSort; // Allow putting the same color into the power stack
							score -= 20; // Deduct 20 points for using the power stack
					}
					else if (powerTop == STACK_SIZE - 1)
					{
						cout << "\t\t\t\t\tPower Stack Full! Cannot use it now." <<
							endl;
					}
					else
					{
						cout << "\t\t\t\t\tInsufficient points to use Power Stack." <<
							endl;
					}
				}
				else
				{
					cout << endl;
					
						cout << "\t\t\t\t\tINVALID CHOICE!!!" << endl;
				}
			}
			if (topIndex == MAX_SIZE)
			{
				if (chosenLevel == 1 || chosenLevel == 2)
				{
					if (isGameWon(redStack, greenStack, blueStack,
						chosenLevel))
					{
						// Display all sorted elements in the respective stack
						displayStack(redStack, redTop, "Red");
						displayStack(greenStack, greenTop, "Green");
						displayStack(blueStack, blueTop, "Blue");
						
							displayStack(powerStack, powerTop, "Power");
						cout << endl << endl;
						cout << "\t\tCONGRATULATIONS!!! All elements are sorted!" << endl << endl;
							cout << "\t\t\t\t -------------------------------------" << endl;
						cout << "\t\t\t\t| Total Points: " << score << " | "
							<< endl;
						cout << "\t\t\t\t -------------------------------------" << endl;
						break;
					}
				}
				else if (chosenLevel == 3)
				{
					if (isGameWon(Stack1, Stack2, Stack3, Stack4))
					{
						// Display sorted stacks and winning message for Level 3
						displayStack(Stack1, stack1Top, "Stack 1");
						
							displayStack(Stack2, stack2Top, "Stack 2");
						displayStack(Stack3, stack3Top, "Stack 3");
						displayStack(Stack4, stack4Top, "Stack 4");
						displayStack(powerStack, powerTop, "Power");
						cout << endl << endl;
						cout << "\t\tCONGRATULATIONS!!! All elements are sorted!" << endl << endl;
							cout << "\t\t\t\t -------------------------------------" << endl;
						cout << "\t\t\t\t| Total Points: " << score << " | "
							<< endl;
						cout << "\t\t\t\t -------------------------------------" << endl;
						break;
					}
				}
			}
		}
		
			if (chosenLevel == 1 || chosenLevel == 2)
			{
				if (topIndex == MAX_SIZE && !isGameWon(redStack,
					greenStack, blueStack, chosenLevel))
				{
					cout << "\n\n\t\t\tAll Sorted! " << endl;
					cout << "\t\t\t\t -------------------------------------" << endl;
					cout << "\t\t\t\t| YOUR FINAL SCORE: " << score <<
						" | " << endl;
					cout << "\t\t\t\t -------------------------------------" << endl;
				}
			}
			else if (chosenLevel == 3)
			{
				if (topIndex == MAX_SIZE && !isGameWon(Stack1, Stack2,
					Stack3, Stack4))
				{
					cout << "\n\n\t\t\tAll Sorted! " << endl;
					
						cout << "\t\t\t\t -------------------------------------" << endl;
					cout << "\t\t\t\t| YOUR FINAL SCORE: " << score <<
						" | " << endl;
					cout << "\t\t\t\t -------------------------------------" << endl;
				}
			}
		cout << "\nWould you like to continue with the game? If not enter 0:";
		cin >> opt;
	}
	cout << "\nThank you for playing :D";
	return 0;
}