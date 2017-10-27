package bert.quizapp;

import android.content.Intent;
import android.net.Uri;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

public class HintActivity extends AppCompatActivity {

    Button button_yes;
    Button button_no;
    Button button_google;
    TextView textView_hint;

    int currentQuestionIndex;
    boolean hasRequestedHint = false;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_hint);

        getSupportActionBar().setDisplayHomeAsUpEnabled(true);

        currentQuestionIndex = getIntent().getIntExtra(TAGS.CURRENT_QUESTION_INDEX, 0);

        textView_hint = (TextView) findViewById(R.id.textView_hint);

        button_yes = (Button) findViewById(R.id.button_yes);
        button_no = (Button) findViewById(R.id.button_no);
        button_google = (Button) findViewById(R.id.button_google);
    }

    @Override
    public void onSaveInstanceState(Bundle savedInstanceState) {
        super.onSaveInstanceState(savedInstanceState);
        savedInstanceState.putBoolean(TAGS.HAS_REQUESTED_HINT, hasRequestedHint);
    }

    @Override
    protected void onRestoreInstanceState(Bundle savedInstanceState) {
        super.onRestoreInstanceState(savedInstanceState);
        if (savedInstanceState.getBoolean(TAGS.HAS_REQUESTED_HINT)) {
            getHint();
        }
    }

    @Override
    public void onBackPressed() {
        Intent returnIntent = new Intent();
        returnIntent.putExtra(TAGS.HAS_REQUESTED_HINT, hasRequestedHint);
        setResult(RESULT_OK, returnIntent);
        super.onBackPressed();
    }

    public void clickedYes(View view) {
        getHint();
    }

    public void clickedNo(View view) {
        this.finish();
    }

    private void getHint() {
        button_yes.setVisibility(View.INVISIBLE);
        button_no.setVisibility(View.INVISIBLE);
        button_google.setVisibility(View.INVISIBLE);
        String answer = getResources().getStringArray(R.array.answers)[currentQuestionIndex];
        textView_hint.setText(answer);
        hasRequestedHint = true;
    }

    public void openGoogle(View view) {
        String keywords = getResources().getStringArray(R.array.keywords)[currentQuestionIndex];
        Uri uri = Uri.parse("http://www.google.com/#q=" + keywords);
        Intent intent = new Intent(Intent.ACTION_VIEW, uri);
        startActivity(intent);
    }
}
