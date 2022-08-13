
/*
ABCD
ABCD
ABCD
ABCD
*/
import java.util.Scanner;

public class Pattern8 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int n = scanner.nextInt();

        int i = 1;
        while (i <= n) {
            int j = 0;
            while (j < n) {
                char c = (char) ('A' + j);
                System.out.print(c);
                j++;
            }
            System.out.println();
            i++;
        }
    }
}
