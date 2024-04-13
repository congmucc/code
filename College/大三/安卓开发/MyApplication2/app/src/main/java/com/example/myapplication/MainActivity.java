package com.example.myapplication;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);


        // 获取实验二的id
        Button e2 = findViewById(R.id.e2);
        // 进行按钮监控
        e2.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                startActivity(new Intent(MainActivity.this, MainActivity2.class));
            }
        });
        Button e3 = findViewById(R.id.e3);
        e3.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                startActivity(new Intent(MainActivity.this, MainActivity3.class));
            }
        });
        Button e4 = findViewById(R.id.e4);
        e4.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                startActivity(new Intent(MainActivity.this, MainActivity4.class));
            }
        });
        Button e5 = findViewById(R.id.e5);
        e5.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                startActivity(new Intent(MainActivity.this, MainActivity5.class));
            }
        });
        Button e6 = findViewById(R.id.e6);
        e6.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                startActivity(new Intent(MainActivity.this, MainActivity6.class));
            }
        });
        Button e7_1 = findViewById(R.id.e7_1);
        e7_1.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                startActivity(new Intent(MainActivity.this, MainActivity7_1.class));
            }
        });
        Button e7_2 = findViewById(R.id.e7_2);
        e7_2.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                startActivity(new Intent(MainActivity.this, MainActivity7_2.class));
            }
        });
        Button e8_1 = findViewById(R.id.e8_1);
        e8_1.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                startActivity(new Intent(MainActivity.this, MainActivity8_1.class));
            }
        });
        Button e8_2 = findViewById(R.id.e8_2);
        e8_2.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                startActivity(new Intent(MainActivity.this, MainActivity8_2.class));
            }
        });
        Button e9_1 = findViewById(R.id.e9_1);
        e9_1.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                startActivity(new Intent(MainActivity.this, MainActivity9_1.class));
            }
        });
        Button e9_2 = findViewById(R.id.e9_2);
        e9_2.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                startActivity(new Intent(MainActivity.this, MainActivity9_2.class));
            }
        });
        Button e9_3 = findViewById(R.id.e9_3);
        e9_3.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                startActivity(new Intent(MainActivity.this, MainActivity9_3.class));
            }
        });
        Button e10_1 = findViewById(R.id.e10_1);
        e10_1.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                startActivity(new Intent(MainActivity.this, MainActivity10_1.class));
            }
        });

        Button e11_1 = findViewById(R.id.e11_1);
        e11_1.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                startActivity(new Intent(MainActivity.this, MainActivity11_1.class));
            }
        });

        Button e11_2 = findViewById(R.id.e11_2);
        e11_2.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                startActivity(new Intent(MainActivity.this, MainActivity11_2.class));
            }
        });

        Button e11_3 = findViewById(R.id.e11_3);
        e11_3.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                startActivity(new Intent(MainActivity.this, MainActivity11_3.class));
            }
        });


        Button e12_1 = findViewById(R.id.e12_1);
        e12_1.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                startActivity(new Intent(MainActivity.this, MainActivity12_1.class));
            }
        });
        Button e12_2 = findViewById(R.id.e12_2);
        e12_2.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                startActivity(new Intent(MainActivity.this, MainActivity12_2.class));
            }
        });

    }
}