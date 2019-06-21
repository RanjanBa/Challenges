#include <iostream>
#include <string>
using namespace std;

int main()
{
	int length;
	string name;
	char modifiedName[1000];

	getline(cin, name);

	length = name.size();
	int j = 0;
	for (int i = 0; i < length; i++)
	{
		if (int(name[i]) >= 97 && int(name[i]) <= 122)
		{
			modifiedName[j] = name[i];
			j++;
		}
	}

	string realName = "";
	for (int i = 0; i < j; i++)
	{
		realName = realName + modifiedName[i];
	}

	name = realName;
	int count = 0;
	length = realName.size();
	int half = length / 2;

	if (length % 2 == 0)
	{
		for (int i = half; i < length; i++)
		{
			if (int(name[i]) - int(name[length - i - 1]) != 0)
			{
				name[i] = name[length - i];
				count++;
			}
		}
	}
	else
	{
		for (int i = half + 1; i < length; i++)
		{
			if (int(name[i]) - int(name[length - i - 1]) != 0)
			{
				name[i] = name[length - i - 1];
				count++;
			}
		}
	}

	length = realName.size();
	half = length / 2;
	int minCount1 = 50000;
	for (int k = 0; k < half; k++)
	{
		int sum = 0;
		name = realName;
		for (int j = k; j >= 0; j--)
		{
			name += name[j];
			sum++;
		}

		length = name.size();
		half = length / 2;
		if (length % 2 == 0)
		{
			for (int i = half; i < length; i++)
			{
				if (int(name[i]) - int(name[length - i - 1]) != 0)
				{
					name[i] = name[length - i - 1];
					sum++;
				}
			}
		}
		else
		{
			for (int i = half + 1; i < length; i++)
			{
				if (int(name[i]) - int(name[length - i - 1]) != 0)
				{
					name[i] = name[length - i - 1];
					sum++;
				}
			}
		}

		if (sum < minCount1)
		{
			minCount1 = sum;
		}
	}

	if (count > minCount1)
	{
		count = minCount1;
	}

	cout << count << endl;
	return 0;
}
