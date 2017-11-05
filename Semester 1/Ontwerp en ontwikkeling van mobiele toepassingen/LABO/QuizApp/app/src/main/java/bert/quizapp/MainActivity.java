package bert.quizapp;

import android.content.Intent;
import android.content.res.Resources;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;

import org.w3c.dom.Text;

import java.util.Random;

public class MainActivity extends AppCompatActivity {

    TextView textView_question;
    EditText editText_answer;
    Button button_hint;
    Button button_ok;

    String[] questions;
    String[] answers;

    int currentQuestionIndex = 0;
    boolean hasRequestedHint;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        questions = getResources().getStringArray(R.array.questions);
        answers = getResources().getStringArray(R.array.answers);

        textView_question = (TextView) findViewById(R.id.textView_question);

        editText_answer = (EditText) findViewById(R.id.editText_answer);

        button_hint = (Button) findViewById(R.id.button_hint);
        button_hint.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Intent intent = new Intent(MainActivity.this, HintActivity.class);
                intent.putExtra(TAGS.CURRENT_QUESTION_INDEX, currentQuestionIndex);
                startActivityForResult(intent, TAGS.HINT_REQUEST_CODE);
            }
        });

        button_ok = (Button) findViewById(R.id.button_ok);
        button_ok.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                submit(view);
            }
        });

        newQuestion();
    }

    public void submit(View view) {
        String message;

        String correctAnswer = answers[currentQuestionIndex].toLowerCase();
        String givenAnswer = editText_answer.getText().toString().toLowerCase();

        if (givenAnswer.equals(correctAnswer)) {
            if (hasRequestedHint) {
                message = getResources().getString(R.string.correct_answer);
            } else {
                message = getResources().getString(R.string.correct_answer_with_hint);
            }
        } else {
            message = getResources().getString(R.string.wrong_answer);
        }
        Toast.makeText(this, message, Toast.LENGTH_SHORT).show();

        newQuestion();
    }

    private void newQuestion() {
        Random r = new Random();
        currentQuestionIndex = r.nextInt(questions.length);
        textView_question.setText(questions[currentQuestionIndex]);
        hasRequestedHint = false;
    }

    @Override
    protected void onActivityResult(int requestCode, int resultCode, Intent data) {
        if (requestCode == TAGS.HINT_REQUEST_CODE) {
            if (resultCode == RESULT_OK) {
                hasRequestedHint = data.getBooleanExtra(TAGS.HAS_REQUESTED_HINT, false);
                Log.d(TAGS.HAS_REQUESTED_HINT, Boolean.toString(hasRequestedHint));
            }
        }
    }
}
