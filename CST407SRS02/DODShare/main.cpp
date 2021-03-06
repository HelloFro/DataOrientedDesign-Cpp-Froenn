#include "pch.h"

#include <future>
#include <random>

#include "DataToExcelThreaded.h"

int randValue()
{
	static std::random_device seed;
	static std::mt19937 eng(seed());
	std::uniform_int_distribution<> const dis(0, 256);

	return dis(eng);
}

int main()
{
	auto const N{ 250 };
	auto const T{ 63 };

	std::vector<unsigned char> v;

	auto fRow = [](std::vector<unsigned char> &v, int row, int T, int currN)
	{
		auto count{ 0 };
		for (auto i{ row }; i < row + currN; ++i)
			if (v[i] > T)
				++count;
		return count;
	};

	for (auto i{ 0 }; i != N*N; ++i)
		v.push_back(randValue());

	for (auto j{ 0 }; j < N; ++j)
	{
		auto const start{ std::chrono::steady_clock::now() };

		std::vector<std::future<int>> futures;
		auto count{ 0 };

		for (auto k{ 0 }; k < j*j - j; k += j)
			futures.push_back(std::async(fRow, std::ref(v), k, T, j));

		for (auto && c : futures)
			count += c.get();

		auto const end{ std::chrono::steady_clock::now() };
		std::chrono::duration<double, std::milli> const elapsed_seconds{ end - start };

		DataToExcelThreaded(j, elapsed_seconds);
	}
}