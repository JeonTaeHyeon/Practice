#include<iostream>
#include<algorithm>
using namespace std;
#define _size 100000

int arr[_size];
int res=_size;
int n, s;
int start, fin;
int sum;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> s;

	for (int i = 0; i <n; i++)
	{
		cin >> arr[i];
	}
	while (fin!=n||sum>=s) {
		if (sum < s) {
			sum += arr[fin];
			++fin;
		}
		if (sum >= s) {
			res = min(res, fin - start);
			sum -= arr[start];
			start++;
		}
	//	if (fin == n)break;
	}
	if (res == _size)cout << "0";
	else { cout << res; }
}