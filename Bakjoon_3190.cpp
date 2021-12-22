#include <iostream>
#include <deque>
#include <queue>

using namespace std;

bool apple[101][101];
// not use index 0

bool visited[101][101];

struct ch_dir {
	int X;
	int C;
};

struct pos {
	int row;
	int col;
};

int main() {
	int N, K;
	// N X N, number of apples is K
	cin >> N;
	cin >> K;

	// initialize visited and apple
	for (int r = 0; r <= N; r++) {
		for (int c = 0; c <= N; c++) {
			visited[r][c] = false;
			apple[r][c] = false;
		}
	}
	visited[N][1] = true;

	int row, col;
	for (int count = 0; count < K; count++) {
		cin >> row >> col;
		apple[N - row + 1][col] = true;
	}

	int L;
	// number of direction change
	cin >> L;

	int X;
	char C;
	// after X seconds, change directionrs
	// C == L : left
	// C == D : right

	queue<ch_dir> dir;
	// store information of direction change

	for (int count = 0; count < L; count++) {
		cin >> X >> C;
		dir.push(ch_dir{ X, C });
	}

	deque<pos> current_pos;
	current_pos.push_back(pos{ N, 1 });



	int time = 0;
	int direction = 1;
	// dir : 1 -> right
	// dir : 2 -> down
	// dir : 3 -> left
	// dir : 4 -> up

	while (true) {
		time++;
		
		pos head = current_pos.back();

		pos next_pos = head;

		// add next postion
		switch (direction)
		{
		case 1:
			next_pos.col++;
			break;
		case 2:
			next_pos.row--;
			break;
		case 3:
			next_pos.col--;
			break;
		default:
			next_pos.row++;
			break;
		}
		current_pos.push_back(next_pos);

		// check Game Over
		if (next_pos.row > N || next_pos.row < 1 || next_pos.col > N || next_pos.col < 1) {
			// out of range
			break;
		}
		if (visited[next_pos.row][next_pos.col] == true) {
			// meet itself
			break;
		}

		// check there is no apple
		if (apple[next_pos.row][next_pos.col] == false) {
			// no apple
			pos del_pos = current_pos.front();
			visited[del_pos.row][del_pos.col] = false;
			current_pos.pop_front();
		}
		else {
			// there is apple
			apple[next_pos.row][next_pos.col] = false;
			// delete apple
		}

		

		

		// indicate visited area
		visited[next_pos.row][next_pos.col] = true;

		// change direction
		if (!dir.empty() && dir.front().X == time) {

			if (dir.front().C == 'L') {
				switch (direction) {
				case 1:
					direction = 4;
					break;
				case 2:
					direction = 1;
					break;
				case 3:
					direction = 2;
					break;
				default:
					direction = 3;
					break;

				}
			}
			else {
				// C == 'D'
				switch (direction) {
				case 1:
					direction = 2;
					break;
				case 2:
					direction = 3;
					break;
				case 3:
					direction = 4;
					break;
				default:
					direction = 1;
					break;

				}
			}
			dir.pop();
		}

		
	}

	cout << time << endl;
}