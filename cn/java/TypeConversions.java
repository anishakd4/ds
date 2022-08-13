public class TypeConversions {
    public static void main(String[] args) {
        char ch = 'a';
        int i = ch;
        // ch = i; //error
        ch = (char) i;
        // ch = ch + 1; //error
        ch = (char) (ch + 1);
        System.out.println(ch);
        System.out.println(i);

        // float f = 1.7;//error
        float f = (float) 1.7;

        int j = (int) 10.6;
        System.out.println(j);

        short s = 17;
        int k = s;
        // s = k;
        System.out.println(k);

        System.out.println(4 + 4);
        System.out.println(4 + 4.5);
        System.out.println(4.3 + 4.5);
        System.out.println(2 / 5);
        System.out.println(2 / 5.0);
        System.out.println(2.0 / 5.0);
    }
}
