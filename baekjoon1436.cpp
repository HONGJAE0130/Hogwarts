#include <iostream>
#include <string>
using namespace std;
int Findseries(int N)
{
	int i = 666;
	int series = 0;
	string target;
	while (1)
	{
		target = to_string(i);									//target�� "666" �� string���� ����
		for (int j = 0; j < target.length() - 2; j++)			//
			if (target[j] == '6' && target[j + 1] == '6' && target[j + 2] == '6')   //���������� 6��  3���� ������ series++ �ϰ� series�� N( �Է��� ��) �� ������ i�� ���
			{
				series++;
				if (series == N)
					return i;
				break;
			}
		i++;					//���� 666�� �ƴϸ� i++
	}
}
int main() {
	int N;
	cin >> N;
	cout << Findseries(N);
}