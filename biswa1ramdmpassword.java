import java.util.Scanner;

import java.util.Random;

public class RandomPasswordGenerator {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the desired length of the Password: ");
        int length = scanner.nextInt();

        System.out.print("Would you like to include numbers? (y/n): ");
        boolean includeNumbers = scanner.next().equalsIgnoreCase("y");

        System.out.print("Would you like to include lowercase letters? (y/n): ");
        boolean includeLowercase = scanner.next().equalsIgnoreCase("y");

        System.out.print("Would you like to include uppercase letters? (y/n): ");
        boolean includeUppercase = scanner.next().equalsIgnoreCase("y");

        System.out.print("Would you like to include special characters? (y/n): ");
        boolean includeSpecialChars = scanner.next().equalsIgnoreCase("y");

        String password = generateRandomPassword(length, includeNumbers, includeLowercase, includeUppercase, includeSpecialChars);
        System.out.println("Your Generated Password is: " + password);

        scanner.close();

    }

    public static String generateRandomPassword(int length, boolean includeNumbers, boolean includeLowercase, boolean includeUppercase, boolean includeSpecialChars) {

        String lowercaseChars = "abcdefghijklmnopqrstuvwxyz";
        String uppercaseChars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        String numberChars = "0123456789";
        String specialChars = "!@#$%^&*()_-+=<>?";

        String allChars = "";
        if(includeLowercase) allChars += lowercaseChars;
        if(includeUppercase) allChars += uppercaseChars;
        if(includeNumbers) allChars += numberChars;
        if(includeSpecialChars) allChars += specialChars;

        Random random = new Random();
        StringBuilder password = new StringBuilder();

        for(int i = 0; i < length; i++) {
            int randomIndex = random.nextInt(allChars.length());
            password.append(allChars.charAt(randomIndex));

        }

        return  password.toString();

    }

}
