#include <iostream>
#include <string>
using namespace std;

class Player {
public:
	Player(int* ID, string* nome, string* usuario, string* email, string* senha);

	//Getters & Setters
	int getID();
	void setID(int* ID);

	string getNome();
	void setNome(string* nome);

	string getUsuario();
	void setUsuario(string* usuario);

	string getEmail();
	void setEmail(string* email);

	string getSenha();
	void setSenha(string* senha);

	bool getOnline();
	void setOnline(bool* online);

private:
	int ID;
	string nome;
	string usuario;
	string email;
	string senha;
	bool online;
};