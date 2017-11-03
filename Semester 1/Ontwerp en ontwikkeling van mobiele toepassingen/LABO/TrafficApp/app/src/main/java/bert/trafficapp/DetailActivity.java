package bert.trafficapp;

import android.app.Activity;
import android.content.Context;
import android.os.Bundle;
import android.support.annotation.Nullable;
import android.util.AttributeSet;
import android.view.View;
import android.widget.TextView;

import org.w3c.dom.Text;

import java.text.DateFormat;
import java.util.UUID;

public class DetailActivity extends Activity {

    private TrafficFeed trafficFeed;

    private TextView textView_title;
    private TextView textView_type_value;
    private TextView textView_source_value;
    private TextView textView_transport_value;
    private TextView textView_message_value;
    private TextView textView_date_value;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_detail);

        textView_title           = findViewById(R.id.textView_title);
        textView_type_value      = findViewById(R.id.textView_type_value);
        textView_source_value    = findViewById(R.id.textView_source_value);
        textView_transport_value = findViewById(R.id.textView_transport_value);
        textView_message_value   = findViewById(R.id.textView_message_value);
        textView_date_value      = findViewById(R.id.textView_date_value);

        trafficFeed = TrafficFeed.getInstance(this);
        TrafficNotification trafficNotification = trafficFeed.getNotification(UUID.fromString("b088ea06-fe11-3bec-aaf5-a1e68036378f"));
        if(trafficNotification != null){
            setContent(trafficNotification);
        }
    }



    private void setContent(TrafficNotification trafficNotification){
        textView_title           .setText(trafficNotification.getName());
        textView_type_value      .setText(trafficNotification.getType());
        textView_source_value    .setText(trafficNotification.getSource());
        textView_transport_value .setText(trafficNotification.getTransport());
        textView_message_value   .setText(trafficNotification.getMessage());
        textView_date_value      .setText(trafficNotification.getDate().toString());
    }
}
