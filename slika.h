#ifndef _slika_h_
#define _slika_h_

#include "multimedija.h"

class Slika : public Multimedija {
	int sir, vis, pixB;
public:
	Slika(int v, int s, int p) :Multimedija("Slika") { sir = s; vis = v; pixB = p; }

	long getVelicina() const override
	{
		return sir*vis*pixB;
	}
	void getOpis(std::ostream& os) const override
	{
		os << '[' << sir << 'x' << vis << "->" << getVelicina() << "B]";
	}
};
#endif // !_slika_h_
