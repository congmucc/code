package com.han;

public class P0200_Person {
    public static void main(String[] args) {
        Person a = new Person();
        a.personAge = 10;
        a.personName = "С��";
        Person b;
        b = a;
        System.out.println("a.personAge = " + a.personAge);
        b.personAge = 15;
        System.out.println("a.personAge = " + a.personAge);
        b = null;
        System.out.println("a.personAge = " + a.personAge);
        System.out.println("b.personAge = " + b.personAge);

        //�����ԭ����b = null  java����� = �������Ϊָ�룬��ʱ��Ϊb����ֱ��new������
        //�ڶ���û�пռ� ����˵����b = a ֮��  b��aһ��ָ��a���ٵĶ����ռ�  ����˵b.personAge = 15
        //ʹ��a.personAge = 15    ֮��b = null,���Ϊb����ָ����� ����˵����
    }
}


class Person {
    String personName;
    int personAge;
}