//
//  DZLCollectionOperators.h
//  TestApp
//
//  Created by sdods on 15/03/2014.
//  Copyright (c) 2014 The App Business. All rights reserved.
//

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

#define DZLEvaluateCollectionNumberOperation(collection, typeOfObjectsInCollection, keyPath, operator) ({ if (NO) { ^(NSNumber *dzl_number, id dzl_obj){dzl_obj = collection; dzl_number = ((typeOfObjectsInCollection)(collection)).keyPath;}(nil, nil); } \
DZLEvaluateCollectionOperation(collection, typeOfObjectsInCollection, keyPath, operator); })

#define DZLEvaluateCollectionDoubleOperation(collection, typeOfObjectsInCollection, keyPath, operator) ({ if (NO) { ^(double dzl_double, id dzl_obj){dzl_obj = collection; dzl_double = ((typeOfObjectsInCollection)(collection)).keyPath;}(0, nil); } \
DZLEvaluateCollectionOperation(collection, typeOfObjectsInCollection, keyPath, operator); })

#define DZLEvaluateCollectionCompareOperation(collection, typeOfObjectsInCollection, keyPath, operator) ({ if (NO) { ^(id dzl_obj){dzl_obj = collection; [((typeOfObjectsInCollection)(collection)).keyPath compare:dzl_obj];}(nil); } \
DZLEvaluateCollectionOperation(collection, typeOfObjectsInCollection, keyPath, operator); })
