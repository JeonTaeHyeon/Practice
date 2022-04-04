#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

priority_queue<pair<int, int>> pq;
vector<pair<int, int>>v;
int n;

int res() {
	int num1, num2;
	for (int i = 0; i < n; i++)
	{
		cin >> num1 >> num2;
		v.push_back({ num1, num2 });
	}
	sort(v.begin(), v.end());//시작시간 기준으로 정렬

		pq.push({ -v[0].second,v[0].first });//min heap

	for (int i = 1; i < n; i++)
	{

		if (-pq.top().first <= v[i].first) {//종료시간이 다음 시작시간보다 빠르다면
			pq.pop();
			pq.push({ -v[i].second, v[i].first });
		}//강의가 끝난것이므로 pop하고 push
		else {
			pq.push({ -v[i].second, v[i].first });
		}//강의가 안끝났으므로 그냥 push
	}
	return pq.size();

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
		cin >> n;

	cout << res();

}