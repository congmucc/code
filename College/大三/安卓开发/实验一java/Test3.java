public class Test3 {
    public static void main(String[] args) {
        char[] alphabets = new char[26];
        for (int i = 0; i < alphabets.length; i++) {
            alphabets[i] = (char) ('a' + i);
        }
        for (char alphabet : alphabets) {
            System.out.print(alphabet + " ");
        }
    }
}
