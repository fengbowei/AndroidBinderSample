LOCAL_PATH:= $(call my-dir)

include $(CLEAR_VARS)

LOCAL_CFLAGS := -D_ANDROID_

LOCAL_C_INCLUDES := $(LOCAL_PATH)/interface \
                    $(LOCAL_PATH)/server \

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
