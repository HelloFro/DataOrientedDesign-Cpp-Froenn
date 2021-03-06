#include "pch.h"

#include <chrono>
#include <random>
#include <vector>

//#include "DataCollector.h"
#include "DataToExcel.h"

int randValue()
{
	static std::random_device seed;
	static std::mt19937 eng(seed());
	std::uniform_int_distribution<> const dis(0, 256);

	return dis(eng);
}

int main()
{
	std::vector<unsigned char> v;

	auto const N{ 250 };

	for (auto i{ 0 }; v.size() != N*N; ++i)
	{
		v.push_back(randValue());

		int const s = sqrt(v.size()); //intentional non-braced initialization

		if (s*s == v.size())
		{
			for (auto T{ 0 }; T != 255; ++T) //See: README.md about T
			{
				auto traversal{ true }; //true -> Row , false -> Column
				auto start{ std::chrono::steady_clock::now() };
				auto count{ 0 };

				for (auto && r: v) //row order traversal
					if (r > T)
						++count;

				auto end{ std::chrono::steady_clock::now() };
				std::chrono::duration<double, std::milli> elapsed_seconds{ end - start };

				//DataCollector(s, T, count, traversal, elapsed_seconds); //For my purposes
				DataToExcel(s, elapsed_seconds, traversal);

				start = std::chrono::steady_clock::now();
				count = 0;
				traversal = false;

				for (auto r{ 0 }; r < s; ++r) //column order traversal
					for (auto c{ r }; c < s*s; c += s)
						if (v[c] > T)
							++count;
				
				end = std::chrono::steady_clock::now();
				elapsed_seconds = end - start;

				//DataCollector(s, T, count, traversal, elapsed_seconds);
				DataToExcel(s, elapsed_seconds, traversal);
			}
		}
	}
}
