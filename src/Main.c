#include <stdio.h>
#include <io.h>
#include <fcntl.h>
#define maximumWordLength 17

main()
{
	_setmode(_fileno(stdout), _O_U16TEXT);
    _setmode(_fileno(stdin),  _O_U16TEXT);
    _setmode(_fileno(stderr), _O_U16TEXT);

	int c, tempLength = 0;
	int wordLength[maximumWordLength] = { 0 };
	int isWord = 0;
	while ((c = getwchar()) != WEOF) {
		if (c != L' ' & c != L'\t' & c != L'\n') {
			tempLength++;
			isWord = 1;
		}
		else if (tempLength < maximumWordLength && isWord) {
			wordLength[tempLength]++;
			tempLength = 0;
			isWord = 0;
		}
		else {
			tempLength = 0;
			isWord = 0;
		}
	}
	for (int i = 1; i < maximumWordLength; i++) {
		wprintf(L"%d - ", i);
		while (wordLength[i] > 0) {
			wprintf(L"*");
			wordLength[i]--;
		}
		wprintf(L"\n");
	}
}