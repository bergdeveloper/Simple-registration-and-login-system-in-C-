#include "Sistema.h"
#include <chrono>
#include <thread>
#include<conio.h>
#include <windows.h>

void escrever(string texto, int microseconds, int color) {
	HANDLE console_color;
	console_color = GetStdHandle(STD_OUTPUT_HANDLE);
	for (int i = 0; i < texto.length(); i++) {
		SetConsoleTextAttribute(console_color, color);
		cout << texto[i];
		std::this_thread::sleep_for(std::chrono::microseconds(microseconds));
	}
	cout << endl;
	SetConsoleTextAttribute(console_color, 8);
}

int main() {

	Sistema sistema;
	setlocale(LC_ALL, "portuguese");

	while (true) {
		const string palavras_reservadas[] = {"cadastrar", "login"};
		cout << "Digite {cadastrar} ou {login} para se cadastrar, ou fazer login." << endl;
		cout << "" << endl;

		string entrada = "null";
		cin >> entrada;

		if (strcmp(entrada.c_str(), palavras_reservadas[0].c_str()) == 0) {
			system("cls");
			cout << "Ok, voce quer se cadastrar no sistema." << endl;
			string nome = "null";
			string usuario = "null";
			string email = "null";
			string senha = "null";

			cout << "Digite seu nome:" << endl;
			cin.ignore();
			getline(cin, nome);

			cout << "Digite seu usuário:" << endl;
			cin >> usuario; 
			cout << "Digite seu email:" << endl;
			cin >> email; 
			cout << "Digite sua senha:" << endl;
			cin >> senha;

			sistema.cadastrarPlayers(&nome, &usuario, &email, &senha);

			cout << "Usuario cadastrado com sucesso." << endl;
			std::this_thread::sleep_for(std::chrono::seconds(2));
			system("cls");
			continue;
		}else if (strcmp(entrada.c_str(), palavras_reservadas[1].c_str()) == 0) {
			system("cls");
			cout << "Ok, voce quer fazer login no sistema." << endl;

			string usuarioLogin = "null";
			string senhaLogin = "null";
			cout << "Digite {seu nome de usuario}." << endl;
			cin >> usuarioLogin;
			cout << "Digite {sua senha}." << endl;
			cin >> senhaLogin;

			if (sistema.loginPlayer(&usuarioLogin, &senhaLogin)) {
				break;
			}
			else {
				continue;
			}
		}
		else {
			system("cls");
			cout << "Nao entendi seu comando, pode repetir ?" << endl;
			continue;
		}

	}
	int indicePlayer = -1;
	for (int i = 0; i < sistema.getPlayers().size(); i++) {
		if (sistema.getPlayers().at(i)->getOnline()) {
			indicePlayer = i;
			break;
		}
	}

	if (indicePlayer != -1) {
		std::this_thread::sleep_for(std::chrono::seconds(3));
		system("cls");

		string palavra = "Bem vindo " + sistema.getPlayers().at(indicePlayer)->getNome();
		escrever(palavra, 70000, 9);
	}

	return 0;
}