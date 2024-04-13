package com.example.myapplication;// TimePickerActivity.java
import android.app.Activity;
import android.os.Bundle;
import android.widget.TimePicker;

public class TimePickerActivity extends Activity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_time_picker);

        TimePicker timePicker = findViewById(R.id.timePicker);

    }
}