#include <iostream>
#include <string>
#include <random>
#include <cstdlib>
using namespace std;

string gen_password (int size){
	string caracteres =
	"abcdefghijklmnopqrstuvwxyz"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "0123456789"
        "!@#$%^&*()-_=+[]{}|;:,.<>?";

	random_device rd;
	mt19937 gerador(rd());
	uniform_int_distribution<> dist(0, caracteres.size() -1);

	string pass_word;

	for(int i = 0; i < size; ++i){
		pass_word += caracteres[dist(gerador)];
	}

	return pass_word;
	
}

int main(int argc, char* argv[]){

	if (argc != 2){
	cerr << "Use: " << argv[0] << " <length_password> " << endl;
	return 1;
	}

	int size = atoi(argv[1]);

	if (size <= 0 ){	
		cerr << "Erro: password length cannot be less than 0!";
		return 1;
	}

	string senha = gen_password(size);

	cout << senha << endl;

	return 0;
}
