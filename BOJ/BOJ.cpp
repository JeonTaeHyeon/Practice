#include<iostream>
#include<queue>

using namespace std;

priority_queue<int> pq;
int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);//����� �ӵ� ������ �ð��ʰ� �߻�

	cin >> n;
	int num;
	while (n--) {
		cin >> num;
		if (!num) {//�Է��� 0�϶�
			if (pq.empty()) {
				cout << "0\n";
			}//queue�� ����ִٸ� 0���
			if (!pq.empty()) {
				cout << pq.top() << "\n";
				pq.pop();
			}//queue�� ������� ������ top�� �� ��� �� pop
		}
		else {
			pq.push(num);
		}//�Է��� 0�� �ƴ϶�� push
	}
}