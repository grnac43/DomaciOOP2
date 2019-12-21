#ifndef _evidencija_h_
#define _evidencija_h_

#include "lista2.h"
#include "korisnik.h"

class G_Postoji{};
inline std::ostream& operator<<(std::ostream& os, const G_Postoji&)
{
	return os << "\n*** GRESKA: Korisnik vec postoji! ***\n";
}
class G_NPostoji 
{ 
	std::string ime; 
public: 
	G_NPostoji(std::string i) :ime(i) {}
	friend std::ostream& operator<<(std::ostream& os, const G_NPostoji& g)
	{
		return os << "\n*** GRESKA: Korisnik sa imenom '" << g.ime << "' ne postoji! ***\n";
	}
};


class Evidencija {
	Lista<Korisnik> korisnici;

public:
	Evidencija(){}
	Evidencija(const Evidencija&) = delete;
	Evidencija& operator=(const Evidencija&) = delete;

	Evidencija& operator+=(const Korisnik& k);

	Korisnik& operator[](std::string ime);
	const Korisnik& operator[](std::string ime) const;
	void operator()(std::string ime);
	void promeniLoz(std::string Ime, std::string lo, std::string ln);
};
#endif // !_evidencija_h_
