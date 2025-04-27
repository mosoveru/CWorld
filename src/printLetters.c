#include <stdio.h>
#include <io.h>
#include <fcntl.h>
#include "printLetters.h"
#define EnglishAlphabetLength 26

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