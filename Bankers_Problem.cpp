#include <bits/stdc++.h>

typedef long long ll;

using namespace std;



int main() {


#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll p, r;
	cout << "Enter number of Processes: ";
	cin >> p;
	cout << "Enter number of Resources: ";
	cin >> r;
	ll alloc[p][r], max_nd[p][r], avail[r], need[p][r];
	cout << "Enter the present Allocated Resources: ";
	for (ll i = 0; i < p; i++)
		for (ll j = 0; j < r; j++)
			cin >> alloc[i][j];
	cout << "Enter the Maximum Need for Resorces: ";

	for (ll i = 0; i < p; i++)
		for (ll j = 0; j < r; j++)
			cin >> max_nd[i][j];
	cout << "Enter the Available Resorces: ";

	for (ll j = 0; j < r; j++)
		cin >> avail[j];



	ll  flag = 0, ans[5], g = 0, c[5] = {0};

	for (ll i = 0; i < p; i++) {
		for (ll j = 0; j < r; j++) {
			need[i][j] = max_nd[i][j] - alloc[i][j];
		}
	}

	for (ll i = 0; i < p; i++) {
		for (ll j = 0; j < p; j++) {
			flag = 0;
			if (c[j] == 0) {
				for (ll k = 0; k < r; k++) {

					if (avail[k] < need[j][k]) {

						flag = 1;
						break;

					}
				}
				if (flag == 0) {
					ans[g++] = j;

					for (ll x = 0; x < r; x++)
						avail[x] += need[j][x];

					c[j] = 1;

				}
			}


		}
	}
	cout << "\n";
	for (ll i = 0; i < p - 1; i++)
	{
		cout <<  "P" << ans[i] << " " << "-->" << " ";
	}
	cout << "P" << ans[p - 1] << " ";
}
