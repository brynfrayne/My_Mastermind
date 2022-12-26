<h1>Mastermind</h1>

<h2>Task</h2>
The task of this project is to implement the classic game of Mastermind. The user will have to guess the secret code, which consists of four integers between 1 and 7. The user will have ten attempts to guess the code correctly.

<h2>Description</h2>
The project is written in C and consists of a main function that handles the gameplay and several helper functions to validate user input, generate the secret code, and check the user's guess against the secret code.

<h2>Installation</h2>
To install the project, follow these steps:

Clone the repository: git clone https://github.com/[USERNAME]/my_mastermind.git
Navigate to the project directory: cd my_mastermind
Compile the project: make

<h2>Usage</h2>
To start the game, run the following command:

<code>
./my_mastermind
</code>

You can also specify the secret code and the number of rounds with the following flags:

<code>
./my_mastermind -c [SECRET CODE] -t [ROUNDS]
</code>

For example:

<code>
./my_mastermind -c 1234 -t 5
</code>

This will set the secret code to 1234 and the number of rounds to 5.

To make a guess, enter a string of four integers between 1 and 7. For example:

1234

The game will then inform you of how many numbers you guessed correctly and in the correct position, and how many numbers you guessed correctly but in the wrong position.

If you guess the secret code correctly, the game will end and inform you of your victory. If you use all your attempts and do not guess the secret code, the game will end and reveal the secret code to you.

You can also exit the game at any time by pressing CTRL + D.
