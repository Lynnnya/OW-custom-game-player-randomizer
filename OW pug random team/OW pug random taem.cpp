#include <iostream>
#include <ctime>
#include <string>
#include <iomanip>

using namespace std;

void teams_out(string team1[5], string team2[5]) {
	cout << setw(20) << left << "Team 1" << "Team 2" << endl;
	for (int i = 0; i < 5; i++) {
		cout << setw(20) << left << team1[i] << team2[i] << endl;
	}
}

string input_player(int player_number) {
	string player_name;
	cout << "Player " << player_number + 1 << ": ";
	cin >> player_name;
	return player_name;
}

int rng(unsigned int seed) {
	int num;
	num = (rand() % 50) + 1;
	return num;
}

int main() {
	unsigned int seed = time(NULL);
	srand(seed);
	string player[10], team1[5], team2[5];
	int team1_cur = 0, team2_cur = 0;

	for (int i = 0; i < 10; i++) {
		player[i] = input_player(i);
	}

	for (int i = 0; i < 10; i++) {
		if (((rng(seed) * rng(seed)) % 50) < 25) {
			if (team1_cur == 5) {
				i--;
				continue;
			}
			team1[team1_cur] = player[i];
			team1_cur++;
		}
		else {
			if (team2_cur == 5) {
				i--;
				continue;
			}
			team2[team2_cur] = player[i];
			team2_cur++;
		}
	}

	teams_out(team1, team2);
	system("pause");
}