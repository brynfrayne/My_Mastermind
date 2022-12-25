import java.util.Scanner;

public class Mastermind {

    public static void main(String[] args) {
        startGame();
    }

    public static int[] codeGenerator() {
        int[] code = new int[4];
        for (int i = 0; i < 4; i++) {
            int random = (int) (Math.random() * 9);
            code[i] = random;
        }
        return code;
    }

    public static int[] userInput(Scanner input) {
        int[] guess = new int[4];
        String line = input.nextLine();
        String[] numbers = line.split("");

        for (int i = 0; i < 4; i++) {
            guess[i] = Integer.parseInt(numbers[i]);
        }
        return guess;
    }

    public static boolean checkGuess(int guess, int[] code) {
        for (int i = 0; i < 4; i++) {
            if (guess == code[i]) {
                return true;
            }
        }
        return false;
    }

    public static void startGame() {
        int[] code = codeGenerator();
        // System.out.println("This is the code: " + code[0] + code[1] + code[2] + code[3]); --- this is for testing purposes
        int attempts = 0;
        int rounds = 10;
        Scanner input = new Scanner(System.in);
        System.out.println("\nWelcome to Mastermind!");

        while (attempts < rounds) {
            int correctPosition = 0;
            int wrongPosition = 0;
            System.out.println("\nYou have " + (rounds - attempts) + " attempts left.");
            System.out.println("Please enter your guess: ");

            int[] guess = userInput(input);
            for (int i = 0; i < 4; i++) {

                if (guess[i] == code[i]) {
                    correctPosition++;
                } else if (checkGuess(guess[i], code)) {
                    wrongPosition++;
                }
            }
            if (correctPosition == 4) {
                System.out.println("You have guessed the code!");
                input.close();
                return;
            }
            System.out.println("\nYou have guessed " + correctPosition + " pieces in the correct position and " + wrongPosition + " pieces in the wrong position.");
            attempts++;
        }
        input.close();
        System.out.println("You have used all your attempts. The code was: " + code[0] + code[1] + code[2] + code[3]);
    }
}

