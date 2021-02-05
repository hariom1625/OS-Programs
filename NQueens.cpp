#include <bits/stdc++.h>

typedef long long ll;

using namespace std;
ll count1 = 0;
bool canAdd(char board[][10], ll i, ll j, ll n) {


	ll x = i, y = j;


	for (ll k = 0; k < n; k++) {
		if (board[k][j] == 1)
			return false;
	}

	while (x >= 0 && y >= 0) {  //left diagonal

		if (board[x][y] == 1) {
			return false;
		}
		x--;
		y--;
	}

	x = i;
	y = j;
	while (x >= 0 && y <= n) { //right diagonal

		if (board[x][y] == 1) {
			return false;
		}
		x--;
		y++;
	}


	return true;
}


bool nqueen(char board[][10], ll i, ll n) {



	if (i == n) {

		for (ll i = 0; i < n; i++) {

			for (ll j = 0; j < n; j++)
			{
				if (board[i][j] == 0)
					cout << "_" << " ";
				else
					cout << "Q" << " ";
			}
			cout << "\n";
		}
		count1++;

		cout << "\n\n";
		return false;


	}

	else {

		for (ll j = 0; j < n; j++) {



			if (canAdd(board, i, j, n)) {
				board[i][j] = 1;
				bool istrue = nqueen(board, i + 1, n);
				if (istrue)
					return true;

				else
					board[i][j] = 0;
			}


		}

		return false;

	}

}




int main() {


#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);



	char board[10][10] = {0};
	ll n;
	cin >> n;
	nqueen(board, 0, n);

	cout << count1 << "\n";



}
