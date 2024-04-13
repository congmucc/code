package com.han.p0580_Thread;

public class P0585_Thread {
    public static void main(String[] args) {
        // T1 t1 = new T1();
        // T2 t2 = new T2();
        // Thread thread1 = new Thread(t1);
        // Thread thread2 = new Thread(t2);
        // thread1.start();
        // thread2.start();

        T3 t3 = new T3("С��");
        T3 t4 = new T3("Сè");
        Thread thread3 = new Thread(t3);
        Thread thread4 = new Thread(t4);
        thread3.start();
        thread4.start();

    }
}

// ���дһ�����򣬴��������̣߳�һ���߳�ÿ��1���������hello��world�������10�Σ��˳���
// һ���߳�ÿ��1�������hi�������5���˳�
// class T1 implements Runnable {
//     @Override
//     public void run() {
//         int temp = 0;
//         while (true) {
//             System.out.println("hello, world" + (++temp));
//             try {
//                 Thread.sleep(1000);
//             } catch (InterruptedException e) {
//                 throw new RuntimeException(e);
//             }
//             if (temp == 10) break;
//         }
//     }
// }


// class T2 implements Runnable {
//     @Override
//     public void run() {
//         int temp = 0;
//         while (true) {
//             System.out.println("hi" + (++temp));
//             try {
//                 Thread.sleep(1000);
//             } catch (InterruptedException e) {
//                 throw new RuntimeException(e);
//             }
//             if (temp == 5) break;
//         }
//     }
// }


class T3 implements Runnable {
    private String name;
    T3 (String name) {
        this.name = name;
    }
    @Override
    public void run() {
        int temp = 0;
        while (true) {
            System.out.println(this.name + (++temp));
            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                throw new RuntimeException(e);
            }
            if (temp == 10) break;
        }
    }
}