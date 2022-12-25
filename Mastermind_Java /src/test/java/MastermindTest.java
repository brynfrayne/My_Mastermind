import java.util.Scanner;
import static org.junit.Assert.*;
import org.junit.Test;

import Mastermind;

public class MastermindTest {

    @Test
    public void testCodeGenerator() {
        // Call the codeGenerator() method and store the result in a variable
        int[] code = Mastermind.codeGenerator();

        // Verify that the code has 4 elements
        assertEquals(4, code.length);

        // Verify that each element of the code is between 0 and 9
        for (int i = 0; i < 4; i++) {
            assertTrue(code[i] >= 0 && code[i] <= 9);
        }
    }

    @Test
    public void testUserInput() {
        // Create a Scanner object with a predefined input
        Scanner input = new Scanner("1234\n");

        // Call the userInput() method and store the result in a variable
        int[] guess = Mastermind.userInput(input);

        // Verify that the guess has 4 elements
        assertEquals(4, guess.length);

        // Verify that each element of the guess is the expected value
        for (int i = 0; i < 4; i++) {
            assertEquals(i + 1, guess[i]);
        }
    }

    @Test
    public void testCheckGuess() {
        // Create an array with the code
        int[] code = {1, 2, 3, 4};

        // Test a correct guess
        assertTrue(Mastermind.checkGuess(1, code));

        // Test an incorrect guess
        assertFalse(Mastermind.checkGuess(5, code));
    }
}
