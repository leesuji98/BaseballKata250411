#include "gmock/gmock.h"
#include "baseball.cpp"
#include <iostream>

using namespace testing;

class BaseballFixture : public Test {
public:
	Baseball game{"123"};
	void assertIllegalArgument(string guessNumber) {
		try {
			game.guess(guessNumber);
			FAIL();
		}
		catch (exception e) {
			//PASS
		}
	}
};

TEST_F(BaseballFixture, ThrowExceptionWhenInvalidCase) {
	assertIllegalArgument("12");
	assertIllegalArgument("12s");
	assertIllegalArgument("121");
}

TEST_F(BaseballFixture, MatchedNumber) {
	Baseball game("123");
	GuessResult result = game.guess("456");

	EXPECT_FALSE(result.solved);
	EXPECT_EQ(0, result.strikes);
	EXPECT_EQ(0, result.balls);
}

int main() {
	::testing::InitGoogleMock();
	return RUN_ALL_TESTS();
}