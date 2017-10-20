package bert.quizapp;

import android.content.Intent;
import android.content.res.Resources;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;
import android.widget.Toast;

import org.w3c.dom.Text;

import java.util.Random;

public class MainActivity extends AppCompatActivity {

    TextView textView_question;
    Button button_hint;

    String[] questions;
    int currentQuestionIndex = 0;
    boolean hasRequestedHint;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        questions = getResources().getStringArray(R.array.questions);

        textView_question = (TextView) findViewById(R.id.textView_question);
        textView_question.setText(getRandomQuestion());

        button_hint = (Button) findViewById(R.id.button_hint);
        button_hint.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Intent intent = new Intent(MainActivity.this, HintActivity.class);
                intent.putExtra(TAGS.CURRENT_QUESTION_INDEX, currentQuestionIndex);
                startActivityForResult(intent, TAGS.HINT_REQUEST_CODE);
            }
        });
    }

    public void submit(View view) {
        Toast.makeText(this, "Submitting answer...", Toast.LENGTH_SHORT).show();
    }

    private String getRandomQuestion(){
        Random r = new Random();
        currentQuestionIndex = r.nextInt(questions.length);
        return questions[currentQuestionIndex];
    }

    @Override
    protected void onActivityResult(int requestCode, int resultCode, Intent data) {
        if(requestCode == TAGS.HINT_REQUEST_CODE){
            if(resultCode == RESULT_OK){
                hasRequestedHint = data.getBooleanExtra(TAGS.HAS_REQUESTED_HINT, false);
            }
        }
    }
}
