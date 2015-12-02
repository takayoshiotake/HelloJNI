#include <jni.h>
#include <android/log.h>

namespace SampleClass {
    jstring message(JNIEnv *env, jobject thiz) {
        return env->NewStringUTF("Hello Native Method!");
    }

    bool register_natives(JNIEnv* env) {
        static const char* K_class_name = "com/takayoshiotake/mylibrary/SampleClass";
        static const JNINativeMethod K_native_methods[] = {
                { "message", "()Ljava/lang/String;", (void*)SampleClass::message },
        };

        jclass clazz = env->FindClass(K_class_name);
        if (clazz == nullptr) {
            return false;
        }
        if (env->RegisterNatives(clazz, K_native_methods, sizeof(K_native_methods) / sizeof(K_native_methods[0])) < 0) {
            return JNI_ERR;
        }
        return true;
    }
}

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM* vm, void* reserved) {

    JNIEnv* env;
    if (vm->GetEnv((void**)&env, JNI_VERSION_1_6) != JNI_OK) {
        return JNI_ERR;
    }

    if (!SampleClass::register_natives(env)) {
        __android_log_print(ANDROID_LOG_FATAL, "JNI", "Failed to register native methods of SampleClass.");
        return JNI_ERR;
    }

    return JNI_VERSION_1_6;
}
