#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

struct Question {
    string question;
    vector<string> options;
    int correctOption;
};

struct User {
    string name;
    int score = 0;
};

void displayQuestions(const vector<Question>& questions, User& user) {
    int questionNumber = 1;
    vector<int> userAnswers;
    
    cout << "\nHello, " << user.name << "! Let's start the quiz.\n\n";

    for (const auto& q : questions) {
        cout << "Question " << questionNumber++ << ": " << q.question << endl;

        for (size_t i = 0; i < q.options.size(); ++i) {
            cout << i + 1 << ". " << q.options[i] << endl;
        }

        int answer;
        while (true) {
            cout << "Your answer (1-" << q.options.size() << "): ";
            cin >> answer;
            if (answer >= 1 && answer <= (int)q.options.size()) {
                break;
            } else {
                cout << "Invalid option. Try again.\n";
            }
        }

        userAnswers.push_back(answer);
        if (answer == q.correctOption) {
            user.score += 10; // Assign 10 points for a correct answer
        }
    }

    cout << "\nQuiz Completed! Here are the correct answers:\n\n";

    // Display correct answers
    questionNumber = 1;
    for (size_t i = 0; i < questions.size(); ++i) {
        cout << "Question " << questionNumber++ << ": " << questions[i].question << endl;
        cout << "Correct Answer: " << questions[i].options[questions[i].correctOption - 1] << endl;
        cout << "Your Answer: " << questions[i].options[userAnswers[i] - 1] 
             << (userAnswers[i] == questions[i].correctOption ? " (Correct)" : " (Wrong)") << endl;
        cout << endl;
    }

    cout << "Your final score: " << user.score << " points.\n";
}

int main() {
    vector<Question> questions = {
        {"What is the capital of India?", {"Kolkata", "Mumbai", "Delhi", "Pune"}, 1},
        {"Which planet is known as the Red Planet?", {"Earth", "Mars", "Jupiter", "Venus"}, 2},
        {"Who wrote 'Romeo and Juliet'?", {"William Shakespeare", "Charles Dickens", "Mark Twain", "Jane Austen"}, 1},
        {"What is the largest ocean on Earth?", {"Atlantic Ocean", "Indian Ocean", "Pacific Ocean", "Arctic Ocean"}, 3},
        {"What is the square root of 64?", {"6", "7", "8", "9"}, 3}
    };

    User user;

    cout << "Welcome to the Quiz Game!\n";
    cout << "Enter your name: ";
    getline(cin, user.name);

    displayQuestions(questions, user);

    cout << "\nThank you for playing, " << user.name << "! See you next time.\n";

    return 0;
}
