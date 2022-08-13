package Patterns;
/*
1
2 3
4 5 6
7 8 9 10
11 12 13 14 15
16 17 18 19 20 21
*/

import java.util.Scanner;

public class Pattern6 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();

        int p = 1;
        int i = 1;
        while (i <= n) {
            int j = 1;
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
