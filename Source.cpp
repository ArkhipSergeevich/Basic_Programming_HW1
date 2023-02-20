#include <iostream>
#include <fstream>
#include <string>
int main()
{
	int N, M;
	std::ifstream input;
	std::ofstream output;
	input.open("in.txt");
	output.open("out.txt");
	setlocale(LC_ALL, "Russian");
	if (input.is_open())
	{
		input >> N;
		int* arr1 = new int[N];
		for (int i = 0; i < N; i++) //чтение из файла и запись в массив1 в нужном порядке ст. 15-25
		{
			if (i != 0)
			{
				input >> arr1[i - 1];
			}
			else
			{
				input >> arr1[N-1];
			}	
		}
		input >> M;
		int* arr2 = new int[M];
		for (int i = 0; i < M; i++) //чтение из файла и запись в массив2 в нудном порядке ст. 28-38
		{
			if (i + 1 < M)
			{
				input >> arr2[i + 1];
			}
			else
			{
				input >> arr2[M - 1 - i];
			}
		}
		input.close();
		output << M << "\n"; //запись в файл количества элементов массива2 и самого массива2 ст. 41-45
		for (int i = 0; i < M; i++)
		{
			output << arr2[i] << " ";
		}
		output << "\n" << N << "\n"; //запись в файл количества элементов массива1 и самого массива1 ст. 46-50
		for (int i = 0; i < N; i++)
		{
			output << arr1[i] << " ";
		}
		output.close();
		delete[] arr1;
		delete[] arr2;
	}
}