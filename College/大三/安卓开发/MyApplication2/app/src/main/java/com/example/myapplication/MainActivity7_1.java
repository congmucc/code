package com.example.myapplication;

import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.RadioGroup;
import android.widget.TextView;

import androidx.appcompat.app.AppCompatActivity;

import java.util.Locale;

public class MainActivity7_1 extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main7_1);
        TextView categoryTextView;
        TextView discountTextView;
        EditText amountEditText;
        Button calculateButton;
        RadioGroup userCategoryRadioGroup;
        categoryTextView = findViewById(R.id.e7_category);
        discountTextView = findViewById(R.id.e7_discount);
        amountEditText = findViewById(R.id.amount_edit_text);
        calculateButton = findViewById(R.id.calculate_button);
        userCategoryRadioGroup = findViewById(R.id.user_category_radio_group);

        calculateButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                // 获取选中的RadioButton的文本
                int selectedRadioButtonId = userCategoryRadioGroup.getCheckedRadioButtonId();
                if (selectedRadioButtonId == R.id.normal_user_radio_button) {
                    // 普通用户选中，不打折
                    categoryTextView.setText("普通用户");
                    String amountText = amountEditText.getText().toString();
                    double amount = Double.parseDouble(amountText);
                    discountTextView.setText(String.format(Locale.getDefault(), "%.2f", amount));
                } else if (selectedRadioButtonId == R.id.vip_user_radio_button) {
                    // VIP用户选中，打8折
                    categoryTextView.setText("VIP");
                    String amountText = amountEditText.getText().toString();
                    double amount = Double.parseDouble(amountText);
                    double discountedAmount = amount * 0.8;
                    discountTextView.setText(String.format(Locale.getDefault(), "%.2f", discountedAmount));
                }
            }
        });


    }
}