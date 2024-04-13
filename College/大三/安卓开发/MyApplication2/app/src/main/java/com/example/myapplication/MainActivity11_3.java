package com.example.myapplication;

import androidx.appcompat.app.AppCompatActivity;
import androidx.drawerlayout.widget.DrawerLayout;
import androidx.fragment.app.FragmentManager;
import androidx.fragment.app.FragmentTransaction;

import android.os.Bundle;
import android.view.View;
import android.widget.Button;

import com.example.myapplication.tw3.RegisterFragment;

public class MainActivity11_3 extends AppCompatActivity {


    private DrawerLayout drawerLayout;
    private Button buttonClearOptions;
    private Button buttonRegister;
    private Button buttonExit;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main11_3);

        drawerLayout = findViewById(R.id.drawerLayout);
        buttonClearOptions = findViewById(R.id.buttonClearOptions);
        buttonRegister = findViewById(R.id.buttonRegister);
        buttonExit = findViewById(R.id.buttonExit);

        // 设置侧滑菜单按钮点击事件
        buttonClearOptions.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                clearOptions();
            }
        });

        buttonRegister.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                register();
            }
        });

        buttonExit.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                showExitDialog();
            }
        });

        // 初始化显示注册界面
        showRegisterFragment();
    }

    private void showRegisterFragment() {
        RegisterFragment registerFragment = new RegisterFragment();
        FragmentTransaction transaction = getSupportFragmentManager().beginTransaction();
        transaction.replace(R.id.fragmentContainer, registerFragment);
        transaction.commit();
    }

    private void clearOptions() {
        // 在这里添加清空选项的逻辑代码
    }

    private void register() {
        // 在这里添加注册逻辑代码
    }

    private void showExitDialog() {
        // 在这里添加退出确认对话框逻辑代码
    }
}