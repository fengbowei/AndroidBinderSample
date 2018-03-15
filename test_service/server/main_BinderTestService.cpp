#include <binder/IPCThreadState.h>
#include <binder/ProcessState.h>
#include <binder/IServiceManager.h>
#include <utils/Log.h>

#include "BinderTestService.h"


using namespace android;

int main(int argc, char** argv)
{

    //sp<ProcessState> proc(ProcessState::self());
    
    defaultServiceManager()->addService(String16("BinderTestService"), new BinderTestService());
    
    if(defaultServiceManager()->checkService(String16("BinderTestService"))== NULL) 
    {
      ALOGE("publishService: Adding BinderTestService Failed!!");
    } 
    else 
    {
      ALOGD("publishService: Added BinderTestService to services and is now running");
    }
    
    ProcessState::self()->startThreadPool();
    IPCThreadState::self()->joinThreadPool();


    return 0;
}