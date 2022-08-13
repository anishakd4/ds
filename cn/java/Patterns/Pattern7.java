package Patterns;

/*
1
2 3
3 4 5
4 5 6 7
*/
import java.util.Scanner;

public class Pattern7 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();

        int i = 1;
        while (i <= n) {
            int j = 1;
            int p = i;
            while (j <= i) {
                System.out.print(p + " ");
                p++;
                j++;
            }
            System.out.println();
            i++;
        }
    }
}
