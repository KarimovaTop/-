#include <iostream>

#define ERROR 0

using namespace std;

void CaesarCipher(int shift, char* line)
{
	for (int i = 0; i < strlen(line); i++)
	cout << (char)(line[i] + shift);
	cout << endl;
}

int CheckErrors(char input[])
{
	int i = 0;
	string error = "ERROR || Введите корректное значение.\n";
	char numberStr[12];

	if (input[0] == '-')
	{
		numberStr[0] = '-';
		i++;
	}

	for (; input[i] != '\0'; i++)
	{
		if (!(input[i] >= 48 && input[i] <= 57) || (input[i] == 48 && i == 0))
		{
			cout << error;
			return ERROR;
		}
		else if (i != 11)
			numberStr[i] = input[i];
		else
		{
			cout << error;
			return 0;
		}
	}
	numberStr[i] = '\0';

	if (atoll(input) < INT_MIN || atoll(input) > INT_MAX)
	{
		cout << error;
		return 0;
	}

	return atoi(input);
}

int main()
{
	setlocale(LC_ALL, "rus");

	int correctShift;
	char line[1000];
	char shift[1000];

	while (true) {
		cout << "Введите строку для шифрования: ";
		cin >> line;
		while (true)
		{
			cout << "Введите шаг сдвига: ";
			cin >> shift;

			if ((correctShift = CheckErrors(shift)) != 0)
			{
				CaesarCipher(correctShift, line);
				break;
			}
		}
	}

	return 0;
}
