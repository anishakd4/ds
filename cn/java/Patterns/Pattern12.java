
/*
    1
   121
  12321
 1234321
123454321
 */
import java.util.Scanner;

public class Pattern12 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();

        int i = 1;
        while (i <= n) {
            int spaces = 1;
            while (spaces <= n - i) {
                System.out.print(' ');
                spaces++;
            }
            int stars = 1;
            while (stars <= i) {
                System.out.print(stars);
                stars++;
            }
            stars = i - 1;
            while (stars >= 1) {
                System.out.print(stars);
                stars--;
            }
            System.out.println();
            i++;
        }
    }
}
