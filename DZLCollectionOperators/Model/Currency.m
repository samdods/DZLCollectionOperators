//
//  Currency.m
//  TestApp
//
//  Created by sdods on 15/03/2014.
//  Copyright (c) 2014 The App Business. All rights reserved.
//


#import "Currency.h"


@implementation Currency

+ (instancetype)currencyWithCode:(NSString *)code
{
  return [[self alloc] initWithCode:code];
}

- (instancetype)initWithCode:(NSString *)code
{
  if (!(self = [super init])) {
    return nil;
  }

  _code = code;

  return self;
}

- (double)exchangeRateFromBaseCurrency
{
  return 0.5;
}

@end
