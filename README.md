KVC Collection Operators Done Properly
======================================

The aim of this project is to tackle the disadvantages of
[KVC Collection Operators](https://developer.apple.com/library/ios/documentation/Cocoa/Conceptual/KeyValueCoding/Articles/CollectionOperators.html)

The obvious advatange is clarity in consicion.

But I also want the following:

* explicit choice of operator with compile-time errors for invalid use
* explicit typing of the objects expected in the collection
* compile-time errors if I use a key path that doesn't belong to the type of object in the collection
* code-completion on key path

# DZLCollectionOperators

All macros intended for public use have the format:

MacroName(collection, typeOfObjectsInCollection, keyPath)

* **collection** - instance of `NSArray *`, `NSSet *`, etc. e.g. `self.transactions`
* **typeOfObjectsInCollection** - the type of objects in the collection, e.g. `Transaction *` - I chose to require the full type including asterisk in order to be explicit
* **keyPath** - dot-separated selector names, e.g. `payee.name`

# Example

I can create an array of all the names of payees for transactions, as follows:

```objc
DZLUnionOfObjects(self.transactions, Transaction *, payee.name);
```

# Full List of Macros

#### Simple Collection Operators
* DZLAverage
