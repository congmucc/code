import java.util.Scanner;
public class Test2 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("请输入您的工资：");
        double salary = scanner.nextDouble();

        double increasedSalary = 0;

        if (salary >= 3000) {
            increasedSalary = salary + salary * 0.10;
        } else if (salary < 3000 && salary >= 2000) {
            increasedSalary = salary + salary * 0.15;
        } else if (salary < 2000) {
            increasedSalary = salary + salary * 0.20;
        }

        System.out.println("调整后的工资为: " + increasedSalary);
    }
}
