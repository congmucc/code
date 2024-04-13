package com.example.myapplication;

import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

import androidx.appcompat.app.AppCompatActivity;

public class MainActivity12_1 extends AppCompatActivity {
        private EditText etUsername;
        private EditText etPassword;
        private Button btnLogin;

        @Override
        protected void onCreate(Bundle savedInstanceState) {
            super.onCreate(savedInstanceState);
            setContentView(R.layout.activity_main12_1);

            etUsername = findViewById(R.id.et_username);
            etPassword = findViewById(R.id.et_password);
            btnLogin = findViewById(R.id.btn_login);

            btnLogin.setOnClickListener(new View.OnClickListener() {
                @Override
                public void onClick(View v) {
                    String username = etUsername.getText().toString();
                    String password = etPassword.getText().toString();

                    if (username.equals("zhangsan") && password.equals("123")) {
                        Toast.makeText(MainActivity12_1.this, "登录成功", Toast.LENGTH_SHORT).show();
                    } else {
                        Toast.makeText(MainActivity12_1.this, "登录失败", Toast.LENGTH_SHORT).show();
                    }
                }
            });
        }
    }