#ifndef _korisnik_h_
#define _korisnik_h_

#include <iostream>
#include <string>

class G_Loz{};
inline std::ostream& operator<<(std::ostream& os, const G_Loz&)
{
	return os << "\n*** GRESKA: Lozinka nije u odgovarajucem formatu! ***\n";
}
class G_NLoz{};
inline std::ostream& operator<<(std::ostream& os, const G_NLoz&)
{
	return os << "\n *** GRESKA: Pogresna stara lozinka! ***\n";
}
class Korisnik {
	std::string ime, lozinka;
	bool provera(const std::string loz) const;
public:
	Korisnik(std::string i="Ime", std::string l="Lozinka1") { if (!provera(l)) throw G_Loz();  ime = i; lozinka = l; }

	std::string getIme() const { return ime; }

	void promeniLoz(const std::string lo,const std::string ln);

	friend bool operator==(const Korisnik& k1, const Korisnik& k2);

	friend std::ostream& operator<<(std::ostream& os, const Korisnik& k);
};


#endif // !_korisnik_h-
