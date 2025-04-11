#include <stdexcept>
using namespace std;

struct GuessResult {
    bool solved;
    int strikes;
    int balls;
};

class Baseball {
public:
    explicit Baseball(const string& question)
        : question(question) {
    }

    bool isDuplicatedNumber(const string& guessNumber) {
        return guessNumber[0] == guessNumber[1]
            || guessNumber[0] == guessNumber[2]
            || guessNumber[1] == guessNumber[2];
    }

    void assertIllegalArgument(const string& guessNumber) {
        if (guessNumber.length() != 3) {
            throw length_error("Must be three letters.");
        }

        for (char ch : guessNumber) {
            if (ch >= '0' && ch <= '9') continue;
            throw invalid_argument("Mus be number");
        }

        if (isDuplicatedNumber(guessNumber)) {
            throw invalid_argument("Must not have the same number");
        }
    }

    GuessResult guess(const string& guessNumber) {
        assertIllegalArgument(guessNumber);

        if (guessNumber == question) {
            return { CorrectlyAnwser, 3, 0 };
        }

        int strikeCount = getStrikeCount(guessNumber);
        int ballCount = getBallCount(guessNumber);
        return { WrongAnswer, strikeCount, ballCount };
    }

    int getBallCount(const std::string& guessNumber) {
        int result = 0;
        for (int index = 0; index < 3; index++) {
            if (guessNumber[index] == question[index]) continue;
            if (question.find(guessNumber[index]) != string::npos) result++;
        }
        return result;
    }

    int getStrikeCount(const std::string& guessNumber) {
        int strikeCount = 0;
        for (int index = 0; index < 3; index++) {
            if (guessNumber[index] == question[index]) strikeCount++;
        }
        return strikeCount;
    }

private:
    string question;
    static const bool CorrectlyAnwser = true;
    static const bool WrongAnswer = false;
};