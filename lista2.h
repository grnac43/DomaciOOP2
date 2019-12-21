#ifndef _lista2_h_
#define _lista2_h_

#include <iostream>

class G_Indeks 
{ 
	int i; 
public: 
	G_Indeks(int i) { this->i = i; } 
	friend std::ostream& operator<<(std::ostream& os, const G_Indeks& g)
	{
		return os << "\n*** GRESKA: Element indeksa " << g.i << " ne postoji! ***\n";
	}
};


template<typename T>
class Lista {
	struct Elem {
		T pod;
		Elem* next;
		Elem(T p)
		{
			pod = p;
			next = nullptr;
		}
	};
	Elem *prvi, *posl;
	
	void kopiraj(const Lista& l);
	void premesti(Lista& l)
	{
		prvi = l.prvi;
		posl = l.posl;
		l.prvi = l.posl = nullptr;
	}
	void brisi();

public:
	Lista() { prvi = posl = nullptr;  }
	Lista(const Lista& l) { kopiraj(l); }
	Lista(Lista&& l) { premesti(l); }
	~Lista() { brisi(); }


	Lista& operator=(const Lista& l)
	{
		if (this != &l)
		{
			brisi();
			kopiraj(l);
		}
		return *this;
	}
	Lista& operator=(Lista&& l)
	{
		if (this != &l)
		{
			brisi();
			premesti(l);
		}
		return *this;
	}

	Lista& operator+=(const T& t)
	{
		posl = (!prvi ? prvi : posl->next) = new Elem(t);
		
		return *this;
	}

	int getDuz() const;

	T& operator[](int i);
	const T& operator[](int i) const;

	void operator()(int i);
};

#endif // !_lista2_h_

template<typename T>
inline void Lista<T>::kopiraj(const Lista & l)
{
	prvi = posl = nullptr;
	for (Elem* tek = l.prvi; tek;tek = tek->next)
		*this += tek->pod;
}

template<typename T>
inline void Lista<T>::brisi()
{
	while (prvi)
	{
		Elem* stari = prvi;
		prvi = prvi->next;
		delete stari;
	}
	prvi = posl = nullptr;
	
}

template<typename T>
inline int Lista<T>::getDuz() const
{
	int i = 0;
	for (Elem* tek = prvi;tek;tek = tek->next) i++;
	return i;
}

template<typename T>
inline T & Lista<T>::operator[](int i)
{
	if (i >= getDuz()) throw G_Indeks(i);
	Elem* tek = prvi;
	for (int j = 0;j < i;j++) tek = tek->next;

	return tek->pod;

}

template<typename T>
inline const T & Lista<T>::operator[](int i) const
{
	return const_cast<Lista&>(*this)[i];
}

template<typename T>
inline void Lista<T>::operator()(int i)
{
	if (i >= getDuz()) throw G_Indeks(i);
	Elem* pret = nullptr;
	Elem* tek = prvi;
	for (int j = 0;j < i;j++)
	{
		pret = tek;
		tek = tek->next;
	}

	Elem* stari = tek;
	tek = tek->next;
	stari->next = nullptr;
	pret->next = tek;
	delete stari;
}
