#include <iostream>
#include <algorithm>
#include <vector>

#define MAX_SIZE 21
using namespace std;

bool is_used[MAX_SIZE];
int s[MAX_SIZE][MAX_SIZE];
int n;
int ans = 987654321;

// curr_player�� ������ ��ŸƮ ������ �̴´�, cnt : ���� ���
void DFS(int curr_player, int cnt)
{
	if (cnt == n / 2)
	{
		vector<int> team_link, team_start;

		// ���� �������� ��ŸƮ������
		for (int i = 0; i < n; i++)
		{
			if (is_used[i]) team_start.push_back(i);
			else team_link.push_back(i);
		}

		// ��ŸƮ���� ��ũ���� �ɷ�ġ ���� ���ϱ�
		int stat_start = 0, stat_link = 0;
		for (int i = 0; i < team_start.size(); i++)
		{
			for (int j = i + 1; j < team_start.size(); j++)
			{
				//start�� += s[i][j] + s[j][i] link��
				int start_x = team_start[i], start_y = team_start[j];
				int link_x = team_link[i], link_y = team_link[j];
				stat_start += s[start_x][start_y] + s[start_y][start_x];
				stat_link += s[link_x][link_y] + s[link_y][link_x];
			}
		}
		// �տ� ����� ans[ �� ���� �������� ] �� ���� �������̸� ���ؼ� ���� ���� ans�� ����)
		ans = min(ans, abs(stat_start - stat_link));
		return;
	}

	// ����Ž��
	for (int i = curr_player + 1; i < n; i++)
	{
		//i��° �������� Ž���ϸ鼭 Ž���ߴ��� ���ߴ��� used
		if (is_used[i] == false)
		{
			is_used[i] = true;
			DFS(i, cnt + 1);
			// ��Ʈ��ŷ
			is_used[i] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> s[i][j];
		}
	}
	DFS(0, 0);
	cout << ans << "\n";

	return 0;
}