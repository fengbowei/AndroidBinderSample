#ifndef IBinderTest_Service_H  
#define IBinderTest_Service_H 

#include <binder/IInterface.h>

namespace android 
{
  class IBinderTestService : public IInterface 
  {
    public:
        DECLARE_META_INTERFACE(BinderTestService);
        virtual int printToLogcat(int code) = 0;
  };

  class BnBinderTestService : public BnInterface<IBinderTestService> 
  {
    public:
        virtual status_t onTransact(uint32_t code,
                                    const Parcel& data,
                                    Parcel* reply,
                                    uint32_t flags = 0);
  };

}
#endif