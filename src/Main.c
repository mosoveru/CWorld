#include <stdio.h>
#include <io.h>
#include <fcntl.h>
#define EnglishAlphabetLength 26

void printLowercaseEnglishLettersHistogram(int letters[]);
void printUppercaseEnglishLettersHistogram(int letters[]);

main()
{
	_setmode(_fileno(stdout), _O_U16TEXT);
    _setmode(_fileno(stdin),  _O_U16TEXT);
    _setmode(_fileno(stderr), _O_U16TEXT);

	int numberOfLowercaseEnglishLetters[EnglishAlphabetLength] = { 0 }, c;
	int numberOfUppercaseEnglishLetters[EnglishAlphabetLength] = { 0 };
	while ((c = getwchar()) != WEOF) {
		if (c >= L'a' & c <= L'z') {
			numberOfLowercaseEnglishLetters[c - L'a']++;
		}
		if (c >= L'A' & c <= L'Z') {
			numberOfUppercaseEnglishLetters[c - L'A']++;
		}
	}
	printLowercaseEnglishLettersHistogram(numberOfLowercaseEnglishLetters);
	printUppercaseEnglishLettersHistogram(numberOfUppercaseEnglishLetters);
	return 0;
}

void printLowercaseEnglishLettersHistogram(int letters[]) {
	for (int i = 0; i < EnglishAlphabetLength; i++) {
		wprintf(L"%c - ", L'a' + i);
		while (letters[i] > 0) {
			wprintf(L"0");
			letters[i]--;
		}
		wprintf(L"\n");
	}
}

void printUppercaseEnglishLettersHistogram(int letters[]) {
	for (int i = 0; i < EnglishAlphabetLength; i++) {
		wprintf(L"%c - ", L'A' + i);
		while (letters[i] > 0) {
			wprintf(L"0");
			letters[i]--;
		}
		wprintf(L"\n");
	}
}