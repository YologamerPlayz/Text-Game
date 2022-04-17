#include <iostream>
#include <iomanip>
#include <cctype>
#include <string>
#include <vector>

#include "entities.h"

#ifdef __unix__

#define CLEAR system("clear")

#elif defined(_WIN32) || defined(WIN32)

#define CLEAR system("cls")

#endif

int main()
{
	CLEAR;

	std::cout << std::setprecision(2) << std::fixed;

	std::string language, name;
	std::vector<char> forbiddenChars = {
		'*', '/', '+', '.', ',', '<', '>', '\"', '\\', '\'',
		';', ':', '{', '}', '[', ']', '(', ')', '=', '&', '^',
		'%', '$', '#', '@', '!', '~', '`', '|', '\?'};
	int mchoice;
	char cchoice;
	bool isRunning = true;

	do
	{
		std::cout << "Pick a language before the game starts:\t"
				  << "\n1. English"
				  << "\n2. Greek"
				  << "\n3. Dutch"
				  << "\n>>>\t";
		std::cin >> mchoice;

		CLEAR;

		switch (mchoice)
		{
		case 1:
			language = "en";
			break;
		case 2:
			language = "gr";
			break;
		case 3:
			language = "nl";
			break;
		default:
			std::cout << "Invalid input, try again.\n";
			break;
		}
	} while (mchoice < 1 || mchoice > 2);

	do
	{
		std::cout << "Choose a name:\n"
				  << "1. Danny\n"
				  << "2. Nick\n"
				  << "3. Fabian\n"
				  << "4. Renate\n"
				  << "5. Bill\n"
				  << "0. Custom\n";
		std::cin >> mchoice;

		switch (mchoice)
		{
		case 1:
			name = "Danny";
			break;
		case 2:
			name = "Nick";
			break;
		case 3:
			name = "Fabian";
			break;
		case 4:
			name = "Renate";
			break;
		case 5:
			name = "Bill";
			break;
		case 0:
			std::cin.ignore(256, '\n');
			std::cout << "1) Spaces Entered will be ignored\n"
					  << "2) The following characters:\t";
			for (auto p : forbiddenChars)
			{
				std::cout << p;
			}
		nloop:
			std::cout << "\n";
			std::cout << "Enter a character name:\n>>>\t";
			getline(std::cin, name);
			for (auto c : forbiddenChars)
			{
				for (int i = 0; i < name.size(); i++)
				{
					if (name[i] == c)
					{
						CLEAR;
						goto nloop;
					}
				}
			}
			break;
		default:
			std::cout << "Invalid input, try again.\n";
			break;
		}

		CLEAR;

		std::cout << "Are you sure about this?\n[y/n]>>>\t";
		std::cin >> cchoice;
		cchoice = tolower(cchoice);
		CLEAR;
	} while (cchoice != 'y');

	pChar playerCharacter(name);

	/*while (isRunning)
	{
	}*/

	return 0;
}