#include <stdio.h>
#include <io.h>
#include <fcntl.h>
#define maximumWordLength 17

main()
{
	_setmode(_fileno(stdout), _O_U16TEXT);
    _setmode(_fileno(stdin),  _O_U16TEXT);
    _setmode(_fileno(stderr), _O_U16TEXT);

	int wordLength[maximumWordLength] = { 0 };
	int isWord = 0, maxNumberOfWordLength = 0, tempLength = 0, c;
	while ((c = getwchar()) != WEOF) {
		if (c != L' ' & c != L'\t' & c != L'\n') {
			tempLength++;
			isWord = 1;
		}
		else if (tempLength < maximumWordLength && isWord) {
			int currentLength = ++wordLength[tempLength];
			if (currentLength > maxNumberOfWordLength)
				maxNumberOfWordLength = currentLength;
			tempLength = 0;
			isWord = 0;
		}
		else {
			tempLength = 0;
			isWord = 0;
		}
	}
	for (int i = 1; i < maximumWordLength; i++) {
		wprintf(L"%4d", i);
	}
	wprintf(L"\n");
	while (maxNumberOfWordLength > 0) {
		for (int i = 1; i < maximumWordLength; i++) {
			if (wordLength[i] > 0) {
				wprintf(L"%4c", L'0');
				wordLength[i]--;
			}
			else {
				wprintf(L"%4c", L' ');
			}
		}
		maxNumberOfWordLength--;
		wprintf(L"\n");
	}
}