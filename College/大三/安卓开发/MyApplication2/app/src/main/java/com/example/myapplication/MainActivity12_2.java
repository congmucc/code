
package com.example.myapplication;

import android.content.Intent;
import android.net.Uri;
import android.os.Bundle;
import android.text.TextUtils;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

import androidx.appcompat.app.AppCompatActivity;

public class MainActivity12_2 extends AppCompatActivity {

    private EditText etLink;
    private Button btnOpen;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main12_2);

        etLink = findViewById(R.id.et_link);
        btnOpen = findViewById(R.id.btn_open);

        btnOpen.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                String link = etLink.getText().toString();
                if (!TextUtils.isEmpty(link)) {
                    Uri uri = Uri.parse(link);
                    Intent intent = new Intent(Intent.ACTION_VIEW, uri);
                    intent.setPackage("com.android.chrome"); // 设置为Chrome的包名
                    startActivity(intent);
                } else {
                    Toast.makeText(MainActivity12_2.this, "请输入链接", Toast.LENGTH_SHORT).show();
                }
            }
        });
    }
}
