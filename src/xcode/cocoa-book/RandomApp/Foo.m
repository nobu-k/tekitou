//
//  Foo.m
//  RandomApp
//
//  Created by Nobuyuki Kubota on 09/11/16.
//  Copyright 2009 __MyCompanyName__. All rights reserved.
//

#import "Foo.h"

@implementation Foo

- (void) awakeFromNib
{
  NSCalendarDate *now;
  now = [NSCalendarDate calendarDate];
  [textField setObjectValue:now];
}

- (IBAction) generate:(id)sender
{
  int generated = 0;
  generated = (random() % 100) + 1;
  
  NSLog(@"generated + %d", generated);
  [textField setIntValue:generated];
}

- (IBAction) seed:(id)sender
{
  srandom(time(NULL));
  [textField setStringValue:@"Generator seeded"];
}

@end
