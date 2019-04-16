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
    * S: get rid of infinite loops
    * N: define the same page based on similarity
    * A: crawl high priority page first, and get the page's signature, when duplicate, set lower priority to the new page
    * K:  if there's lots of page, put key-value in to Redis 
    * E:

1. Duplicate URLs
    * S: detect duplicate documents in 10b URLs
    * It's like a large scale problem, rather than design a system
    * URLs in a large file, Split these URLs into 1k files by Hashing
    * find the duplicate URL
    * Or use multiple machine, split files to those machine

1. Cache
    * S: cache the query result to speed up processSearch, deal with updates
    * N: massive call, and return would be a list, most popular query will be always in the cache
    * A: start from a signle machine, LRU cache
    * K: millions query
    * E: multiple machine, LRU cache, splited into several machine, when query comes in, find corresponding machine by hashing, then return result

1. Sales Rank
    * S: list best-selling products overall and by catogory, purchase logic? date range? category and subcategory?  
    * N: purchase -> add record, date range -> within week, category -> no subcategory & each product can have several categories, do not need to be real-time, data should be update hourly, 
    * A: ft (list sys + purchase sys) + bk + db 
    * K: 1m purchase/s, 1m products, store weekly, rather then together
    * E: Cache the updates before write (Write is expensive), Denomination (Join is expensive), Using log which can be processed by MapReduce rather than DB (Query is expensive)  

# Another way to solve
1. Personal Financial Manager
    * Scope the problem:
        * users can register on system
        * users can add multiple acccouts
        * system will pull transaction from users' accounts
        * system will categorize the transactions
        * user can change the category manually
        * system can analyze the habit of user
        * based on analysis, sys will recommend to specific user
        * assume it's just a website
        * no user specify category

    * Reasonable Assumption:
        * adding or removing bank account is unusual
        * the system is write-heavy
        * only when user change the category, else won't change after assigned

    * Draw Major Components:
        * pull data comp
        * categorize comp
        * analyzer
        * user management comp
        * recommendation
        * front-end

    * Identify the key issues:
        * pull can't be frequently, hourly, 360m * 10 / 3600 = 1m writes to db， use queue to write to database
        * categorize data by seller, update budget, if budget exceed, send email
        * user change category, decrease budget of one category, increase another

1. Pastebin
    * Scope the problem:
        * register
        * add paste content to a center directory
        * publish the post with url
        * highlight, support module
        * expiration
        * track how many time the page get viewed

    * Reasonable Assumption:
        * million documents
        * heavy access, write-heavy and read-heavy
        * some document get more access than other

    * Draw Major Components:
        * front-end
        * analytic for access record
        * addDocument
        * url generator
        * cache
        * datastore , hdfs
        * database for url : filepath, file access records (record in cache first, update db hourly)

    * Identify the key issues:
        * url -> file path, match
        * each access will update the access records
        * url generator when distributed
        

1. Recommendation System
    * Scope the problem:
        * users can add items to their cart
        * get the cart info and update the backend
        * store item info with user
        * get recommendation based on other users

    * Reasonable Assumption:
        * 

    * Draw Major Components:
    * Identify the key issues:

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