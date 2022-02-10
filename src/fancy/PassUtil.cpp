#include "cn_fancylab_util_NativePassUtil.h"
#include "JavaString.h"
#include "md5.h"

using namespace spotify::jni;
using namespace std;
/*
 * Class:     cn_fancylab_web_support_PassUtil
 * Method:    encodeNative
 * Signature: (Ljava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_cn_fancylab_util_NativePassUtil_encodeNative
  (JNIEnv *env, jclass, jstring data)
{
  string salt = "xxyyzz@@22";
  string content = JavaString(env, data).get();
  MD5 md5;
  string result1 = md5(content) + salt;
  string last = md5(result1);
  JavaString result = last;
  return result.toJavaString(env);
}
