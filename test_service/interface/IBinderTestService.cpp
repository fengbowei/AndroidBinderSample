#include "IBinderTestService.h"
#include <binder/Parcel.h>
#include <binder/IInterface.h>
#include <utils/Log.h>

namespace android 
{

  enum 
  {
      PRINT_TO_LOCAT = IBinder::FIRST_CALL_TRANSACTION,
  };

  //------------------------------------proxy side--------------------------------
  //note: not used in java client

  class BpBinderTestService : public BpInterface<IBinderTestService> {
  public:
      BpBinderTestService(const sp<IBinder>& impl) : BpInterface<IBinderTestService>(impl) 
      {

      }
      
      virtual int printToLogcat(int code)
      {
          ALOGD("BpBinderTestService::printToLogcat code = %d ", code);
          Parcel data, reply;
          data.writeInt32(code);
          remote()->transact(PRINT_TO_LOCAT, data, &reply);
          return reply.readInt32();
      }
  };
  //---------------------- interface--------------------

  IMPLEMENT_META_INTERFACE(BinderTestService, "com.test.BinderTestService");

  //------------------------------------server side--------------------------------
  status_t BnBinderTestService::onTransact (uint32_t code, const Parcel& data, Parcel* reply, uint32_t flags)
  {
      ALOGD("BnBinderTestService::onTransact");
      CHECK_INTERFACE(BinderTestService, data, reply);
      switch (code) 
      {
          case PRINT_TO_LOCAT: {
              ALOGD("BnBinderTestService::PRINT_TO_LOCAT");
              reply->writeInt32(printToLogcat((int) data.readInt32()));
              return NO_ERROR;
          } break;
      }
      return BBinder::onTransact(code, data, reply, flags);
  }
}