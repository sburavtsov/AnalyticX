#include "AnalyticX.h"
#import "AnalyticXStringUtil.h"

const char * AnalyticX::getCurrentDateWithFormat(const char *dateStringFormat) {
	
	NSDate *date = [NSDate date];
	NSDateFormatter *dateFormatter = [[[NSDateFormatter alloc] init] autorelease];
	[dateFormatter setDateFormat:[AnalyticXStringUtil nsstringFromCString:dateStringFormat]];
	NSString *formattedDateString = [dateFormatter stringFromDate:date];
	return [AnalyticXStringUtil cstringFromNSString:formattedDateString];
}
