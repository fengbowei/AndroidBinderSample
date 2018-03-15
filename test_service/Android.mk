LOCAL_PATH:= $(call my-dir)

include $(CLEAR_VARS)

LOCAL_CFLAGS := -D_ANDROID_

LOCAL_C_INCLUDES := $(TARGET_OUT_INTERMEDIATES)/KERNEL_OBJ/usr/include \
                    $(TARGET_OUT_HEADERS)/common/inc \
                    $(TOP)/vendor/qcom/proprietary/securemsm-internal/test_service/interface \
                    $(TOP)/vendor/qcom/proprietary/securemsm-internal/test_service/server \

LOCAL_ADDITIONAL_DEPENDENCIES := $(TARGET_OUT_INTERMEDIATES)/KERNEL_OBJ/usr

LOCAL_SHARED_LIBRARIES := \
        libcutils \
        libutils \
        libbinder \
        liblog


LOCAL_MODULE := bindertest_service

LOCAL_SRC_FILES := interface/IBinderTestService.cpp \
                   server/BinderTestService.cpp \
                   server/main_BinderTestService.cpp \

LOCAL_MODULE_TAGS := optional debug
LOCAL_PRELINK_MODULE := false
LOCAL_PROPRIETARY_MODULE := true

include $(BUILD_EXECUTABLE)
