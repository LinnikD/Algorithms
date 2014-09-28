//============================================================================
// Name        : GameMatrix.cpp
// Author      : D.Linnik
// Version     :
// Copyright   : lol
// Description : Hello World in C++, Ansi-style
//============================================================================



/*
     	a b c d e f g h i

	1	x x x o o o x x x
	2	x x x o o o x x x
	3	x x x o o o x x x
	4	o o o o o o o o o
	5	o o o o e o o o o
	6	o o o o o o o o o
	7	x x x o o o x x x
	8	x x x o o o x x x
	9	x x x o o o x x x

	input example:
	State:e3
	Turn:e5

	enjoy it, Alenka!
 */
#include <iostream>
#include <stdio.h>

////////////////////////////////////////////////

class Input {
// Don't know
};

class ConsoleInput : public Input {
public:
	ConsoleInput();
void GetTurn(int &s1, int &s2, int &t1, int &t2);
private:
	void in_turn(const char * txt, std::pair <int,int> & var);
	int translate(char t);
	std::pair <int, int> state;
	std::pair <int, int> turn;
};

int ConsoleInput::translate(char t) {
	if(t > 64 && t < 74 )
		return t - 64;
	if(t > 96 && t < 106)
		return t - 96;
	if(t > 48 && t < 58)
		return t - 48;
	return 0;
}

void ConsoleInput::in_turn(const char * txt, std::pair <int,int> & var) {
	bool t = false;
		char ctmp;
		while(!t) {
			while(* txt != 0)
				std::cout<<*(txt++);
			std::cin>> ctmp;
			if( ctmp < 58 ) {
				var.first = translate(ctmp);
				std::cin >> ctmp;
				var.second = translate(ctmp);

			}
			else {
				var.second = translate(ctmp);
				std::cin >> ctmp;
				var.first = translate(ctmp);
			}
			if(var.first > 0 && var.first < 10 && var.second > 0 && var.second <10)
				t = !t;
			else
				std::cout << "Wrong input";
		}
}

ConsoleInput::ConsoleInput() {
	in_turn("State:\0", state);
	in_turn("Turn:\0", turn);
}

void ConsoleInput::GetTurn(int &s1, int &s2, int &t1, int &t2) {
	s1 = state.first - 1;
	s2 = state.second - 1;
	t1 = turn.first - 1;
	t2 = turn.second - 1;
}

//////////////////////////////////////////////////////

class GameMatrix {
public:
	GameMatrix();
	void Show();
	void Turn();
private:
	bool Check(int &s1, int &s2, int &t1, int &t2);
	static const int size = 9;
	char Matrix[size][size];
};

GameMatrix::GameMatrix() {
	for(int i = 0; i < size; ++i) {
		for(int j = 0; j < size; ++j) {
			if( (i > 2 && i < 6) || (j > 2 && j < 6) ) {
				Matrix[i][j] = 'o';
				if( (i == 4) && (j == 4))
					Matrix[i][j] = 'e';
			}
			else
				Matrix[i][j] = 'x';
			}
		}
}

void GameMatrix::Show() {
	std::cout << "      a b c d e f g h i \n\n";
	for(int i = 0; i < size; ++i) {
		std::cout << " " << i+1<< "    ";
		for(int j = 0; j < size; ++j)
			std::cout << Matrix[i][j] << ' ';
		std::cout << '\n';
	}
}

bool GameMatrix::Check(int &s1, int &s2, int &t1, int &t2) {
	if(Matrix[s1][s2] != 'o' || Matrix[t1][t2] != 'e')
		return 0;
	int st1 = s1 - t1;
	int st2 = s2 - t2;
	if(st1 == 2 && st2 == 0) {
		std::cout<<"a";
		if(Matrix[s1 - 1][s2] == 'o')
			return 1;
		else
			return 0;
	}
	if(st1 == -2 && st2 == 0) {
		std::cout<<"d";
		if(Matrix[s1 + 1][s2] == 'o')
			return 1;
		else
			return 0;
	}
	if(st1 == 0 && st2 == 2) {
		std::cout<<"c";
		if(Matrix[s1][s2 - 1] == 'o')
			return 1;
		else
			return 0;

	}
	if(st1 == 0 && st2 == -2) {
		std::cout<<"b";
		if(Matrix[s1][s2 + 1] == 'o')
			return 1;
		else
			return 0;
	}
	return 0;
}

void GameMatrix::Turn() {
	int state1, state2, turn1, turn2;
	ConsoleInput C;
    C.GetTurn(state1,state2,turn1,turn2);
	while(!Check(state1,state2,turn1,turn2)) {
		std::cout<<"Wrong input /n";
		ConsoleInput C;
		C.GetTurn(state1,state2,turn1,turn2);
		std::cout<< state1<< " " <<state2<< "\n"<<turn1<<" "<<turn2;
	}
	Matrix[state1][state2] = 'e';
	Matrix[turn1][turn2] = 'o';
	if(state1 == turn1) {
		if(state2 - turn2 == 2)
			Matrix[state1][state2 - 1] = 'e';
		else
			Matrix[state1][state2 + 1] = 'e';

	}
	else {
		if(state1 - turn1 == 2)
			Matrix[state1 - 1][state2] = 'e';
		else
			Matrix[state1 + 1][state2] = 'e';

	}
}

int main() {
	GameMatrix M;
	M.Show();
	while(1){
		M.Turn();
		M.Show();
	}
	return 0;
}
