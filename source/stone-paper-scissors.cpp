// stone-paper-scissor.cpp
// A game of stone, paper and scissor - pitting you
// against the computer. Enjoy!

using namespace std;

// Includes standard libraries.
#include <string>
#include <cstring>
#include <iostream>

// Define colors so they can be used to prettify output.
const std::string red("\033[1;31m");
const std::string green("\033[0;32m");
const std::string yellow("\033[0;33m");
const std::string blue("\033[1;34m");
const std::string magenta("\033[0;35m");
const std::string cyan("\033[1;36m");
const std::string reset("\033[0m");

// Defines the values that denote stone, paper and scissor
// in the game.
const int STONE = 1;
const int PAPER = 2;
const int SCISSORS = 3;

// Defines messages that might be printed to the console
// during the game.
const char* banner = "\n░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n░█▀▀░▀█▀░█▀█░█▀█░█▀▀░░░█▀█░█▀█░█▀█░█▀▀░█▀▄░░░█▀▀░█▀▀░▀█▀░█▀▀░█▀▀░█▀█░█▀▄░█▀▀░\n░▀▀█░░█░░█░█░█░█░█▀▀░░░█▀▀░█▀█░█▀▀░█▀▀░█▀▄░░░▀▀█░█░░░░█░░▀▀█░▀▀█░█░█░█▀▄░▀▀█░\n░▀▀▀░░▀░░▀▀▀░▀░▀░▀▀▀░░░▀░░░▀░▀░▀░░░▀▀▀░▀░▀░░░▀▀▀░▀▀▀░▀▀▀░▀▀▀░▀▀▀░▀▀▀░▀░▀░▀▀▀░\n░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n\n";
const char* start_message = "> Great! The three rounds of the game will now begin.\n> Good luck!\n";
const char* win_message = "* You won this round - yum yum gee gee!\n";
const char* lose_message = "* You lost this round - ff :/\n";
const char* tie_message = "* This round ended in a draw!\n";
const char* computer_move_message = "> The computer played ";
const char* score_message = "> Well played! Your score (out of 3) is ";
const char* invalid_move_error = "! Please enter a valid move.\n";
const char* username_prompt = "• Enter a username: ";
const char* move_prompt = "• Enter your move (stone/paper/scissor): ";

// The main function that acts as an entrypoint for the program.
int main() {
	// Setup the random number generator with a random seed.
	// We do not need a cryptographically secure random number, so
	// we can seed it with the current time.
	srand((unsigned) time(0));

	// The username of the user, against which to store the score.
	string username;
	int score = 0;

	// Print out the banner and ask the user to pick a username.
	cout << blue << banner << reset;
	cout << cyan << username_prompt << reset;
	// Accept the input and store it as their username.
	cin >> username;

	// Print out the start message, and begin the game.
	cout << "\n" << green << start_message << reset << "\n";

	// Play 3 rounds with the user (best of 3).
	int rounds = 3;
	while (rounds > 0) {
		// The user's move in this round.
		string move;

		// Generate the computer's move, and initialise a variable to hold
		// the user's move.
		int computer_move = 1 + rand() % 3;
		int user_move = 0;

		string computer_move_string;
		if (computer_move == STONE) computer_move_string = "stone";
		if (computer_move == PAPER) computer_move_string = "paper";
		if (computer_move == SCISSORS) computer_move_string = "scissors";

		// Ask the user to enter their move.
		cout << cyan << move_prompt << reset;
		cin >> move;
		// Check if the move is valid.
		if (strcmp(move.c_str(), "stone") == 0) {
			user_move = STONE;
		} else if (strcmp(move.c_str(), "paper") == 0) {
			user_move = PAPER;
		} else if (strcmp(move.c_str(), "scissors") == 0 || strcmp(move.c_str(), "scissor") == 0) {
			user_move = SCISSORS;
		} else {
			// Ask them to enter a valid move.
			cout << red << invalid_move_error << reset;
			continue;
		}

		// Tell the user which move the computer played.
		cout << blue << computer_move_message << computer_move_string << ".\n" << reset;

		// Check who won the round.
		if (user_move == computer_move) {
			score++;
			cout << yellow << tie_message << reset;
		} else if (
		     user_move == STONE && computer_move == SCISSORS
		  || user_move == PAPER && computer_move == STONE
		  || user_move == SCISSORS && computer_move == PAPER
		) {
			score++;
			cout << green << win_message << reset;
		} else {
			cout << red << lose_message << reset;
		}

		cout << "\n";

		// Move on to play the next round.
		rounds--;
	}

	// Print out their final score.
	cout << blue << score_message << score << ".\n" << reset;

	// Good bye :]
	cout << "\n";
	return 0;
}
