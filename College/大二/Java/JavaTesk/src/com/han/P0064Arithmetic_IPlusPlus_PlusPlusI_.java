package com.han;

public class P0064Arithmetic_IPlusPlus_PlusPlusI_ {
    public static void main(String[] args) {

         int i = 1;//i->1
         i = i++; //����ʹ����ʱ����: (1) temp=i;(2) i=i+1;(3)i=temp;
         System.out.println(i); // 1
         int j=1;
         j=++j; //����ʹ����ʱ����: (1) i=i+1;(2) temp=i;(3)i=temp;
         System.out.println(j); //2
    }
}
