//
//  AnalyticXEvents.h
//  buildanempire
//
//  Created by Sergey Buravtsov on 05/10/13.
//
//
#include "common.h"
#include "AnalyticX.h"

void AnalyticX::flurryLogEventTimed(char const *,bool)
{}

void AnalyticX::flurryLogEvent(char const *)
{}

void AnalyticX::flurryLogEventWithParameters(const char * eventName, cocos2d::CCDictionary * parameters)
{
}

void AnalyticX::flurryLogEventWithParametersTimed(char const *,class cocos2d::CCDictionary *,bool)
{}

void AnalyticX::flurryEndTimedEventWithParameters(char const *,class cocos2d::CCDictionary *)
{}

void AnalyticX::flurrySetUserID(char const *)
{}

void AnalyticX::matTrackAction(const char * event, double revenue, const char * currency)
{}

void AnalyticX::mixpanelSharedInstanceWithToken(const char * token) {}
void AnalyticX::mixpanelIdentify(const char * distinctId) {}
void AnalyticX::mixpanelTrackCharge(double amount, cocos2d::CCDictionary *properties){}
const char * AnalyticX::getCurrentDateWithFormat(const char *dateStringFormat) {return "";}