#include "pch.h"
#include "CppUnitTest.h"
#include "../main-proj/utils.h"
#include "../main-proj/file_reader.h"
#include "../main-proj/utils.cpp"
#include "../main-proj/file_reader.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:

		TEST_METHOD(TestSecondsToTime)
		{
			Assert::AreEqual(std::string("02:00:00"), seconds_to_time(7200));
			Assert::AreEqual(std::string("00:00:00"), seconds_to_time(0));
			Assert::AreEqual(std::string("01:01:01"), seconds_to_time(3661));
		}

		TEST_METHOD(TestReadDataAndConversion)
		{
			// временный файл с тестовыми данными
			std::ofstream testFile("test_input.txt");
			testFile << "1 Иванов Пётр Сидорович 08:00:00 10:30:00 Спартак\n";
			testFile << "2 Сидорова Анна Ивановна 08:05:00 10:55:00 Локомотив\n";
			testFile.close();

			std::vector<Participant> data = read_data("test_input.txt");

			Assert::AreEqual((size_t)2, data.size());

			Assert::AreEqual(std::string("Иванов"), data[0].surname);
			Assert::AreEqual(std::string("Пётр"), data[0].name);
			Assert::AreEqual(std::string("Спартак"), data[0].club);
			Assert::AreEqual(9000, data[0].result_seconds); // 2 ч 30 мин

			Assert::AreEqual(std::string("Сидорова"), data[1].surname);
			Assert::AreEqual(10200, data[1].result_seconds); // 2 ч 50 мин
		}

		TEST_METHOD(TestSpartakFilter)
		{
			std::vector<Participant> participants = {
				{"Иванов", "Пётр", "Спартак", 9000},
				{"Сидорова", "Анна", "Локомотив", 10200},
				{"Петров", "Алексей", "Спартак", 9900}
			};

			// перехватываем вывод
			std::ostringstream oss;
			std::streambuf* oldCout = std::cout.rdbuf(oss.rdbuf());

			print_spartak(participants);
			std::cout.rdbuf(oldCout);

			std::string output = oss.str();
			Assert::IsTrue(output.find("Иванов Пётр") != std::string::npos);
			Assert::IsTrue(output.find("Петров Алексей") != std::string::npos);
			Assert::IsTrue(output.find("Сидорова Анна") == std::string::npos);
		}

		TEST_METHOD(TestBestTimeFilter)
		{
			std::vector<Participant> participants = {
				{"Иванов", "Пётр", "Спартак", 9000},
				{"Сидорова", "Анна", "Локомотив", 10200},
				{"Петров", "Алексей", "Спартак", 10000}
			};

			std::ostringstream oss;
			auto* old = std::cout.rdbuf(oss.rdbuf());

			print_best_time(participants);
			std::cout.rdbuf(old);

			std::string output = oss.str();
			Assert::IsTrue(output.find("Иванов Пётр") != std::string::npos);
			Assert::IsTrue(output.find("Петров Алексей") != std::string::npos);
			Assert::IsTrue(output.find("Сидорова Анна") == std::string::npos);
		}
	};
}
