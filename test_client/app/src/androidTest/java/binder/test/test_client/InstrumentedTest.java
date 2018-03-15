package binder.test.test_client;

import android.os.Binder;
import android.os.IBinder;
import android.os.Parcel;

import android.support.test.runner.AndroidJUnit4;
import android.util.Log;

import org.junit.Test;
import org.junit.runner.RunWith;

import java.lang.reflect.Method;



@RunWith(AndroidJUnit4.class)
public class InstrumentedTest {
    @Test
    public void BinderTest() throws Exception {
        Log.d("Binder_Test_Client", "Starting BinderTest:");
        IBinder BinderTestServiceBinder = null;
        Method getService = Class.forName("android.os.ServiceManager").getMethod("getService", String.class);
        BinderTestServiceBinder = (IBinder) getService.invoke(null, "BinderTestService");
        if (BinderTestServiceBinder == null) {
            Log.d("Binder_Test_Client", "get BinderTestService: Failed");
        }
        else
        {
            Log.d("Binder_Test_Client", "get BinderTestService: Passed");
        }

        Parcel data = null;
        Parcel reply = null;

        data = Parcel.obtain();
        reply = Parcel.obtain();

        //Invoke args to parcels
        String DESCRIPTOR = "com.test.BinderTestService";
        int content = 1;
        Log.d("Binder_Test_Client", "Wrting " + DESCRIPTOR + "into data parcel");
        data.writeInterfaceToken(DESCRIPTOR);
        Log.d("Binder_Test_Client", "Wrting " + content + "into data parcel");
        data.writeInt(content);

        Log.d("Binder_Test_Client", "Calling AptTestServiceBinder Transact()");
        //call on Binder
        int INVOKE_TRANSACTION = Binder.FIRST_CALL_TRANSACTION;
        BinderTestServiceBinder.transact(INVOKE_TRANSACTION, data, reply, 0);


        //Read the response, starting with result
        int result = reply.readInt();
        Log.d("Binder_Test_Client", "BinderTestService returned: " + result);

        if (data != null)
            data.recycle();
        if (reply != null)
            reply.recycle();
    }
}
