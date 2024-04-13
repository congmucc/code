package com.example.myapplication;

import android.app.DatePickerDialog;
import android.app.TimePickerDialog;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.DatePicker;
import android.widget.TimePicker;
import android.widget.Toast;

import androidx.appcompat.app.AppCompatActivity;

import java.util.Calendar;

public class MainActivity9_2 extends AppCompatActivity {

        private Button btnDatePicker;
        private Button btnTimePicker;

        @Override
        protected void onCreate(Bundle savedInstanceState) {
                super.onCreate(savedInstanceState);
                setContentView(R.layout.activity_main9_2);

                btnDatePicker = findViewById(R.id.btnDatePicker);
                btnTimePicker = findViewById(R.id.btnTimePicker);
        }

        public void showDatePickerDialog(View v) {
                // 获取当前日期
                Calendar now = Calendar.getInstance();

                DatePickerDialog datePickerDialog = new DatePickerDialog(
                        this,
                        (DatePicker view, int year, int month, int dayOfMonth) -> {
                                String selectedDate = String.format("%04d年%02d月%02d日", year, month + 1, dayOfMonth);
                                Toast.makeText(MainActivity9_2.this, "所选择的日期：" + selectedDate, Toast.LENGTH_SHORT).show();
                        },
                        now.get(Calendar.YEAR),
                        now.get(Calendar.MONTH),
                        now.get(Calendar.DAY_OF_MONTH));

                datePickerDialog.show();
        }

        public void showTimePickerDialog(View v) {
                // 获取当前时间
                Calendar now = Calendar.getInstance();

                TimePickerDialog timePickerDialog = new TimePickerDialog(
                        this,
                        (TimePicker view, int hourOfDay, int minute) -> {
                                String selectedTime = String.format("%02d时%02d分", hourOfDay, minute);
                                Toast.makeText(MainActivity9_2.this, "所选择的时间：" + selectedTime, Toast.LENGTH_SHORT).show();
                        },
                        now.get(Calendar.HOUR_OF_DAY),
                        now.get(Calendar.MINUTE),
                        true);

                timePickerDialog.show();
        }
}