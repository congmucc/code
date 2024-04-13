package com.example.myapplication;

import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;

import androidx.appcompat.app.AppCompatActivity;

public class MainActivity5 extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main5);
        Button e5 = findViewById(R.id.e5_button);

        e5.setOnClickListener(new View.OnClickListener() {
            int clickCount = 0;
            @Override
            public void onClick(View view) {
                clickCount++;
                if (clickCount <= 5) {
                    String buttonText = "这是第" + clickCount + "次点击";
                    e5.setText(buttonText);
                } else {
                    finish();
                }
            }
        });


        EditText e5_exit = findViewById(R.id.e5_exit);
        TextView e5_exit_show = findViewById(R.id.e5_exit_show);

        e5_exit.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                String inputText = "输出为："+ e5_exit.getText().toString();
                e5_exit_show.setText(inputText);
            }
        });


    }
}