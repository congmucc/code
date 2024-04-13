package com.example.myapplication;

import android.app.Activity;
import android.app.TimePickerDialog;
import android.os.Bundle;
import android.view.View;
import android.widget.EditText;
import android.widget.TimePicker;

import java.util.Calendar;

public class MainActivity9_3 extends Activity {

    private EditText editTextTime;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main9_3);

        editTextTime = findViewById(R.id.editTextTime);
    }

    public void showTimePickerDialog(View v) {
        // 获取当前时间
        Calendar nowTime = Calendar.getInstance();
        int hourNow = nowTime.get(Calendar.HOUR_OF_DAY);
        int minuteNow = nowTime.get(Calendar.MINUTE);

        // 创建时间选择对话框
        TimePickerDialog timePickerDialog = new TimePickerDialog(
                this,
                new TimePickerDialog.OnTimeSetListener() {
                    @Override
                    public void onTimeSet(TimePicker view, int hourOfDay, int minute) {
                        // 将用户选择的时间显示在EditText中
                        editTextTime.setText(String.format("%02d:%02d", hourOfDay, minute));
                    }
                },
                hourNow,
                minuteNow,
                true);

        // 显示对话框
        timePickerDialog.show();
    }
}