package bert.trafficapp;

import android.content.Context;
import android.widget.Toast;

import org.json.JSONException;
import org.json.JSONObject;

import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.UUID;

/**
 * Created by Bert on 26-Oct-17.
 */

public class TrafficFeed {


    private static TrafficFeed instance;
    private static Context context;

    private static List<TrafficNotification> trafficNotificationList;

    private final String file = "verkeersmeldingen.json";

    private TrafficFeed(Context c) {
        try {
            context = c;
            trafficNotificationList = new ArrayList<>();
            JSONObject res = Utils.loadJSONFromAsset(c, file);
            trafficNotificationList = Utils.parseJSON(res);
        }catch(Exception e){
            Toast.makeText(c, e.getMessage(), Toast.LENGTH_LONG).show();
        }
    }

    public static TrafficFeed getInstance(Context c) {
        if (instance == null) {
            instance = new TrafficFeed(c);
        }
        return instance;
    }

    public TrafficNotification getNotification(UUID id){
        TrafficNotification trafficNotification = null;

        int i = 0;
        while(trafficNotification == null || i >= trafficNotificationList.size()){
            if(trafficNotificationList.get(i).getId().compareTo(id) == 0){
                trafficNotification = trafficNotificationList.get(i);
            }
            i++;
        }
        return trafficNotification;
    }

    public List<TrafficNotification> getNotifications(){
        return trafficNotificationList;
    }
}
