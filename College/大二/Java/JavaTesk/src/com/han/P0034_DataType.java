package com.han;

public class P0034_DataType {
	public static void main(String[] args){
/*	    int a = 10;  //true
	    long b = 10L;  //  ����û��l��Ϊjava����������������ֵ��
	    //Ĭ��Ϊint�ͣ�����long�ͳ�������'l'��'L';
	    double c = 100.23;  //true
	    float d = 100.32F;  //  ͬ��һ����java�ĸ����ͳ�����Ĭ��
	    //Ϊdouble�ͣ�����float�ͳ�������'f'��'F';
*/	    
	    //ʮ��������ʽ���磺5.12 512.0f .512 (������С���㣩
        double num1=.123;
        System.out.println(num1);//�ȼ���0.123
        
        //��ѧ��������ʽ:�磺5.12e2 [5.12 * 10 �� 2 �η� ] 5.12E-2 []
        System.out.println(5.12e2);//512.0
        System.out.println(5.12E-2);//0.0512
        
        //ͨ������£�Ӧ��ʹ�� double �ͣ���Ϊ���� float �͸���ȷ��
		//[����˵��]double num9 = 2.1234567851;float num10 = 2.1234567851F;
		double num9 = 2.1234567851;
		float num10 = 2.1234567851F;
		System.out.println(num9);
		System.out.println(num10);

		
		
		//������ʹ������: 2.7 �� 8.1 / 3 �Ƚ�
		//����һ�δ���
		double num11 = 2.7;
		double num12 = 8.1/3; //8.1 / 3; //2.7
		System.out.println(num11);//2.7
		System.out.println(num12);//�ӽ� 2.7 ��һ��С��������
        //�õ�һ����Ҫ��ʹ�õ�: �����Ƕ���������С���Ľ�������ж��ǣ�ҪС��
        //Ӧ�������������Ĳ�ֵ�ľ���ֵ����ĳ�����ȷ�Χ���ж�
       
        if( num11 == num12) {
		System.out.println("num11 == num12 ���");
		}
		
		//��ȷ��д�� , ���������С��ĳ��ֵ
		if(Math.abs(num11 - num12) < 0.000001 ) {
		System.out.println("��ֵ�ǳ�С�����ҵĹ涨���ȣ���Ϊ���...");
        }
        boolean pass = true;
        if(pass) {
            System.out.println("ture");
        } else {
        	System.out.println("false");
        }
    
        
	}
}