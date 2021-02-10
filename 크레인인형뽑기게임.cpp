#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
	int answer = 0;
	int size = moves.size();
	stack<int> s;
	for (int i = 0; i < moves.size(); i++) {                            //moves�� �� ������ ������
		int check = moves[i] - 1;                                 //
		for (int j = 0; j < board.size(); j++) {                        //
			if (board[j][check] != 0)                             //move�ؾ��� ������ 0�� �ƴϸ�
			{
				if (!s.empty() && s.top() == board[j][check])    //������ 0�� �ƴϰ� ������top�� move�ؾ��� ������ ���ٸ� ����pop ������ ��� +2;
				{
					s.pop();
					answer += 2;
				}
				else                                            //move�ؾ��� ���� push
					s.push(board[j][check]);
				board[j][check] = 0;                            //�ش� ��ǥ ������ �������� 0���� �����
				break;
			}
		}
	}

	return answer;
}