#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int answer = 0;
	int weight_sum = 0;
	//���ο� �ö����ִ� ��, ������ ���� �Ÿ�
	queue<int> bridge, count;

	while (true) {
		int size = bridge.size();
		for (int i = 0; i < size; i++) {
			int length = bridge.front();
			bridge.pop();
			//���ο� ���� ���̰� ���ٸ�
			if (length <= 1) {
				//���ο� ������ ���Ը� ����
				weight_sum -= count.front();
				//���ο� �ö� �ִ� �� ����
				count.pop();
				continue;
			}
			//�����ִٸ� ���� ������ �ٽ� �ֱ�
			bridge.push(length - 1);
		}
		//��� Ʈ���� �ְ�  && (���� �ٸ��� �ִ� ���� ���� + ��� Ʈ�� 1���� ����) <= �ٸ� ����)
		if (truck_weights.size() > 0 && weight_sum + truck_weights.at(0) <= weight) {
			//��� 0���� Ʈ�� �߰�
			count.push(truck_weights.at(0));
			//�ٸ� �� ���� �߰�
			weight_sum += truck_weights.at(0);
			//�ٸ� ���� ��ŭ �߰�
			bridge.push(bridge_length);
			//��� Ʈ�� 0���� ���� 
			truck_weights.erase(truck_weights.begin());
		}
		//�ð��� ����
		answer++;
		//��� Ʈ���� ���� ���� �ٸ��� �Ÿ��� 0�̸� break;
		if (truck_weights.size() == 0 && count.size() == 0)
			break;

	}

	return answer;

}