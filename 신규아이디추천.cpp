#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(string new_id) {
	string answer = "";
	int i;
	transform(new_id.begin(), new_id.end(), new_id.begin(), ::tolower); //1�ܰ�    

	for (i = 0; i < new_id.length(); i++)	{
		if ((new_id[i] >= 'a' && new_id[i] <= 'z') || ('0' <= new_id[i] && new_id[i] <= '9') || (new_id[i] == '_') || (new_id[i] == '-') || (new_id[i] == '.'))  continue; //2�ܰ�
		else {
			new_id.erase(i, 1);
			i--;
		}
	}
	for (i = 1; i < new_id.size(); i++) {
		if (new_id[i - 1] == '.' && new_id[i] == '.')	{				//3�ܰ�
			new_id.erase(i, 1);
			i--;
		}
	}

	if (new_id[0] == '.') new_id.erase(new_id.begin());		//4�ܰ�
	if (new_id[new_id.length() - 1] == '.') new_id.erase(new_id.end() - 1);          //4�ܰ�

	if (new_id.empty()) new_id.push_back('a');                  //5�ܰ�

	if (new_id.length() >= 16) {                                            //6�ܰ�
		new_id.erase(new_id.begin() + 15, new_id.end());
		if (new_id[new_id.length() - 1] == '.') new_id.pop_back();
	}
	if (new_id.length() <= 2) {                                                 //7�ܰ�
		while (new_id.length() < 3)
			new_id += new_id[new_id.size() - 1];
	}
	answer += new_id;
	return answer;
}



