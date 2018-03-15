#include "../interface/IBinderTestService.h"
#include <binder/BinderService.h>

namespace android 
{
  class BinderTestService : public BinderService<BinderTestService>, public BnBinderTestService 
  {
    public:
        BinderTestService();
        virtual int printToLogcat(int code);
  };
}