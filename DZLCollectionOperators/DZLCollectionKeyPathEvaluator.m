//
//  DZLCollectionKeyPathEvaluator.m
//  TestApp
//
//  Created by Sam Dods on 15/03/2014.
//  Copyright (c) 2014 Sam Dods. All rights reserved.
//

#import <objc/runtime.h>
#import "DZLCollectionKeyPathEvaluator.h"


@interface DZLCollectionKeyPathEvaluator ()
@property (nonatomic, strong, readonly) id originalObject;
@property (nonatomic, strong, readonly) NSString *keyPath;
@end


@implementation DZLCollectionKeyPathEvaluator

@dynamic avg, count, max, min, sum;
@dynamic distinctUnionOfObjects, unionOfObjects;
@dynamic distinctUnionOfArrays, unionOfArrays, distinctUnionOfSets;

+ (instancetype)generatorWithOriginalObject:(id)originalObject keyPath:(NSString *)keyPath
{
  return [[self alloc] initWithOriginalObject:originalObject keyPath:keyPath];
}

- (instancetype)initWithOriginalObject:(id)originalObject keyPath:(NSString *)keyPath
{
  self = [super init];
  if (self) {
    _originalObject = originalObject;
    _keyPath = keyPath;
  }

  return self;
}

+ (NSArray *)evaluationSelectors
{
  static NSArray *evaluationSelectors = nil;
  static dispatch_once_t onceToken;

  dispatch_once(&onceToken, ^{
    evaluationSelectors = [self.class namesOfDynamicProperties];
  });

  return evaluationSelectors;
}

+ (NSArray *)namesOfDynamicProperties
{
  NSMutableArray *dynamicPropertyNames = [NSMutableArray new];

  unsigned int numberOfProperties;
  objc_property_t *properties = class_copyPropertyList([self class], &numberOfProperties);

  for (unsigned int i = 0; i < numberOfProperties; i++) {
    objc_property_t property = properties[i];
    const char *propertyName = property_getName(property);

    BOOL isDynamic = NO;
    unsigned int numberOfAttributes;
    objc_property_attribute_t *attributes = property_copyAttributeList(property, &numberOfAttributes);

    for (unsigned int a = 0; a < numberOfAttributes; a++) {
      objc_property_attribute_t attribute = attributes[a];
      if (!strcmp(attribute.name, "D")) {
        isDynamic = YES;
      }
    }

    free (attributes);

    if (isDynamic) {
      [dynamicPropertyNames addObject:[NSString stringWithUTF8String:propertyName]];
    }
  }

  free(properties);

  return dynamicPropertyNames.copy;
}

+ (BOOL)resolveInstanceMethod:(SEL)selector
{
  BOOL shouldEvaluate = [[self.class evaluationSelectors] containsObject:NSStringFromSelector(selector)];

  id (^impBlock)(DZLCollectionKeyPathEvaluator *) = shouldEvaluate ? [self evaluationImplementationBlock:selector] : [self chainedKeyPathImplementationBlock:selector];

  IMP imp = imp_implementationWithBlock(impBlock);
  class_addMethod([self class], selector, imp, "");
  return YES;
}

+ (id (^)(DZLCollectionKeyPathEvaluator *))chainedKeyPathImplementationBlock:(SEL)selector
{
  return ^id(DZLCollectionKeyPathEvaluator *_self) {
    NSString *keyPath = [_self.keyPath ?: @"" stringByAppendingFormat:@".%@", NSStringFromSelector(selector)];
    return [DZLCollectionKeyPathEvaluator generatorWithOriginalObject:_self.originalObject keyPath:keyPath];
  };
}

+ (id (^)(DZLCollectionKeyPathEvaluator *))evaluationImplementationBlock:(SEL)selector
{
  return ^id(DZLCollectionKeyPathEvaluator *_self) {
    return [_self evaluateKeyPathForSelector:selector];
  };
}

- (id)evaluateKeyPathForSelector:(SEL)selector
{
  NSString *keyPath = [NSString stringWithFormat:@"@%@%@", NSStringFromSelector(selector), self.keyPath];
  return [self.originalObject valueForKeyPath:keyPath];
}

@end


@implementation NSObject (KeyPathGenerator)

- (id)keyPathGenerator
{
  return [DZLCollectionKeyPathEvaluator generatorWithOriginalObject:self keyPath:nil];
}

@end
