#include <iostream>
#include <string>
#include "korisnik.h"
//#include "lista2.h"
#include "slika.h"
#include "multimedija.h"
#include "evidencija.h"


int main()
{
	try {
		std::string ime = "Dusan";
		
		Korisnik k1(ime, "dusan2911999");
		std::cout << k1;
		std::cout << std::endl;
		/*Lista<int> lista;
		lista += 1;
		lista += 5;
		lista += 2;
		lista += 3;
		std::cout << std::endl;
		for (int i = 0;i < lista.getDuz();i++)
			std::cout << lista[i]<<' ';
		//std::cout << lista[5];
		std::cout << std::endl;*/
		Slika s1(10, 10, 5);

		std::cout << s1;
		//std::cout << s1.getOpis();
		std::cout << std::endl;
		Evidencija e;
		e += k1;
		e["Dusan"].promeniLoz("dusan2911999", "fifa740014");
		std::cout << e["Dusan"];
		std::cout << std::endl;
		std::cout << e["Goran"];
	}
	catch (G_Loz g) { std::cout << g; }
	catch (G_Indeks g) { std::cout << g; }
	catch(G_NPostoji g){ std::cout << g; }
	catch(G_Postoji g){ std::cout << g; }
	system("pause");
	return 0;
}