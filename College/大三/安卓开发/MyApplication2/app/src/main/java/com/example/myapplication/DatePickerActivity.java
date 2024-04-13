package com.example.myapplication;// DatePickerActivity.java
import android.app.Activity;
import android.os.Bundle;
import android.widget.DatePicker;

public class DatePickerActivity extends Activity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_date_picker);

        DatePicker datePicker = findViewById(R.id.datePicker);

    }
}