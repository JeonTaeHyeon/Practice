#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<set>
using namespace std;
int N, M;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

int map[9][9];
int save[9][9];
int res = 0;
int cnt = 0;

void bfs() {
	cnt = 0;
	queue<pair<int, int>> q;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if (save[i][j] == 2) {
				q.push({ i,j });
			}
		}
	}//바이러스가 있으면 push
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int xx = x + dx[i];
			int yy = y + dy[i];
			if (xx > 0 && yy > 0 && xx <= N && yy <= M && !save[xx][yy]) {
				q.push({ xx,yy });
				save[xx][yy] = 2;
			}//벽이 없으면 바이러스를 퍼뜨린다
		}
	}
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if (!save[i][j]) {
				cnt++;
			}
		}
	}//바이러스가 퍼지지 않은 영역 갯수 구하기
	res = max(res, cnt);
}

void makewall(int w) {
	if (w == 3) {
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= M; j++)
			{
				save[i][j] = map[i][j];
			}
		}
		bfs();
		return;
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if (!map[i][j]) {
				map[i][j] = 1;
				makewall(w + 1);
				map[i][j] = 0;
			}

		}
	}
}//벽을 3개씩 세우면서 bfs를 진행한다.


int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cin >> map[i][j];
		}
	}
	makewall(0);

	cout << res;

}