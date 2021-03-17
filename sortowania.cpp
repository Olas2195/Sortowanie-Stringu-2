#include <iostream>
#include <fstream>
#include <vector>
#include<algorithm>

using namespace std;

class Program {
	ifstream plik1;
	vector <string> imiona;
	
	public:
		Program();
		~Program();
		void wczytajPlik();
		void sortAlfabet();
		void sortWstecz();
		void sortDlugosc();
		void sortWaga();
};

Program::Program() {
	plik1.open("we.txt");
}

void Program::wczytajPlik() {
	string wprowadzane;
	if(plik1.good())
		while(!plik1.eof()) {
			plik1>>wprowadzane;
			imiona.push_back(wprowadzane);
		}
}

void Program::sortAlfabet() {
	sort(imiona.begin(), imiona.end());
	for (int i=0; i<imiona.size(); i++) {
    	cout<<imiona[i]<<"\n";
	}
}

void Program::sortWstecz() {
	sort(imiona.begin(), imiona.end(), greater <string>());
	for (int i=0; i<imiona.size(); i++) {
    	cout<<imiona[i]<<"\n";
	}
}

bool dlugosc(string a, string b) {
	return a.length()<b.length();
	
}

void Program::sortDlugosc() {
	sort(imiona.begin(), imiona.end(), dlugosc);
	for (int i=0; i<imiona.size(); i++) {
    	cout<<imiona[i]<<"\n";
	}	
}

bool waga(string a, string b) {
	int z=0;
	int y=0;
	for (int i=0; i<a.length(); i++) {
    	z=z+a[i];
	}
	for (int i=0; i<b.length(); i++) {
    	y=y+b[i];
	}
	return z<y;		
}

void Program::sortWaga() {
	sort(imiona.begin(), imiona.end(), waga);
	for (int i=0; i<imiona.size(); i++) {
    	cout<<imiona[i]<<"\n";
	}
}

Program::~Program() {
	plik1.close();
}

int main(int argc, char** argv) {
	Program p1;
	int x;
	
	cout<<"Menu: \n"
		<<"1. wczytaj plik\n"
		<<"2. sortuj alfabetycznie\n"
		<<"3. sortuj w kolejnosci odwrotnej\n"
		<<"4. sortuj w kolejnosci dlugosci wyrazu\n"
		<<"5. sortuj wedlug wagi wyrazu, obliczanej jako suma wszystkich kodow ASCII\n"
		<<"0. KONIEC\n\n";
	
	do{
		cin>>x;
		switch(x){
			case 1:
				p1.wczytajPlik();
				break;
			case 2:
				p1.sortAlfabet();
				break;
			case 3:
				p1.sortWstecz();
				break;
			case 4:
				p1.sortDlugosc();
				break;
			case 5:
				p1.sortWaga();
				break;
			case 0:
				cout<<"KONIEC!";
				break;
			default:
				cout<<"Nieprawid³owy wybor\n";
				break;
		}
	}while(x!=0);
	
	return 0;
}
