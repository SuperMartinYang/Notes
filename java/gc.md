# Garbage Collector for Java

## Memory 
```
                 / survivor  \
 |---- eden ----|- s0 -|- s1 -|-- tenured --|-- permanent --|
 \        young gen          / \     old   / \  permanent  /
```

## Explain
* young gen: 
    * eden: when object is created, we try to get a space for it in eden  
    * s0: when eden is full, copy survivor from eden to s0
    * s1: when eden and s0 are full, copu surviver from eden and s0 to s1
* old: 
    * Tenured: store objects which haven't been collected after N times
* permanent:
    * store class and methods

## Reference
* reference count
* tracing (reachable?)