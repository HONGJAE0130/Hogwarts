#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;
	queue<int> q;

	for (int i = 0; i < progresses.size(); i++) {
		int dayCount = 0;
		while (progresses[i] < 100) {
			progresses[i] += speeds[i];				// [i]��° 100�� �ɶ����� ī��Ʈ
			dayCount++;
		}
		q.push(dayCount);                           // ���� 100 �Ǹ� q�� Ǫ�� 
	}
	int max = 1;									
	int curr = q.front();                           // curr == ���� ����Ʈ ����
	q.pop();										  
	while (!q.empty()) {							
		if (q.front() <= curr) {					
			q.pop();
			max++;
		}
		else {
			answer.push_back(max);
			max = 1;
			curr = q.front();
			q.pop();
		}
	}
	answer.push_back(max);


	return answer;
}