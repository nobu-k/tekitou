//
//  Foo.h
//  RandomApp
//
//  Created by Nobuyuki Kubota on 09/11/16.
//  Copyright 2009 __MyCompanyName__. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@interface Foo : NSObject {
  IBOutlet NSTextField *textField;
}
- (IBAction)seed:(id)sender;
- (IBAction)generate:(id)sender;

@end
