//
//  DZLCollectionOperators.h
//  TestApp
//
//  Created by sdods on 15/03/2014.
//  Copyright (c) 2014 The App Business. All rights reserved.
//

#define DZLKeyPath(type, keyPath) ({ if(NO){((type)nil).keyPath;} @#keyPath; })

#define DZLAverage(collection, typeOfObjectsInCollection, keyPath) (((NSNumber *)DZLEvaluateCollectionOperation(collection, typeOfObjectsInCollection, keyPath, avg)).doubleValue)
#define DZLCount(collection, typeOfObjectsInCollection, keyPath) (((NSNumber *)DZLEvaluateCollectionOperation(collection, typeOfObjectsInCollection, keyPath, count)).doubleValue)
#define DZLMaximum(collection, typeOfObjectsInCollection, keyPath) DZLEvaluateCollectionCompareOperation(collection, typeOfObjectsInCollection, keyPath, max)
#define DZLMinimum(collection, typeOfObjectsInCollection, keyPath) DZLEvaluateCollectionCompareOperation(collection, typeOfObjectsInCollection, keyPath, min)
#define DZLSum(collection, typeOfObjectsInCollection, keyPath) (((NSNumber *)DZLEvaluateCollectionOperation(collection, typeOfObjectsInCollection, keyPath, sum)).doubleValue)

#define DZLAverageOfNumbers(collection) DZLAverageNumber(collection, NSNumber *, self)
#define DZLSumOfNumbers(collection) DZLSumNumber(collection, NSNumber *, self)

#define DZLAverageNumber(collection, typeOfObjectsInCollection, keyPath) (((NSNumber *)DZLEvaluateCollectionNumberOperation(collection, typeOfObjectsInCollection, keyPath, avg)).doubleValue)
#define DZLSumNumber(collection, typeOfObjectsInCollection, keyPath) (((NSNumber *)DZLEvaluateCollectionNumberOperation(collection, typeOfObjectsInCollection, keyPath, sum)).doubleValue)

#define DZLAverageDouble(collection, typeOfObjectsInCollection, keyPath) (((NSNumber *)DZLEvaluateCollectionDoubleOperation(collection, typeOfObjectsInCollection, keyPath, avg)).doubleValue)
#define DZLSumDouble(collection, typeOfObjectsInCollection, keyPath) (((NSNumber *)DZLEvaluateCollectionDoubleOperation(collection, typeOfObjectsInCollection, keyPath, sum)).doubleValue)

#define DZLDistinctUnionOfObjects(collection, typeOfObjectsInCollection, keyPath) DZLEvaluateCollectionOperation(collection, typeOfObjectsInCollection, keyPath, distinctUnionOfObjects)
#define DZLUnionOfObjects(collection, typeOfObjectsInCollection, keyPath) DZLEvaluateCollectionOperation(collection, typeOfObjectsInCollection, keyPath, unionOfObjects)

#define DZLDistinctUnionOfArrays(collection, typeOfObjectsInCollection, keyPath) DZLEvaluateCollectionOperation(collection, typeOfObjectsInCollection, keyPath, distinctUnionOfArrays)
#define DZLUnionOfArrays(collection, typeOfObjectsInCollection, keyPath) DZLEvaluateCollectionOperation(collection, typeOfObjectsInCollection, keyPath, unionOfArrays)
#define DZLDistinctUnionOfSets(collection, typeOfObjectsInCollection, keyPath) DZLEvaluateCollectionOperation(collection, typeOfObjectsInCollection, keyPath, distinctUnionOfSets)


#define DZLEvaluateCollectionOperation(collection, typeOfObjectsInCollection, keyPath, operator) ({ if (NO) { ^id(){((typeOfObjectsInCollection)(nil)).keyPath; return collection;}(); } \
[(collection) valueForKeyPath:@"@"#operator"."#keyPath]; })

#define DZLEvaluateCollectionNumberOperation(collection, typeOfObjectsInCollection, keyPath, operator) ({ if (NO) { ^id(NSNumber *dzl_number){dzl_number = ((typeOfObjectsInCollection)(nil)).keyPath; return collection;}(nil); } \
DZLEvaluateCollectionOperation(collection, typeOfObjectsInCollection, keyPath, operator); })

#define DZLEvaluateCollectionDoubleOperation(collection, typeOfObjectsInCollection, keyPath, operator) ({ if (NO) { ^id(double dzl_double){dzl_double = ((typeOfObjectsInCollection)(nil)).keyPath; return collection;}(0); } \
DZLEvaluateCollectionOperation(collection, typeOfObjectsInCollection, keyPath, operator); })

#define DZLEvaluateCollectionCompareOperation(collection, typeOfObjectsInCollection, keyPath, operator) ({ if (NO) { ^id(){[((typeOfObjectsInCollection)(nil)).keyPath compare:nil]; return collection;}(); } \
DZLEvaluateCollectionOperation(collection, typeOfObjectsInCollection, keyPath, operator); })
