/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class com_webtop_om_OmStem */

#ifndef _Included_com_webtop_om_OmStem
#define _Included_com_webtop_om_OmStem
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     com_webtop_om_OmStem
 * Method:    createNativeObject
 * Signature: (Ljava/lang/String;)J
 */
JNIEXPORT jlong JNICALL Java_com_webtop_om_OmStem_createNativeObject
  (JNIEnv *, jobject, jstring);

/*
 * Class:     com_webtop_om_OmStem
 * Method:    deleteNativeObject
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_webtop_om_OmStem_deleteNativeObject
  (JNIEnv *, jobject);

/*
 * Class:     com_webtop_om_OmStem
 * Method:    stem_word
 * Signature: (Ljava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_webtop_om_OmStem_stem_1word
  (JNIEnv *, jobject, jstring);

#ifdef __cplusplus
}
#endif
#endif
