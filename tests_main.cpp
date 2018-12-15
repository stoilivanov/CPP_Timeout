#include "Timeout.h"

#include <chrono>
#include <thread>

#include <gtest/gtest.h>


TEST(TIMEOUT, TestTimeOut) {
	sivanov::Timeout Timeout;

	bool key = false;

	Timeout([&]()
	{
		key = true;
	}, 3);

	std::this_thread::sleep_for(std::chrono::milliseconds(3050));

	EXPECT_TRUE(key);
}

TEST(TIMEOUT, TestWaitMember) {
	sivanov::Timeout Timeout;

	bool key = false;

	Timeout([&]()
	{
		key = true;
	}, 3);

	Timeout.wait();

	EXPECT_TRUE(key);
}
