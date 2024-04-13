package com.example.myapplication;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.Toast;

import androidx.appcompat.app.AppCompatActivity;

public class MainActivity3 extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main3);
        Button e3_button_cancel = findViewById(R.id.e3_button_cancel);
        Button e3_button_confirm = findViewById(R.id.e3_button_confirm);
        e3_button_cancel.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                startActivity(new Intent(MainActivity3.this, MainActivity11_2.class));
            }
        });
        e3_button_confirm.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                showToast("这个功能还没有写");
            }
        });
    }
    private void showToast(String message) {
        Toast.makeText(getApplicationContext(), message, Toast.LENGTH_SHORT).show();
    }
}