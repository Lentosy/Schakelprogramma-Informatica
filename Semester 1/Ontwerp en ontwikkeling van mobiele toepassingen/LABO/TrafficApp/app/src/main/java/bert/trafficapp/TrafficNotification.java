package bert.trafficapp;

import java.util.Date;
import java.util.UUID;

/**
 * Created by bert on 26/10/2017.
 */

public class TrafficNotification {

    private final UUID mId;
    private String mName;
    private String mType;
    private String mSource;
    private String mTransport;
    private String mMessage;
    private float mLatitude;
    private float mLongitude;
    private Date mDate;

    public TrafficNotification() {
        this(UUID.randomUUID());
    }

    public TrafficNotification(UUID id) {
        mId = id;
    }

    public UUID getId() {
        return mId;
    }

    public String getName() {
        return mName;
    }

    public void setName(String name) {
        mName = name;
    }

    public String getType() {
        return mType;
    }

    public void setType(String type) {
        mType = type;
    }

    public String getSource() {
        return mSource;
    }

    public void setSource(String source) {
        mSource = source;
    }

    public String getTransport() {
        return mTransport;
    }

    public void setTransport(String transport) {
        mTransport = transport;
    }

    public String getMessage() {
        return mMessage;
    }

    public void setMessage(String message) {
        mMessage = message;
    }

    public float getLatitude() {
        return mLatitude;
    }

    public void setLatitude(float latitude) {
        mLatitude = latitude;
    }

    public float getLongitude() {
        return mLongitude;
    }

    public void setLongitude(float longitude) {
        mLongitude = longitude;
    }

    public Date getDate() {
        return mDate;
    }

    public void setDate(Date date) {
        mDate = date;
    }

    @Override
    public String toString() {
        return mSource + " - " + mType;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;

        TrafficNotification that = (TrafficNotification) o;
        if (Float.compare(that.getLatitude(), getLatitude()) != 0) return false;
        if (Float.compare(that.getLongitude(), getLongitude()) != 0) return false;
        if (!getId().equals(that.getId())) return false;
        if (getName() != null ? !getName().equals(that.getName()) : that.getName() != null)
            return false;
        if (getType() != null ? !getType().equals(that.getType()) : that.getType() != null)
            return false;
        if (getSource() != null ? !getSource().equals(that.getSource()) : that.getSource() != null)
            return false;
        if (getTransport() != null ? !getTransport().equals(that.getTransport()) : that.getTransport() != null)
            return false;
        if (getMessage() != null ? !getMessage().equals(that.getMessage()) : that.getMessage() != null)
            return false;
        return getDate() != null ? getDate().equals(that.getDate()) : that.getDate() == null;
    }

    @Override
    public int hashCode() {
        return getId().hashCode();
    }
}
