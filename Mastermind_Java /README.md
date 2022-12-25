<h1>Welcome to My Mastermind<h1>
<h2>Task</h2>
Mastermind is a code-breaking game where the player has to guess a four-digit code. In this implementation, the player has 10 attempts to guess the code, and after each guess, the player is given feedback on how many digits they have guessed correctly and how many are in the correct position.

<h2>Description</h2>
The Mastermind class contains a main method that calls the startGame method, which in turn calls the codeGenerator method to generate a random four-digit code. The startGame method then prompts the user for their guess and calls the userInput and checkGuess methods to process the input and check if any of the digits are correct. The game continues until the player either guesses the code correctly or runs out of attempts.

<h2>Installation</h2>
To run this program, you will need to have the Java Development Kit (JDK) installed on your system. You can then clone or download the Mastermind.java file and compile and run it using the following commands in the terminal:
<code>
javac Mastermind.java
java Mastermind
</code>

<h2>Usage</h2>
When you run the Mastermind program, you will be prompted to enter your guess. Your guess should be a four-digit number, with each digit being a number between 0 and 9 (inclusive). After you enter your guess, you will receive feedback on how many digits you have guessed correctly and how many are in the correct position. The game will continue until you either guess the code correctly or run out of attempts.
