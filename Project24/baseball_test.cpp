#include "gmock/gmock.h"
#include "baseball.cpp"

using namespace testing;

TEST(BaseballGame, TryGameTest) {
	EXPECT_EQ(1, 1);
}

TEST(BaseballGame, ThrowExceptionWhenInputLengthIsUnmached) {
	Baseball game;
	EXPECT_THROW(game.guess(string("12")), std::length_error);
}

int main() {
	::testing::InitGoogleMock();
	return RUN_ALL_TESTS();
}