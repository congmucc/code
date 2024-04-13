package com.example.myapplication;

import androidx.appcompat.app.AppCompatActivity;
import androidx.drawerlayout.widget.DrawerLayout;

import android.app.FragmentManager;
import android.app.FragmentTransaction;
import android.os.Bundle;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.ListView;

import com.example.myapplication.tw.bailongFragment;
import com.example.myapplication.tw.shaFragment;
import com.example.myapplication.tw.sunFragment;
import com.example.myapplication.tw.tangFragment;
import com.example.myapplication.tw.zhuFragment;

public class MainActivity11_2 extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main11_2);
        DrawerLayout drawerLayout = findViewById(R.id.drawer_layout);
        ListView mylistView = findViewById(R.id.drawer_list);
        mylistView.setAdapter(new ArrayAdapter<>(this, R.layout.list_item, new String[]{"tang", "zhu", "sun", "sha", "bailong"}));
        mylistView.setOnItemClickListener(new AdapterView.OnItemClickListener() {
            @SuppressWarnings("deprecation")
            @Override
            public void onItemClick(AdapterView<?> adapterView, View view, int i, long l) {
                FragmentManager fragmentManager = getFragmentManager();
                FragmentTransaction transaction = fragmentManager.beginTransaction();
                switch (i) {
                    case 0:
                        tangFragment tangFragment = new tangFragment();
                        transaction.replace(R.id.main, tangFragment);
                        transaction.commit();
                        break;
                    case 1:
                        sunFragment sunFragment = new sunFragment();
                        transaction.replace(R.id.main, sunFragment);
                        transaction.commit();
                        break;
                    case 2:
                        zhuFragment zhuFragment = new zhuFragment();
                        transaction.replace(R.id.main, zhuFragment);
                        transaction.commit();
                        break;
                    case 3:
                        shaFragment shaFragment = new shaFragment();
                        transaction.replace(R.id.main, shaFragment);
                        transaction.commit();
                        break;
                    case 4:
                        bailongFragment bailongFragment = new bailongFragment();
                        transaction.replace(R.id.main, bailongFragment);
                        transaction.commit();
                        break;
                }
                drawerLayout.closeDrawer(mylistView);
            }
        });
    }
}