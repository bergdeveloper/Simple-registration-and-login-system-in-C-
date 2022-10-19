#include "Player.h"
#include <vector>

class Sistema {
public:
	void cadastrarPlayers(string* nome, string* usuario, string* email, string* senha);
	bool loginPlayer(string* usuario, string* senha);

	//Getters & Setters
	vector<Player*> getPlayers();
	void setPlayers(vector<Player*> *players);
	void setPlayers(Player *player);
private:
	vector<Player*>* players = new vector<Player*>();
};