//
//  DZLCollectionOperators.h
//  TestApp
//
//  Created by sdods on 15/03/2014.
//  Copyright (c) 2014 The App Business. All rights reserved.
//

#define DZLKeyPath()

#define DZLAverage(collection, typeOfObjectsInCollection, keyPath) DZLEvaluateCollectionOperation(collection, typeOfObjectsInCollection, keyPath, avg)
#define DZLCount(collection, typeOfObjectsInCollection, keyPath) DZLEvaluateCollectionOperation(collection, typeOfObjectsInCollection, keyPath, count)
#define DZLMaximum(collection, typeOfObjectsInCollection, keyPath) DZLEvaluateCollectionCompareOperation(collection, typeOfObjectsInCollection, keyPath, max)
#define DZLMinimum(collection, typeOfObjectsInCollection, keyPath) DZLEvaluateCollectionCompareOperation(collection, typeOfObjectsInCollection, keyPath, min)
#define DZLSum(collection, typeOfObjectsInCollection, keyPath) DZLEvaluateCollectionOperation(collection, typeOfObjectsInCollection, keyPath, sum)

#define DZLAverageNumber(collection, typeOfObjectsInCollection, keyPath) DZLEvaluateCollectionNumberOperation(collection, typeOfObjectsInCollection, keyPath, avg)
#define DZLSumNumber(collection, typeOfObjectsInCollection, keyPath) DZLEvaluateCollectionNumberOperation(collection, typeOfObjectsInCollection, keyPath, sum)

#define DZLAverageDouble(collection, typeOfObjectsInCollection, keyPath) DZLEvaluateCollectionDoubleOperation(collection, typeOfObjectsInCollection, keyPath, avg)
#define DZLSumDouble(collection, typeOfObjectsInCollection, keyPath) DZLEvaluateCollectionDoubleOperation(collection, typeOfObjectsInCollection, keyPath, sum)

#define DZLDistinctUnionOfObjects(collection, typeOfObjectsInCollection, keyPath) DZLEvaluateCollectionOperation(collection, typeOfObjectsInCollection, keyPath, distinctUnionOfObjects)
#define DZLUnionOfObjects(collection, typeOfObjectsInCollection, keyPath) DZLEvaluateCollectionOperation(collection, typeOfObjectsInCollection, keyPath, unionOfObjects)

#define DZLDistinctUnionOfArrays(collection, typeOfObjectsInCollection, keyPath) DZLEvaluateCollectionOperation(collection, typeOfObjectsInCollection, keyPath, distinctUnionOfArrays)
#define DZLUnionOfArrays(collection, typeOfObjectsInCollection, keyPath) DZLEvaluateCollectionOperation(collection, typeOfObjectsInCollection, keyPath, unionOfArrays)
#define DZLDistinctUnionOfSets(collection, typeOfObjectsInCollection, keyPath) DZLEvaluateCollectionOperation(collection, typeOfObjectsInCollection, keyPath, distinctUnionOfSets)


#define DZLEvaluateCollectionOperation(collection, typeOfObjectsInCollection, keyPath, operator) ({ if (NO) { ^id(id dzl_obj){((typeOfObjectsInCollection)(dzl_obj)).keyPath; return collection;}(nil); } \
[(collection) valueForKeyPath:@"@"#operator"."#keyPath]; })

#define DZLEvaluateCollectionNumberOperation(collection, typeOfObjectsInCollection, keyPath, operator) ({ if (NO) { ^id(NSNumber *dzl_number){dzl_number = ((typeOfObjectsInCollection)(dzl_number)).keyPath; return collection;}(nil); } \
DZLEvaluateCollectionOperation(collection, typeOfObjectsInCollection, keyPath, operator); })

#define DZLEvaluateCollectionDoubleOperation(collection, typeOfObjectsInCollection, keyPath, operator) ({ if (NO) { ^id(double dzl_double, id dzl_obj){dzl_double = ((typeOfObjectsInCollection)(dzl_obj)).keyPath; return collection;}(0, nil); } \
DZLEvaluateCollectionOperation(collection, typeOfObjectsInCollection, keyPath, operator); })

#define DZLEvaluateCollectionCompareOperation(collection, typeOfObjectsInCollection, keyPath, operator) ({ if (NO) { ^id(id dzl_obj){[((typeOfObjectsInCollection)(dzl_obj)).keyPath compare:dzl_obj]; return collection;}(nil); } \
DZLEvaluateCollectionOperation(collection, typeOfObjectsInCollection, keyPath, operator); })
