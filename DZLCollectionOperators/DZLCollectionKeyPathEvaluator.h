//
//  DZLCollectionKeyPathEvaluator.h
//  TestApp
//
//  Created by Sam Dods on 15/03/2014.
//  Copyright (c) 2014 Sam Dods. All rights reserved.
//

#define DZLEvaluateCollectionOperation(collection, typeOfObjectsInCollection, keyPath, operator) ({ if (NO) { ^id(id dzl_obj){dzl_obj = ((typeOfObjectsInCollection)(dzl_obj)).keyPath; return collection;}(nil); } \
(((DZLCollectionKeyPathEvaluator *)((typeOfObjectsInCollection)[(collection) keyPathGenerator]).keyPath).operator); })

#define DZLEvaluateCollectionNumberOperation(collection, typeOfObjectsInCollection, keyPath, operator) ({ if (NO) { ^(NSNumber *dzl_number, id dzl_obj){dzl_obj = collection; dzl_number = ((typeOfObjectsInCollection)(collection)).keyPath;}(nil, nil); } \
DZLEvaluateCollectionOperation(collection, typeOfObjectsInCollection, keyPath, operator); })

#define DZLEvaluateCollectionCompareOperation(collection, typeOfObjectsInCollection, keyPath, operator) ({ if (NO) { ^(id dzl_obj){dzl_obj = collection; [((typeOfObjectsInCollection)(collection)).keyPath compare:dzl_obj];}(nil); } \
DZLEvaluateCollectionOperation(collection, typeOfObjectsInCollection, keyPath, operator); })


@interface DZLCollectionKeyPathEvaluator : NSObject

@property (nonatomic, strong, readonly) NSNumber *avg;
@property (nonatomic, strong, readonly) NSNumber *count;
@property (nonatomic, strong, readonly) NSNumber *max;
@property (nonatomic, strong, readonly) NSNumber *min;
@property (nonatomic, strong, readonly) NSNumber *sum;

@property (nonatomic, strong, readonly) NSArray *distinctUnionOfObjects;
@property (nonatomic, strong, readonly) NSArray *unionOfObjects;

@property (nonatomic, strong, readonly) NSArray *distinctUnionOfArrays;
@property (nonatomic, strong, readonly) NSArray *unionOfArrays;
@property (nonatomic, strong, readonly) NSArray *distinctUnionOfSets;

@end

@interface NSObject (KeyPathGenerator)
- (id)keyPathGenerator;
@end
