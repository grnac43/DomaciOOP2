#ifndef _multimedija_h_
#define _multimedija_h_

#include <iostream>
#include <string>

class Multimedija {
	std::string ime;
public:
	Multimedija(std::string i):ime(i){}
	virtual ~Multimedija(){}
	virtual long getVelicina() const = 0;
	virtual void getOpis(std::ostream& os) const = 0;
protected:
	virtual void pisi(std::ostream& os) const
	{
		os << ime << ':'; getOpis(os);
	}
	friend std::ostream& operator<<(std::ostream& os, const Multimedija& m)
	{
		m.pisi(os);
		return os;
	}
};

#endif // !_multimedija_h_
