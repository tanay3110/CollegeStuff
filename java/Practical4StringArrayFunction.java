public class Practical4StringArrayFunction {
    public static void main(String[] args) {
        // String Operations
        String str1 = "Hello";
        String str2 = "World";
        System.out.println("Concatenation: " + str1 + " " + str2);
        System.out.println("Length of str1: " + str1.length());
        System.out.println("Uppercase: " + str1.toUpperCase());
        System.out.println("Lowercase: " + str2.toLowerCase());

        // Array Operations
        int[] numbers = {10, 20, 30, 40, 50};
        System.out.println("Array Elements:");
        for (int num : numbers) {
            System.out.println(num);
        }

        // Function Call
        int sumResult = addNumbers(5, 10);
        System.out.println("Sum of 5 and 10: " + sumResult);

    }

    public static int addNumbers(int first, int second) {
        return first + second;
    }
}
