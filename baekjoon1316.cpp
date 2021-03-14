#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int main()
{
	int n, count = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		char sentence[100];
		cin >> sentence;
		if (strlen(sentence) <= 2)
		{
			count++;
		}
		else
		{
			int overlap_count = 0;
			for (int j = 2; j < strlen(sentence); j++)
			{
				for (int k = 0; k < j - 1; k++)
				{
					if (sentence[k] == sentence[j] && sentence[k + 1] == sentence[j])
					{
						continue;
					}
					else if (sentence[k] == sentence[j])
					{
						overlap_count++;
					}
				}
			}
			if (overlap_count == 0)
			{
				count++;
			}
		}
	}

	cout << count << endl;
	return 0;
}