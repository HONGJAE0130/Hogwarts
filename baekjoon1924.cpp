#include <string>
#include <vector>
#include <iostream>

using namespace std;
string DAY[7] = { "SUN","MON","TUE","WED","THU","FRI","SAT" };

string solution(int a, int b) {
	string answer = "";
	int i;
	if (a == 1) i = 0;
	else if (a == 2) i = 3;
	else if (a == 3) i = 3;
	else if (a == 4) i = 6;
	else if (a == 5) i = 1;
	else if (a == 6) i = 4;
	else if (a == 7) i = 6;
	else if (a == 8) i = 2;
	else if (a == 9) i = 5;
	else if (a == 10) i = 0;
	else if (a == 11) i = 3;
	else if (a == 12) i = 5;

	b = i + b;
	answer = DAY[b % 7];

	return answer;
}
int main() {
	int a, b;
	cin >> a >> b;
	cout << solution(a, b);
	return 0;
}