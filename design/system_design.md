# System Design

## Step 1: Understand overall system / application
* clarify by asking questions

## Step 2: Understand system funcitonal requirements
* what functions should be supported.

## Step 3: Understand system non-functional requirements
* availability, consistency, Partition tolerance, trade-off

## Step 4: Evaluate workload
* assumption of data

## Step 5: Brain storm system
* S.N.A.K.E
    * S -> Scenario: usecase
    * N -> Necessity: assumptions / constraints
    * A -> Application: architecture
    * K -> Kilobit: data model, store, query
    * E -> Evolve: high ACP

## Step 6: Scale out
* Horizontal / Vertical Scaling
* Load Balancer
* Database Denormalization and NoSQL
* Database Partitioning (sharding)
    * Vertical Partitioning
    * Key-Based (Hash-Based) Partitioning
    * Directory-Based Partitioning
* Caching
* Asynchronous Processing & Queues
* Networking Metrics
* MapReduce

## PS (Considerations):
* Failures
* Availability and Reliability
* Read-heavy / Write-heavy: RH -> Caching, WH -> Queuing up the writes
* Security

# Case Study
1. Search Engine
    * S: search documents with given keywork list, add new document
    * N: No memory limit, all data can fit in one machine
    * A: front-end, back-end, hash table to store word -> documents
    * K: get real, assume the daily data access. Total documents: 1m * 10MB = 10TB. HashMap size: 10k * 10k * 32B = 3.2GB
    * E: front-end, back-end (Distribute HashMap -> different hash in different node, MapReduce, Hadoop HDFS) 

1. Stock Data：
    * S: get end-of-day stock price, history? analytics, get History
    * N: one machine can serve all requests
    * A: ft + bk + db (relational db) / XML file
    * K: 200m / 365 ~ 500k years -> enough
    * E: 

1. Social Network
    * S: add friends, add / view posts, chat with friends, millions of visits
    * N: all fit in one machine
    * A: ft + bk + db
    * K: 1m visit/s * 1KB = 1GB/s, 1b users * 1KB = 1TB,
    * E: store data in multiple machine, use load balancer for visit, CDN for content, friend map will be split in multiple server by geolocation, find shortest path will go to different server by hash (BFS, with machine id)

1. Web Crawler
    * S:
    * N:
    * A:
    * K: 
    * E:

1. Recommendation System
    * S:
    * N:
    * A:
    * K: 
    * E:

1. Photosharing Website 
    * S:
    * N:
    * A:
    * K: 
    * E:

1. Subscription System
    * S:
    * N:
    * A:
    * K: 
    * E:

1. Twitter
    * S:
    * N:
    * A:
    * K: 
    * E:

1. Uber
    * S:
    * N:
    * A:
    * K: 
    * E:

1. Amazon CloudFront
    * S:
    * N:
    * A:
    * K: 
    * E:

1. Tiny Url
    * S:
    * N:
    * A:
    * K: 
    * E:

1. Ads click frequency
    * S:
    * N:
    * A:
    * K: 
    * E:

1. Vending machine
    * S:
    * N:
    * A:
    * K: 
    * E:

1. Shopping website
    * S:
    * N:
    * A:
    * K: 
    * E: