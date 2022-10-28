#include <iostream>

int GetLength(char* name)
{
	char* ptr2 = name;
	int number{};

	while (*ptr2 != '\0')
	{
		ptr2++;
		number++;
	}

	return number;
};

int Max(int* mlength, int num)
{
	int* ptr3 = mlength;
	int temp{};
	int maxnum = ptr3[0];
	for (int i = 0; i < num - 1; i++)
	{
		for (int j = i + 1; j < num; j++)
		{
			temp = ptr3[i] > ptr3[j] ? ptr3[i] : ptr3[j];

			if (maxnum <= temp)
			{
				maxnum = temp;
			}
		}
	}

	return maxnum;
};

int main()
{
	int count, maximum{};
	std::cout << "몇 명의 친구가 있나요?" << std::endl;
	std::cin >> count;

	char** array1 = new char* [count];

	for (int i = 0; i < count; i++)
	{
		array1[i] = new char[20];
	}

	int* length = new int[count];

	for (int i = 0; i < count; i++)
	{
		std::cout << "친구 #" << i + 1 << ":";
		std::cin >> array1[i];
	}
	
	for (int i = 0; i < count; i++)
	{
		length[i] = GetLength(array1[i]);
	}

	maximum = Max(length, count);

	for (int i = 0; i < count; i++)
	{
		if (length[i] == maximum)
		{
			std::cout << "이름이 가장 긴 친구는 " << array1[i] << "입니다.";
		}
	}

	for (int i = 0; i < count; i++)
	{
		delete[] array1[i];
	}
	delete[] array1;
	array1 = nullptr;
}