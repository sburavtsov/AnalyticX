//
//  appsFlyerIntegration.h
//  buildanempire
//
//  Created by Sergey Buravtsov on 04/04/14.
//
//

static void appsFlyerStartSession(const char *appID, const char * devKey);
static void appsFlyerSetCustomerUserID(const char *customerUserID);
static void appsFlyerTrackAppLaunch();
static void appsFlyerSetCurrencyCode(const char *currencyCode);
static void appsFlyerTrackEventWithValue(const char *eventName, const char *eventValue);
