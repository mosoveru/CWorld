#include <stdio.h>
#include <io.h>
#include <fcntl.h>

main()
{
	_setmode(_fileno(stdout), _O_U16TEXT);
    _setmode(_fileno(stdin),  _O_U16TEXT);
    _setmode(_fileno(stderr), _O_U16TEXT);

	int c, i, nwhite, nother;
	int ndigit[10];
	nwhite = nother = 0;
	for (i = 0; i < 10; ++i)
		ndigit[i] = 0;
	while ((c = getwchar()) != WEOF)
		if (c >= L'0' && c <= L'9')
			++ndigit[c - L'0'];
		else if (c == L' ' || c == L'\n' || c == L'\t')
			++nwhite;
		else
			++nother;
	wprintf(L"Цифры =");
	for (i = 0; i < 10; ++i)
		wprintf(L" %d", ndigit[i]);
	wprintf(L", символы-разделители = %d, прочие = %d\n", nwhite, nother);
}