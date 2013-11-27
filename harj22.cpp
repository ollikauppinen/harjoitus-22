/**********************************************************
*Tehtävä: Harjoitus22
*Tekijä: Olli Kauppinen
*PVM: 19.11.2013
*Kuvaus:
Tee ohjelma, joka toimii henkilörekisterinä (max 10).
Ohjelma antaa käyttäjälle seuraavan valikon:

VALIKKO
0 Lopeta
1 Lisaa henkilo
2 Nayta kaikki hlo

Tallenna henkilöiden hlo tietuetaulukkoon.
Tallennettavia tietoja ovat
etunimi (merkkijono)
koulumatka (liukuluku)
hatun koko (kokonaisluku)

Toteuta ensin koko ohjelma pääohjelmana. 

Tämän jälkeen lisää seuraavat aliohjelmat:
a) int Valikko(void);

b) void TulostaHenkilo(TIEDOT );
c) void TulostaKaikkiTIEDOT(TIEDOT [], int lkm);
d) void LisaaHenkilo(TIEDOT [], int *lkm);
*
* Versio 1.0 H4718 19.11.2013
***********************************************************/

#include <iostream>
using namespace std;



struct TIEDOT
{
	char nimi[20];
	float kmatka;
	int hat;
};

const int MAX_TAULU = 10;

int Valikko(void);
void TulostaKaikkiTIEDOT(TIEDOT hlo[], int lkm);
void LisaaHenkilo(TIEDOT [], int *lkm);
void TulostaHenkilo(TIEDOT hlo[]);

int main()
{
	int valinta = 0;
	int lkm = 0;
	bool jatka = true;
	TIEDOT hlo[MAX_TAULU];
	

	do
	{
		cout << "\nHenkiloita rekisterissa " << lkm << " kpl" << endl;
		cout << "Max. 10 kpl." << endl;
		valinta = Valikko();
		cout << endl;

		switch (valinta)
		{
			case 0:
			{
				cout << "\nGood bye.\n";
				jatka = false;
				break;
			}

			case 1:
			{
				if (lkm < 10)
				{
				LisaaHenkilo(hlo, &lkm);
				}
//				cout << "\nEtunimi?\n";
//				cin >> hlo[lkm].nimi;
//				cout << "\nKoulumatka?\n";
//				cin >> hlo[lkm].kmatka;
//				cout << "\nHatun koko?\n";
//				cin >> hlo[lkm].hat;
				
				else
				{
				cout << "Taulukko taysi!" << endl;
				}
				break;
			}

			case 2:
			{
				TulostaHenkilo(hlo);
				break;
			}

			case 3:
			{

				TulostaKaikkiTIEDOT(hlo, lkm);
				//for (int ind = 0; (ind < lkm); ind++)
				//{
				//	cout << "Nimi: " << hlo[ind].nimi << ", koulumatka: " << hlo[ind].kmatka << " km, hatun koko: " << hlo[ind].hat << endl;
				//}

				break;
			}

			default:
			{
				cout << "\nVaara valinta\n";
				break;
			}

		}
	}

	while (jatka == true);

}

int Valikko(void)
{
	int valinta;

	cout << "\nVALIKKO\n\n0 Lopeta\n1 Lisaa henkilo\n2 Tulosta hlo\n3 Tulosta kaikki\n" << endl;
	cin >> valinta;

	return valinta;
}

void TulostaKaikkiTIEDOT(TIEDOT hlo[],int lkm)
{
	cout << "Listaus:" << endl;
	for (int ind = 0; (ind < lkm); ind++)
	{
		cout << "Nimi: " << hlo[ind].nimi << ", koulumatka: " << hlo[ind].kmatka << " km, hatun koko: " << hlo[ind].hat << endl;
	}
}

void LisaaHenkilo(TIEDOT p_hlo[], int *hlo_lkm)
{
	cout << "\nEtunimi?\n";
	cin >> p_hlo[*hlo_lkm].nimi;
	cout << "\nKoulumatka?\n";
	cin >> p_hlo[*hlo_lkm].kmatka;
	cout << "\nHatun koko?\n";
	cin >> p_hlo[*hlo_lkm].hat;

	(*hlo_lkm)++;
}

void TulostaHenkilo(TIEDOT p_hlo[])
{
	int nro;
	cout << "Henkilo nro? " << endl;
	cin >> nro;
	if (nro > 10)
	{
		cout << "Valinta ei mahdollinen, max maara 10" << endl;

	}
	else
	{
	 cout << "Nimi: " << p_hlo[nro-1].nimi << ", koulumatka: " << p_hlo[nro-1].kmatka << " km, hatun koko: " << p_hlo[nro-1].hat << endl;
	}
}
