/* Simple Quiz Game with Multiple-Choice Questions, Score Tracking, and Feedback in C++ */
#include <iostream>
#include <vector>
#include <string>

struct Question {
    std::string question;
    std::vector<std::string> choices;
    char answer;
};

class QuizGame {
public:
    QuizGame() {
        // Initialize the questions
        questions = {
            {"What is the capital of France?", {"A. London", "B. Berlin", "C. Paris", "D. Madrid"}, 'C'},
            {"Which planet is known as the Red Planet?", {"A. Earth", "B. Mars", "C. Jupiter", "D. Venus"}, 'B'},
            {"Who wrote 'To Kill a Mockingbird'?", {"A. Harper Lee", "B. Mark Twain", "C. J.K. Rowling", "D. Ernest Hemingway"}, 'A'}
        };
        score = 0;
    }

    void play() {
        std::cout << "Welcome to the Quiz Game!" << std::endl;
        std::cout << "For each question, type the letter of the correct answer." << std::endl;
        std::cout << "Let's get started!\n" << std::endl;

        for (size_t i = 0; i < questions.size(); ++i) {
            std::cout << "Question " << i + 1 << ": " << questions[i].question << std::endl;
            for (const auto& choice : questions[i].choices) {
                std::cout << choice << std::endl;
            }

            char answer;
            std::cout << "Your answer: ";
            std::cin >> answer;
            answer = toupper(answer);

            if (answer == questions[i].answer) {
                std::cout << "Correct!" << std::endl;
                ++score;
            } else {
                std::cout << "Wrong! The correct answer is " << questions[i].answer << "." << std::endl;
            }

            std::cout << std::endl;
        }

        std::cout << "You scored " << score << " out of " << questions.size() << "." << std::endl;
    }

private:
    std::vector<Question> questions;
    int score;
};

int main() {
    QuizGame quizGame;
    quizGame.play();
    return 0;
}
