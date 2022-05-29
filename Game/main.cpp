#include "Monster.h"
#include "Player.h"

void break_game(int& program_fighting, int& program_choose, Player& const player, int& count_ms);
void showInitPlayer(Player& const player);
void showInitMonster(Monster& const cp_monster);
void choose_f(int& program_fighting, int& program_choose, Player& player, Monster& cp_monster, int& count_ms, int& turn);
void choose_e(int& program_choose, int rd_choose, Player& player, Monster& cp_monster);

void break_game(int& program_fighting, int& program_choose, Player &const player, int & count_ms) {
	count_ms = 0;
	char chose_Y_N;
	cout << "Status: " << "Level " << player.getLevel() << "   Health " << player.getHealth() << "   Dmg " << player.getDmg() << "   Gold " << player.getGold() << "   Kill " << count_ms << endl;
	cout << "\nBan co muon choi tiep ko ? YES (Y) or NO (N)" << endl;
	do {
		cin >> chose_Y_N;
		if (chose_Y_N == 'Y' || chose_Y_N == 'y') {
			program_choose = 1;
			break;
		}
		else if (chose_Y_N == 'N' || chose_Y_N == 'n') {
			program_choose = 1;
			program_fighting = 1;
			cout << "\nEnd Game!" << endl;
			break;
		}
		else {
			cout << "\nNhap lai lua chon Y hoac N" << endl;
		}
	} while (chose_Y_N);
}
void showInitPlayer(Player& const player) {
	cout << "Thong tin nguoi choi:" << endl;
	cout << "Name: " << player.getName() << endl;
	cout << "Heal: " << player.getHealth() << endl;
	cout << "Dmg: " << player.getDmg() << endl;
	cout << "Gold: " << player.getGold() << endl;
}
void showInitMonster(Monster & const cp_monster) {
	cout << "Thong tin Monster:" << endl;
	cout << "Name: " << cp_monster.getName() << endl;
	cout << "Heal: " << cp_monster.getHealth() << endl;
	cout << "Dmg: " << cp_monster.getDmg() << endl;
	cout << "Gold: " << cp_monster.getGold() << endl;
}
void choose_f(int& program_fighting, int& program_choose, Player& player, Monster& cp_monster, int& count_ms, int &turn)
{
	cp_monster.fight(player.getDmg());
	cout << "Ban tan cong. Quai vat mat " << player.getDmg() << " mau" << endl;


	if (cp_monster.getHealth() > 0) {
		player.fight(cp_monster.getDmg());
		cout << cp_monster.getName() << " tan cong. Ban mat " << cp_monster.getDmg() << " mau" << endl;
		turn ++;
	}
	else if (cp_monster.getHealth() <= 0) {
		player.fight_win(cp_monster.getGold());
		cout << "\nChien dau ket thuc. Ban tieu diet duoc " << cp_monster.getName() << endl;
		count_ms++;
		cout << "\n-------------------------------------------------------------------------------------------" << endl;
		cout << "Status: " << "Level " << player.getLevel() << "   Health " << player.getHealth() << "   Dmg " << player.getDmg() << "   Gold " << player.getGold() << endl;
		if (player.getLevel() == 20) {
			cout << "\n==========================" << endl;
			cout << "YOU ARE WINNER!" << endl;
			break_game(program_fighting, program_choose, player, count_ms);
		}
		else {
			program_choose = 1;
		}

	}

	if (player.getHealth() > 0 && cp_monster.getHealth() > 0 ) {
		cout << "\nSatus:" << endl;
		cout << "Player: Health " << player.getHealth() << "  Dmg " << player.getDmg() << endl;
		cout << cp_monster.getName() << ": Health " << cp_monster.getHealth() << "  Dmg " << cp_monster.getDmg() << endl;
	}
	else if (player.getHealth() <= 0) {
		cout << "\n\n========================================================" << endl;
		cout << "\nYou are Lose." << endl;
		player.setHealth(0);
		break_game(program_fighting, program_choose, player, count_ms);
	}
}
void choose_e(int& program_choose, int rd_choose, Player& player, Monster& cp_monster)
{
	if (rd_choose < 6) {
		cout << "\Ban chay thoat thanh cong\n";
		program_choose = 1;
	}

	else if (rd_choose > 5) {
		cout << "\Ban chay thoat that bai. Tiep tuc chien dau\n";
		player.fight(cp_monster.getDmg());
		program_choose = 0;
		//Quay lai chien dau tiep
	}
}

int main() {
	cout << "WELCOME TO GAME" << endl;
	string name_player;
	cout << "\nName player: ";
	getline(cin, name_player);
	Player player(name_player);
	showInitPlayer(player);

	srand(time(NULL));
	char choose;

	cout << "=====================FIGHTING===============" << endl;

	int program_fighting = 0;
	int count_ms = 0;

	while (program_fighting == 0) {
		count_ms++;
		cout << "\nQuai vat so: " << count_ms;
		//Chon quai vat ngau nhien
		Type choose_ms = Type(rand() % int(Type::max));
		Monster monster(choose_ms);
		Monster cp_monster = monster;
		cout << "\nBan gap " << cp_monster.getName() << endl;
		cout << "===============================================" << endl;
		showInitMonster(cp_monster);
		//

		int program_choose = 0;
		int turn = 1;
		while (program_choose == 0) {
			cout << "\n========================================================" << endl;
			cout << "Turn " << turn << endl;
			int rd_choose = rand() % 10 + 1;

			cout << "Ban muon chien dau (f) hay chay (e): "; cin >> choose;
			if (choose == 'f') {
				choose_f(program_fighting, program_choose, player, cp_monster, count_ms, turn);
			}
			else if (choose == 'e') {
				choose_e(program_choose, rd_choose, player, cp_monster);
			}
			else {
				cout << "\nMoi ban nhap lai dung lua chon (f) hay (e)" << endl;
				program_choose = 0;
				//Quay lai cho nhap lua chon
			}
		}
	}


	return 0;
}