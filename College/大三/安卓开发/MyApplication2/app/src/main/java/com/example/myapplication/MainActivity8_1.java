package com.example.myapplication;

import android.os.Bundle;
import android.view.View;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Spinner;

import androidx.appcompat.app.AppCompatActivity;

import java.util.ArrayList;

public class MainActivity8_1 extends AppCompatActivity {
    private EditText editText;
    private Button buttonAdd;
    private Button buttonDelete;
    private Spinner spinner;
    private ArrayList<String> listItems;
    private ArrayAdapter<String> adapter;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main8_1);

        // Initialize UI components
        editText = findViewById(R.id.editText);
        buttonAdd = findViewById(R.id.button_add);
        buttonDelete = findViewById(R.id.button_delete);
        spinner = findViewById(R.id.spinner);

        // Initialize listItems and adapter
        listItems = new ArrayList<>();
        adapter = new ArrayAdapter<>(this, android.R.layout.simple_spinner_item, listItems);
        spinner.setAdapter(adapter);

        // Add click listener for "添加" Button
        buttonAdd.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                String inputText = editText.getText().toString();
                if (!inputText.isEmpty()) {
                    listItems.add(inputText);
                    adapter.notifyDataSetChanged();
                    editText.setText("");
                }
            }
        });

        // Add click listener for "删除" Button
        buttonDelete.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                String inputText = editText.getText().toString();
                int itemPosition = listItems.indexOf(inputText);
                if (itemPosition >= 0) {
                    listItems.remove(itemPosition);
                    adapter.notifyDataSetChanged();
                    editText.setText("");
                }
            }
        });
    }
}