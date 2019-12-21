#include "korisnik.h"

bool Korisnik::provera(const std::string loz) const
{
	bool slovo=false, broj=false;
	int k=0;
	for (int i = 0;i < (int)loz.length();i++)
	{
		if (isdigit(loz[i])) broj = true;
		if (isalpha(loz[i])) slovo = true;
		k++;
	}
	return k >= 8 && slovo && broj;
}

void Korisnik::promeniLoz(const std::string lo, const std::string ln)
{
	if (lo != lozinka) throw G_NLoz();

	lozinka = ln;
}

bool operator==(const Korisnik & k1, const Korisnik & k2)
{
	return k1.ime==k2.ime;
}

std::ostream & operator<<(std::ostream & os, const Korisnik & k)
{
	return os << k.ime;
}
