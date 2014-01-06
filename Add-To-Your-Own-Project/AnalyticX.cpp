//	
//  AnalyticX.cpp
//  AnalyticX
//
//  Created by diwwu on 5/11/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include "common.h"
#include "AnalyticX.h"
#include "JavaCallManager.h"

#include <android/log.h>
#include "AnalyticXStringUtilAndroid.h"


JavaCall * g_bridge = NULL;
#define TRUE_VALUE "true"
#define FALSE_VALUE "false"
#define PLACEHOLDER_VALUE "placeholder"

void InitBridge()
{
return;
	if (NULL == g_bridge)
	{		
		g_bridge = g_javaCallManager->GetMethod(
			"com/diwublog/AnalyticX/AnalyticXBridge",
			"Bridge",
			"(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V");
	 
		CC_ASSERT(NULL != g_bridge);
	}
}


void AnalyticX::flurryLogEvent(const char * eventName)
{
    InitBridge();
	
	if (NULL != g_bridge)
	{
		g_bridge->Run( CCArray::create(
			CCString::create("flurryLogEvent"),
			CCString::create(eventName),
			CCString::create(FALSE_VALUE),
			NULL));
    }
}

void AnalyticX::flurryLogEventTimed(const char * eventName, bool timed)
{
	InitBridge();
	
	if (NULL != g_bridge)
	{	
		g_bridge->Run( CCArray::create(
			CCString::create("flurryLogEventTimed"),
			CCString::create(eventName),
			CCString::create((true == timed) ? TRUE_VALUE : FALSE_VALUE),
			NULL));
    }
}

void AnalyticX::flurryLogEventWithParameters(const char * eventName, cocos2d::CCDictionary * parameters) {
    cocos2d::JniMethodInfo minfo;
	
	return; // HACK

    bool isHave = cocos2d::JniHelper::getStaticMethodInfo(minfo,"com/diwublog/AnalyticX/AnalyticXBridge","Bridge", "(Ljava/lang/String;[Ljava/lang/String;Ljava/lang/String;)V"); 

    if (!isHave) {
        //do nothing
    } else {
        string eventNameString("flurryLogEventWithParameters,");
        eventNameString += eventName;
		jstring stringArg0 = minfo.env->NewStringUTF(eventNameString.c_str());
        jstring stringArg2 = minfo.env->NewStringUTF(FALSE_VALUE);

        minfo.env->CallStaticVoidMethod(minfo.classID, minfo.methodID, stringArg0, AnalyticXStringUtilAndroid::jobjectArrayFromCCDictionary(minfo, parameters), stringArg2);
		
		minfo.env->DeleteLocalRef(stringArg0);
		minfo.env->DeleteLocalRef(stringArg2);
		minfo.env->DeleteLocalRef(minfo.classID);
    }
}

void AnalyticX::flurryLogEventWithParametersTimed(const char * eventName, cocos2d::CCDictionary * parameters, bool timed) {
    
    cocos2d::JniMethodInfo minfo;
    
	return; // HACK
	
    bool isHave = cocos2d::JniHelper::getStaticMethodInfo(minfo,"com/diwublog/AnalyticX/AnalyticXBridge","Bridge", "(Ljava/lang/String;[Ljava/lang/String;Ljava/lang/String;)V"); 
    
    if (!isHave) {
        //do nothing
    } else {
        string eventNameString("flurryLogEventWithParametersTimed,");
        eventNameString += eventName;
        jstring stringArg0 = minfo.env->NewStringUTF(eventNameString.c_str());
        jstring stringArg2 = minfo.env->NewStringUTF(FALSE_VALUE);
        
        if (timed == true) {
            stringArg2 = minfo.env->NewStringUTF(TRUE_VALUE);
        }
        
        minfo.env->CallStaticVoidMethod(minfo.classID, minfo.methodID, stringArg0, AnalyticXStringUtilAndroid::jobjectArrayFromCCDictionary(minfo, parameters), stringArg2);
        
		minfo.env->DeleteLocalRef(stringArg0);
		minfo.env->DeleteLocalRef(stringArg2);
		minfo.env->DeleteLocalRef(minfo.classID);
    }
}

// Since Flurry for Android does not support *parameters* in *endTimedEvent()*.
// This *parameters* will be ignored when running in Android
void AnalyticX::flurryEndTimedEventWithParameters(const char * eventName, cocos2d::CCDictionary * parameters)
{
	InitBridge();
	
	if (NULL != g_bridge)
	{	
		g_bridge->Run( CCArray::create(
			CCString::create("flurryEndTimedEvent"),
			CCString::create(eventName),
			CCString::create(FALSE_VALUE),
			NULL));
    }
}

void AnalyticX::flurryLogPageView()
{
	InitBridge();
	
	if (NULL != g_bridge)
	{	
		g_bridge->Run( CCArray::create(
			CCString::create("flurryLogPageView"),
			CCString::create(PLACEHOLDER_VALUE),
			CCString::create(FALSE_VALUE),
			NULL));
    }
}

void AnalyticX::flurrySetAppVersion(const char * version)
{
	InitBridge();
	
	if (NULL != g_bridge)
	{	
		g_bridge->Run( CCArray::create(
			CCString::create("flurrySetAppVersion"),
			CCString::create(version),
			CCString::create(FALSE_VALUE),
			NULL));
    }
}

const char * AnalyticX::flurryGetFlurryAgentVersion() {
    
	return "0"; // HACK
	
    cocos2d::JniMethodInfo minfo;
    
    bool isHave = cocos2d::JniHelper::getStaticMethodInfo(minfo,"com/diwublog/AnalyticX/AnalyticXBridge","flurryGetAgentVersion", "()I"); 
    
    if (!isHave) {
        //do nothing
        return NULL;
    } else {
        jint version =  minfo.env->CallStaticIntMethod(minfo.classID, minfo.methodID);
        static char result[20];
        sprintf(result, "%d", version);
		
		//minfo.env->DeleteLocalRef(version);
		minfo.env->DeleteLocalRef(minfo.classID);
        return result;
    }
}

void AnalyticX::flurrySetShowErrorInLogEnabled(bool value) {
    //do nothing on Android
    //only supported in iOS
}

void AnalyticX::flurrySetDebugLogEnabled(bool value)
{
	InitBridge();
	
	if (NULL != g_bridge)
	{	
		g_bridge->Run( CCArray::create(
			CCString::create("flurrySetLogEnabled"),
			CCString::create(PLACEHOLDER_VALUE),
			CCString::create(FALSE_VALUE),
			NULL));
    }
}

void AnalyticX::flurrySetSessionContinueSeconds(int seconds) {
    
	return; // HACK
	
    cocos2d::JniMethodInfo minfo;
    
    bool isHave = cocos2d::JniHelper::getStaticMethodInfo(minfo,"com/diwublog/AnalyticX/AnalyticXBridge","flurrySetSessionContinueSecond", "(I)V"); 
    
    if (!isHave) {
        //do nothing
    } else {        
        minfo.env->CallStaticVoidMethod(minfo.classID, minfo.methodID, (jint)seconds);
		minfo.env->DeleteLocalRef(minfo.classID);
    }
}

void AnalyticX::flurrySetSecureTransportEnabled(bool value)
{
	InitBridge();
	
	if (NULL != g_bridge)
	{	
		g_bridge->Run( CCArray::create(
			CCString::create("flurrySetSecureEnabled"),
			CCString::create(PLACEHOLDER_VALUE),
			CCString::create(FALSE_VALUE),
			NULL));
    }
}

void AnalyticX::flurryStartSession(const char * apiKey)
{
    InitBridge();
	
	if (NULL != g_bridge)
	{	
		g_bridge->Run( CCArray::create(
			CCString::create("flurryOnStartSession"),
			CCString::create(apiKey),
			CCString::create(FALSE_VALUE),
			NULL));
	}
}

void AnalyticX::flurryEndSession()
{
	if (NULL != g_bridge)
	{	
		g_bridge->Run( CCArray::create(
			CCString::create("flurryOnEndSession"),
			CCString::create(PLACEHOLDER_VALUE),
			CCString::create(FALSE_VALUE),
			NULL));
	}
}

void AnalyticX::flurrySetUserID(const char * userID)
{
    InitBridge();
	
	if (NULL != g_bridge)
	{	
		g_bridge->Run( CCArray::create(
			CCString::create("flurrySetUserID"),
			CCString::create(userID),
			CCString::create(FALSE_VALUE),
			NULL));
	}
}

void AnalyticX::flurrySetAge(int age) {
    
	return; // HACK
	
    cocos2d::JniMethodInfo minfo;
    
    bool isHave = cocos2d::JniHelper::getStaticMethodInfo(minfo,"com/diwublog/AnalyticX/AnalyticXBridge","flurrySetAge", "(I)V"); 
    
    if (!isHave) {
        //do nothing
    } else {        
        minfo.env->CallStaticVoidMethod(minfo.classID, minfo.methodID, (jint)age);
		minfo.env->DeleteLocalRef(minfo.classID);
    }
}


void AnalyticX::flurrySetGender(const char * gender)
{
	InitBridge();
	
	if (NULL != g_bridge)
	{	
		g_bridge->Run( CCArray::create(
			CCString::create("flurrySetGender"),
			CCString::create(('m' == (*gender)) ? "male" : "female"),
			CCString::create(FALSE_VALUE),
			NULL));
    }
}

void AnalyticX::flurrySetLatitudeLongitudeHorizontalAccuracyVerticalAccuracy(double latitude, double longitude, float horizontalAccuracy, float verticalAccuracy) {
    // Not supported in Android
}

void AnalyticX::flurrySetReportLocation(bool reportLocation)
{
	InitBridge();
	
	if (NULL != g_bridge)
	{	
		g_bridge->Run( CCArray::create(
			CCString::create("flurryReportLocation"),
			CCString::create(PLACEHOLDER_VALUE),
			CCString::create((true == reportLocation) ? TRUE_VALUE : FALSE_VALUE),
			NULL));
    }
}

void AnalyticX::flurrySetSessionReportsOnCloseEnabled(bool sendSessionReportsOnClose) {
    //iOS only
}

void AnalyticX::flurrySetSessionReportsOnPauseEnabled(bool setSessionReportsOnPauseEnabled) {
    //iOS only
}

void AnalyticX::flurrySetEventLoggingEnabled(bool value) {
    //iOS only
}

void AnalyticX::matTrackAction(const char * event, double revenue, const char * currency)
{
return; // HACK
	cocos2d::JniMethodInfo minfo;
	bool isMethodFound = cocos2d::JniHelper::getStaticMethodInfo(
		minfo,
		"com/playstorm/buildanempire/platform_android",
		"MatWrap",
		"(Ljava/lang/String;D;Ljava/lang/String;)V"); 
    
    if (true == isMethodFound)
	{
        jstring stringArg0 = minfo.env->NewStringUTF(event);
        jstring stringArg2 = minfo.env->NewStringUTF(currency);
        
        minfo.env->CallStaticVoidMethod(minfo.classID, minfo.methodID, stringArg0, revenue, stringArg2);
		
		minfo.env->DeleteLocalRef(stringArg0);
		minfo.env->DeleteLocalRef(stringArg2);
		minfo.env->DeleteLocalRef(minfo.classID);
    }
}







