#include<iostream>
#include<queue>

using namespace std;

priority_queue<int> pq;
int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);//입출력 속도 때문에 시간초과 발생

	cin >> n;
	int num;
	while (n--) {
		cin >> num;
		if (!num) {//입력이 0일때
			if (pq.empty()) {
				cout << "0\n";
			}//queue가 비어있다면 0출력
			if (!pq.empty()) {
				cout << pq.top() << "\n";
				pq.pop();
			}//queue가 비어있지 않으면 top의 값 출력 후 pop
		}
		else {
			pq.push(num);
		}//입력이 0이 아니라면 push
	}
}