package com.example.thjcc;

import androidx.appcompat.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        Button checkBtn = findViewById(R.id.check_btn);
        checkBtn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Toast.makeText(MainActivity.this, "Find it yourself!", Toast.LENGTH_SHORT).show();
            }
        });
    }
    public String flag(){
        return "THJCC{l4zy_"+"@string/real_flag"+"==}";
    }
}

