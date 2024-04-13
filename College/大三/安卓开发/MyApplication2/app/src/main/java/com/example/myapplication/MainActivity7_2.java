package com.example.myapplication;

import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;

import androidx.appcompat.app.AppCompatActivity;

public class MainActivity7_2 extends AppCompatActivity {
    private TextView resultTextView;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main7_2);

        EditText numberEditText;
        Button convertButton;


        numberEditText = findViewById(R.id.number_edit_text);
        convertButton = findViewById(R.id.convert_button);
        resultTextView = findViewById(R.id.result_text_view);

        convertButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                String numberText = numberEditText.getText().toString();
                if (numberText.isEmpty()) {
                    Toast.makeText(MainActivity7_2.this, "请输入数字", Toast.LENGTH_SHORT).show();
                    return;
                }

                try {
                    int number = Integer.parseInt(numberText);
                    displayResult(number);
                } catch (NumberFormatException e) {
                    Toast.makeText(MainActivity7_2.this, "请输入有效的数字", Toast.LENGTH_SHORT).show();
                }
            }
        });
    }

    private void displayResult(int number) {
        String result;
        if (number >= 90 && number <= 100) {
            result = "优秀";
        } else if (number >= 80 && number < 90) {
            result = "良好";
        } else if (number >= 70 && number < 80) {
            result = "中等";
        } else if (number >= 60 && number < 70) {
            result = "及格";
        } else if (number >= 0 && number < 60) {
            result = "不及格";
        } else {
            Toast.makeText(MainActivity7_2.this, "请输入0-100之间的数字", Toast.LENGTH_SHORT).show();
            return;
        }
        resultTextView.setText(result);

    }

}