#include <binder/IPCThreadState.h>
#include <binder/IServiceManager.h>
#include <utils/Log.h>
#include <binder/Parcel.h>
#include <binder/IPCThreadState.h>
#include <utils/threads.h>

#include <cutils/properties.h>
#include "BinderTestService.h"


namespace android 
{
    BinderTestService::BinderTestService() 
    {
    }

    int BinderTestService::printToLogcat(int code)
    {
        ALOGD(" BinderTestService::printToLogcat code = %d.", code);
        return 0;
    }
}