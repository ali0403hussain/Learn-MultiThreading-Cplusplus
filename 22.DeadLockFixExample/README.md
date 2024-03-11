# Dead Lock Fixed Example
## Deadlock Avoidance
* Use try_lock() with a timeout
    * Instead of blocking lock()
    * May result in livelock
* Use std::lock()
    * Lock both mutex in a single operation
* Use hierarchical ordering
    * Lock lower-numbered mutex first.