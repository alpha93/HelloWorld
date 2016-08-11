import java.util.Random;
import java.util.Scanner;
import java.util.InputMismatchException;

public class Test {
	public static void main(String[] args) throws Exception {
		Random num = new Random();
		Scanner s = new Scanner(System.in);
		System.out.println("-------------------------Enter any key to quit-------------------------");
		
		int counter = 0, correct = 0, wrong = 0;
		long startTime = System.currentTimeMillis();
		
		while(true) {
			int multiplicand = 12+num.nextInt(3); //11 to 20
			int multiplier = 2+num.nextInt(8); //2 to 9
			System.out.print(multiplicand + " x " + multiplier + " = ");
			int ans;
			
			try {
				ans = s.nextInt();
			} catch(Exception e) {
				break;
			}
			
			if(ans == multiplicand*multiplier) {
				System.out.println("---Correct---\n");
				correct++;
			} else {
				System.out.println("---Wrong---- " + multiplicand + " x " + multiplier + " = " + multiplicand*multiplier + "\n");
				wrong++;
			}
			
			counter++;
		}
		
		System.out.println("\nCorrect answers: " + correct + "\tWrong answers: " + wrong);
		System.out.println("Correctness: " + (correct*100)/counter + "%");
		System.out.println("Average time taken: " + (double)(System.currentTimeMillis() - startTime)/(counter*1000) + " seconds");

		s.nextLine();
		s.nextLine();
	}
}
