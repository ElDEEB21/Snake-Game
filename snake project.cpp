#include <iostream>
#include <ctime>
#include <conio.h>
#include <Windows.h>
using namespace std;

enum direction { Top = 1, Down, Right, Left };
struct map { int Width, Height, Fruit_X, Fruit_Y; };
struct snake { int Head_X, Head_Y, t, Tail_X[50], Tail_Y[50]; char dir; };
struct player { int score; bool lose; };
map Map; snake Snake; player Player;

void Intro() {
	cout << R"( $$$$$$\                      $$\                        $$$$$$\                                    
$$  __$$\                     $$ |                      $$  __$$\                                   
$$ /  \__|$$$$$$$\   $$$$$$\  $$ |  $$\  $$$$$$\        $$ /  \__| $$$$$$\  $$$$$$\$$$$\   $$$$$$\  
\$$$$$$\  $$  __$$\  \____$$\ $$ | $$  |$$  __$$\       $$ |$$$$\  \____$$\ $$  _$$  _$$\ $$  __$$\ 
 \____$$\ $$ |  $$ | $$$$$$$ |$$$$$$  / $$$$$$$$ |      $$ |\_$$ | $$$$$$$ |$$ / $$ / $$ |$$$$$$$$ |
$$\   $$ |$$ |  $$ |$$  __$$ |$$  _$$<  $$   ____|      $$ |  $$ |$$  __$$ |$$ | $$ | $$ |$$   ____|
\$$$$$$  |$$ |  $$ |\$$$$$$$ |$$ | \$$\ \$$$$$$$\       \$$$$$$  |\$$$$$$$ |$$ | $$ | $$ |\$$$$$$$\ 
 \______/ \__|  \__| \_______|\__|  \__| \_______|       \______/  \_______|\__| \__| \__| \_______|
                                                                                                    
                                                                                                    
                                                                                                    )";
	cout << endl;
}

void sheft_right(int arr[], int size) {
	for(int i = size - 2; i >= 0; --i) {
		arr[i + 1] = arr[i];
	}
}
		
void generate_fruit() {
	srand(time(NULL));
	Map.Fruit_X = rand() % (Map.Width - 2) + 1;
	Map.Fruit_Y = rand() % (Map.Height - 2) + 1;
}

void Setup() {
	Map.Width = 40; Map.Height = 20;
	generate_fruit();
	//...............
	Snake.Head_X = Map.Width / 2;
	Snake.Head_Y = Map.Height / 2;

	Snake.t = 0;
	//.............
	Player.score = 0;
	Player.lose = false;
}

void draw() {
	system("cls");
	for (int i = 0; i < Map.Height;++i) {
		for (int j = 0; j < Map.Width; ++j) {
			if (i == 0 || i == Map.Height - 1)
				cout << "*";
			else if ((j == 0 || j == Map.Width - 1))
				cout << "*";
			else if (i == Snake.Head_Y && j == Snake.Head_X)
				cout << "O";
			else if (i == Map.Fruit_Y && j == Map.Fruit_X)
				cout << "$";
			else {
				bool eldeeb = false;
				for (int k = 0; k < Snake.t; ++k) {
					if (Snake.Tail_X[k] == j && Snake.Tail_Y[k] == i) {
						cout << "o";
						eldeeb = true;
						break;
					}
				}
				if (!eldeeb)
					cout << " ";
			}
		}
		cout << endl;
	}
	cout << "Player score : " << Player.score << endl;
	cout << "If you want to pause the game press ( P / p ) ." << endl;
	cout << "If you want to exit the game press ( X / x ) ." << endl;
	cout << endl;
}

void input() {
	if (_kbhit()) {
		char c = _getch();
		switch (c) {
		case 'w':
			if (Snake.dir != Down)
				Snake.dir = Top;
			break;
		case 's':
			if (Snake.dir != Top)
				Snake.dir = Down;
			break;
		case 'd':
			if (Snake.dir != Left)
				Snake.dir = Right;
			break;
		case 'a':
			if (Snake.dir != Right)
				Snake.dir = Left;
			break;
		case 'x':
			exit(0);
		case 'W':
			if (Snake.dir != Down)
				Snake.dir = Top;
			break;
		case 'S':
			if (Snake.dir != Top)
				Snake.dir = Down;
			break;
		case 'D':
			if (Snake.dir != Left)
				Snake.dir = Right;
			break;
		case 'A':
			if (Snake.dir != Right)
				Snake.dir = Left;
			break;
		case 'X':
			exit(0);
		case 'p':
			system("pause");
		case 'P':
			system("pause");
		}
	}
}

void move() {
	sheft_right(Snake.Tail_X, 50);
	sheft_right(Snake.Tail_Y, 50);
	Snake.Tail_X[0] = Snake.Head_X;
	Snake.Tail_Y[0] = Snake.Head_Y;
	switch (Snake.dir) {
	case Top: Snake.Head_Y--; break;
	case Down: Snake.Head_Y++; break;
	case Right: Snake.Head_X++; break;
	case Left: Snake.Head_X--; break;
	}
	if (Snake.Head_Y >= Map.Height - 1 || Snake.Head_Y <= 0 || Snake.Head_X >= Map.Width - 1 || Snake.Head_X <= 0) {
		Player.lose = true;
		cout << "You lose because you hit the wall . " << endl;
	}

	//if (Snake.Head_X >= Map.Width)Snake.Head_X = 0;else if (Snake.Head_X < 0)Snake.Head_X = Map.Width - 1;
	//if (Snake.Head_Y >= Map.Height)Snake.Head_Y = 0;else if (Snake.Head_Y < 0)Snake.Head_Y = Map.Height - 1;

	for (int i = 0; i < Snake.t; ++i) {
		if (Snake.Tail_X[i] == Snake.Head_X && Snake.Tail_Y[i] == Snake.Head_Y) {
			Player.lose = true;
			cout << "You lose because you hit yourself . " << endl;
		}
	}
	if (Snake.Head_X == Map.Fruit_X && Snake.Head_Y == Map.Fruit_Y) {
		generate_fruit();
		Player.score++;
		Snake.t++;
	}
}

int main() {
	x:
	system("cls");
	Intro();
	system("pause");
	system("cls");
	Setup();
	Snake.dir = 0;
	while(!Player.lose) {
		draw();
		input();
		move();
		Sleep(200 - (10 * Player.score));
	}
	if (Player.lose) {
		cout << endl;
		cout << "If you want to play again press (Y / y ) , or press any key to exit the game ." << endl;
		char c; cin >> c;
		if (c == 'y' || c == 'Y')
			goto x;
		else {
			return 0;
		}
	}
}