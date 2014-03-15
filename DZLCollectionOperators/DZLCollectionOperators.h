//
//  DZLCollectionOperators.h
//  TestApp
//
//  Created by sdods on 15/03/2014.
//  Copyright (c) 2014 The App Business. All rights reserved.
//

#import "DZLCollectionKeyPathEvaluator.h"

#define DZLAverage(collection, typeOfObjectsInCollection, keyPath) DZLEvaluateCollectionNumberOperation(collection, typeOfObjectsInCollection, keyPath, avg)
#define DZLCount(collection, typeOfObjectsInCollection, keyPath) DZLEvaluateCollectionNumberOperation(collection, typeOfObjectsInCollection, keyPath, count)
#define DZLMaximum(collection, typeOfObjectsInCollection, keyPath) DZLEvaluateCollectionCompareOperation(collection, typeOfObjectsInCollection, keyPath, max)
#define DZLMinimum(collection, typeOfObjectsInCollection, keyPath) DZLEvaluateCollectionCompareOperation(collection, typeOfObjectsInCollection, keyPath, min)
#define DZLSum(collection, typeOfObjectsInCollection, keyPath) DZLEvaluateCollectionNumberOperation(collection, typeOfObjectsInCollection, keyPath, sum)

#define DZLDistinctUnionOfObjects(collection, typeOfObjectsInCollection, keyPath) DZLEvaluateCollectionOperation(collection, typeOfObjectsInCollection, keyPath, distinctUnionOfObjects)
#define DZLUnionOfObjects(collection, typeOfObjectsInCollection, keyPath) DZLEvaluateCollectionOperation(collection, typeOfObjectsInCollection, keyPath, unionOfObjects)

#define DZLDistinctUnionOfArrays(collection, typeOfObjectsInCollection, keyPath) DZLEvaluateCollectionOperation(collection, typeOfObjectsInCollection, keyPath, distinctUnionOfArrays)
#define DZLUnionOfArrays(collection, typeOfObjectsInCollection, keyPath) DZLEvaluateCollectionOperation(collection, typeOfObjectsInCollection, keyPath, unionOfArrays)
#define DZLDistinctUnionOfSets(collection, typeOfObjectsInCollection, keyPath) DZLEvaluateCollectionOperation(collection, typeOfObjectsInCollection, keyPath, distinctUnionOfSets)
