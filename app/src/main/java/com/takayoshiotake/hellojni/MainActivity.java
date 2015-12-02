package com.takayoshiotake.hellojni;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.TextView;

import com.takayoshiotake.mylibrary.SampleClass;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }

    @Override
    protected void onResume() {
        super.onResume();

        SampleClass sample = new SampleClass();
        ((TextView) findViewById(R.id.textView1)).setText(sample.message());
    }
}
