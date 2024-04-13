package com.example.myapplication;

import android.app.Activity;
import android.app.AlertDialog;
import android.app.DatePickerDialog;
import android.content.DialogInterface;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuInflater;
import android.view.MenuItem;
import android.view.View;
import android.widget.Button;
import android.widget.CheckBox;
import android.widget.DatePicker;
import android.widget.EditText;
import android.widget.RadioButton;
import android.widget.RadioGroup;
import android.widget.TextView;
import android.widget.Toast;
import android.widget.Toolbar;

import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.Locale;

public class MainActivity10_1 extends Activity {

    private EditText usernameEditText, accountEditText, passwordEditText;
    private RadioGroup genderRadioGroup;
    private RadioButton maleRadioButton, femaleRadioButton;
    private TextView birthDateTextView;
    private Button setBirthDateButton, registerButton;
    private CheckBox swimmingCheckBox, sportsCheckBox, runningCheckBox, hikingCheckBox;

    private Calendar birthDateCalendar;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main10_1);

        // 初始化控件
        initializeViews();

        // 设置Toolbar
        Toolbar toolbar = findViewById(R.id.toolbar);
//        setSupportActionBar(toolbar); // 设置Toolbar作为ActionBar
        setActionBar(toolbar);
        // 设置默认出生日期为当前日期
        birthDateCalendar = Calendar.getInstance();
        updateBirthDateTextView();

        // 设置点击设置按钮的事件
        setBirthDateButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                showDatePickerDialog();
            }
        });

        // 设置注册按钮点击事件
        registerButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                // 处理注册按钮点击事件
                handleRegistration();
            }
        });
    }

    // 初始化控件的方法
    private void initializeViews() {
        // 初始化所有控件
        usernameEditText = findViewById(R.id.usernameEditText);
        accountEditText = findViewById(R.id.accountEditText);
        passwordEditText = findViewById(R.id.passwordEditText);
        genderRadioGroup = findViewById(R.id.genderRadioGroup);
        maleRadioButton = findViewById(R.id.maleRadioButton);
        femaleRadioButton = findViewById(R.id.femaleRadioButton);
        birthDateTextView = findViewById(R.id.birthDateTextView);
        setBirthDateButton = findViewById(R.id.setBirthDateButton);
        registerButton = findViewById(R.id.registerButton);
        swimmingCheckBox = findViewById(R.id.swimmingCheckBox);
        sportsCheckBox = findViewById(R.id.sportsCheckBox);
        runningCheckBox = findViewById(R.id.runningCheckBox);
        hikingCheckBox = findViewById(R.id.hikingCheckBox);
    }

    // 显示日期选择对话框的方法
    private void showDatePickerDialog() {
        DatePickerDialog datePickerDialog = new DatePickerDialog(
                this,
                dateSetListener,
                birthDateCalendar.get(Calendar.YEAR),
                birthDateCalendar.get(Calendar.MONTH),
                birthDateCalendar.get(Calendar.DAY_OF_MONTH)
        );
        datePickerDialog.show();
    }

    // 更新出生日期文本的方法
    private void updateBirthDateTextView() {
        SimpleDateFormat sdf = new SimpleDateFormat("yyyy-MM-dd", Locale.getDefault());
        birthDateTextView.setText(sdf.format(birthDateCalendar.getTime()));
    }

    // 处理日期选择对话框设置的方法
    private DatePickerDialog.OnDateSetListener dateSetListener =
            new DatePickerDialog.OnDateSetListener() {
                @Override
                public void onDateSet(DatePicker datePicker, int year, int month, int day) {
                    birthDateCalendar.set(Calendar.YEAR, year);
                    birthDateCalendar.set(Calendar.MONTH, month);
                    birthDateCalendar.set(Calendar.DAY_OF_MONTH, day);

                    updateBirthDateTextView();
                }
            };

    // 处理注册按钮点击事件的方法
    private void handleRegistration() {
        // 获取用户输入
        String username = usernameEditText.getText().toString();
        String account = accountEditText.getText().toString();
        String password = passwordEditText.getText().toString();
        String gender = maleRadioButton.isChecked() ? "男" : "女";
        String birthDate = birthDateTextView.getText().toString();

        StringBuilder hobbies = new StringBuilder();
        if (swimmingCheckBox.isChecked()) hobbies.append("游泳, ");
        if (sportsCheckBox.isChecked()) hobbies.append("球类, ");
        if (runningCheckBox.isChecked()) hobbies.append("慢跑, ");
        if (hikingCheckBox.isChecked()) hobbies.append("爬山");

        // 构建Notification消息
        String notificationMessage = "注册完成\n用户名：" + username;

        // 显示Notification消息
        Toast.makeText(this, notificationMessage, Toast.LENGTH_SHORT).show();
    }
    // 创建菜单的方法
    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        MenuInflater inflater = getMenuInflater();
        inflater.inflate(R.menu.register_menu, menu);
        return true;
    }

    // 处理菜单项的点击事件
    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        switch (item.getItemId()) {
            case R.id.menu_clear_options:
                clearAllOptions();
                return true;
            case R.id.menu_exit:
                showExitDialog();
                return true;
            default:
                return super.onOptionsItemSelected(item);
        }
    }

    // 清空所有选项的方法
    private void clearAllOptions() {
        usernameEditText.setText("");
        accountEditText.setText("");
        passwordEditText.setText("");
        maleRadioButton.setChecked(true);
        birthDateCalendar = Calendar.getInstance();
        updateBirthDateTextView();
        swimmingCheckBox.setChecked(true);
        sportsCheckBox.setChecked(true);
        runningCheckBox.setChecked(false);
        hikingCheckBox.setChecked(false);
    }

    // 显示退出对话框的方法
    private void showExitDialog() {
        AlertDialog.Builder builder = new AlertDialog.Builder(this);
        builder.setTitle("警告")
                .setMessage("确定要退出吗？")
                .setPositiveButton("确定", new DialogInterface.OnClickListener() {
                    @Override
                    public void onClick(DialogInterface dialogInterface, int i) {
                        finish(); // 关闭Activity
                    }
                })
                .setNegativeButton("取消", null)
                .show();
    }
}