import java.util.Scanner;

public class DataTypes {
    public static void main(String[] args) {
        int a = 10;
        long b = 20;
        short c = 30;
        byte d = 40;

        double e = 20.5;
        float f = 13.5f;

        char g = 'a';
        boolean h = false;

        // System.out.println(i);
        int i;
        // System.out.println(i);
        i = 20;
        System.out.println(i);

        /// int 1i; //not allowed

        int Var;
        int var;

        int j = 10 / 3;
        System.out.println(j);
        j = 10 / 30;
        System.out.println(j);
        j = 3 * 2 / 5;
        System.out.println(j);
        j = 3 * (2 / 5);
        System.out.println(j);
        double k = 10 / 3;
        System.out.println(k);

        int l, m;
        Scanner s = new Scanner(System.in);
        l = s.nextInt();
        m = s.nextInt();
        int o = l + m;
        System.out.println(o);
        double p = s.nextDouble();
        System.out.println(p);
        float q = s.nextFloat();
        System.out.println(q);
        long r = s.nextLong();
        System.out.println(r);

        String str = s.next();
        System.out.println(str);

        String str1 = s.next();
        char ch = str1.charAt(0);
        System.out.println(ch);

        String strr = s.nextLine();
        System.out.println(strr);

    }
}
