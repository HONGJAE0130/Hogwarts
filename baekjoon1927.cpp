#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;

	priority_queue<int, vector<int>, greater<int>> q; //�켱���� ť ������� ����
	//for(int i=0;i<N;i++)
	while (N--)
	{
		int x;
		cin >> x;
		if (x == 0) {
			if (q.empty()) cout << "0\n"; // ��������� 0���            
			else {
				cout << q.top() << "\n"; // top���
				q.pop(); // ��� �� ����
			}
		}
		else {       //x != 0 �̸�
			q.push(x);   //���� ����
		}
	}
	return 0;
}
