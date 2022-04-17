package com.example.user.myapplication;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.view.ViewDebug;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.TextView;

public class Main2Activity extends AppCompatActivity implements View.OnClickListener{
    @Override
    public void onClick(View view)
    {
        Intent i = new Intent(this,MainActivity.class);
        startActivity(i);

    }
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main2);
        Button b = findViewById(R.id.s321);
        b.setOnClickListener(this);
        int num1 = (int)(Math.random()*52);
        int num2 = num1%13;
        ImageView iv = findViewById(R.id.iu1);
        TextView v = findViewById(R.id.yesman) ;
        String strpos="";
        String strp = "";
        if(num1/13 ==0)
        {
            if(num2 == 0)
                strpos = "ace";
            if(num2>0&&num2<10)
                strpos=Integer.toString(num2+1);
            if (num2 ==10)
                strpos="jack";
            if (num2 ==11)
                strpos="queen";
            if (num2 ==12)
                strpos="king";
            strp = "clubs";
        }

        else if(num1/13 ==1) {
            if(num2 == 0)
                strpos = "ace";
            if(num2>0&&num2<10)
                strpos=Integer.toString(num2+1);
            if (num2 ==10)
                strpos="jack";
            if (num2 ==11)
                strpos="queen";
            if (num2 ==12)
                strpos="king";
           strp = "diamonds";
        }
        else if(num1/13 ==2) {
            if(num2 == 0)
                strpos = "ace";
            if(num2>0&&num2<10)
                strpos=Integer.toString(num2+1);
            if (num2 ==10)
                strpos="jack";
            if (num2 ==11)
                strpos="queen";
            if (num2 ==12)
                strpos="king";
          strp = "hearts";
        }
        else if(num1/13 ==3) {
            if(num2 == 0)
                strpos = "ace";
            if(num2>0&&num2<10)
                strpos=Integer.toString(num2+1);
            if (num2 ==10)
                strpos="jack";
            if (num2 ==11)
                strpos="queen";
            if (num2 ==12)
                strpos="king";
           strp ="spades";
        }
        String name = String.format("c%s_of_%s" , strpos , strp);
        int res = getResources().getIdentifier(name,"drawable", getPackageName());
        iv.setImageResource(res);
        v.setText(name);
    }
}
