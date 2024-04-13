package com.example.myapplication;

import android.os.Bundle;
import android.view.View;
import android.widget.Button;

import androidx.appcompat.app.AppCompatActivity;

public class MainActivity6 extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main6);
        Button btn_6_1 = findViewById(R.id.btn_6_1);
        Button btn_6_2 = findViewById(R.id.btn_6_2);
        btn_6_1.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                btn_6_1.setVisibility(View.INVISIBLE);
                btn_6_2.setVisibility(View.VISIBLE);
            }
        });

        btn_6_2.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                btn_6_2.setVisibility(View.INVISIBLE);
                btn_6_1.setVisibility(View.VISIBLE);
            }
        });
    }
}