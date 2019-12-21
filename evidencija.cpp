#include "evidencija.h"

Evidencija & Evidencija::operator+=(const Korisnik & k)
{
	bool postoji = false;
	for (int i = 0; i < korisnici.getDuz(); i++)
	{
		if (korisnici[i] == k) postoji = true;
	}
	if (postoji) throw G_Postoji();
	korisnici += k;
	return *this;
}

Korisnik & Evidencija::operator[](std::string ime)
{
	int ind;
	bool nasao = false;
	for(int i=0;i<korisnici.getDuz();i++)
		if (korisnici[i].getIme() == ime)
		{
			ind = i;
			nasao = true;
		}
	if (!nasao) throw G_NPostoji(ime);
	return korisnici[ind];
}

const Korisnik & Evidencija::operator[](std::string ime) const
{
	return const_cast<Evidencija&>(*this)[ime];
}

void Evidencija::operator()(std::string ime)
{
	int ind;
	bool nasao = false;
	for (int i = 0;i<korisnici.getDuz();i++)
		if (korisnici[i].getIme() == ime)
		{
			ind = i;
			nasao = true;
		}
	if (!nasao) throw G_NPostoji(ime);
	korisnici(ind);
}

void Evidencija::promeniLoz(const std::string Ime,const std::string lo,const std::string ln)
{
	int ind;
	bool nasao = false;
	for (int i = 0;i<korisnici.getDuz();i++)
		if (korisnici[i].getIme() == Ime)
		{
			ind = i;
			nasao = true;
		}
	if (!nasao) throw G_NPostoji(Ime);

	korisnici[ind].promeniLoz(lo, ln);
}
