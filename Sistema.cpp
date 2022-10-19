#include "Sistema.h"


void Sistema::cadastrarPlayers(string* nome, string* usuario, string* email, string* senha) {
	int idTemp = 0;
	int validarDados = 0;
	if (!players->empty()) {
		for (int i = 0; i < players->size(); i++) {
			if (strcmp(players->at(i)->getEmail().c_str(), email->c_str()) == 0) {
				validarDados = 1;
				break;
			}
		}

		for (int i = 0; i < players->size(); i++) {
			if (strcmp(players->at(i)->getUsuario().c_str(), usuario->c_str()) == 0) {
				validarDados = 2;
				break;
			}
		}
		idTemp = players->at(players->size() - 1)->getID() + 1;
	}

	switch (validarDados) {
	case 1:
		cout << "Email já existe." << endl;
		break;
	case 2:
		cout << "Usuario já existe." << endl;
		break;
	case 0:
		Player * player = new Player(&idTemp, nome, usuario, email, senha);
		this->players->push_back(player);
		break;
	}
}

bool Sistema::loginPlayer(string* usuario, string* senha) {
	bool online = false;
	int IdTemp = -1;
	bool login = false;
	if (!this->players->empty()) {
		for (int i = 0; i < players->size(); i++) {
			if (strcmp(players->at(i)->getUsuario().c_str(), usuario->c_str()) == 0) {
				IdTemp = players->at(i)->getID();
				break;
			}
		}
		if (IdTemp != -1) {
			for (int i = 0; i < players->size(); i++) {
				if (IdTemp == players->at(i)->getID()) {
					if (strcmp(players->at(i)->getSenha().c_str(), senha->c_str()) == 0) {
						online = true;
						players->at(i)->setOnline(&online);
						login = true;
						break;
					}
					else {
						cout << "Senha incorreta. " << endl;
						break;
					}
				}
			}
		}
		else {
			cout << "Usuario incorreta. " << endl;
		}
	}

	for (int i = 0; i < players->size(); i++) {
		if (players->at(i)->getOnline()) {
			cout << "Player Online: " + players->at(i)->getNome() << endl;
		}
	}
	return login;
}

//Getters & Setters

vector<Player*> Sistema::getPlayers() {
	return *players;
}

void Sistema::setPlayers(vector<Player*> *players) {
	this->players = players;
}

void Sistema::setPlayers(Player* player) {
	this->players->push_back(player);
}