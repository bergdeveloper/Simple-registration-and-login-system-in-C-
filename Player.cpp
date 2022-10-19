#include "Player.h"

Player::Player(int* ID, string* nome, string* usuario, string* email, string* senha) {
	//estou pegando o conteúdo do endereço do parametro e colocando nas variáveis da classe.
	this->ID = *ID;
	this->nome = *nome;
	this->usuario = *usuario;
	this->email = *email;
	this->senha = *senha;
	this->online = false;
}

int Player::getID() {
	return this->ID;
}

void Player::setID(int* ID) {
	//estou pegando o conteúdo do endereço do parametro e colocando no ID da classe.
	this->ID = *ID;
}

string Player::getNome() {
	return this->nome;
}

void Player::setNome(string* nome) {
	//estou pegando o conteúdo do endereço do parametro e colocando no ID da classe.
	this->nome = *nome;
}

string Player::getUsuario() {
	return this->usuario;
}

void Player::setUsuario(string* usuario) {
	//estou pegando o conteúdo do endereço do parametro e colocando no ID da classe.
	this->usuario = *usuario;
}

string Player::getEmail() {
	return this->email;
}

void Player::setEmail(string* email) {
	//estou pegando o conteúdo do endereço do parametro e colocando no ID da classe.
	this->email = *email;
}

string Player::getSenha() {
	return this->senha;
}

void Player::setSenha(string* senha) {
	//estou pegando o conteúdo do endereço do parametro e colocando no ID da classe.
	this->senha = *senha;
}

bool Player::getOnline() {
	return this->online;
}

void Player::setOnline(bool* online) {
	//estou pegando o conteúdo do endereço do parametro e colocando no ID da classe.
	this->online = *online;
}