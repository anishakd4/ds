
/*  
*****
****
***
**
*
*/
import java.util.Scanner;

public class Pattern11 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();

        int i = 1;
        while (i <= n) {
            int stars = 1;
            while (stars <= n - i + 1) {
                System.out.print('*');
                stars++;
            }
            System.out.println();
            i++;
        }
    }
}
